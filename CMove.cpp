#include"CMove.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
CMove::CMove(ApplicationManager * pApp) :Action(pApp)
{}
void CMove::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click on place to move to");
	pIn->GetPointClicked(P.x, P.y);
}
void CMove::Execute()
{
	ReadActionParameters();
	pManager->Move(P);
}