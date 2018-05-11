#include "AddCircle.h"
#include "CCircle.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"
#include <cmath>

bool AddCircle::In_Zone()
{
	if ((P1.x - R) < 0 || (P1.x + R)>UI.width || (P1.x + R) < 0 || (P1.x - R)>UI.width)
	{
		return false;
	}
	if ((P1.y - R) < UI.ToolBarHeight || (P1.y + R)>(UI.height - UI.StatusBarHeight) || (P1.y + R) < UI.ToolBarHeight || (P1.y - R)>(UI.height - UI.StatusBarHeight))
	{
		return false;
	}
	return true;
}




AddCircle::AddCircle(ApplicationManager * pApp) :Action(pApp)
{}
void AddCircle::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	bool in;
	do {
		pOut->PrintMessage("New Circle: Click at centre");

		//Read 1st corner and store in point P1
		pIn->GetPointClicked(P1.x, P1.y);

		pOut->PrintMessage("New Circle: Click at a point on the circle");

		//Read 2nd corner and store in point P2
		pIn->GetPointClicked(P2.x, P2.y);
		R = sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));
		in = In_Zone();
		if (!in)
		{
			pOut->PrintMessage("Out of zone , Please try again");
			Sleep(750);
		}
	} while (!in);

	CirtGfxInfo.isFilled = false;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	CirtGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CirtGfxInfo.FillClr = pOut->getCrntFillColor();
	CirtGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();

}
void AddCircle::Execute()
{
	pManager->Endsel();

	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Circle with the parameters read from the user

	CCircle *C = new CCircle(P1, R, CirtGfxInfo);

	//Add the Circle to the list of figures

	//uncomment this line after you create the function
	pManager->AddFigure(C);

}
