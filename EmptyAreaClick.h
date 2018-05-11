#ifndef EMPTY_AREA_CLICK
#define EMPTY_AREA_CLICK
#include"Actions\Action.h"
class EmptyAreaClick :public Action {
public:
	virtual void ReadActionParameters() {};
	EmptyAreaClick(ApplicationManager *pApp);
	virtual void Execute();
};

#endif