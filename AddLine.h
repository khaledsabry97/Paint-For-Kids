#ifndef ADD_LINE_H
#define ADD_LINE_H

#include "Actions\Action.h"

class AddLine : public Action
{
private:
	Point P1, P2; //Line Points
	GfxInfo LinetGfxInfo;
public:
	AddLine(ApplicationManager *pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();
	virtual bool In_Zone();

	//Add Line to the ApplicationManager
	virtual void Execute();

};
























#endif