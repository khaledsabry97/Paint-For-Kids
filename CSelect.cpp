#include"CSelect.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
Selectfig::Selectfig(ApplicationManager * pApp) :Action(pApp)
{}
void Selectfig::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click on figuer/s to select");
	pIn->GetPointClicked(P.x,P.y);
}
void Selectfig::Execute()
{
	ReadActionParameters();
	CFigure* f = pManager->GetFigure(P);
	while (f != NULL)
	{
		pManager->Sel(f);
		pManager->UpdateInterface();
		ReadActionParameters();
		f = pManager->GetFigure(P);
	}
}