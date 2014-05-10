/*+===================================================================

   File:      main.h

   Summary:   definitions for main program

   Classes:   none

   Functions: none

   Origin:    none

 ----------------------------------------------------------------------
   Copyright (C) 2014, Stephen Wunschel
 ===================================================================+*/

#pragma once

// standard header files

// project header files

// declarations
#define PROJECT_VERSION "SCS 1.0.0, Copyright (C) 2014, Stephen Wunschel"

// enumerations
enum ENUM_CMDS							// console command translation
{
	quit=0,									// defined commands
	display,
	setposition,
	setthrust,
	unknown=100								// other commands
};

// variables

// function prototypes
bool doCommand(const char *);			// execute contents of command buffer
bool handle_display(void);				// execute display command
bool handle_setposition(const char *);	// execute setposition command
bool handle_setthrust(const char *);	// execute setthrust command
int parseCommand(const char *);			// return switch token for command received
void readCommands(void);				// command entry loop

