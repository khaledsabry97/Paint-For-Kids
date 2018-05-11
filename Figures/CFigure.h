#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
public:
	const enum Type
	{
		Triangle,
		Circle,
		Line,
		Rectangle

	};
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	void ChngID(int a);
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	virtual void ChngFillClr(color Fclr)=0;	//changes the figure's filling color
	virtual bool Belong(Point P)=0;
	virtual void To_Left()=0;
	//virtual Point To_Left()=0;           //returns a point in left side where figure should move to
	color Getdrawclr();
	bool Getfillclr (color &C);
	virtual void Move(Point P)=0;
	virtual void RandomMove()=0;
	virtual Point GetMainPoint()=0; 
	virtual int GetMinX()=0;
	virtual int GetMaxX()=0;
	virtual int GetMinY()=0;
	virtual int GetMaxY()=0;
	virtual Type GetType() const=0;
	virtual void Resize(float Ratio) = 0;
	virtual void Zoom(float x) = 0;
	virtual void EndZoom() = 0;
	virtual CFigure* ACopy() = 0;
	virtual CFigure* Paste(Point P) = 0;
	virtual void Rotate(int x) = 0;

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure
	
	GfxInfo get_info() { return  FigGfxInfo; };
	//virtual void Save(ofstream &out) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	virtual double GetArea()=0;
};

#endif