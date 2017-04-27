
#include <glm/ext.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include <ctime>
#include <ratio>
#include <chrono>

#include <util/log.hxx>
#include <error/error.hxx>
#include <util/file.hxx>
#include <graphics/shader.hxx>
#include <graphics/camera.hxx>
#include <graphics/renderer.hxx>
#include <ent/Entity.hxx>
#include <ent/cube.hxx>
#include <ent/gadget.hxx>
#include <ent/terrain.hxx>
#include <world/world.hxx>
#include <userinput/callbacks.hxx>
#include <graphics/texture.hxx>
#include <network/Server.hxx>
#include <network/Client.hxx>
#include <network/MessageProtocols.hxx>
#include <cstring>

#define PORT 8008

//defined in util/log.hxx
int loglevel_GLOBAL;

int keyboard[350];
int mouse[8];
double mousepos[2];

static void error_callback(int error, const char* description){
    fprintf(stderr, "Error: %s\n", description);
    Error::error(std::string(description),0);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    keyboard[key] = action;
}
static void mouse_callback(GLFWwindow* window, int button, int action, int mods){
    mouse[button] = action;
}
static void cursorpos_callback(GLFWwindow* window, double xpos, double ypos){
    // xpos and ypos are in pixels (not sure why they're doubles).
    mousepos[0] = xpos;
    mousepos[1] = ypos;
}


// there is only one world per instance of our program.
World* world;

GLFWwindow *initializeGLFW(){
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        Error::error("glfwInit failed",1);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* window = glfwCreateWindow(1280, 960, "Submarines!", NULL, NULL);
    if (!window){
        glfwTerminate();
        Error::error("glfwCreateWindow failed",1);
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_callback);
    glfwSetCursorPosCallback(window, cursorpos_callback);
    // glfwSetKeyCallback (window, KeyCallback);
    glfwMakeContextCurrent (window);

    // initialize GLEW
    glewExperimental = GL_TRUE;
    GLenum glerr = glewInit();
    glGetError();    
    if (glerr != GLEW_OK){
        Error::error("GLEW init failed"+glerr, 1);
    }

    glfwSwapInterval(1);

    return window;
}
void init(){
    world = new World();
    world->window = initializeGLFW();

    //associate the window with our world struct so window callbacks
    //can easily find the world state using glfwGetWindowUserPointer(window)
    glfwSetWindowUserPointer(world->window, world);

    for(int i=0;i<350;++i)keyboard[i]=0;
}


void update(double elapsed){
    using namespace std;
    // std::cout << elapsed << std::endl;

    View *view = world->view;    
    Camera *cam = view->activeCamera(); 

    double rSpeed = 2.0 * elapsed;
    double tSpeed = 10.0 * elapsed;

    // if(keyboard[GLFW_KEY_UP])          cam->rotateCamUpDown(-rSpeed);
    // if(keyboard[GLFW_KEY_DOWN])        cam->rotateCamUpDown(rSpeed);
    // if(keyboard[GLFW_KEY_LEFT])        cam->rotateCamLeftRight(rSpeed);
    // if(keyboard[GLFW_KEY_RIGHT])       cam->rotateCamLeftRight(-rSpeed);


    if(keyboard[GLFW_KEY_UP])          cam->addYPR(glm::vec3(0, rSpeed,0));
    if(keyboard[GLFW_KEY_DOWN])        cam->addYPR(glm::vec3(0, -rSpeed,0));
    if(keyboard[GLFW_KEY_LEFT])        cam->addYPR(glm::vec3(rSpeed, 0,0));
    if(keyboard[GLFW_KEY_RIGHT])       cam->addYPR(glm::vec3(-rSpeed, 0,0));

    // if(keyboard[GLFW_KEY_Q])          cam->rotateCamRoll(rSpeed);
    // if(keyboard[GLFW_KEY_E])          cam->rotateCamRoll(-rSpeed);
    
    // cout << keyboard[GLFW_KEY_UP] <<" , " << keyboard[GLFW_KEY_DOWN] << endl;

    if(keyboard[GLFW_KEY_W])           cam->translateCamViewAxis(tSpeed);
    if(keyboard[GLFW_KEY_S])           cam->translateCamViewAxis(-tSpeed);
    if(keyboard[GLFW_KEY_A])           cam->translateCamStrafeAxis(-tSpeed);
    if(keyboard[GLFW_KEY_D])           cam->translateCamStrafeAxis(tSpeed);
    if(keyboard[GLFW_KEY_R])           cam->translateCamUpAxis(tSpeed);
    if(keyboard[GLFW_KEY_F])           cam->translateCamUpAxis(-tSpeed);

    if(keyboard[GLFW_KEY_ESCAPE])      world->quit();
    if(keyboard[GLFW_KEY_Q])           world->quit();

    int scw, sch;
    glfwGetWindowSize (world->window, &scw, &sch);

    int cenx=scw/2;
    int ceny=sch/2;

    double dmx = mousepos[0] - cenx;
    double dmy = mousepos[1] - ceny;

    if(abs(dmx) > 1.f){
        // cam->addYPR(glm::vec3(-dmx*rSpeed*0.05f, 01,0));
    }
    if(abs(dmy) > 1.f){
        // cam->addYPR(glm::vec3(0, -dmy*rSpeed*0.05f,0));
    }

    // glfwSetCursorPos(world->window,cenx,ceny);

}

