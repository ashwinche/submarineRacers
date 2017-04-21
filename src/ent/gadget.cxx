#include "gadget.hxx"

Gadget::Gadget(vec3 initial_position, quaternion initial_orientation, int id, char*name, 
    EntityType type, EntityStatus status, float tick_interval, vec3 color, char *modelfilein)
: Entity(initial_position, initial_orientation, id, name, type, status, tick_interval)
{
    this->nMeshes = 1;
    this->meshes = NULL;

    this->color = color;

    this->modelfile = modelfilein;
    this->initalizeVisualData();
}

Gadget::~Gadget()
{ }

void Gadget::initalizeVisualData()
{
    this->initalizeTextures("../assets/textures/cubetex.png");
    this->initalizeMeshes();
}

//call this before initalizing meshes
void Gadget::initalizeTextures(const char* texfile)
{
    //load texture
    image2d * image = new image2d(texfile, true);
    texture2d * cubetex = new texture2d(GL_TEXTURE_2D, image);
    this->tex = cubetex;
    this->img = image;
}

void Gadget::initalizeMeshes(){

    nMeshes = 2;

    meshes = new Mesh*[2];

    meshes[0] = new Mesh(GL_TRIANGLES);
    meshes[0]->loadOBJ(modelfile);
    meshes[0]->data.color = vec4(this->color,0.5);
    meshes[0]->data.tex = this->tex;

    volume = new SphereVolume(vec3(0,0,0),1.f);

    meshes[1] = (volume->collisionMesh());
    meshes[1]->data.tex = this->tex;

}