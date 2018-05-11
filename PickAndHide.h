#ifndef PICKANDHIDE_H
#define PICKANDHIDE_H
#include"Actions\Action.h"
class PickByType : public Action
{
public:
	virtual void ReadActionParameters() {}
	PickByType(ApplicationManager *pApp);
	virtual void Execute();
};
class PickByColor : public Action
{
public:
	virtual void ReadActionParameters() {}
	PickByColor(ApplicationManager *pApp);
	virtual void Execute();
};
class PickByTypeColor : public Action
{
public:
	virtual void ReadActionParameters() {}
	PickByTypeColor(ApplicationManager *pApp);
	virtual void Execute();
};
class PickByArea : public Action
{
public:
	virtual void ReadActionParameters() {}
	PickByArea(ApplicationManager *pApp);
	virtual void Execute();
};


#endif


