#include "DrawTB.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"


CDrawClrTB::CDrawClrTB(ApplicationManager * pApp) :Action(pApp)
{}
void CDrawClrTB::Execute()
{
	DrawClrTB Bar;
	pManager->Drawtb(&Bar);
}
void CDrawClrTB::ReadActionParameters()
{
}


CFillClrTB::CFillClrTB(ApplicationManager * pApp) :Action(pApp)
{}
void CFillClrTB::Execute()
{
	FillClrTB Bar;
	pManager->Drawtb(&Bar);
}
void CFillClrTB::ReadActionParameters()
{
}


CBKClrTB::CBKClrTB(ApplicationManager * pApp) :Action(pApp)
{}
void CBKClrTB::Execute()
{
	pManager->Endsel();
	BKClrTB Bar;
	pManager->Drawtb(&Bar);
}
void CBKClrTB::ReadActionParameters()
{
}


CToDrawTB::CToDrawTB(ApplicationManager * pApp) :Action(pApp)
{}
void CToDrawTB::Execute()
{
	pManager->Endsel();
	ToDrawTB Bar;
	pManager->Drawtb(&Bar);
}
void CToDrawTB::ReadActionParameters()
{
}


CToPlayTB::CToPlayTB(ApplicationManager * pApp) :Action(pApp)
{}
void CToPlayTB::Execute()
{
	pManager->Endsel();
	ToPlayTB Bar;
	pManager->Drawtb(&Bar);
}
void CToPlayTB::ReadActionParameters()
{
}

CResizeTB::CResizeTB(ApplicationManager * pApp) :Action(pApp)
{}
void CResizeTB::Execute()
{
	ResizeTB Bar;
	pManager->Drawtb(&Bar);
}
void CResizeTB::ReadActionParameters()
{
}

CRotateTB::CRotateTB(ApplicationManager * pApp) :Action(pApp)
{}
void CRotateTB::Execute()
{
	RotateTB Bar;
	pManager->Drawtb(&Bar);
}
void CRotateTB::ReadActionParameters()
{
}

CPickTB::CPickTB(ApplicationManager * pApp) :Action(pApp)
{}
void CPickTB::Execute()
{
	PickTB Bar;
	pManager->Drawtb(&Bar);
}
void CPickTB::ReadActionParameters()
{
}