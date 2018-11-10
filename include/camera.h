#ifndef CAMERA_H
#define CAMERA_H


// ===============================
// AUTHOR       : Angel Ortiz (angelo12 AT vt DOT edu)
// CREATE DATE  : 2018-09-11
// PURPOSE      : TODO
// ===============================
// SPECIAL NOTES: TODO update comments
// ===============================

//Headers
#include "geometry.h"
#include "displayManager.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <set>

struct Camera{
    Camera();

    //Visibility and geometry member variables
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
    Frustrum cameraFrustrum = Frustrum(DisplayManager::SCREEN_ASPECT_RATIO);

    //View frustrum culling
    bool checkVisibility(AABox *bounds);

    //Updates the camera matrices with the user input obtained in the input class
    void update(unsigned int deltaT);
    void resetCamera(); 

    //Test test test test
    std::set< char > set;

    //Position and direction of camera, used to build view matrix
    glm::vec3 position{1,1,1};
    glm::vec3 target{0,0,0};
    glm::vec3 up{0,1,0};
    glm::vec3 front;
    glm::vec3 side;

    //Optical properties
    float exposure = 1.0f;
    int blurAmount = 0;

    //Values related to orbiting mode
    float radius  = 1;
    float period  = 30; //in seconds
    bool orbiting = false;

    //Momentary fixed camera speed (FPS dependent)
    float camSpeed = 0.005f;
    float pitch    = 0;
    float yaw      = 0;
};

#endif