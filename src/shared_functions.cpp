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

// project header files
#include "shared_functions.h"

/*************************************************************************************************************************************
 * toDegrees -
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   05/09/2014   BSW   initial coding
 *************************************************************************************************************************************/
float toDegrees(float rad)
{
	return rad * (180.0 / M_PI);
}

/*************************************************************************************************************************************
 * toEuler
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   05/09/2014   BSW   initial coding
 *************************************************************************************************************************************/
bearing3D toEuler(Quaternionf rotation)
{
	bearing3D result = {0.0,0.0,0.0};	// yaw, pitch, roll; in degrees
	float w = rotation.w();
	float x = rotation.x();
	float y = rotation.y();
	float z = rotation.z();

	result.pitch = asinf(2 * x *y + 2 * z * w);
	if(x * y + z * w == 0.5) {
		result.yaw = toDegrees(2.0 * atan2f(x, w));
		result.roll = 0.0;
	}
	else if(x * y + z * w == -0.5) {
		result.yaw = toDegrees(-2.0 * atan2f(x, y));
		result.roll = 0.0;
	}
	else {
		result.yaw = toDegrees(
				atan2f(((2.0 * y * w) - (2 * x * z)), (1.0 - (2.0 * powf(y, 2.0)) - (2.0 * powf(z, 2.0)))));
		result.roll = toDegrees(
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
Quaternionf toQuat(bearing3D rotation)
{
	Quaternionf results;

	rotation.yaw = toRads(rotation.yaw);
	rotation.pitch = toRads(rotation.pitch);
	rotation.roll = toRads(rotation.roll);
	results.w() = cosf(rotation.yaw / 2) * cosf(rotation.pitch / 2) * cosf(rotation.roll / 2) - sinf(rotation.yaw / 2) * sinf(rotation.pitch / 2) * sinf(rotation.roll / 2);
	results.x() = sinf(rotation.yaw / 2) * sinf(rotation.pitch / 2) * cosf(rotation.roll / 2) - cosf(rotation.yaw / 2) * cosf(rotation.pitch / 2) * sinf(rotation.roll / 2);
	results.y() = sinf(rotation.yaw / 2) * cosf(rotation.pitch / 2) * cosf(rotation.roll / 2) - cosf(rotation.yaw / 2) * sinf(rotation.pitch / 2) * sinf(rotation.roll / 2);
	results.z() = cosf(rotation.yaw / 2) * sinf(rotation.pitch / 2) * cosf(rotation.roll / 2) - sinf(rotation.yaw / 2) * cosf(rotation.pitch / 2) * sinf(rotation.roll / 2);
	return results;
}

/*************************************************************************************************************************************
 * toRads -
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   05/09/2014   BSW   initial coding
 *************************************************************************************************************************************/
float toRads(float degree)
{
	return degree * (M_PI / 180.0);
}


/*************************************************************************************************************************************
 * findAngle
 *

 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================

 * 100   05/09/2014   BSW   initial coding

 *************************************************************************************************************************************/
//TODO
//float[] findAngle(SpaceObject object, Matrix<float> targetPos)
//{//postion in GFoR
//	float[3] targetPosition = targetPos.array();
//	Matrix<float> vector = new Matrix<float>(object.toLocal(targetPostion[0], object.toLocal(targetPostion[1], object.toLocal(targetPostion[2]);
//	Quaternion angle = new Quaternion();
//	angle.setFromTwoVectors(new Matrix<float>(0,0,0), vector);
//	return toEuler(angle);
//}



