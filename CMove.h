#ifndef CMOVE_H
#define CMOVE_H
#include"Actions\Action.h"
class CMove : public Action
{
	Point P;
public:
	virtual void ReadActionParameters();
	CMove(ApplicationManager *pApp);
	virtual void Execute();
};
#endif
