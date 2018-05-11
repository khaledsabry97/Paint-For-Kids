#ifndef DRAW_AREA_CLICK
#define DRAW_AREA_CLICK
#include"Actions\Action.h"
class DrawAreaClick :public Action {
public :
	virtual void ReadActionParameters() {};
	DrawAreaClick(ApplicationManager *pApp);
	virtual void Execute();
};

#endif