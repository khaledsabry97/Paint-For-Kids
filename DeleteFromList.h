#ifndef DELETE_FROM_LIST_H
#define DELETE_FROM_LIST_H
#include"Actions\Action.h"
class DeleteFromList : public Action
{
public:
	virtual void ReadActionParameters() {}
	DeleteFromList(ApplicationManager *pApp);
	virtual void Execute();
};
#endif
