#ifndef SEND_FRONT_H
#define SEND_FRONT_H
#include"Actions\Action.h"
class SendFront : public Action
{
public:
	virtual void ReadActionParameters() {};
	SendFront(ApplicationManager *pApp);
	virtual void Execute();
};
#endif
