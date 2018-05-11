#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	RESIZE,			//Resize a figure(s)
	ROTATE,			//Rotate a figure(s)
	GET_ZOOM_IN,
	GET_ZOOM_OUT,
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	GET_D_SAVE,			//Save the whole graph to a file
	GET_D_LOAD,			//Load a graph from a file
	GET_EXIT,			//Exit the application
	GET_SELECT,
	GET_COPY,
	GET_CUT,
	GET_PASTE,
	GET_UNDO,
	GET_REDO,
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,			//Switch interface to Play mode
						/*FOR MODE PLAY*/
						GET_PICK,
						GET_PICK_TYPE,
						GET_PICK_FILL_COLOR,
						GET_PICK_TYPE_FILL_COLOR,
						GET_PICK_AREA,
						GET_SCRAMBLE,
						GET_SAVE,
						GET_LOAD,




						/*For MODE_COLOR*/
						GET_Blue,
						GET_Red,
						GET_Green,
						GET_Black,
						GET_White,
						GET_Yellow,
						GET_Purple,
						GET_Pink,
						GET_Grey,
						GET_Orange,

						/*For FILL_COLOR*/

						GET_FILL_Blue,
						GET_FILL_Red,
						GET_FILL_Green,
						GET_FILL_Black,
						GET_FILL_White,
						GET_FILL_Yellow,
						GET_FILL_Purple,
						GET_FILL_Pink,
						GET_FILL_Grey,
						GET_FILL_Orange,

						/*For BK_COLOR*/

						GET_BK_Blue,
						GET_BK_Red,
						GET_BK_Green,
						GET_BK_Black,
						GET_BK_White,
						GET_BK_Yellow,
						GET_BK_Purple,
						GET_BK_Pink,
						GET_BK_Grey,
						GET_BK_Orange,
						/*Resize*/
                   HALF,QURT,DOUB,QUAD,
				   /*Rotete*/
				   R90,R180,R270,
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders
};

#endif