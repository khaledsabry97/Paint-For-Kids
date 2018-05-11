#ifndef SCRAMBLEGAME_H
#define SCRAMBLEGAME_H
#include"Actions\Action.h"
class ScrambleGame : public Action
{
public:
	virtual void ReadActionParameters() {}
	ScrambleGame(ApplicationManager *pApp);
	virtual void Execute();
};
#endif
