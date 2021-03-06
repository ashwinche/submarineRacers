#include <json/json.hpp>
#include "world.hxx"
#include <util/file.hxx>
#include <util/conversion.hxx>

using json = nlohmann::json;

World::World() 
{
    this->state=TITLE;
    this->setLevel(NULL);
}

World::~World(){};


void World::quit()
{
    glfwSetWindowShouldClose (this->window, true);
}

// Eventually this can perform a hard reset to a crash or title screen
void World::fatalError(){exit(-1);}

//========================== EVENT HANDLERS =========================//

int World::handleEvent(EventType t, HANDLER_PARAMS)
{
    switch(t)
    {
        case STARTCLIENT:
            return this->handleEventSTARTCLIENT(HANDLER_PARAMS_PASSED);
        case STARTSERVER:
            return this->handleEventSTARTSERVER(HANDLER_PARAMS_PASSED);
        case ADVANCEMENU:
            return this->handleEventADVANCEMENU(HANDLER_PARAMS_PASSED);
        case BACKMENU:
            return this->handleEventBACKMENU(HANDLER_PARAMS_PASSED);
        case LOADLEVEL:
            return this->handleEventLOADLEVEL(HANDLER_PARAMS_PASSED);
        case LEVELLOADEDBYALL:
            return this->handleEventLEVELLOADEDBYALL(HANDLER_PARAMS_PASSED);
        case PAUSEGAME:
            return this->handleEventPAUSEGAME(HANDLER_PARAMS_PASSED);
        case EXIT:
            return this->handleEventEXIT(HANDLER_PARAMS_PASSED);
        case USERDISCONNECT:
            return this->handleEventUSERDISCONNECT(HANDLER_PARAMS_PASSED);
        case USERFINISH:
            return this->handleEventUSERFINISH(HANDLER_PARAMS_PASSED);
        default:
            this->fatalError();
            return this->state;
    }
}

int World::handleEventSTARTCLIENT(HANDLER_PARAMS)
{

    switch(this->state)
    {
        case TITLE:
            this->state = CONNECTING;
            this->getClient()->connectServer();
            this->state = MENU1;
            return ALL_GOOD;
        default:
            //disconnect, reset as client
            return this->state; 
    }
}

int World::handleEventSTARTSERVER(HANDLER_PARAMS)
{

    switch(this->state)
    {
        case TITLE:
            this->state = LISTEN;
            this->getServer()->initListeningSocket();
            return ALL_GOOD;
        default:
            //disconnect, reset as server
            return this->state;
    }
}

int World::handleEventADVANCEMENU(HANDLER_PARAMS)
{
    switch(this->state)
    {
        case MENU1:
            this->state = MENU2;
            return ALL_GOOD;
        default:
            return this->state;
    }
}

int World::handleEventBACKMENU(HANDLER_PARAMS)
{
        return 0;
}

int World::handleEventLOADLEVEL(HANDLER_PARAMS)
{
    switch(this->state)
    {
        case MENU1:
        case MENU2:
        case LISTEN:
            this->state = LOADING_LEVEL;
            this->loadLevel(i);
            return ALL_GOOD;
        default:
            return this->state;
    }
}

int World::handleEventLEVELLOADEDBYALL(HANDLER_PARAMS)
{
    switch(this->state)
    {
        case LOADING_LEVEL:
            this->state = RACE_START;
            return ALL_GOOD;
        default:
            return this->state;
    }
}


int World::handleEventPAUSEGAME(HANDLER_PARAMS)
{
    switch(this->state)
    {
        case PAUSED:
            this->state = RACE_RUNNING;
            return ALL_GOOD;
        case RACE_RUNNING:
            this->state = PAUSED;
            return ALL_GOOD;
        default:
            return this->state;
    }

}

int World::handleEventEXIT(HANDLER_PARAMS)
{
    switch(this->state)
    {
        /* Exit the current level */
        case RACE_RUNNING:
        case RACE_START:
        case RACE_FINISH:
            if(this->isClient())
                this->state = MENU1;
            else {
                /* Unbind all subs */
                this->getServer()->unbindAll();
                this->state = LISTEN;
            }
            return ALL_GOOD;
        default:
            return this->state;

    }
        return 0;
}

