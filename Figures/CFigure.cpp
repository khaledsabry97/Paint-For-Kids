#include "CFigure.h"
#include <string>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}
void CFigure::SetSelected(bool s)
{	
	Selected = s;
}
void CFigure::ChngID(int a)
{
	if (a > 0)
		ID = a;
}
bool CFigure::IsSelected() const
{	return Selected; }
void CFigure::ChngDrawClr(color cl)
{	FigGfxInfo.DrawClr = cl; }
color CFigure::Getdrawclr() {
	return FigGfxInfo.DrawClr;
}
bool CFigure::Getfillclr(color & C){
	if(FigGfxInfo.isFilled) {C=FigGfxInfo.FillClr; return true;}
	else {return false;}
}



