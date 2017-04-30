#include <json/json.hpp>
#include "Level.hxx"
#include <util/file.hxx>
#include <graphics/mesh.hxx>
#include <physics/Volume.hxx>
#include <ent/terrain.hxx>

using json = nlohmann::json;

Level::Level() {}

Level::Level(const char *path) {
    this->path = path;
}

Level::~Level() { }

quaternion quatFromSTDVec(std::vector<float> v) {
    return quaternion(v.at(0), v.at(1), v.at(2), v.at(3));
}

vec3 vec3FromSTDVec(std::vector<float> v) {
    return vec3(v.at(0), v.at(1), v.at(2));
}

Entity *entityFromJSON(int id, json j) {
    /* copy over entity data */
    std::string name = j["name"];
    std::vector<float> position = j["position"];
    vec3 real_position = vec3FromSTDVec(position);
    std::vector<float> orientation = j["orientation"];
    quaternion realOrientation = quatFromSTDVec(orientation);
    float tick_interval = j["tick_interval"];
    bool movable = j["movable"];
    bool drawable = j["drawable"];
    vec3 color = vec3(0,0,0);
    char *model_file = NULL;

    if (drawable) {
        std::vector<float> fakeColor = j["color"];
        color = vec3FromSTDVec(fakeColor);
        std::string model_file_str = j["model"];
        model_file = strdup(model_file_str.c_str());
    }

    bool collidable = j["collidable"];
    std::string volume_type = "";
    json volume_data = {};

    /* Create entity */
    // this line probably should be edited in the future to reflect "not all entities are gadgets"
    Entity *retVal = new Gadget(id, real_position, realOrientation, name.c_str(), TYPE1, SPAWNED, tick_interval, color, model_file);
    if (movable) {
        float mass = j["mass"];
        retVal->setMass(mass);
        // float dragCoef = j["dragCoef"];
        // retVal->dragCoef = dragCoef;
        std::vector<float> velocity = j["velocity"];
        retVal->vel(vec3FromSTDVec(velocity));
    }
    if (collidable) {
        volume_type = j["volume-type"];
        volume_data = j["volume-data"];
        // initialize a sphere
        if (volume_type.compare("sphere") == 0) {
            std::vector<float> spherePos = volume_data["position"];
            vec3 sphereCenter = vec3FromSTDVec(spherePos);
            float sphereRad = volume_data["radius"];
            retVal->setVolume(new SphereVolume(sphereCenter, sphereRad));
        }
    }

    /* Free any memory used in object construction */
    /* TODO: We almost def have to free more stuff here */
    free(model_file);

    return retVal;
}

/* Populate all fields of the class by loading them from a file. */
void Level::buildLevelFromFile() {
    if(!this->path){
        buildDemoLevel();
        return;
    }
    int id =0;
    char *raw = fileio::load_file(this->path);
    json raw_j = json::parse(raw);
    std::vector<json> entities = raw_j["entities"];

    std::vector<json>::iterator it = entities.begin();
    while (it != entities.end()) {
        Entity *ent = entityFromJSON(++id,*it);
        log(LOGMEDIUM, "adding an item called %s\n", ent->getName().c_str());
        this->addEntity(ent);
        ++it;
    }

     //create skybox
    Gadget *skybox = new Gadget(++id,vec3(0,0,0), quaternion(), strdup("sky"), TYPE1, SPAWNED, 0.1f, vec3(1,1,1), "../assets/models/sphere.obj");
    this->setSkybox(skybox);

}

