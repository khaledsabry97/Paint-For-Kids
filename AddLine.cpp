#include "AddLine.h"
#include "CLine.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"
#include <cmath>



bool AddLine::In_Zone()
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

AddLine::AddLine(ApplicationManager * pApp) :Action(pApp)
{}
void AddLine::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	bool in;
	do {
		pOut->PrintMessage("New Line: Click starting point");

		//Read 1st corner and store in point P1
		pIn->GetPointClicked(P1.x, P1.y);

		pOut->PrintMessage("New Line: Click at ending point");

		//Read 2nd corner and store in point P2
		pIn->GetPointClicked(P2.x, P2.y);
		in = In_Zone();
		if (!in)
		{
			pOut->PrintMessage("Out of zone , Please try again");
			Sleep(750);
		}
	} while (!in);
	LinetGfxInfo.isFilled = false;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	LinetGfxInfo.DrawClr = pOut->getCrntDrawColor();
	//LinetGfxInfo.FillClr = pOut->getCrntFillColor();
	LinetGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}
void AddLine::Execute()
{
	pManager->Endsel();

	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Line with the parameters read from the user

	CLine *R = new CLine(P1, P2, LinetGfxInfo);

	//Add the line to the list of figures

	//uncomment this line after you create the function
	pManager->AddFigure(R);
}


