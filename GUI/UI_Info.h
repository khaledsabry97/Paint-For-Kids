#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_COLOR,  //Color tool bar
	MODE_FILL,   // fill tool bar
	MODE_BK ,    //background tool bar
	MODE_RESIZE,// Resize toolbar
	MODE_ROTATE, //Rotate toolbar
	MODE_PICK    //Pick and Hide game toolbar
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_CIRC,		//Circle item in menu
	ITM_Line,		//Line item in menu
	ITM_Triangle,		//Triangle item in menu
	ITM_DRAW_CLR,	//Change the drawing color
	ITM_FILL_CLR,	//Change the filling color
	ITM_BK_CLR,	//Change background color
	ITM_DEL,    //Delete a figure(s)
	ITM_SELECT,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_UNDO,
	ITM_REDO,
	ITM_MOVE,			//Move a figure(s)
	ITM_RESIZE,			//Resize a figure(s)
	ITM_ROTATE,			//Rotate a figure(s)
	ITM_ZOOM_IN,
	ITM_ZOOM_OUT,
	ITM_SEND_BACK,		//Send a figure to the back of all figures
	ITM_BRNG_FRNT,		//Bring a figure to the front of all figures
	ITM_SAVE,			//Save the whole graph to a file
	ITM_LOAD,			//Load a graph from a file		
	ITM_TO_PLAY,			//Switch interface to Play mode
	ITM_EXIT,//Exit item
	DRAW_ITM_COUNT,		//no. of menu items ==> This should be the last line in this enum

	ITM_DRAWING_AREA,	//A click on the drawing area
	ITM_STATUS,			//A click on the status bar
	ITM_EMPTY,			//A click on empty place in the toolbar




};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	PICK,
	SCRAMBLE,
	SAVE,
	LOAD,
	DRAW_TOOL_BAR,
	EXIT,

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};
enum PickMenuItem
{
	FIG_TYPE,
	FIG_FILL_COLOR,
	FIG_TYPE_FILL_COLOR,
	FIG_AREA,
	PLAY_TOOL_BAR,

	PICK_ITM_COUNT
};

enum ColorMenuItem
{
	Back_TO_DRAW,
	Blue,
	Red,
	Green,
	Black,
	White,
	Yellow,
	Purple,
	Pink,
	Grey,
	Orange,
	COLOR_ITM_COUNT
};
enum ResizeMenuItem
{
	Go_TO_DRAW,
	Half,
	Quarter,
	Double,
	Quadratic,
	Resize_ITM_COUNT
};
enum RotateMenuItem
{
	Go_Back_TO_DRAW,
	Ro90,
	Ro180,
	Ro270,
	Rotate_ITM_COUNT
};



__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color TempHLCL;
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

							/// Add more members if needed

}UI;	//create a global object UI

#endif