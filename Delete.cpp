#include"Delete.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
Delete::Delete(ApplicationManager * pApp) :Action(pApp)
{}
void Delete::Execute()
{
	pManager->Deletefig();
}