/* DEMO LEVEL */
void Level::buildDemoLevel() 
{ 
	//create test objects
    vec3 cubePos[] = {vec3(5,6,5), vec3(5, 0, 5), vec3(5, -5, 5), vec3(5, -10, 5), vec3(5, -20, 5),
        vec3(5, -40, 5)}; 
    vec3 cubeColor[] = {vec3(1,1,1), vec3(1,1,1), vec3(1,1,0), vec3(1,0,1), vec3(0,1,1), vec3(0,0,1)};
    int ncubes = 4, i;
    Entity * cubes[ncubes];
    cubes[0] = new Gadget(0,cubePos[0], quaternion(), "cube0", TYPE1, SPAWNED, 0.1f, cubeColor[0], "../assets/models/monkey.obj");
    cubes[0]->setVolume(new SphereVolume(vec3(0,0,0),1.f));
    // cubes[0]->meshes.push_back(cubes[0]->volume->collisionMesh());
    cubes[0]->setVelocity(vec3(0,-0.8f,0));
    cubes[0]->setMass(1.f);
    for(i=1; i<ncubes; i++){
        cubes[i] = new Gadget(i,cubePos[i], quaternion(), "cube"+std::to_string(i), TYPE1, SPAWNED, 0.1f, cubeColor[i], "../assets/models/cube.obj");
        cubes[i]->setVolume(new SphereVolume(vec3(0,0,0),1.414));
        // cubes[i]->meshes.push_back(cubes[i]->volume->collisionMesh());
        cubes[i]->setVelocity(vec3());
        cubes[i]->setMass(1.f);;
    }

    for(i=0; i<ncubes; i++)
    	this->addEntity(cubes[i]);

    Entity *cave = new Terrain(ncubes, vec3(), quaternion(), "canyon", TYPE1, SPAWNED, 1.f, vec3(1.f,0.8f,0.5f));
    addEntity(cave);

    //create skybox
    Gadget *skybox = new Gadget(ncubes+1,vec3(0,0,0), quaternion(), "sky", TYPE1, SPAWNED, 0.1f, vec3(1,1,1), "../assets/models/sphere.obj");
    this->setSkybox(skybox);

    logln(LOGHIGH,"built level.");

}

/* Update the data for an entity based on a CODE_OBJECT_CHANGE message */
void Level::upEntData(posUpBuf *info)
{
	// Get the entity for this ID
	Entity *ent = this->getEntityByID(info->id);
	if(ent == NULL){
		log(LOGERROR, "%s %d\n", "Null entity in upEntData", info->id);
		return;
	}

	ent->overwrite(info);
}

/* Spawn or despawn an object. Returns the old EntityStatus */
EntityStatus Level::changeObjectSpawn(int id, EntityStatus n) { /*TODO*/return SPAWNED; }


/* Get the entity with the given ID */
Entity * Level::getEntityByID(int id)
{
	if(!this->entityExists(id))
		return NULL;
	return this->entities[id];
}

/* Returns 1 if an entity with id exists in our entity list,
0 otherwise */
int Level::entityExists(int id)
{
	return this->entities.find(id) != entities.end();
}

/* Add this entity to the entity list. This function checks that an entity
with the current ID does not already exist. Returns 1 if the entity was
added, 0 if it couldn't due to the ID already being taken. Since we
identify entities by ID, we can't let one entity "overwrite" another. */
int Level::addEntity(Entity *entity)
{	
	if(this->entityExists(entity->getID()))
		return 0;
	this->entities[entity->getID()] = entity;
	return 1;
}

//Returns 0 if successful, -1 if the element can't be found
int Level::removeEntity(Entity *entity)
{   
    //TODO
    return -1;
}



void Level::addAI(AI *ai, float tickrate)
{   
    AI_entry entry;
    entry.ai = ai;
    entry.tickrate = tickrate;
    entry.time_left = tickrate;
    ais.push_back(entry);
}
//Returns 0 if successful, -1 if the element can't be found
int Level::removeAI(AI *ai)
{   
    for (std::vector<AI_entry>::const_iterator it = ais.begin() ; it != ais.end(); ++it) {
        if(it->ai == ai) {
            ais.erase(it);
            return 0;
        }
    }
    
    return -1;
}



