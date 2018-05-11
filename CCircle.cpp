#include "CCircle.h"
#include<cmath>
#include <string>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

CCircle::CCircle(Point Pcent, int r, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Rmain = r;
	R = r;
	Pc = Pcent;
	Pcmain = Pc;
}
void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Circle on the screen	
	pOut->DrawCircle(Pc, R, FigGfxInfo, Selected);
}
void CCircle::ChngFillClr(color clr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = clr;
}

bool CCircle::Belong(Point P)
{
	float dist;
	dist = sqrt(pow(P.x - Pc.x, 2) + pow(P.y - Pc.y, 2));
	if (dist > R)
		return false;
	else
		return true;
}

void CCircle:: To_Left()
{
	Pc.x=Pc.x/2;
	Pc.y=Pc.y/2+UI.height/4;
	R=R/2;
}


void CCircle::Move(Point P)
{
	Pc = P;
	Pcmain = Pc;
}
void CCircle::RandomMove()
{
	Point Random;
	Random.x=(rand()% (UI.width/2- 2*R))+ UI.width/2+R;        //to generate random values from UI.width/2+R to UI.width-R 
	Random.y=(rand()% (UI.height - UI.StatusBarHeight -UI.ToolBarHeight- 2*R)) + UI.ToolBarHeight+R;  //to generate random values from toolbar height+R to UI.height - UI.statusbar height - R 
	CCircle::Move(Random);
}
Point CCircle::GetMainPoint()
{
	return Pc;
}
int CCircle:: GetMinX(){
	return Pc.x-R;
}
int CCircle:: GetMaxX(){
	return Pc.x+R;
}
int CCircle:: GetMinY(){
	return Pc.y-R;
}
int CCircle:: GetMaxY(){
	return Pc.y+R;
}

double CCircle::GetArea()
{
	return 3.14*R*R;            
}

CFigure::Type CCircle::GetType() const 
{
	return Circle;

}
void CCircle::Resize(float Ratio)
//resize by multiplying the radius by ratio and take the nearest value
{
	if (R == 1 && Ratio<1)
	{
		return;
	}
	if ((R == 2 || R == 3) && Ratio == 0.25)
	{
		return;
	}
	int Rad = floor((R*Ratio) + .5);
	R = Rad;
	Rmain = Rad;
}
void CCircle::Zoom(float x)
{
	R = ceil(R*x);
	Pc.x = ceil(Pc.x*x);
	Pc.y = ceil(Pc.y*x);

}
void CCircle::EndZoom()
{
	R = Rmain;
	Pc = Pcmain;	
}
CCircle* CCircle::ACopy()
{
	CCircle* AC = new CCircle(*this);
	return AC;
}
CCircle* CCircle::Paste(Point P)
{
	CCircle* AC = new CCircle(*this);
	AC->Pc = P;
	AC->Pcmain = P;
	return AC;
}
void CCircle::Rotate(int x) {};