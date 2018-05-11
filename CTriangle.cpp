#include "CTriangle.h"
#include <string>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	if (P1.x < P2.x&&P1.x < P3.x)
	{
		Corner1 = P1;
		if (P2.x > P3.x)
		{
			Corner2 = P2;
			Corner3 = P3;
		}
		else
		{
			Corner2 = P3;
			Corner3 = P2;
		}
	}
	else if (P2.x < P3.x)
	{
		Corner1 = P2;
		if (P1.x > P3.x)
		{
			Corner2 = P1;
			Corner3 = P3;
		}
		else
		{
			Corner2 = P3;
			Corner3 = P1;
		}
	}
	else
	{
		Corner1 = P3;
		Corner2 = P2;
		Corner3 = P1;
		if (P1.x > P2.x)
		{
			Corner2 = P1;
			Corner3 = P2;
		}
		else
		{
			Corner2 = P2;
			Corner3 = P1;
		}
	}
	Corner1main = Corner1;
	Corner2main = Corner2;
	Corner3main = Corner3;
}
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Triangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
bool CTriangle::Belong(Point P) {
	int s = Corner1.y * Corner3.x - Corner1.x * Corner3.y + (Corner3.y - Corner1.y) * P.x + (Corner1.x - Corner3.x) * P.y;
	int t = Corner1.x * Corner2.y - Corner1.y * Corner2.x + (Corner1.y - Corner2.y) * P.x + (Corner2.x - Corner1.x) * P.y;

	if ((s < 0) != (t < 0))
		return false;

	int A = -Corner2.y * Corner3.x + Corner1.y * (Corner3.x - Corner2.x) + Corner1.x * (Corner2.y - Corner3.y) + Corner2.x * Corner3.y;
	if (A < 0.0)
	{
		s = -s;
		t = -t;
		A = -A;
	}
	return s > 0 && t > 0 && (s + t) <= A;
}

