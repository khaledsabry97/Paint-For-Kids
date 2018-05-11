#ifndef ADD_CIRCLE_H
#define ADD_CIRCLE_H

#include "Actions\Action.h"





class AddCircle : public Action
{
private:
	Point P1, P2; //Circle Corners
	int R;
	GfxInfo CirtGfxInfo;
public:
	AddCircle(ApplicationManager *pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();
	virtual bool In_Zone();

	//Add Circle to the ApplicationManager
	virtual void Execute();

};























#endif