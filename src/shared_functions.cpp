/*+===================================================================

   File:      shared_functions.cpp

   Summary:   methods shared by entire project

   Classes:   none

   Functions: none

   Origin:    none

 ----------------------------------------------------------------------
   Copyright (C) 2014, Stephen Wunschel
 ===================================================================+*/

// standard header files
#include <math.h>

// 3rd party header files
#include <Eigen/Geometry>
using namespace Eigen;

// project header files
#include "common.h"

/*************************************************************************************************************************************
 * toDegrees -
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   05/09/2014   BSW   initial coding
 *************************************************************************************************************************************/
public float toDegrees(float rad)
{
	return rad * (180.0 / M_PI);
}

/*************************************************************************************************************************************
 * toEuler
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 1xx   xx/xx/2014   BSW   initial coding
 *************************************************************************************************************************************/
public float[3] toEuler(Quaternion rotation)
{
	float[3] result = {0.0,0.0,0.0} // yaw, pitch, roll; in degrees
	float w = rotation.w();
	float x = rotation.x();
	float y = rotation.y();
	float z = rotation.z();

	result[1] = asinf(2 * x *y + 2 * z * w);
	if(x * y + z * w == 0.5) {
		result[0] = toDegrees(2.0 * atan2f(x, w));
		result[3] = 0.0;
	}
	else if(x * y + z * w == -0.5) {
		result[0] = toDegrees(-2.0 * atan2f(x, y);)
		result[3] = 0.0;
	}
	else {
		result[0] = toDegrees(
				atan2f(((2.0 * y * w) - (2 * x * z)), (1.0 - (2.0 * powf(y, 2.0)) - (2.0 * powf(z, 2.0)))));
		result[3] = toDegrees(
				atan2f(((2.0 * x * w) - (2.0 * y * z)) , (1.0 - (2.0 * powf(x, 2.0)) - (2.0 * powf(z, 2.0)))));
	}
	return result;
}

/*************************************************************************************************************************************
 * toQuat - takes a array of 3 floats. yaw, pitch, and roll in degrees
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   05/09/2014   BSW   initial coding
 *************************************************************************************************************************************/
public Quaternion toQuat(float[3] rotation)
{
	rotation[0] = toRads(rotation[0]);
	rotation[1] = toRads(rotation[1]);
	rotation[2] = toRads(rotation[2]);
	float w = cosf(rotation[0] / 2) * cosf(rotation[1] / 2) * cosf(rotation[2] / 2) - sinf(rotation[0] / 2) * sinf(rotation[1] / 2) * sinf(rotation[2] / 2);
	float x = sinf(rotation[0] / 2) * sinf(rotation[1] / 2) * cosf(rotation[2] / 2) - cosf(rotation[0] / 2) * cosf(rotation[1] / 2) * sinf(rotation[2] / 2);
	float y = sinf(rotation[0] / 2) * cosf(rotation[1] / 2) * cosf(rotation[2] / 2) - cosf(rotation[0] / 2) * sinf(rotation[1] / 2) * sinf(rotation[2] / 2);
	float z = cosf(rotation[0] / 2) * sinf(rotation[1] / 2) * cosf(rotation[2] / 2) - sinf(rotation[0] / 2) * cosf(rotation[1] / 2) * sinf(rotation[2] / 2);
	return new Quaternion(w, x, y, z);
}

/*************************************************************************************************************************************
 * toRads -
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   05/09/2014   BSW   initial coding
 *************************************************************************************************************************************/
public float toRads(float degree)
{
	return degree * (M_PI / 180.0);
}