int World::handleEventUSERDISCONNECT(HANDLER_PARAMS)
{
    /*switch(this->state)
    {

    }*/
        return 0;
}

int World::handleEventUSERFINISH(HANDLER_PARAMS)
{
    /*switch(this->state)
    {

    }*/
        return 0;
}


//quaternion quatFromSTDVec(std::vector<float> v) {
//    return quaternion(v.at(0), v.at(1), v.at(2), v.at(3));
//}
//
//vec3 vec3FromSTDVec(std::vector<float> v) {
//    return vec3(v.at(0), v.at(1), v.at(2));
//}


int World::loadLevel(int i)
{
    if(i >= this->levels.size()){
        logln(LOGERROR, "Invalid level ID: %d\n", i);
        return -1;
    }

    Level* oldLevel = this->getLevel();
    const char* levelPath = this->levels[i];
    
    logln(LOGMEDIUM, "loading level %s\n", levelPath);
    Level* newLevel = new Level(levelPath);
    newLevel->buildLevelFromFile();

    this->setLevel(newLevel);
    if(!(oldLevel==NULL))
        delete(oldLevel);

    /* Initalize Track Visuals */
    Track *track = this->getLevel()->getTrack();
    if(track)
        track->resetAllChecksVis();

    /* Add submarine entities */
    this->addSubsToLevel();

    return 0;
}

void World::addLevel(const char*path)
{
    this->levels.push_back(path);
}

void World::addAllLevels(vector<const char*> levels)
{
    for (auto level : levels) {
        this->levels.push_back(level);
    }
}


void World::addSub(int id, Submarine *sub)
{
    this->subs.insert(make_pair(id, sub));
}

Submarine * World::getSub(int id)
{
    return this->subs[id];
}

void World::addSubsToLevel()
{
    if(!this->curLevel) return;

    int nSubsAdded = 0;

    for (auto pair : subs){
        // pair.second is the submarine

        // Initalize the progress trackers and get starting position
        int nSeeks, nChecks;
        startInfo start;
        if(!curLevel->getTrack()){
            // Defaults if no track exists
            nSeeks = 0;
            nChecks = 0;
            start = startInfo(pair.second->getOriginalPosition(), 
                pair.second->getOriginalOrientation(), vec3(0,0,0));
        } else  {
            nSeeks = curLevel->getTrack()->nSeeks();
            nChecks = curLevel->getTrack()->nChecks();
            logln(LOGMEDIUM, "loading sub start for sub %d", nSubsAdded);
            start = curLevel->getTrack()->getStartInfoi(nSubsAdded);
        }
        pair.second->getPTSeek()->initalizePoints(nSeeks);
        pair.second->getPTCheck()->initalizePoints(nChecks);
        pair.second->setStartInfo(start);

        // If AI, also add AI to level
        if(pair.second->isAI()){
            curLevel->addAI(pair.second->getAI(), 0.1);
        }

        // Add to level
        pair.second->resetForRace();
        curLevel->addEntity(pair.second);
        nSubsAdded++;
    }
}



/* Handle one tick of the graphics clock (that is, render the game) */
int World::handleGraphicsTick(float t, float dt)
{
    Camera * curCam;
    switch(this->state)
    {
        case MENU1:
            this->displayMenuSub();
            return 1;
        case MENU2:
            this->displayMenuLevel();
            return 1;
        case RACE_RUNNING:
        case RACE_START:
        case RACE_FINISH:
        case PAUSED:
            /* Client-side interpolation may happen here as well */ 

            /* Update tethered camera before rendering */
            curCam = this->view->activeCamera();
            if(curCam->isTethered()){
                ((TetheredCamera*)curCam)->updateTetheredCameraPos();
            }

            this->renderAll();

            return 1;
        
        default:
            return -1;
    }
}

void World::renderAll()
{
    this->getLevel()->renderAll(this->getView(), this->getEntityRenderer(), 
        this->getSkyboxRenderer(), this->getFlatRenderer());
}

