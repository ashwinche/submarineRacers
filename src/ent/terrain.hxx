#ifndef _TERRAIN_HXX_
#define _TERRAIN_HXX_

#include <ent/Entity.hxx>
#include <graphics/mesh.hxx>

using namespace glm;

/* Simple example mesh */

class Terrain : public Entity {

public:

    Terrain(int ID,vec3 initial_position, quaternion initial_orientation, std::string name, 
    EntityType type, EntityStatus status, float tick_interval, vec3 color, const char* texfile,
    const char* hmpfile);
    ~Terrain();

    inline vec3 getScale() {return this->scale;}

    void initalizeVisualData();

protected:

	std::string hmpfile;
    vec3 color;
    vec3 scale;

    void initalizeTextures(const char* texfile);
    void initalizeMeshes();
};



#endif //_CUBE_HXX_