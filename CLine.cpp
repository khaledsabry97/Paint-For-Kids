#include "CLine.h"
#include <string>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	if (P1.x < P2.x)
	{
		Start = P1;
		End = P2;
	}
	else
	{
		Start = P2;
		End = P1;
	}
	Startmain = Start;
	Endmain = End;
}
void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Line on the screen	
	pOut->DrawLine(Start, End, FigGfxInfo, Selected);
}
bool CLine::Belong(Point P)
{
	if (Start.x == End.x)
	{
		if (abs(P.x - Start.x)>2)
			return false;
		if (Start.y > End.y)
		{
			if (P.y > Start.y || P.y < End.y)
				return false;
		}
		else
		{
			if (P.y < Start.y || P.y > End.y)
				return false;
		}
		return true;
	}
	if (P.x < Start.x)
		return false;
	if (P.x > End.x)
		return false;
	float Slope = (End.y - Start.y) / float(End.x - Start.x);
	float PSlope = (End.y - P.y) / float(End.x - P.x);
	if (fabs(Slope) > 30)
	{
		Slope = Slope / 32;
		PSlope = PSlope / 32;
	}	else if (fabs(Slope) > 25)
	{
		Slope = Slope / 27;
		PSlope = PSlope / 27;
	}
    else if (fabs(Slope) > 20)
	{
		Slope = Slope / 22;
		PSlope = PSlope / 22;
	}
	else if (fabs(Slope) > 15)
	{
		Slope = Slope / 16.5;
		PSlope = PSlope / 16.5;
	}
	else if (fabs(Slope) > 10)
	{
		Slope = Slope / 11;
		PSlope = PSlope / 11;
	}
	if (fabs(Slope - PSlope)<.1 )
		return true;
	
	return false;
}

void CLine:: To_Left(){
	Start.x=Start.x/2;
	Start.y=Start.y/2+UI.height/4;
	End.x=End.x/2;
	End.y=End.y/2+UI.height/4;
}
void CLine::ChngFillClr(color clr)
{
}
void CLine::Move(Point P)
{
	Point temp = P;
	temp.x = End.x + (P.x - Start.x);
	temp.y = End.y + (P.y - Start.y);
	Start = P;
	End = temp;
	Startmain = Start;
	Endmain = End;
}
void CLine :: RandomMove()
{
	Point Random; Point main= CLine::GetMainPoint();
	Random.x= (rand()% (UI.width/2-(CLine::GetMaxX()-CLine::GetMinX()))) + UI.width/2; // generate random values from UI.width/2 to UI.width/2 - (max x - min x)
	Random.y=(rand()% (UI.height - UI.StatusBarHeight -UI.ToolBarHeight- (main.y- CLine::GetMinY()) - (CLine::GetMaxY()-main.y))) + UI.ToolBarHeight+(main.y-CLine::GetMinY());	
	CLine:: Move(Random);
}
Point CLine::GetMainPoint()
{
	return Start;
}
int CLine :: GetMinX(){
	return Start.x;
}
int CLine :: GetMaxX(){
	return End.x;
}
int CLine :: GetMinY(){
	if (Start.y<End.y) {return Start.y;}
	else {return End.y;}
}
int CLine :: GetMaxY(){
	if (Start.y>End.y) {return Start.y;}
	else {return End.y;}
}
CFigure::Type CLine::GetType() const 
{
	return Line;

}
double CLine::GetArea()
{
	return sqrt(pow((Start.y-End.y),2)+pow((Start.x-End.x),2));            
}
void CLine::Resize(float Ratio) 
{
	if (abs(Start.x - End.x) == 1 && Ratio<1)
	{
		return;
	}
	if (abs(Start.y - End.y) == 1)
	{
		return;
	}
	if ((abs(Start.x - End.x) == 2 || abs(Start.x - End.x == 3)) && Ratio == 0.25)
	{
		return;
	}
	if ((abs(Start.y - End.y) == 2 || abs(Start.y - End.y == 3)) && Ratio == 0.25)
	{
		return;
	}
	Point PNext1, PNext2;
	PNext1 = Start;
	PNext2.x = Start.x + floor((End.x - Start.x)*Ratio + .5);
	PNext2.y = Start.y + floor((End.y - Start.y)*Ratio + .5);
	Start = PNext1;
	End = PNext2;
	Startmain = PNext1;
	Endmain = PNext2;
}
void CLine::Zoom(float x)
{
	/*Point pc; float len;
	pc.x = floor((Start.x + End.x) / 2 + .5);
	pc.y = floor((Start.y + End.y) / 2 + .5);
	pc.x = pc.x*x;
	pc.y = pc.y*x;
	len = sqrt(pow(ceil(Start.x - End.x), 2) + pow(ceil(Start.y - End.y), 2));
	float Cos = ((End.x - Start.x) / len);
	float Sin = ((End.y - Start.y) / len);
	len *= x;*/

	Start.x = floor(Start.x*x);
	Start.y = floor(Start.y*x);
	End.x = floor(End.x*x);
	End.y = floor(End.y*x);
}
void CLine::EndZoom()
{
	Start = Startmain;
	End = Endmain;
}
CLine* CLine::ACopy()
{
	CLine* AC = new CLine(*this);
	return AC;
}
CLine* CLine::Paste(Point P)
{
	CLine* AC = new CLine(*this);
	AC->Start = P;
	AC->End.x = End.x + (P.x - Start.x);
	AC->End.y = End.y + (P.y - Start.y);
	AC->Startmain = AC->Start;
	AC->Endmain = AC->End;
	return AC;
}
void CLine::Rotate(int x)
{
	for (int i = x; i != 0; i -= 90)
	{
		int temp = Start.y;
		Start.y = End.y;
		End.y = temp;
	}
	Startmain.y = Start.y;
	Endmain.y = End.y;
}