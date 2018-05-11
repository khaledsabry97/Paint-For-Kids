#ifndef CROTATE_H
#define CROTATE_H
#include"Actions\Action.h"
class Rotate90 : public Action
{
public:
	virtual void ReadActionParameters() {}
	Rotate90(ApplicationManager *pApp);
	virtual void Execute();
};
class Rotate180 : public Action
{
public:
	virtual void ReadActionParameters() {}
	Rotate180(ApplicationManager *pApp);
	virtual void Execute();
};
class Rotate270 : public Action
{
public:
	virtual void ReadActionParameters() {}
	Rotate270(ApplicationManager *pApp);
	virtual void Execute();
};


#endif
