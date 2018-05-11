#ifndef CCOPY_H
#define CCOPY_H
#include"Actions\Action.h"
class CCopy : public Action
{
public:
	virtual void ReadActionParameters();
	CCopy(ApplicationManager *pApp);
	virtual void Execute();
};
#endif
