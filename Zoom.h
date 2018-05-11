#ifndef ZOOM_H
#define ZOOM_H
#include"Actions\Action.h"
class ZoomIn : public Action
{
public:
	virtual void ReadActionParameters() {}
	ZoomIn(ApplicationManager *pApp);
	virtual void Execute();
};
class ZoomOut : public Action
{
public:
	virtual void ReadActionParameters() {}
	ZoomOut(ApplicationManager *pApp);
	virtual void Execute();
};
#endif