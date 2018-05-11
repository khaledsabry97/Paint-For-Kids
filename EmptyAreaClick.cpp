#include"EmptyAreaClick.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
EmptyAreaClick::EmptyAreaClick(ApplicationManager * pApp) :Action(pApp)
{}
void EmptyAreaClick::Execute()
{
	pManager->ClickEmptyArea();
}