/* Using the given server, broadcast position updates to all clients. */
void Level::sendPosUps(Server *server){
	for (auto entry : this->entities){
        auto entity = entry.second;
        bool should = entity->isShouldSendUpdate();
        if(should){
            fprintf(stderr,"%s: %s\n",entry.second->getName().c_str(),should?"1":"-");
            message* m = entity->prepareMessageSegment();
            server->broadcast(m);
            deleteMessage(m);
        }
    }
}

/* Render all renderable entities, the skybox ... */
void Level::renderAll(View *view, Renderer *r, Renderer *rsky)
{
	this->renderSkybox(view, rsky);
	this->renderAllEnts(view, r);
}

/* Using the given view and renderer, draw all entities in the level. */
void Level::renderAllEnts(View *view, Renderer *r)
{
	r->enable();
	for (auto entry : this->entities) {
        auto entity = entry.second;
        //log(LOGMEDIUM, "rendering entity %d with %p\n", entity->getID(), r);
        if(entity->isDrawable())
        	r->render(view, entity);
    }
}

/* Skybox */
void Level::setSkybox(Gadget *skybox)
{
	this->skybox = skybox;
}

void Level::renderSkybox(View *view, Renderer *r)
{
	r->enable();
	r->render(view, this->skybox);
}



void Level::updateLevel(float dt) {
    updateAIs(dt);
    physicsTick(dt);
}
void Level::interpolateLevel(float dt) {
    physicsTick(dt);
}

void Level::updateAIs(float dt) {
    for(AI_entry en : ais) {
        en.time_left -= dt;
        if(en.time_left <= 0) {
            en.time_left = en.tickrate; //REMARK could be better with time_left += tickrate depending on behavior
            en.ai->updateAI();
        }
    }
}

/**
 * ONLY physics (and unimportant graphics update) behaviors
 * go in here. This function is called both (1) by the server
 * as well as (2) by the client when interpolating between
 * server messages.
 *
 */
void Level::physicsTick(float dt) {
    for(std::pair<int, Entity *> en : entities) {
        // if(en.second->velocity.y != en.second->velocity.y)en.second->velocity = vec3();
        // en.second->position += dt*en.second->velocity;
        fprintf(stderr,"%s, %f, %f\n",en.second->getName().c_str(),dt,en.second->vel().y);
        en.second->onTick(dt);
        en.second->updatePhysicsVolume();
    }
    handleCollisions(dt);
}

void Level::handleCollisions(float dt) {
    map<int, bool> processed;
    for(std::pair<int, Entity *> e : entities)
        processed[e.first]=false;

    for(std::pair<int, Entity *> en1 : entities) {
        // fprintf(stderr,"col %d %d %s\n",en1.first, en1.second->getID(),en1.second->getName().c_str());
        for(std::pair<int, Entity *> en2 : entities) {
            if(processed[en2.first])continue;
            if(en1.first == en2.first)continue;
            // fprintf(stderr,"check %d %d\n",en1.first,en2.first);
            Entity &e1 = *(en1.second);
            Entity &e2 = *(en2.second);
            vec3 e1p = e1.pos();
            vec3 pushe1 = e1.getVolume()->push(e2.getVolume());
            // fprintf(stderr,"(%.3f,%.3f,%.3f)\n",e1p.x,e1p.y,e1p.z);
            // fprintf(stderr,"(%.3f,%.3f,%.3f)\n",pushe1.x,pushe1.y,pushe1.z);
            if(pushe1 != vec3()){
                // there is a collision
                e1.pos(e1.pos()-pushe1);
                vec3 v1 = (e1.vel()*(e1.mass()-e2.mass()) + e2.vel()*2.f*e2.mass())/(e1.mass()+e2.mass());
                vec3 v2 = (e2.vel()*(e2.mass()-e1.mass()) + e1.vel()*2.f*e1.mass())/(e1.mass()+e2.mass());
                e1.vel(v1);
                e2.vel(v2);
            }
            vec3 np = e1.pos();
            // fprintf(stderr,"(%.3f,%.3f,%.3f)\n\n",np.x,np.y,np.z);
        }
        processed[en1.first] = true;
    }
}

