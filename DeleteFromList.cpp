#include"DeleteFromList.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
DeleteFromList::DeleteFromList(ApplicationManager * pApp) :Action(pApp)
{}
void DeleteFromList::Execute()
{
	pManager->Deletefig();
}
