#include"CRotate.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
Rotate90::Rotate90(ApplicationManager * pApp) :Action(pApp)
{}
void Rotate90::Execute()
{
	pManager->Rotate(90);
}





Rotate180::Rotate180(ApplicationManager * pApp) :Action(pApp)
{}
void Rotate180::Execute()
{
	pManager->Rotate(180);
}


Rotate270::Rotate270(ApplicationManager * pApp) :Action(pApp)
{}

void Rotate270::Execute()
{
	pManager->Rotate(270);
}


