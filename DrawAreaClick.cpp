#include"DrawAreaClick.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
DrawAreaClick::DrawAreaClick(ApplicationManager * pApp) :Action(pApp)
{}
void DrawAreaClick::Execute()
{
		pManager->ClickDrawArea();
}