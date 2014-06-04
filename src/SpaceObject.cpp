/*+===================================================================

   Class:    SpaceObject

   Summary:  none

   Methods:  none

 ----------------------------------------------------------------------
   Copyright (C) 2014, Stephen Wunschel
 ===================================================================+*/

// standard header files

// project header files
#include "SpaceObject.h"

//3rd party header files
using namespace Eigen;


/*************************************************************************************************************************************
 * constructor
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 1xx   xx/xx/2014   SDW   initial coding
 *************************************************************************************************************************************/
SpaceObject::SpaceObject()
{
	//ctor
}

/*************************************************************************************************************************************
 * destructor
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 1xx   xx/xx/2014   SDW   initial coding
 *************************************************************************************************************************************/
SpaceObject::~SpaceObject()
{
	//dtor
}

/*************************************************************************************************************************************
 * getPosition	- return objectPosition in global FoR
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   05/09/2014   SDW   initial coding
 *************************************************************************************************************************************/
cords3D SpaceObject::getPosition()
{
	return objectPosition;
}

/*************************************************************************************************************************************
 * setPosition	- set objectPosition to provided coordinates
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   05/09/2014   SDW   initial coding
 *************************************************************************************************************************************/
void SpaceObject::setPosition(float _x, float _y, float _z)
{
	objectPosition(x_cord) = _x;
	objectPosition(y_cord) = _y;
	objectPosition(z_cord) = _z;
}

/*************************************************************************************************************************************
 * applyForce
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 1xx   xx/xx/2014   BSW   initial coding
 *************************************************************************************************************************************/
void SpaceObject::applyForce(vector3D)
{
//TODO
//	objectVelocity = objectVelocity + (vector3D / objectMass);
}

/*************************************************************************************************************************************
 * rotate
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 1xx   xx/xx/2014   BSW   initial coding
 *************************************************************************************************************************************/
void SpaceObject::rotate(float yaw, float pitch, float roll)
{
	//TODO
	//objectRotation = objectRotation * toQuat(yaw, pitch, roll);
}


/*************************************************************************************************************************************
 * findTargetBearing - returns bearing (Euler angles) of target space object
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   05/09/2014   BSW   initial coding
 *************************************************************************************************************************************/
bearing3D SpaceObject::findTargetBearing(cords3D targetPosition)
{
	// local variables
	bearing3D returnValue;

	// process
	returnValue.yaw = 0;				// initialize return variable
	returnValue.pitch = 0;
	returnValue.roll = 0;

	Matrix<float> vector = new Matrix<float>(object.toLocal(targetPostion[0], object.toLocal(targetPostion[1], object.toLocal(targetPostion[2]);

	Quaternionf angle = new Quaternionf();

	angle.setFromTwoVectors(new Matrix<float>(0,0,0), vector);

	return toEuler(angle);
//	return returnValue;
}

cords3D toLocal(cords3D loc)  {
    return objectFacing._transformVector(loc);
}
