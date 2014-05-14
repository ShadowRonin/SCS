/*+===================================================================

   File:      common.h

   Summary:   definitions shared by entire project

   Classes:   none

   Functions: none

   Origin:    none

 ----------------------------------------------------------------------
   Copyright (C) 2014, Stephen Wunschel
 ===================================================================+*/

#pragma once

// standard header files

// 3rd party header files
#include <Core>
using namespace Eigen;

// project header files

// type definitions
typedef Matrix<float, 3, 1> cords3D;
typedef struct bearing3D {
	float yaw, pitch, roll;
	} bearing3D;
typedef Matrix<float, 3, 1> vector3D;

// definitions
#define MAX_CMD_BUFF 256				// console command input buffer

// enumerations
enum COORDS								// offset into vector for each coordinate
{
	x_cord=0,
	y_cord,
	z_cord
};