/* Handle one tick of the networks clock. This is where we handle communication
with the server/client. */
int World::handleNetworksTick(float t, float dt, int mmax)
{
    if(this->isServer())
        this->handleNetworksTickServer(t, dt, mmax);
    else
        this->handleNetworksTickClient(t, dt, mmax);

    return 1;
}

void World::handleNetworksTickServer(float t, float dt, int mmax)
{
    this->getServer()->ReadMessages(mmax);
    switch(this->state)
    {  
        case RACE_RUNNING:
        case RACE_START:
        case RACE_FINISH:
            this->sendAllUpdates();
            return;
        default:
            return;
    }
}

void World::handleNetworksTickClient(float t, float dt, int mmax)
{
    this->getClient()->ReadMessages(mmax);
    this->getClient()->sendControllerState();
    this->getView()->getFirstPersonCam()->changeTether(this->getClient()->getOurSub());
}

/* Handle one tick of the physics system. If we are a server, we handle
AI input (not decision-making) in this tick as well. If we are a client,
we run the physics engine just to interpolate the position of entities. */
int World::handlePhysicsTick(float t, float dt)
{
    switch(this->state){
    case RACE_RUNNING:
    case RACE_START:
    case RACE_FINISH:
        if(this->isServer()){
            this->getLevel()->updateLevel(dt);
        }
        else{
            this->getLevel()->interpolateLevel(dt);
        }
        return 0;
    default:
        return 1;
    }
}


void World::sendAllUpdates()
{
    if(this->getLevel())
        this->getLevel()->sendPosUps(this->getServer());
}

void World::setEntData(posUpBuf* msg)
{
    if(this->getLevel())
        this->getLevel()->upEntData(msg);
}


void World::displayMenu(Menu* menu)
{
    /* Move the camera to the defined menu-viewing location */
    ((TetheredCamera*)this->getView()->activeCamera())->changeTether(NULL);
    this->getView()->activeCamera()->move(CAMERAMENUPOSITION, CAMERALOOKPOSITION, CAMERAUP);

    /* Render the menu */
    this->getEntityRenderer()->enable();
    this->getEntityRenderer()->render(this->getView(),menu->getDisplay());
}


void World::win(Submarine *sub)
{
    printf("A winner is you, %s!\n", sub->getName().c_str());
}



/* Create all renderers, views, cameras, etc for the world, based off a 
default. We may eventually want to write a function to load this stuff
from a .config file instead of having it hard coded here. */
void World::worldInitalizeDefault(int isServer)
{
    this->initalizeSubsFromFile("../assets/subs/subs0.json");

    // set up shaders.
    Shader *shader = new Shader();
    shader->addShader(GL_VERTEX_SHADER,fileio::load_file("../assets/shaders/lightshader.vert"));
    shader->addShader(GL_FRAGMENT_SHADER,fileio::load_file("../assets/shaders/lightshader.frag"));
    shader->build();

    Shader *skyboxShader = new Shader();
    skyboxShader->addShader(GL_VERTEX_SHADER,fileio::load_file("../assets/shaders/skyboxshader.vert"));
    skyboxShader->addShader(GL_FRAGMENT_SHADER,fileio::load_file("../assets/shaders/skyboxshader.frag"));
    skyboxShader->build();

    Shader *flatShader = new Shader();
    flatShader->addShader(GL_VERTEX_SHADER,fileio::load_file("../assets/shaders/shader.vert"));
    flatShader->addShader(GL_FRAGMENT_SHADER,fileio::load_file("../assets/shaders/shader.frag"));
    flatShader->build();

    //create renderer for the given shader
    Renderer *r = new UnderwaterRenderer(shader);  
    Renderer *rsky = new SkyboxRenderer(skyboxShader);
    Renderer *rflat = new FlatShadingRenderer(flatShader);

    //initialize camera
    Camera *camera = new Camera();
    //position, yaw-roll, up-vector
    camera->init(vec3(50,200,50),vec3(50,-200,50),vec3(0,0,1)); //location, looking-at, up
//  camera->init(vec3(15,10,-3),vec3(-3.14159264f/2.f,0,0),vec3(0,1,0)); //location, looking-at, up
    camera->setFOV(90.0);
    camera->setNearFar(0.1, 1000.0);
    /* Add tethered Camera */
    TetheredCamera * camTeth = new TetheredCamera(FIRSTPERSON, NULL, vec3(0.2,2,0));
    camTeth->setYPR(4.4f, 0.13f, 0.0f);

    vec3 oceanColor = vec3(0,70,95) / 256.0;
    vec3 oceanBrightColor = vec3(70,241,245) / 256.0;

    //create view
    View *view = new View(this->window);
    view->setSunlight(vec3(0.3, -1.0, 0), vec3(0.9, 0.9, 0.9), vec3(0.1, 0.1, 0.1));
    view->setFog(0, oceanColor, 0.05f, 5.0);
    view->setColoring(1, vec3(1,1,1), vec3(0.2,0.2,0.2), oceanBrightColor, oceanColor,
        0.03f, -5.0f, -30.0f);

    //view->addCamera(camera);
    view->addCamera(camTeth);
    view->setFirstPersonCam(camTeth);

    this->setView(view);
    this->setEntityRenderer(r);
    this->setSkyboxRenderer(rsky);
    this->setFlatRenderer(rflat);

    /* Bind AIs to subs HARDCODED FOR NOW*/
    if(this->subs.size() > 1)
    {
        SubmarineAI * ai1 = new SubmarineAI();
        Racer *loneAIracer = new Racer(ai1); //only one rn
        loneAIracer->bindToSub(subs[0]);
    }

    // Bind first person camera to 0-th sub by default
    this->getView()->getFirstPersonCam()->changeTether(subs[0]);

    this->initalizeMenus();

}

