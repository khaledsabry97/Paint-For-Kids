#include"CSave.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
CSave::CSave(ApplicationManager * pApp) :Action(pApp)
{}
void CSave::Execute()
{
	pManager->Save_All();
}