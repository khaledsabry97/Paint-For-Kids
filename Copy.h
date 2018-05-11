#ifndef COPY_H
#define COPY_H
#include"Actions\Action.h"
class Copy : public Action
{
public:
	virtual void ReadActionParameters() {};
	Copy(ApplicationManager *pApp);
	virtual void Execute();
};
#endif
