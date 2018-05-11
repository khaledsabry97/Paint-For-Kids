#include"SendBack.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
SendBack::SendBack(ApplicationManager * pApp) :Action(pApp)
{}
void SendBack::Execute()
{
	pManager->SendtoBack();
}