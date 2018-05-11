#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreatePickToolBar() const; //creates pick and hide game tool bar
	void CreateStatusBar() const;	//create the status bar
	void CreateColorToolBar() const;
	void CreateFillColorToolBar() const;
	void CreatebkColorToolBar() const;
	void CreateResizeToolBar() const;
	void CreateRotateToolBar() const;
	void ChangebkColor(color a);
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearToolBar() const;
	void SetTempHLCL(color a);
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const;
	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const;
	void DrawCircle(Point P1, int radius, GfxInfo CirGfxInfo, bool selected) const;
	///Make similar functions for drawing all other figures.

	void PrintMessage(string msg) const;	//Print a message on Status bar
	void PrintMessage_string(string msg, string m) const;
	void PrintPicks(string msg1 , int Valid , string msg2 , int InValid) const;
	void PrintGrade(string msg1, double Percent , string msg2) const; 
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


	~Output();
};

#endif