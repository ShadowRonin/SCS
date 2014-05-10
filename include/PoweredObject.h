/*+===================================================================

   Class:    PowerObject

   Summary:  none

   Methods:  none

 ----------------------------------------------------------------------
   Copyright (C) 2014, Stephen Wunschel
 ===================================================================+*/

#pragma once

// standard header files

// project header files
#include <SpaceObject.h>

/***************************************************************************************************************
 * symbolic definitions
 ***************************************************************************************************************/

/***************************************************************************************************************
 * class definition
 ***************************************************************************************************************/
class PoweredObject : public SpaceObject
{
	public:
		// public data members
		// public method members
		float getThrust(void);			// return value of objectThrust
		PoweredObject();
		~PoweredObject();
		void setThrust(float);			// set value of objectThrust
	protected:
		// protected data members
		// protected method members
	private:
		// private data members
		float objectThrust;				// magnitude of thrust vector of object
		// private method members
		void applyThrust(void);		// modify objectVelocity using facing and thrust
		void applyThrust(float);		// modify objectVelocity using provided thrust
};

