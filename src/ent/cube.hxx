#ifndef _CUBE_HXX_
#define _CUBE_HXX_

#include <ent/Entity.hxx>

using namespace glm;

/* Simple example mesh */

#define RED_COLOR  vec4(1.0f, 0.0f, 0.0f, 1.0f)   /*!< Red color */ 
#define GREEN_COLOR vec4(0.0f, 1.0f, 0.0f, 1.0f)    /*!< Green color */
#define YELLOW_COLOR  vec4(1.0f, 1.0f, 0.0f, 1.0f)    /*!< Yellow color */
#define BLUE_COLOR vec4(0.0f, 0.0f, 1.0f, 1.0f)   /*!< Blue color */
#define SKY_BLUE_COLOR vec4(0.0f, 1.0f, 1.0f, 1.0f)   /*!< Sky Blue color */
#define PINK_COLOR vec4(1.0f, 0.0f, 0.5f, 1.0f)   /*!< Pink */ 
#define WHITE_COLOR vec4(1, 1, 1, 1)

#define INDICES_ARRAY const uint32_t[4] = {0, 1, 2, 3};

typedef struct Wall { 
  vec4 color; 
  vec3 norm;
  vec3 corners[4]; 
  vec2 texCoords[4]; 
} Wall; 


class Cube : public Entity {

public:

    Cube(vec3 initial_position, quaternion initial_orientation, std::string name, 
    EntityType type, EntityStatus status, float tick_interval, vec3 color);
    ~Cube();

    void initalizeVisualData();

protected:

    vec3 color;

    void initalizeTextures(const char* texfile);
    void initalizeMeshes();

    /* The vertices for the triangle */ 
    /*! the five visible walls of the box */  
    Wall  wallsguys[6] = {
        { /* left */
            WHITE_COLOR,    // color
            vec3{  1.0f,  0.0f,  0.0f },  // norm
            {vec3{ -1.0f,  1.0f, -1.0f },  // corner[0]
            vec3{ -1.0f,  1.0f,  1.0f },
            vec3{ -1.0f, -1.0f,  1.0f },
            vec3{ -1.0f, -1.0f, -1.0f }},
            {vec2{  0.333f,  0.666f},  // texture coordinates 
            vec2{  0.666f,  0.666f},
            vec2{  0.666f,  0.333f},
            vec2{  0.334f,  0.333f}}

        },
        { /* right */
            WHITE_COLOR,
            vec3{ -1.0f,  0.0f,  0.0f },
            {vec3{  1.0f,  1.0f,  1.0f },
            vec3{  1.0f,  1.0f, -1.0f },
            vec3{  1.0f, -1.0f, -1.0f },
            vec3{  1.0f, -1.0f,  1.0f }}, 
            {vec2{  0.666f,  0.666f}, //texture coordinates 
            vec2{  1.0f,  0.666f},
            vec2{  1.0f,  0.333f},
            vec2{  0.666f,  0.333f}}

        },
        { /* top */
            WHITE_COLOR,
            vec3{  0.0f, -1.0f,  0.0f },
            {vec3{ -1.0f,  1.0f, -1.0f },
            vec3{  1.0f,  1.0f, -1.0f },
            vec3{  1.0f,  1.0f,  1.0f },
            vec3{ -1.0f,  1.0f,  1.0f }}, 
            {vec2{  0.333f,  0.333f}, 
            vec2{  0.666f,  0.333f},
            vec2{  0.666f,  0.0f},
              vec2{  0.333f,  0.0f}}
        },
        { /* bottom */
            WHITE_COLOR,
            vec3{  0.0f,  1.0f,  0.0f },
            {vec3{ -1.0f, -1.0f,  1.0f },
            vec3{  1.0f, -1.0f,  1.0f },
            vec3{  1.0f, -1.0f, -1.0f },
            vec3{ -1.0f, -1.0f, -1.0f }}, 
            {vec2{  0.0f,  0.666f}, //texture coordinates 
            vec2{  0.333f,  0.666f},
            vec2{  0.333f,  0.333f}, 
            vec2{  0.0f,  0.333f}}
        },
        { /* front */
            WHITE_COLOR, 
            vec3{  0.0f,  0.0f,  1.0f },
            {vec3{  1.0f,  1.0f, -1.0f },
            vec3{ -1.0f,  1.0f, -1.0f },
            vec3{ -1.0f, -1.0f, -1.0f },
            vec3{  1.0f, -1.0f, -1.0f }}, 
            {vec2{  0.0f,  0.333f}, // texture coordinates 
            vec2{  0.333f,  0.333f},
            vec2{  0.333f,  0.0f},
            vec2{  0.0f,  0.0f}}

        },
        { /* back */
            WHITE_COLOR,
            vec3{  0.0f,  0.0f, -1.0f },
            {vec3{ -1.0f,  1.0f,  1.0f },
            vec3{  1.0f,  1.0f,  1.0f },
            vec3{  1.0f, -1.0f,  1.0f },
            vec3{ -1.0f, -1.0f,  1.0f }}, 
            { vec2{  0.666f,  0.333f},
            vec2{  1.0f,  0.333f},
            vec2{  1.0f,  0.0f}, 
            vec2{  0.666f,  0.0f}}

        }
    };
};



#endif //_CUBE_HXX_