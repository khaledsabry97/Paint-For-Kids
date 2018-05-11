#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include"Figures\CFigure.h"




class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	Point Corner1main;
	Point Corner2main;
	Point Corner3main;
public:
	CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(Point P);
	virtual void To_Left(); 
	virtual void ChngFillClr(color clr);
	virtual void Move(Point P);//most left
	virtual void RandomMove();
	virtual Point GetMainPoint();	
	virtual int GetMinX();
	virtual int GetMaxX();
	virtual int GetMinY();
	virtual int GetMaxY();
	virtual Type GetType() const;
	virtual double GetArea();
	virtual void Resize(float Ratio);
	virtual void Zoom(float x);
	virtual void EndZoom();
	virtual CTriangle* ACopy();
	virtual CTriangle* Paste(Point P);
	virtual void Rotate(int x);

};











#endif