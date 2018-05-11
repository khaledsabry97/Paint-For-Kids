#include"Zoom.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
ZoomIn::ZoomIn(ApplicationManager * pApp) :Action(pApp)
{}
void ZoomIn::Execute()
{
	pManager->Zoom(1.1);
}





ZoomOut::ZoomOut(ApplicationManager * pApp) :Action(pApp)
{}
void ZoomOut::Execute()
{
	pManager->Zoom(.9);
}


