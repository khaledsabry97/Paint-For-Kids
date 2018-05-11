#include "ApplicationManager.h"

int main()
{

	ActionType ActType;

	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();
		
		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();	

	}while(ActType != GET_EXIT);
	

	
	return 0;
}

