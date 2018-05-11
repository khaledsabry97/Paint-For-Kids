#include "PickAndHide.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include <iostream>

PickByType::PickByType(ApplicationManager * pApp) :Action(pApp)
{}
void PickByType::Execute()
{
	Input* Pin=pManager->GetInput();
	Output* Pout=pManager->GetOutput();
	int Valid=0,InValid=0;
	int TotalPicks; 	double ValidPercentage;
	int N=pManager->GetFigCount();
	pManager->UpdateInterface();
	if(pManager->GetFigCount()!=0){
	CFigure** FigureCopy=new CFigure*[pManager->GetMaxFigCount()];
	pManager->CopyFigList(FigureCopy);
	int x,y; Point P;
	int figureTypecount=0, figureIndex=-1;
	string T;
	ActionType Action;
		Pout->PrintMessage("Pick a figure to start playing!");
		do {
		Action=Pin->GetUserAction(x,y);
		if(Action==DRAWING_AREA){
		P.x=x; P.y=y;
		int i=pManager->GetFigureIndex(FigureCopy,N,P);
		figureIndex=i;}
		else if (Action==STATUS) {figureIndex=-1;}
		else { 
			pManager->DeleteFigureList(FigureCopy,N);
			pManager->ExecuteAction(Action);   return;}}
		while (figureIndex==-1);
		CFigure::Type temp=pManager->GetFigType(FigureCopy,figureIndex,T); 
		pManager->DeleteFromList(FigureCopy,figureIndex,N);
		pManager->DrawFigList(FigureCopy,N);
		Pout->PrintMessage_string("Good! Now Pick all",T);
		figureTypecount=pManager->GetFigsCountWithSameType(FigureCopy,temp,N);
	while(figureTypecount!=0){
	Action=Pin->GetUserAction(x,y);
		if(Action==DRAWING_AREA){
		P.x=x; P.y=y;
		int i=pManager->GetFigureIndex(FigureCopy,N,P);
		            if(i==-1) {}
					else if(pManager->GetFigType(FigureCopy,i,T)==temp){
					Valid++;
				    Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ", InValid );  
					pManager->DeleteFromList(FigureCopy,i,N);
					pManager->DrawFigList(FigureCopy,N); figureTypecount--;}
		            else 
		            {
			          InValid++;
			          Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ",InValid);}
		            }

		else if (Action==STATUS) {}
		else { 
			pManager->DeleteFigureList(FigureCopy,N);
			pManager->ExecuteAction(Action);   return;}
	}
	
	TotalPicks= Valid + InValid;
	if(TotalPicks==0){Pout->PrintMessage("Oops! it was just one figure with same type :(");}              //Handling division by 0
	else {ValidPercentage=(Valid/double(TotalPicks))*100;
	Pout->PrintGrade("You got ",ValidPercentage, " % Correct!!");}
	pManager->DeleteFigureList(FigureCopy,N);
	pManager->ExecuteAction(Pin->GetUserAction(x,y));}
	else {Pout->PrintMessage("No Figures Drawn to play!");}
}
PickByColor::PickByColor(ApplicationManager * pApp) :Action(pApp)
{}
void PickByColor::Execute()
{
	Input* Pin=pManager->GetInput();
	Output* Pout=pManager->GetOutput();
	int Valid=0,InValid=0;
	int TotalPicks; double ValidPercentage;
	int N=pManager->GetFigCount(); 	
	pManager->UpdateInterface();
	if(pManager->GetFigCount()!=0){
	CFigure** FigureCopy=new CFigure*[pManager->GetMaxFigCount()];
	pManager->CopyFigList(FigureCopy);
	color c, temp; 
	int x,y; Point P;
	int filledcount=0,nonfilledcount=0,figureIndex=-1;
	string clr;
	ActionType Action;
	Pout->PrintMessage("Pick a figure to start playing!");
		do {
		Action=Pin->GetUserAction(x,y);
		if(Action==DRAWING_AREA){
		P.x=x; P.y=y;
		int i=pManager->GetFigureIndex(FigureCopy,N,P);
		figureIndex=i;}
		else if (Action==STATUS) {figureIndex=-1;}
		else { 
			pManager->DeleteFigureList(FigureCopy,N);
			pManager->ExecuteAction(Action);   return;}}
		while (figureIndex==-1);
		if(pManager->GetFillClr(FigureCopy,figureIndex,c,clr)){
			pManager->DeleteFromList(FigureCopy,figureIndex,N);
		filledcount=pManager->GetFigCountWithSameFillColor(FigureCopy,c,N);}
		else {pManager->DeleteFromList(FigureCopy,figureIndex,N);
        nonfilledcount=pManager->GetNonFilledFigsCount(FigureCopy,N);}
		pManager->DrawFigList(FigureCopy,N);
	clr+=" Figures!";
	Pout->PrintMessage_string("Good! Now Pick all ",clr);
	while(filledcount!=0||nonfilledcount!=0){
	Action=Pin->GetUserAction(x,y);
		if(Action==DRAWING_AREA){
		P.x=x; P.y=y;
		int i=pManager->GetFigureIndex(FigureCopy,N,P);
		if(filledcount>0){
		            if(i==-1) {}
					else if(pManager->GetFillClr(FigureCopy,i,temp,clr)){
						if(c.ucBlue==temp.ucBlue&&c.ucGreen==temp.ucGreen&&c.ucRed==temp.ucRed){
					Valid++;
				    Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ", InValid ); 
					pManager->DeleteFromList(FigureCopy,i,N);
					pManager->DrawFigList(FigureCopy,N); filledcount--;}
						else{
					          InValid++;
			                  Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ",InValid);
						}
					}
		            else 
		            {
			          InValid++;
			          Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ",InValid);
					}
		            }
				
		if(nonfilledcount>0){
			if(i==-1) {}
			else if(!pManager->GetFillClr(FigureCopy,i,temp,clr)){
					Valid++;
				    Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ", InValid ); 
 					pManager->DeleteFromList(FigureCopy,i,N);
			        pManager->DrawFigList(FigureCopy,N); nonfilledcount--;
			}
			else {InValid++;
			Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ",InValid);}
				}
		}
			
		else if (Action==STATUS) {}
		else {
		pManager->DeleteFigureList(FigureCopy,N);
		pManager->ExecuteAction(Action); return;}
	}
	TotalPicks= Valid + InValid;
	if(TotalPicks==0){Pout->PrintMessage("Oops! it was just one figure with same color :(");}              //Handling division by 0
	else {ValidPercentage=(Valid/double(TotalPicks))*100;
	Pout->PrintGrade("You got ",ValidPercentage, " % Correct!!");}
	pManager->DeleteFigureList(FigureCopy,N);
	pManager->ExecuteAction(Pin->GetUserAction(x,y));
	}
	else {Pout->PrintMessage("No Figures Drawn to play!");}
}
PickByTypeColor::PickByTypeColor(ApplicationManager * pApp) :Action(pApp)
{}
void PickByTypeColor::Execute()
{
	Input* Pin=pManager->GetInput();
	Output* Pout=pManager->GetOutput();
	int Valid=0,InValid=0;
	int TotalPicks;
	int N=pManager->GetFigCount();
	pManager->UpdateInterface();
	double ValidPercentage;
	if(pManager->GetFigCount()!=0){
	CFigure** FigureCopy=new CFigure*[pManager->GetMaxFigCount()];
	pManager->CopyFigList(FigureCopy);
	int x,y; Point P; color C; color tempC;
	int filledTypecount=0, nonfilledTypecount=0, figureIndex=-1;
	string T , clr;
	ActionType Action;
	Pout->PrintMessage("Pick a figure to start playing!");
		do {
		Action=Pin->GetUserAction(x,y);
		if(Action==DRAWING_AREA){
		P.x=x; P.y=y;
		int i=pManager->GetFigureIndex(FigureCopy,N,P);
		figureIndex=i;}
		else if (Action==STATUS) {figureIndex=-1;}
		else { 
			pManager->DeleteFigureList(FigureCopy,N);
			pManager->ExecuteAction(Action);   return;}}
		while (figureIndex==-1);
		CFigure::Type type=pManager->GetFigType(FigureCopy,figureIndex,T); 
		if(pManager->GetFillClr(FigureCopy,figureIndex,C,clr)){
			pManager->DeleteFromList(FigureCopy,figureIndex,N);
			filledTypecount=pManager->GetfilledFigsCountWithSameColorType(FigureCopy,C,type,N);}
		else{
			pManager->DeleteFromList(FigureCopy,figureIndex,N);
			nonfilledTypecount=pManager->GetnonfilledFigsCountWithSameType(FigureCopy,type,N);}
		pManager->DrawFigList(FigureCopy,N);
		string typecolor=clr+T;
		Pout->PrintMessage_string("Good! Now Pick all ",typecolor);
		while(filledTypecount!=0||nonfilledTypecount!=0){
	    Action=Pin->GetUserAction(x,y);
		if(Action==DRAWING_AREA){
		P.x=x; P.y=y;
		int i=pManager->GetFigureIndex(FigureCopy,N,P);
		  if(filledTypecount>0){
		        if(i==-1){}
				else if(pManager->GetFillClr(FigureCopy,i,tempC,clr)){
					if(C.ucBlue==tempC.ucBlue&&C.ucGreen==tempC.ucGreen&&C.ucRed==tempC.ucRed&&(pManager->GetFigType(FigureCopy,i,T)==type)){
					Valid++;
				    Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ", InValid );  
					pManager->DeleteFromList(FigureCopy,i,N);
					pManager->DrawFigList(FigureCopy,N); filledTypecount--;}
					else {InValid++;
			              Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ",InValid);;}
				}
				else {
					InValid++;
			        Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ",InValid);}
				}
		  if(nonfilledTypecount>0){
			  if(i==-1){}
			  else if(!pManager->GetFillClr(FigureCopy,i,tempC,clr)&&(pManager->GetFigType(FigureCopy,i,T)==type)){
					Valid++;
				    Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ", InValid );
					pManager->DeleteFromList(FigureCopy,i,N);
			        pManager->DrawFigList(FigureCopy,N); nonfilledTypecount--;
			}
			  else {InValid++;
			Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ",InValid);}
		  
		  }}
		else if (Action==STATUS) {}
		else {	
		pManager->DeleteFigureList(FigureCopy,N);
		pManager->ExecuteAction(Action); return;}
		}
	TotalPicks= Valid + InValid; 
	if(TotalPicks==0){Pout->PrintMessage("Oops! it was just one figure with same color and type :(");}              //Handling division by 0
	else {ValidPercentage=(Valid/double(TotalPicks))*100;
	Pout->PrintGrade("You got ",ValidPercentage, " % Correct!!");}
	pManager->DeleteFigureList(FigureCopy,N);
	pManager->ExecuteAction(Pin->GetUserAction(x,y));
	}
	else {Pout->PrintMessage("No Figures Drawn to play!");}
}
PickByArea::PickByArea(ApplicationManager * pApp) :Action(pApp)
{}
void PickByArea::Execute()
{
	Input* Pin=pManager->GetInput();
	Output* Pout=pManager->GetOutput();
	int Valid=0 , InValid=0;
	double TotalPicks; 	double ValidPercentage; int figureIndex=-1;
	int N=pManager->GetFigCount();
	pManager->UpdateInterface();
	if(pManager->GetFigCount()!=0){
	CFigure** FigureCopy=new CFigure*[pManager->GetMaxFigCount()];
	pManager->CopyFigList(FigureCopy);
	pManager->SortFromLargeToSmall(FigureCopy,N);      	//sorting array of Fig. Copy by Areas in descending order
	int x,y; Point P;
	ActionType Action;
	Pout->PrintMessage("Pick the largest or smallest figure to start playing!");
		do {
		Action=Pin->GetUserAction(x,y);
		if(Action==DRAWING_AREA){
		P.x=x; P.y=y;
		int i=pManager->GetFigureIndex(FigureCopy,N,P);
		figureIndex=i;}
		else if (Action==STATUS) {figureIndex=-1;}
		else { 
			pManager->DeleteFigureList(FigureCopy,N);
			pManager->ExecuteAction(Action);   return;}}
		while (figureIndex!=0 && figureIndex!=N-1);           //not largest or smallest
		if(figureIndex==0){Pout->PrintMessage("Good! Now Pick Figures from Largest to Smallest!");}
		else {pManager->SortFromSmallToLarge(FigureCopy,N); Pout->PrintMessage("Good! Now Pick Figures from Smallest to Largest!");}
	pManager->DeleteFromList(FigureCopy,0,N);
	pManager->DrawFigList(FigureCopy,N);
	while(!pManager->Is_Empty(FigureCopy)){
		Action=Pin->GetUserAction(x,y);
		if(Action==DRAWING_AREA){
		P.x=x; P.y=y;
		int i=pManager->GetFigureIndex(FigureCopy,N,P);
		if(i==-1){}
		else if(i==0) {
			Valid++;
		    Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ", InValid );  
			pManager->DeleteFromList(FigureCopy,0,N);
			pManager->DrawFigList(FigureCopy,N);}
		else {
			InValid++;
			Pout->PrintPicks("Correct Picks = ",Valid,"Wrong Picks = ",InValid);}
		}
		else if (Action==STATUS) {}
		else {
			pManager->DeleteFigureList(FigureCopy,N);
			pManager->ExecuteAction(Action); return;}
		}
	TotalPicks=Valid+InValid;
	if(TotalPicks==0){Pout->PrintMessage("Oops! it was just one drawn figure :(");}              //Handling division by 0
	else {ValidPercentage=(Valid/double(TotalPicks))*100;
	Pout->PrintGrade("You got ",ValidPercentage, " % Correct!!");}
	pManager->DeleteFigureList(FigureCopy,N);
	pManager->ExecuteAction(Pin->GetUserAction(x,y));
	}
	else {Pout->PrintMessage("No Figures Drawn to play!");}
}

