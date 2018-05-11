#ifndef CCUT_H
#define CCUT_H
#include"Actions\Action.h"
class CCut : public Action
{
public:
	virtual void ReadActionParameters();
	CCut(ApplicationManager *pApp);
	virtual void Execute();
};
#endif
