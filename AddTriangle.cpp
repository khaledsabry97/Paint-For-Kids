#include "AddTriangle.h"
#include "CTriangle.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"
#include <cmath>




bool AddTriangle::In_Zone()
{
	if (P1.x < 0 || P1.x>UI.width || P2.x < 0 || P2.x>UI.width || P3.x < 0 || P3.x>UI.width)
	{
		return false;
	}
	if (P1.y < UI.ToolBarHeight || P1.y>(UI.height - UI.StatusBarHeight) || P2.y < UI.ToolBarHeight || P2.y>(UI.height - UI.StatusBarHeight) || P3.y < UI.ToolBarHeight || P3.y>(UI.height - UI.StatusBarHeight))
	{
		return false;
	}
	return true;
}


AddTriangle::AddTriangle(ApplicationManager * pApp) :Action(pApp)
{}
void AddTriangle::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	bool in;
	do {
		pOut->PrintMessage("New Triangle: Click at first corner");

		//Read 1st corner and store in point P1
		pIn->GetPointClicked(P1.x, P1.y);

		pOut->PrintMessage("New Triangle: Click at second corner");

		//Read 2nd corner and store in point P2
		pIn->GetPointClicked(P2.x, P2.y);

		pOut->PrintMessage("New Triangle: Click at third corner");

		//Read 2nd corner and store in point P2
		pIn->GetPointClicked(P3.x, P3.y);
		in = In_Zone();
		if (!in)
		{
			pOut->PrintMessage("Out of zone , Please try again");
			Sleep(750);
		}
	} while (!in);
	TritGfxInfo.isFilled = false;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	TritGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TritGfxInfo.FillClr = pOut->getCrntFillColor();
	TritGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}
void AddTriangle::Execute()
{
	pManager->Endsel();

	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Triangle with the parameters read from the user

	CTriangle *R = new CTriangle(P1, P2, P3, TritGfxInfo);

	//Add the Triangle to the list of figures

	//uncomment this line after you create the function
	pManager->AddFigure(R);
}


