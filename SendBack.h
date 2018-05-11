#ifndef SEND_BACK_H
#define SEND_BACK_H
#include"Actions\Action.h"
class SendBack : public Action
{
public:
	virtual void ReadActionParameters() {};
	SendBack(ApplicationManager *pApp);
	virtual void Execute();
};
#endif