void CTriangle:: To_Left(){
	Corner1.x=Corner1.x/2;
	Corner1.y=Corner1.y/2+UI.height/4;
	Corner2.x=Corner2.x/2;
	Corner2.y=Corner2.y/2+UI.height/4;
	Corner3.x=Corner3.x/2;
	Corner3.y=Corner3.y/2+UI.height/4;


}
void CTriangle::ChngFillClr(color clr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = clr;
}
void CTriangle::Move(Point P) 
{
	Point temp1, temp2;
	temp1.x = Corner2.x + (P.x - Corner1.x);
	temp1.y = Corner2.y + (P.y - Corner1.y);
	temp2.x = Corner3.x += (P.x - Corner1.x);
	temp2.y = Corner3.y += (P.y - Corner1.y);
	Corner1 = P;
	Corner2 = temp1;
    Corner3 = temp2;
	Corner1main = Corner1;
	Corner2main = Corner2;
	Corner3main = Corner3;
}
void CTriangle :: RandomMove()
{
	Point Random; Point main;
	main=CTriangle::GetMainPoint();
	Random.x= (rand()% (UI.width/2-(CTriangle::GetMaxX()-CTriangle::GetMinX()))) + UI.width/2; // generate random values from UI.width/2 to UI.width/2 - (max x - min x)
	Random.y=(rand()% (UI.height - UI.StatusBarHeight -UI.ToolBarHeight- (main.y-CTriangle::GetMinY()) - (CTriangle::GetMaxY()-main.y))) + UI.ToolBarHeight+(main.y-CTriangle::GetMinY());	
	CTriangle:: Move(Random);
}
Point CTriangle::GetMainPoint()
{
	return Corner1;
}
int CTriangle :: GetMinX(){
	return Corner1.x;
}
int CTriangle :: GetMaxX(){
	if (Corner2.x>Corner3.x) {return Corner2.x;}
	else {return Corner3.x;}
}
int CTriangle :: GetMinY(){
	if (Corner1.y<Corner2.y){
		if (Corner1.y<Corner3.y) {return Corner1.y;} 
		else { return Corner3.y;}
	}
	else {if(Corner2.y<Corner3.y){return Corner2.y;}
	else {return Corner3.y;}
	}
}
int CTriangle :: GetMaxY(){
	if (Corner1.y>Corner2.y){
		if (Corner1.y>Corner3.y) {return Corner1.y;} 
		else { return Corner3.y;}
	}
	else {if(Corner2.y>Corner3.y){return Corner2.y;}
	else {return Corner3.y;}
	}
}
CFigure::Type CTriangle::GetType() const 
{
	return Triangle;

}
double CTriangle::GetArea()
{
	return abs((Corner1.x*(Corner2.y-Corner3.y)+Corner2.x*(Corner3.y-Corner1.y)+Corner3.x*(Corner1.y-Corner2.y))*0.5) ;            
}
void CTriangle::Resize(float Ratio)
{
	if (abs((Corner1.x - Corner2.x)==1 || abs(Corner1.x - Corner3.x)==1 || abs(Corner3.x - Corner2.x) == 1) && Ratio<1)
	{
		return;
	}
	if (abs((Corner1.y - Corner2.y)==1 || abs(Corner1.y - Corner3.y)==1 || abs(Corner3.y - Corner2.y) == 1) && Ratio<1)
	{
		return;
	}
	if ((abs(Corner1.x - Corner2.x) == 2 || abs(Corner1.x - Corner2.x == 3) || abs(Corner1.x - Corner3.x) == 2 || abs(Corner1.x - Corner3.x == 3) || abs(Corner2.x - Corner3.x) == 2 || abs(Corner2.x - Corner3.x == 3)) && Ratio == 0.25)
	{
		return;
	}
	if ((abs(Corner1.x - Corner2.x) == 2 || abs(Corner1.x - Corner2.x == 3) || abs(Corner1.x - Corner3.x) == 2 || abs(Corner1.x - Corner3.x == 3) || abs(Corner2.x - Corner3.x) == 2 || abs(Corner2.x - Corner3.x == 3)) && Ratio == 0.25)
	{
		return;
	}
	Point PNext1, PNext2, PNext3;
	PNext1 = Corner1;
	PNext2.x = Corner1.x + floor(abs((Corner2.x - Corner1.x)*Ratio + .5));
	PNext2.y = Corner1.y + floor(abs((Corner2.y - Corner1.y)*Ratio + .5));
	PNext3.x = Corner1.x + floor(abs((Corner3.x - Corner1.x)*Ratio + .5));
	PNext3.y = Corner1.y + floor(abs((Corner3.y - Corner1.y)*Ratio + .5));
	Corner1 = PNext1;
	Corner2 = PNext2;
	Corner3 = PNext3;
	Corner1main = Corner1;
	Corner2main = Corner2;
	Corner3main = Corner3;
}
void CTriangle::Zoom(float x)
{
	/*Point pc;
	pc.x = ceil(Corner1.x + Corner2.x + Corner3.x) / 3;
	pc.y = ceil(Corner1.y + Corner2.y + Corner3.y) / 3;
	pc.x = ceil(pc.x*x);
	pc.y = ceil(pc.y*x);
	Corner1.x = ceil(Corner1.x*x);
	Corner1.y = ceil(Corner1.y*x);
	Corner2.x = ceil(Corner2.x*x);
	Corner2.y = ceil(Corner2.y*x);
	Corner3.x = ceil(Corner3.x*x);
	Corner3.y = ceil(Corner3.y*x);*/
	Corner1.x = floor(Corner1.x*x);
	Corner1.y = floor(Corner1.y*x);
	Corner2.x = floor(Corner2.x*x);
	Corner2.y = floor(Corner2.y*x);
	Corner3.x = floor(Corner3.x*x);
	Corner3.y = floor(Corner3.y*x);
}
void CTriangle::EndZoom()
{
	Corner1 = Corner1main;
	Corner2 = Corner2main;
	Corner3 = Corner3main;
}
CTriangle* CTriangle::ACopy()
{
	CTriangle* AC = new CTriangle(*this);
	return AC;
}
CTriangle* CTriangle::Paste(Point P)
{
	CTriangle* AC = new CTriangle(*this);
	AC->Corner1 = P;
	AC->Corner1main = P;
	AC->Corner2.x = Corner2.x + (P.x - Corner1.x);
	AC->Corner2.y = Corner2.y + (P.y - Corner1.y);
	AC->Corner2main = AC->Corner2;
	AC->Corner3.x = Corner3.x + (P.x - Corner1.x);
	AC->Corner3.y = Corner3.y + (P.y - Corner1.y);
	AC->Corner3main = AC->Corner3;
	return AC;

}
void CTriangle::Rotate(int x)
{
	for (int i = x; i != 0; i -= 90)
	{
		float pcx = (Corner1.x + Corner2.x + Corner3.x) / 3.0;
		float pcy = (Corner1.y + Corner2.y + Corner3.y) / 3.0;
		Corner1.x = Corner1.x - pcx;
		Corner2.x = Corner2.x - pcx;
		Corner3.x = Corner3.x - pcx;
		Corner1.y = Corner1.y - pcy;
		Corner2.y = Corner2.y - pcy;
		Corner3.y = Corner3.y - pcy;
		int temp;
		temp = Corner1.x;
		Corner1.x = -Corner1.y;
		Corner1.y = temp;
		temp = Corner2.x;
		Corner2.x = -Corner2.y;
		Corner2.y = temp;
		temp = Corner3.x;
		Corner3.x = -Corner3.y;
		Corner3.y = temp;
		Corner1.x = Corner1.x + pcx;
		Corner2.x = Corner2.x + pcx;
		Corner3.x = Corner3.x + pcx;
		Corner1.y = Corner1.y + pcy;
		Corner2.y = Corner2.y + pcy;
		Corner3.y = Corner3.y + pcy;
	}
	Corner1main = Corner1;
	Corner2main = Corner2;
	Corner3main = Corner3;
}