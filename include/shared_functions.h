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

// project header files

// type definitions

// definitions
#define M_PI 3.14159265358979323846

// enumerations

// variables

// function prototypes
public float toDegrees(float);
public float[3] toEuler(Quaternion);
public Quaternion toQuat(float[3]);		//takes a array of 3 floats. yaw, pitch, and roll in degrees
public float toRads(float);
