#ifndef DRAW_TB_H
#define DRAW_TB_H

#include "Actions\Action.h"
#include"ToolBars.h"




class CDrawClrTB : public Action
{
public:
	virtual void ReadActionParameters();
	CDrawClrTB(ApplicationManager *pApp);
	virtual void Execute();
};

class CFillClrTB : public Action
{
public:
	virtual void ReadActionParameters();
	CFillClrTB(ApplicationManager *pApp);
	virtual void Execute();
};
class CBKClrTB : public Action
{
public:
	virtual void ReadActionParameters();
	CBKClrTB(ApplicationManager *pApp);
	virtual void Execute();
};

class CToDrawTB : public Action
{
public:
	virtual void ReadActionParameters();
	CToDrawTB(ApplicationManager *pApp);
	virtual void Execute();
};


class CToPlayTB : public Action
{
public:
	virtual void ReadActionParameters();
	CToPlayTB(ApplicationManager *pApp);
	virtual void Execute();
};
class CResizeTB : public Action
{
public:
	virtual void ReadActionParameters();
	CResizeTB(ApplicationManager *pApp);
	virtual void Execute();
};
class CRotateTB : public Action
{
public:
	virtual void ReadActionParameters();
	CRotateTB(ApplicationManager *pApp);
	virtual void Execute();
};
class CPickTB : public Action
{
public:
	virtual void ReadActionParameters();
	CPickTB(ApplicationManager *pApp);
	virtual void Execute();
};














#endif