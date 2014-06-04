/*+===================================================================

   Class:    SpaceObject

   Summary:  none

   Methods:  none

 ----------------------------------------------------------------------
   Copyright (C) 2014, Stephen Wunschel
 ===================================================================+*/

#pragma once

// standard header files

// project header files
#include "common.h"						// definitions shared by entire project

//3rd party files
using namespace Eigen;
#include <Geometry>

/***************************************************************************************************************
 * symbolic definitions
 ***************************************************************************************************************/

/***************************************************************************************************************
 * class definition
 ***************************************************************************************************************/
class SpaceObject
{
	public:
		// public data members
		// public method members
		cords3D getPosition();			// get position vector in global FoR
		void setPosition(float, float, float);  // set objectPosition to provided coordinates
		SpaceObject();
		~SpaceObject();
	protected:
		// protected data members
		vector3D objectVelocity;		// current velocity vector of object in 3D space using local FoR
		// protected method members
		void applyForce(vector3D);		// adjusts V based on the force given
	private:
		// private data members
		Quaternionf objectFacing;		// facing
		vector3D objectOrientation;		// orientation (unit vector) of object in 3D using global FoR
		cords3D objectPosition;			// position of object in 3D space using global FoR
		float objectMass;				// mass of object
		// private method members
		void applyTurn();				// applys V(global) to objectPosition
		bearing3D findTargetBearing(cords3D);  // returns bearing (Euler angles) of target space object
		vector3D getFacingV();			// get facing vector
		bearing3D getFacingB();			// get facing stated as degrees off x and y planes
		bearing3D getHeadingB();		// get heading stated as degrees off x and y planes
		vector3D getVelocityG();		// get velocity in global FoR
		vector3D getVelocityL();		// get velocity in local FoR
		void rotate(float, float, float);	// rotates the ship by the given euler angles
		cords3d toLocal(cords3D);		//converts the given cords to the lfor
		cords3D toGlobal(cords3D);		//converts the given cords to the gfor
};

