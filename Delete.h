#ifndef DELETE_H
#define DELETE_H
#include"Actions\Action.h"
class Delete : public Action
{
public:
	virtual void ReadActionParameters() {}
	Delete(ApplicationManager *pApp);
	virtual void Execute();
};
#endif
