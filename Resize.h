#ifndef RESIZE_H
#define RESIZE_H
#include"Actions\Action.h"
class ResizeHalf : public Action
{
public:
	virtual void ReadActionParameters() {}
	ResizeHalf(ApplicationManager *pApp);
	virtual void Execute();
};
class ResizeQuart : public Action
{
public:
	virtual void ReadActionParameters() {}
	ResizeQuart(ApplicationManager *pApp);
	virtual void Execute();
};
class ResizeDoub : public Action
{
public:
	virtual void ReadActionParameters() {}
	ResizeDoub(ApplicationManager *pApp);
	virtual void Execute();
};
class ResizeQuad : public Action
{
public:
	virtual void ReadActionParameters() {}
	ResizeQuad(ApplicationManager *pApp);
	virtual void Execute();
};

#endif
