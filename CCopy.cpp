#include"CCopy.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
CCopy::CCopy(ApplicationManager * pApp) :Action(pApp)
{}
void CCopy::ReadActionParameters() {
	
}
void CCopy::Execute()
{
	pManager->Copy();

}