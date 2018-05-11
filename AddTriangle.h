#ifndef ADD_TRIANGLE_H
#define ADD_TRIANGLE_H

#include "Actions\Action.h"



class AddTriangle : public Action
{
private:
	Point P1, P2, P3; //Triangle Corners
	GfxInfo TritGfxInfo;
public:
	AddTriangle(ApplicationManager *pApp);
	virtual bool In_Zone();

	//Reads Triangle parameters
	virtual void ReadActionParameters();

	//Add Triangle to the ApplicationManager
	virtual void Execute();

};























#endif