void World::initalizeMenus()
{
    this->menuSub = new Menu("../assets/textures/menu_sub.png");
    this->menuLevel = new Menu("../assets/textures/menu_level.png");
}

void World::initalizeSubsFromFile(const char* path)
{
    int id = 0;
    int subid = SUBID_START;
    char *raw = fileio::load_file(path);
    json raw_j = json::parse(raw);

    std::vector<json> subs = raw_j["submarines"];

    for (std::vector<json>::const_iterator it = subs.begin() ; it != subs.end(); ++it) {
        json curSub = *it;
        std::vector<float> pos = curSub["position"];
        vec3 realpos = convert::vec3FromSTDVec(pos);
        std::vector<float> orientation = curSub["orientation"];
        quat realOrientation = convert::quatFromSTDVec(orientation);
        std::vector<float> col = curSub["color"];
        vec3 realcol = convert::vec3FromSTDVec(col);
        string model_file = curSub["model"];
        char *real_mf = strdup(model_file.c_str());
        string n= curSub["name"];
        char *real_name = strdup(n.c_str());
        float mass = curSub["mass"];
        float tick_interval = curSub["tick-interval"];
        Submarine * next = new Submarine(subid++, realpos, realOrientation, real_name, TYPESUB, SPAWNED, tick_interval, realcol, real_mf);
        next->setVolume(new CylinderVolume(Volume::Pos(next),1.f,9.f,glm::rotate(glm::mat4(1),3.14159265f/2.f,glm::vec3(1,0,0))));
        next->meshes.push_back(next->getVolume()->collisionMesh());
        next->setMass(mass);
        next->setMovementParameters(curSub["maxAccel"], curSub["maxTurn"], curSub["maxRise"],
            curSub["maxDive"], curSub["drag"], curSub["angularDrag"]);

        this->addSub(id++, next);
    }
}

void World::initializeSubsDefault()
{
    int id = 0;
    Submarine * sub1 = new Submarine(6969,vec3(0,-26,38), glm::angleAxis(1.74f, vec3(0, -1, 0)), strdup("sub1"), TYPESUB, SPAWNED, 0.1f, vec3(1,1,1), "../assets/models/sub_3.obj");
    sub1->mass(2.0);
    sub1->dragCoef(0.2);

    this->addSub(id++, sub1);
}



/* Quickly set up the given level so that you can skip all the menu stuff.
Mostly useful for testing in-game things. */
void World::quickSetup(int level)
{
    this->loadLevel(level);
    this->state = RACE_RUNNING;
}
