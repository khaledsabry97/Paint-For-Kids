#include "CRectangle.h"
#include <string>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	if (P1.x < P2.x)
	{
		Corner1.x = P1.x;
		Corner2.x = P2.x;
	}
	else
	{
		Corner1.x = P2.x;
		Corner2.x = P1.x;
	}
	if (P1.y < P2.y)
	{
		Corner1.y = P1.y;
		Corner2.y = P2.y;
	}
	else
	{
		Corner1.y = P2.y;
		Corner2.y = P1.y;
	}
	Corner1main = Corner1;
	Corner2main = Corner2;
}
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::Belong(Point P)
{
	if (P.x < Corner1.x || P.y < Corner1.y)
		return false;
	if (P.x > Corner2.x || P.y > Corner2.y)
		return false;
	return true;
}
void CRectangle:: To_Left(){
	Corner1.x=Corner1.x/2;
	Corner1.y=Corner1.y/2+UI.height/4;
	Corner2.x=Corner2.x/2;
	Corner2.y=Corner2.y/2+UI.height/4;
}

void CRectangle::ChngFillClr(color clr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = clr;
}
void CRectangle::Move(Point P)
{
	Point temp;
	temp.x = Corner2.x + (P.x - Corner1.x);
	temp.y = Corner2.y + (P.y - Corner1.y);
	Corner1 = P;
	Corner2 = temp;
	Corner1main = Corner1;
	Corner2main = Corner2;
}
void CRectangle :: RandomMove()
{
	Point Random;
	Random.x= (rand()% (UI.width/2-(CRectangle::GetMaxX()-CRectangle::GetMinX()))) + UI.width/2; // generate random values from UI.width/2 to UI.width/2 - (max x - min x)
	Random.y= (rand()% (UI.height - UI.StatusBarHeight- UI.ToolBarHeight- (CRectangle::GetMaxY()-CRectangle::GetMinY()))) + UI.ToolBarHeight;
	CRectangle:: Move(Random);
}
Point CRectangle::GetMainPoint()
{
	return Corner1;
}
int CRectangle :: GetMinX(){
	return Corner1.x;
}
int CRectangle :: GetMaxX(){
	return Corner2.x;
}
int CRectangle :: GetMinY(){
	return Corner1.y;
}
int CRectangle :: GetMaxY(){
	return Corner2.y;
}
CFigure::Type CRectangle::GetType() const 
{
	return Rectangle;

}
double CRectangle::GetArea()
{
	Point Corner3;
	Corner3.x=Corner2.x;
	Corner3.y=Corner1.y;
	double w,l;
	w=sqrt(pow((Corner1.y-Corner3.y),2)+pow((Corner1.x-Corner3.x),2));
	l=sqrt(pow((Corner2.y-Corner3.y),2)+pow((Corner2.x-Corner3.x),2));
	return w*l;
}
void CRectangle::Resize(float Ratio)
{
	if (abs(Corner1.x - Corner2.x) == 1 && Ratio<1)
	{
		return;
	}
	if (abs(Corner1.y - Corner2.y) == 1)
	{
		return;
	}
	if ((abs(Corner1.x - Corner2.x) == 2 || abs(Corner1.x - Corner2.x == 3)) && Ratio == 0.25)
	{
		return;
	}
	if ((abs(Corner1.y - Corner2.y) == 2 || abs(Corner1.y - Corner2.y == 3)) && Ratio == 0.25)
	{
		return;
	}
	Point PNext1, PNext2;
	PNext1 = Corner1;
	PNext2.x = Corner1.x + floor(abs((Corner2.x - Corner1.x)*Ratio + .5));
	PNext2.y = Corner1.y + floor(abs((Corner2.y - Corner1.y)*Ratio + .5));
	Corner1 = PNext1;
	Corner2 = PNext2;
	Corner1main = PNext1;
	Corner2main = PNext2;
}
void CRectangle::Zoom(float x)
{
/*	Point pc;
	pc.x = ceil ((Corner1.x + Corner2.x) / 2);
	pc.y = ceil((Corner1.y + Corner2.y) / 2);
	pc.x = ceil(pc.x*x);
	pc.y = ceil(pc.y*x);
	float l1, l2;
	l1 = floor(Corner2.x*x+.5) - floor(Corner1.x*x+.5);
	l2 = floor(Corner2.y*x+.5) - floor(Corner1.y*x+.5);
	Corner1.x = pc.x - floor((l1 / 2) + .5);
	Corner1.y = pc.y - floor((l2 / 2) + .5);
	Corner2.x = pc.x + floor((l1 / 2) + .5);
	Corner2.y = pc.y + floor((l1 / 2) + .5);*/
	Corner1.x = floor(Corner1.x*x);
	Corner1.y = floor(Corner1.y*x);
	Corner2.x = floor(Corner2.x*x);
	Corner2.y = floor(Corner2.y*x);
}
void CRectangle::EndZoom()
{
	Corner1 = Corner1main;
	Corner2 = Corner2main;
}
CRectangle* CRectangle::ACopy()
{
	CRectangle* AC = new CRectangle(*this);
	return AC;
}
CRectangle* CRectangle::Paste(Point P)
{
	CRectangle* AC = new CRectangle(*this);
	AC->Corner1 = P;
	AC->Corner1main = P;
	AC->Corner2.x = Corner2.x + (P.x - Corner1.x);
	AC->Corner2.y = Corner2.y + (P.y - Corner1.y);
	AC->Corner2main = AC->Corner2;
	return AC;
}
void CRectangle::Rotate(int x)
{
	for (int i = x; i != 0; i -= 90)
	{
		float pcx, pcy;
		pcx = (Corner2.x + Corner1.x) / 2.0;
		pcy = (Corner2.y + Corner1.y) / 2.0;
		Corner1.x = pcx - (Corner2main.y - Corner1main.y) / 2;
		Corner1.y = pcy - (Corner2main.x - Corner1main.x) / 2;
		Corner2.x = pcx + (Corner2main.y - Corner1main.y) / 2;
		Corner2.y = pcy + (Corner2main.x - Corner1main.x) / 2;
		Corner1main = Corner1;
		Corner2main = Corner2;
	}
}