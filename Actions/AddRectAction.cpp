#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
#include <cmath>

bool AddRectAction::In_Zone()
{
	if (P1.x < 0 || P1.x>UI.width || P2.x < 0 || P2.x>UI.width)
	{
		return false;
	}
	if (P1.y < UI.ToolBarHeight || P1.y>(UI.height - UI.StatusBarHeight) || P2.y < UI.ToolBarHeight || P2.y>(UI.height - UI.StatusBarHeight))
	{
		return false;
	}
	return true;
}

AddRectAction::AddRectAction(ApplicationManager * pApp) :Action(pApp)
{}
void AddRectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	bool in;
	do {
		pOut->PrintMessage("New Rectangle: Click at first corner");

		//Read 1st corner and store in point P1
		pIn->GetPointClicked(P1.x, P1.y);

		pOut->PrintMessage("New Rectangle: Click at second corner");

		//Read 2nd corner and store in point P2
		pIn->GetPointClicked(P2.x, P2.y);
		in = In_Zone();
		if (!in)
		{
			pOut->PrintMessage("Out of zone , Please try again");
			Sleep(750);
		}
	} while (!in);
	RectGfxInfo.isFilled = false;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}
void AddRectAction::Execute()
{
	pManager->Endsel();

	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CRectangle *R = new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}