int main(int argc, char*argv[]){

    // Set logging level
    loglevel_GLOBAL = LOGMEDIUM;

    world = new World();

    init();

    //set up server or client: eventually we will make command line flags more advanced
    //First arg is "s" for server or "c" for client
    //Second arg is server hostname is we are a client
    int isServer = !((argc>=2) && (argv[1][0] == 'c'));
    Server *server;
    Client *client;
    if(isServer){
        server = new Server((short)PORT, NULL);
        fprintf(stderr,"Port: %d\n", server->getPort());
        server->initListeningSocket();
    } else {
        client = new Client(PORT, argv[2]);
        fprintf(stderr,"Hostname: %s, Port: %d\n", client->getHost(), client->getPort());
        client->connectServer();
    }

    // set up shaders.
    Shader *shader = new Shader();
    shader->addShader(GL_VERTEX_SHADER,fileio::load_file("../assets/shaders/lightshader.vert"));
    shader->addShader(GL_FRAGMENT_SHADER,fileio::load_file("../assets/shaders/lightshader.frag"));
    shader->build();

    Shader *skyboxShader = new Shader();
    skyboxShader->addShader(GL_VERTEX_SHADER,fileio::load_file("../assets/shaders/skyboxshader.vert"));
    skyboxShader->addShader(GL_FRAGMENT_SHADER,fileio::load_file("../assets/shaders/skyboxshader.frag"));
    skyboxShader->build();

    //create renderer for the given shader
    Renderer *r = new UnderwaterRenderer(shader);  
    Renderer *rsky = new SkyboxRenderer(skyboxShader);

    //initalize camera
    Camera *camera = new Camera();
    
    //position, look-at point, up-vector
    camera->init(vec3(-20,0,-20),vec3(3.141592f/4,3.141592f*-0.1f,0),vec3(0,1,0)); //location, looking-at, up
    camera->setFOV(90.0);
    camera->setNearFar(0.1, 1000.0);

    vec3 oceanColor = vec3(0,70,95) / 256.0;
    vec3 oceanBrightColor = vec3(70,241,245) / 256.0;

    //create view
    View *view = new View(world->window);
    world->view = view;
    view->addCamera(camera);
    view->setFOV(90);
    view->setNear(0.1);
    view->setFar(1000.0);
    view->setSunlight(vec3(-0.3, 1.0, 0), vec3(0.9, 0.9, 0.9), vec3(0.1, 0.1, 0.1));
    view->setFog(0, oceanColor, 0.05f, 5.0);
    view->setColoring(1, vec3(1,1,1), vec3(0.2,0.2,0.2), oceanBrightColor, oceanColor,
        0.03f, -5.0f, -30.0f);

    //create test objects
    vec3 cubePos[] = {vec3(1,5,10), vec3(5, 0, 5), vec3(5, -5, 5), vec3(5, -10, 5), vec3(5, -13, 5),
        vec3(5, -40, 5)}; 
    vec3 cubeColor[] = {vec3(1,1,1), vec3(1,1,1), vec3(1,1,0), vec3(1,0,1), vec3(0,1,1), vec3(0,0,1)};
    int ncubes = 6, i;

    Entity * cubes[ncubes];
    cubes[0] = new Gadget(cubePos[0], quaternion(), 0, strdup("kyubey"), TYPE1, SPAWNED, 0.1f, cubeColor[0], "../assets/models/monkey.obj");
    cubes[0]->volume = new Space::SphereVolume(vec3(0,0,0),1.f);
    cubes[0]->meshes.push_back(cubes[0]->volume->collisionMesh());
    cubes[1] = new Cube(cubePos[1], quaternion(), 0, strdup("kyubey"), TYPE1, SPAWNED, 0.1f, cubeColor[1]);
    cubes[2] = new Gadget(cubePos[2], quaternion(), 0, strdup("kyubey"), TYPE1, SPAWNED, 0.1f, cubeColor[2], "../assets/models/bigmonkey.obj");
    cubes[2]->volume = new Space::SphereVolume(vec3(0,0,0),2.f);
    cubes[2]->meshes.push_back(cubes[2]->volume->collisionMesh());
    cubes[3] = new Gadget(cubePos[3], quaternion(), 0, strdup("kyubey"), TYPE1, SPAWNED, 0.1f, cubeColor[3], "../assets/models/crate.obj");
    cubes[3]->volume = new Space::SphereVolume(vec3(0,0,0),1.414);
    cubes[4] = new Terrain(cubePos[4], quaternion(), 0, strdup("kyubey"), TYPE1, SPAWNED, 0.1f, cubeColor[4]);
    cubes[4]->volume = new Space::SphereVolume(vec3(0,0,0),1.414);
    for(i=5; i<ncubes; i++){
        cubes[i] = new Gadget(cubePos[i], quaternion(), 0, strdup("kyubey"), TYPE1, SPAWNED, 0.1f, cubeColor[i], "../assets/models/crate.obj");
        cubes[i]->volume = new Space::SphereVolume(vec3(0,0,0),1.414);
        // cubes[i]->meshes.push_back(cubes[i]->volume->collisionMesh());
    }

    world->physics = new PhysicsEngine();
    world->physics->entities.push_back(cubes[0]);
    world->physics->entities.push_back(cubes[2]);

    //create skybox
    Gadget *skybox = new Gadget(vec3(0,0,0), quaternion(), 0, strdup("sky"), TYPE1, SPAWNED, 0.1f, vec3(1,1,1), "../assets/models/sphere.obj");

    int width, height;

    // for timing
    using namespace std::chrono;
    high_resolution_clock::time_point time_prev = high_resolution_clock::now();
    high_resolution_clock::time_point time_begin = time_prev;
    high_resolution_clock::time_point time_curr;
    duration<double, std::milli> time_span;
    duration<double, std::milli> time_total;
    double elapsed;

    if(!isServer) {
        char *str = "binch";
        client->messageServer(strlen(str), (uint8_t*)str);
    }

    world->moveable = cubes[0];

    while (!glfwWindowShouldClose(world->window)){

        // timing across update operations.
        time_curr = high_resolution_clock::now();
        time_span = time_curr - time_prev;
        time_total = time_curr - time_begin;
        elapsed   = time_span.count() / 1000.0;
        update(elapsed);
        world->physics->update(elapsed);

        time_prev = time_curr;

        //network testing
        if(isServer){
            char *str = "hi im a server lol";
            server->readOneMessage();
            //quick hack-in of a cube movement animation
            vec3 pos = cubes[0]->getPosition();
            cubes[0]->setPosition(pos - vec3(0,0.03,0));
            posUpMsg msg; msg.pos = cubes[0]->getPosition();
            server->broadcast((short)24, sizeof(msg), (uint8_t*)&msg);
        } else {
            client->readOneMessage();
        }

        //quick hack-in of a cube movement animation
        vec3 pos = cubes[0]->getPosition();
        cubes[0]->setPosition(vec3(pos.x,-10.f + 10.f*sin(time_total.count()*0.0005),pos.z));

        //window setup
        glfwGetFramebufferSize(world->window, &width, &height);
        glViewport(0, 0, width, height); //allows us to adjust window size
        //glClearColor(oceanColor[0], oceanColor[1], oceanColor[2], 1.0);
        glClearColor(1.0, 0.5, 0.5, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        rsky->enable();
        rsky->render(view, skybox);

        r->enable ();

        for(i=0; i<ncubes; i++){
            r->render(view, cubes[i]);
            cubes[i]->orientation = glm::rotate(cubes[i]->orientation,3.14f*(i+1)/1024.f,vec3(0,1.f,0));
        }

        glfwSwapBuffers(world->window);
        glfwPollEvents();
    }



    glfwDestroyWindow(world->window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}