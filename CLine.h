#ifndef CLINE_H
#define CLINE_H

#include "Figures\CFigure.h"

class CLine : public CFigure
{
private:
	Point Start;
	Point End;
	Point Startmain;
	Point Endmain;
public:
	CLine(Point P1, Point P2, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(Point P);
	virtual void To_Left();
	virtual void ChngFillClr(color clr);
	virtual void Move(Point P);//the most left
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
	virtual CLine* ACopy();
	virtual CLine* Paste(Point P);
	virtual void Rotate(int x);

};


#endif