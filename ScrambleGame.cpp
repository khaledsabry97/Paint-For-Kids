#include "ScrambleGame.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include<iostream>
ScrambleGame::ScrambleGame(ApplicationManager * pApp) :Action(pApp)
{}
void ScrambleGame::Execute()
{
    Input* Pin=pManager->GetInput();
	Output* Pout=pManager->GetOutput();
	pManager->UpdateInterface();
	int N=pManager->GetFigCount();
	int M=N+1;
	int Valid=0,InValid=0;
	int TotalPicks;
	double ValidPercentage;
	Pout->PrintMessage("Find Highlghted Figures On Right Side! ");  
	if(pManager->GetFigCount()!=0){
	CFigure** FigureCopy=new CFigure*[pManager->GetMaxFigCount()];
	CFigure** RandomFigureCopy=new CFigure*[pManager->GetMaxFigCount()];
	pManager->CopyFigList(RandomFigureCopy);
	pManager->CopyFigList(FigureCopy);
	pManager->ResizeFigList(RandomFigureCopy,N);
	pManager->Move_To_Left(FigureCopy,N);
	pManager->AddFigureToList(FigureCopy,pManager->CentreLine(),N);      //add centre line to Fig Copy list
	int x,y; Point P;
	pManager->RandomMove(RandomFigureCopy,N);
	ActionType Action;
	while (!pManager->Is_Empty(RandomFigureCopy)){	
	pManager->Sel(FigureCopy[0]);
	//pManager->SendFirstFigtoFront(FigureCopy,N);
	pManager->DrawFigLists(RandomFigureCopy,FigureCopy,N,M);
	Action=Pin->GetUserAction(x,y);
		if(Action==DRAWING_AREA){
		P.x=x; P.y=y;
		int i=pManager->GetFigureIndex(RandomFigureCopy,N,P);
				cout<<i<<endl;

		    if(i==-1) {pManager->Sel(FigureCopy[0]);}    
		    else if (i==0){   Valid++;
				    Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ", InValid );  
					pManager->DeleteFromList(FigureCopy,0,M);
					pManager->DeleteFromList(RandomFigureCopy,0,N);
					pManager->DrawFigLists(RandomFigureCopy,FigureCopy,N,M);
			}
			else
			{		InValid++; pManager->Sel(FigureCopy[0]);
			Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ",InValid);
			}
			}
		else if (Action==STATUS) {pManager->Sel(FigureCopy[0]);}
		else { 
			pManager->DeleteFigureList(FigureCopy,M);
			pManager->DeleteFigureList(RandomFigureCopy,N);
			pManager->ExecuteAction(Action);   return;}
	}
	TotalPicks= Valid + InValid;
	ValidPercentage=(Valid/double(TotalPicks))*100;
	Pout->PrintGrade("You got ",ValidPercentage, " % Correct!!");
	pManager->DeleteFigureList(FigureCopy,M);
	pManager->DeleteFigureList(RandomFigureCopy,N);
	pManager->ExecuteAction(Pin->GetUserAction(x,y));
	}
	else {Pout->PrintMessage("No figures Drawn to play!");}
}