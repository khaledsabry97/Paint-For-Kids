#ifndef CPASTE_H
#define CPASTE_H
#include"Actions\Action.h"
class CPaste : public Action
{
	Point P;
public:
	virtual void ReadActionParameters();
	CPaste(ApplicationManager *pApp);
	virtual void Execute();
};
#endif
