#ifndef CSELECT_H
#define CSELECT_H
#include"Actions\Action.h"
class Selectfig: public Action
{
	Point P;
public:
	virtual void ReadActionParameters() ;
	Selectfig(ApplicationManager *pApp);
	virtual void Execute() ;
};
#endif
