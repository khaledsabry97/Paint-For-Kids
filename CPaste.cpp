#include"CPaste.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
CPaste::CPaste(ApplicationManager * pApp) :Action(pApp)
{}
void CPaste::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click a point to paste at it");
	pIn->GetPointClicked(P.x, P.y);
}
void CPaste::Execute()
{
	ReadActionParameters();
	pManager->Paste(P);
}