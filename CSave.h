#ifndef SAVE_H
#define SAVE_H
#include"Actions\Action.h"
class CSave : public Action
{
public:
	virtual void ReadActionParameters() {}
	CSave(ApplicationManager *pApp);
	virtual void Execute();
};
#endif