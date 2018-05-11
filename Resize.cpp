#include"Resize.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
ResizeHalf::ResizeHalf(ApplicationManager * pApp) :Action(pApp)
{}
void ResizeHalf::Execute()
{
	pManager->Resize(.5);
}





ResizeQuart::ResizeQuart(ApplicationManager * pApp) :Action(pApp)
{}
void ResizeQuart::Execute()
{
	pManager->Resize(.25);
}


ResizeDoub::ResizeDoub(ApplicationManager * pApp) :Action(pApp)
{}

void ResizeDoub::Execute()
{
	pManager->Resize(2);
}


ResizeQuad::ResizeQuad(ApplicationManager * pApp) :Action(pApp)
{}
void ResizeQuad::Execute()
{
	pManager->Resize(4);
}