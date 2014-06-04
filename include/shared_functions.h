/*+===================================================================

   File:      shared_functions.h

   Summary:   definitions for methods shared by entire project

   Classes:   none

   Functions: none

   Origin:    none

 ----------------------------------------------------------------------
   Copyright (C) 2014, Stephen Wunschel
 ===================================================================+*/

#pragma once

// standard header files

// 3rd party header files
using namespace Eigen;
#include <Geometry>


// project header files
#include "common.h"
#include "SpaceObject.h"

// type definitions

// definitions
#define M_PI 3.14159265358979323846

// enumerations

// variables

// function prototypes
float toDegrees(float);
bearing3D toEuler(Quaternionf);
Quaternionf toQuat(bearing3D);			//takes a array of 3 floats. yaw, pitch, and roll in degrees
float toRads(float);
