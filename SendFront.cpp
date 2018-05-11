#include"SendFront.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
SendFront::SendFront(ApplicationManager * pApp) :Action(pApp)
{}
void SendFront::Execute()
{
	pManager->SendtoFront();
}