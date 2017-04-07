
#include "camera.hxx"
#include <stdio.h>
#include <string.h>

/***** class Camera member functions *****/

using namespace glm;

Camera::Camera ()
    : _errorFactor(-1)
{ }

void Camera::init(vec3 pos, vec3 dir, vec3 up)
{
    this->_pos = pos;
    this->_dir = dir;
    this->_up = up;
}

// translate a point to the coordinate system that has the camera as the origin, but is
// oriented and scaled the same as the world coordinates.
vec3 Camera::translate (vec3 const &p) const
{
    return p - this->_pos;
}

// a transformation matrix 
mat4 Camera::viewTransform () const
{
    return lookAt (
    this->_pos,
    this->_dir,
    this->_up);
}

vec3 vec3dToVec3(vec3 d)
{
    return vec3((float)d[0],
                 (float)d[1],
                 (float)d[2]);
}


mat4 Camera::ModelViewMatrix () const
{
  return lookAt (
  this->position(),
  this->_dir,
  this->_up);
}

// the projection transform for the camera
mat4 Camera::projTransform () const
{
    //printf("%f, %f, %f, %f\n", this->_halfFOV, this->_aspect, this->_nearZ, this->_farZ);
    return perspective(this->_halfFOV, this->_aspect, this->_nearZ, this->_farZ);
}

// update the camera for the aspect ratio of the given viewport.  This operations will change
// the aspect ratio, but not the field of view.
void Camera::setViewport (int wid, int ht)
{
    this->_errorFactor = -1.0f;  // mark the error factor as invalid
    this->_aspect = float(wid) / float(ht);
    this->_wid = wid;
}

// set the horizontal field of view in degrees
void Camera::setFOV (float angle)
{
    this->_errorFactor = -1.0f;
    this->_halfFOV = radians(0.5 * angle);
}

// set the near and far planes
void Camera::setNearFar (double nearZ, double farZ)
{
    assert ((0.0 < nearZ) && (nearZ < farZ));
    this->_nearZ = nearZ;
    this->_farZ = farZ;
}

// move the camera to a new position while maintaining its heading
void Camera::move (vec3 const &pos)
{
    this->_pos = pos;
}

// move the camera to a new position and heading, while maintaining
// its up vector
void Camera::move (vec3 const &pos, vec3 const &at)
{
    this->_pos = pos;
    this->_dir = normalize(at - pos);
}

// move the camera to a new position, heading, and up vector
void Camera::move (vec3 const &pos, vec3 const &at, vec3 const &up)
{
    this->_pos = pos;
    this->_dir = normalize(at - pos);
    this->_up = normalize(up);
}

// change the direction of the camera
void Camera::look (vec3 const &dir)
{
    this->_dir = dir;
}

// change the direction of the camera
void Camera::look (vec3 const &dir, vec3 const &up)
{
    this->_dir = dir;
    this->_up = up;
}

void Camera::setUp(vec3 const &up)
{
    this->_up = normalize(up);
}

// compute the screen-space error for a geometric error of size err at distance dist.
float Camera::screenError (float dist, float err) const
{
    if (this->_errorFactor < 0.0f) {
    this->_errorFactor = float(this->_wid) / (2.0 * tanf(this->_halfFOV));
    }
    return this->_errorFactor * (err / dist);

}


//=====rotate camera controls======//

vec3 Camera::getLookVec(){
    return normalize(this->direction() - this->position());
}

//rotate camera around an arbitrary axis
void Camera::rotateCam(float theta, vec3 axis)
{
    //translate lookat point to be relative to a camera at the origin
    vec3 camlook = this->getLookVec();

    //get the rotation matrix and lookat vector
    //mat4 rot = mat4();//need a new rotation matrix function //rotate(theta, value_ptr(axis));
    mat4 rot = rotate(mat4(), theta, axis);

    vec4 atp = vec4(camlook, 1.0f);

    vec3 newdir = vec3(rot * atp);

    //set lookat to the new value relative to the camera position
    this->_dir = newdir + this->position();

    //update the up-vector
    this->_up = normalize(vec3(rot * vec4(this->up(), 0.0f)));

    //printf("axis %f %f %f\n", axis[0], axis[1], axis[2]);
    //printf("new dir %f %f %f\n", newdir[0], newdir[1], newdir[2]);
}

void Camera::rotateCamUpDown(float theta)
{
    this->rotateCam(theta, cross(this->up(), this->getLookVec()));
}

void Camera::rotateCamLeftRight(float theta)
{
    this->rotateCam(theta, this->up());
}

void Camera::rotateCamRoll(float theta)
{
    this->rotateCam(theta, this->getLookVec());
}

void Camera::rotateX(float theta)
{
    this->rotateCam(theta, vec3(1, 0, 0));
}

void Camera::rotateY(float theta)
{
    this->rotateCam(theta, vec3(0, 1, 0));
}

void Camera::rotateZ(float theta)
{
    this->rotateCam(theta, vec3(0, 0, 1));
}


//=====translate camera and look at point=====/

//translate cam along arbitrary axis, without rotating view at all
void Camera::translateCam(vec3 offset)
{
    this->_pos = this->_pos + offset;
    this->_dir = this->_dir + offset;
}

void Camera::moveZAxis(float dis)
{
    this->translateCam(vec3(0.0, 0.0, (double)dis));
}

void Camera::translateCamViewAxis(float dis)
{
    vec3 axis = this->getLookVec();
    this->translateCam(dis * axis);
}

void Camera::translateCamStrafeAxis(float dis)
{
    vec3 axis = cross(this->getLookVec(), this->up());
    this->translateCam(dis * axis);
}

void Camera::translateCamUpAxis(float dis)
{
    vec3 axis = this->up();
    this->translateCam(dis * axis);
}
