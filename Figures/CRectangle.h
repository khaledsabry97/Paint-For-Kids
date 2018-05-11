#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner1main;
	Point Corner2main;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
    virtual bool Belong(Point P);
	virtual void To_Left(); 
	virtual void ChngFillClr(color clr);
	virtual void Move(Point P);//top left corner
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
	virtual CRectangle* ACopy();
	virtual CRectangle* Paste(Point P);
	virtual void Rotate(int x);

};










#endif