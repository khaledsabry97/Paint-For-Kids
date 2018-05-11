#include"CCut.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
CCut::CCut(ApplicationManager * pApp) :Action(pApp)
{}
void CCut::ReadActionParameters() {

}
void CCut::Execute()
{
	pManager->Cut();
}