#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "Figures\CFigure.h"

class CCircle : public CFigure
{
private:
	Point Pc;
	int R;
	int Rmain;
	Point Pcmain;

public:
	CCircle(Point Pa, int r, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(Point P);
	virtual void ChngFillClr(color clr);
	virtual void Move(Point P);//from centre
	virtual void RandomMove();
	virtual void To_Left();
	virtual Point GetMainPoint();
	virtual int GetMinX();
	virtual int GetMaxX();
	virtual int GetMinY();
	virtual int GetMaxY();
	virtual double GetArea();
	Type GetType() const;
	virtual void Resize(float Ratio);
	virtual void Zoom(float x);
	virtual void EndZoom();
	virtual CCircle* ACopy();
	virtual CCircle* Paste(Point P);
	virtual void Rotate(int x);

};


#endif