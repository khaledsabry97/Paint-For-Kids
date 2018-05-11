#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"AddCircle.h"
#include"AddLine.h"
#include"AddTriangle.h"
#include"CLine.h"
#include"CSelect.h"
#include"ChangeColors.h"
#include"DrawTB.h"
#include"DrawAreaClick.h"
#include"EmptyAreaClick.h"
#include"Delete.h"
#include"CSave.h"
#include"SendBack.h"
#include"SendFront.h"
#include"Zoom.h"
#include <fstream>
#include"CMove.h"
#include"Resize.h"
#include "CCopy.h"
#include"CCut.h"
#include"CPaste.h"
#include"CRotate.h"
#include"PickAndHide.h"
#include"ScrambleGame.h"
#include<iostream>
using namespace std;

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output();
	pIn = pOut->CreateInput();

	FigCount = 0;
	CB.count = 0;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
	{
		FigList[i] = NULL;
		CB.Figs[i] = NULL;
	}
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	int x,y;
	return pIn->GetUserAction(x,y);
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		EndZoom();
		pAct = new AddRectAction(this);
		break;

	case DRAW_LINE:
		EndZoom();
		pAct = new AddLine(this);
		break;

	case DRAW_TRI:
		EndZoom();
		pAct = new AddTriangle(this);
		break;

	case DRAW_CIRC:
		EndZoom();
		pAct = new AddCircle(this);
		break;

	case CHNG_DRAW_CLR:
		EndZoom();
		pAct = new CDrawClrTB(this);
		break;
		case GET_Blue:
		pAct = new Blue_COLOR(this);
		break;
		case GET_Red:
		pAct = new Red_COLOR(this);
		break;
		case GET_Green:
		pAct = new Green_COLOR(this);
		break;
		case GET_Black:
		pAct = new Black_COLOR(this);
		break;
		case GET_White:
		pAct = new White_COLOR(this);
		break;
		case GET_Yellow:
		pAct = new Yellow_COLOR(this);
		break;
		case GET_Purple:
		pAct = new Purple_COLOR(this);
		break;
		case GET_Pink:
		pAct = new Pink_COLOR(this);
		break;
		case GET_Grey:
		pAct = new Grey_COLOR(this);
		break;
		case GET_Orange:
		pAct = new Orange_COLOR(this);
		break;

		
	case CHNG_FILL_CLR:
		EndZoom();
		pAct = new CFillClrTB(this);
		break;
		case GET_FILL_Blue:
		pAct = new Fill_Blue_COLOR(this);
		break;
		case GET_FILL_Red:
		pAct = new Fill_Red_COLOR(this);
		break;
		case GET_FILL_Green:
		pAct = new Fill_Green_COLOR(this);
		break;
		case GET_FILL_Black:
		pAct = new Fill_Black_COLOR(this);
		break;
		case GET_FILL_White:
		pAct = new Fill_White_COLOR(this);
		break;
		case GET_FILL_Yellow:
		pAct = new Fill_Yellow_COLOR(this);
		break;
		case GET_FILL_Purple:
		pAct = new Fill_Purple_COLOR(this);
		break;
		case GET_FILL_Pink:
		pAct = new Fill_Pink_COLOR(this);
		break;
		case GET_FILL_Grey:
		pAct = new Fill_Grey_COLOR(this);
		break;
		case GET_FILL_Orange:
		pAct = new Fill_Orange_COLOR(this);
		break;
		
	case CHNG_BK_CLR:
		EndZoom();
		pAct = new CBKClrTB(this);
		break;
		
		case GET_BK_Blue:
		pAct = new BK_Blue_COLOR(this);
		break;
		case GET_BK_Red:
		pAct = new BK_Red_COLOR(this);
		break;
		case GET_BK_Green:
		pAct = new BK_Green_COLOR(this);
		break;
		case GET_BK_Black:
		pAct = new BK_Black_COLOR(this);
		break;
		case GET_BK_White:
		pAct = new BK_White_COLOR(this);
		break;
		case GET_BK_Yellow:
		pAct = new BK_Yellow_COLOR(this);
		break;
		case GET_BK_Purple:
		pAct = new BK_Purple_COLOR(this);
		break;
		case GET_BK_Pink:
		pAct = new BK_Pink_COLOR(this);
		break;
		case GET_BK_Grey:
		pAct = new BK_Grey_COLOR(this);
		break;
		case GET_BK_Orange:
		pAct = new BK_Orange_COLOR(this);
		break;
		case GET_SELECT:
		EndZoom();
		pAct = new Selectfig(this);
		break;

		
		case DEL:
		EndZoom();
		pAct = new Delete(this);
		break;

		case MOVE:
		EndZoom();
		pAct = new CMove(this);
		break;
		case GET_COPY:
			EndZoom();
			pAct = new CCopy(this);
			break;
		case GET_CUT:
			EndZoom();
			pAct = new CCut(this);
			break;
		case GET_PASTE:
			EndZoom();
			pAct = new CPaste(this);
			break;
		case RESIZE:
		EndZoom();
		pAct = new CResizeTB(this);
		break;
		case HALF:
		EndZoom();
		pAct = new ResizeHalf(this);
		break;
		case QURT:
		EndZoom();
		pAct = new ResizeQuart(this);
		break;
		case DOUB:
			EndZoom();
			pAct = new ResizeDoub(this);
			break;
		case QUAD:
			EndZoom();
			pAct = new ResizeQuad(this);
			break;

		case ROTATE:
		EndZoom();
		pAct = new CRotateTB(this);
		break;
		case R90 :
			pAct = new Rotate90(this);
			break;
		case R180:
			pAct = new Rotate180(this);
			break;
		case R270:
			pAct = new Rotate270(this);
			break;
		case SEND_BACK:
			EndZoom();
			pAct = new SendBack(this);
		break;

		case BRNG_FRNT:
			EndZoom();
			pAct = new SendFront(this);
		break;

		case GET_ZOOM_IN:
			pAct = new ZoomIn(this);
			break;

		case GET_ZOOM_OUT:
			pAct = new ZoomOut(this);
			break;

		case GET_PICK :
			EndZoom();
			pAct = new CPickTB(this);
			break;
		case GET_PICK_TYPE:
			pAct = new PickByType(this);
			break;
		case GET_PICK_FILL_COLOR:
			pAct= new PickByColor(this);
			break;
		case GET_PICK_TYPE_FILL_COLOR:
			pAct= new PickByTypeColor(this);
			break;
		case GET_PICK_AREA:
			pAct= new PickByArea(this);
			break;
		case GET_SCRAMBLE:
			pAct= new ScrambleGame(this);
			break;
		
		
		/*
		case LOAD:
				EndZoom();
pAct = new AddRectAction(this);
		break;

		case EXIT:
				EndZoom();
          pAct = new AddRectAction(this);
		break;
		*/
		case DRAWING_AREA:
			EndZoom();
			pAct = new DrawAreaClick(this);
		break;
		
		case EMPTY:
			EndZoom();
			pAct = new EmptyAreaClick(this);
		break;
	case TO_DRAW:
		pAct = new CToDrawTB(this);
		break;


	case TO_PLAY:
				EndZoom();
pAct = new CToPlayTB(this);
		break;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::Drawtb(TB* Bar)
{
	Bar->draw_tb(pOut);
}
void ApplicationManager::AddFigure(CFigure* pFig)
{
	Endsel();
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount++] = pFig;
		FigList[FigCount] = NULL;
	}
}
void ApplicationManager:: AddFigureToList(CFigure* FigCopy[],CFigure* pFig,int N) {
	Endsel();
	if (N < MaxFigCount)
	{
		FigCopy[N++] = pFig;
		FigCopy[N] = NULL;
	}


}
void ApplicationManager::CopyFigList(CFigure* FigCopy[]){
	for (int i = 0; i < FigCount; i++)
	{
		FigCopy[i]=FigList[i]->ACopy();
	}}
void ApplicationManager::DrawFigList(CFigure* FigCopy[],int N) const {
	pOut->ClearDrawArea();
	for (int i = 0; i < N; i++)
	{
		FigCopy[i]->Draw(pOut);
	}
}
void ApplicationManager:: DrawFigLists(CFigure* FigList1[],CFigure* FigList2[],int N,int M) const{
	pOut->ClearDrawArea();
	for (int i = 0; i < N; i++)
	{
		FigList1[i]->Draw(pOut);
	}
	for (int i = 0; i < M; i++)
	{
		FigList2[i]->Draw(pOut);
	}
}
void ApplicationManager:: ResizeFigList(CFigure *FigCopy[],int N){     
	for (int i = 0; i < N; i++)
	{
		FigCopy[i]->Resize(0.5);
	}

}
bool ApplicationManager:: Is_Empty(CFigure* FigCopy[]){
	return (FigCopy[0]==NULL);

} 
CFigure* ApplicationManager::CentreLine() {
	Point P1,P2; GfxInfo info; info.DrawClr=BLACK; info.BorderWdth=2; info.isFilled=false;
	P1.x=UI.width/2; P1.y=UI.ToolBarHeight; P2.x=UI.width/2; P2.y=UI.height-UI.StatusBarHeight;
	CLine *CentreLine=new CLine(P1,P2,info);
	return CentreLine;
}
void ApplicationManager:: Move_To_Left(CFigure* FigCopy[],int N){
	for (int i = 0; i < N; i++)
	{
		FigCopy[i]->To_Left();
	}

}
int ApplicationManager::GetFigCount() const{
	return FigCount;
}
int ApplicationManager::GetMaxFigCount() const {
	return MaxFigCount;
}
CFigure::Type ApplicationManager:: GetFigType(CFigure* FigCopy[],int i,string& T){
	CFigure::Type temp=FigCopy[i]->GetType(); 
	switch (temp)
		{
		case CFigure::Triangle:
			T=" Triangles";
			break;
		case CFigure::Circle:
			T=" Circles";
			break;
		case CFigure::Line:
			T=" Lines";
			break;
		case CFigure::Rectangle:
			T=" Rectangles";
			break;
		default:
			break;
		}
	return temp;
}
bool ApplicationManager:: GetFillClr(CFigure* FigCopy[],int i,color& C, string& T){
	if(FigCopy[i]->Getfillclr(C)) {
		if(BLACK.ucBlue==C.ucBlue&&BLACK.ucGreen==C.ucGreen&&BLACK.ucRed==C.ucRed){
		T="Black";}
		if(WHITE.ucBlue==C.ucBlue&&WHITE.ucGreen==C.ucGreen&&WHITE.ucRed==C.ucRed){
		T="White";}
		if(RED.ucBlue==C.ucBlue&&RED.ucGreen==C.ucGreen&&RED.ucRed==C.ucRed){
		T="Red";}
		if(YELLOW.ucBlue==C.ucBlue&&YELLOW.ucGreen==C.ucGreen&&YELLOW.ucRed==C.ucRed){
		T="Yellow";}
		if(PURPLE.ucBlue==C.ucBlue&&PURPLE.ucGreen==C.ucGreen&&PURPLE.ucRed==C.ucRed){
		T="Purple";}
		if(PINK.ucBlue==C.ucBlue&&PINK.ucGreen==C.ucGreen&&PINK.ucRed==C.ucRed){
		T="Pink";}
		if(BLUE.ucBlue==C.ucBlue&&BLUE.ucGreen==C.ucGreen&&BLUE.ucRed==C.ucRed){
		T="Blue";}
		if(GREEN.ucBlue==C.ucBlue&&GREEN.ucGreen==C.ucGreen&&GREEN.ucRed==C.ucRed){
		T="Green";}
		if(GREY.ucBlue==C.ucBlue&&GREY.ucGreen==C.ucGreen&&GREY.ucRed==C.ucRed){
		T="Grey";}
		if(ORANGE.ucBlue==C.ucBlue&&ORANGE.ucGreen==C.ucGreen&&ORANGE.ucRed==C.ucRed){
		T="Orange";}
		return true;
	}
		else {
		T="Non filled"; return false;
	}

}
int ApplicationManager:: GetFigCountWithSameFillColor(CFigure* FigCopy[],color c,int N){
	color temp;
	int count=0;
	for (int i = 0; i < N; i++)
	{
		if (FigCopy[i]->Getfillclr(temp)){if (temp.ucBlue==c.ucBlue&&temp.ucGreen==c.ucGreen&&temp.ucRed==c.ucRed) {count++;}}
	}
	return count;}

int ApplicationManager:: GetNonFilledFigsCount(CFigure* FigCopy[],int N){
	int count=0; color temp;
		for (int i = 0; i < N; i++)
		{
			if (!FigCopy[i]->Getfillclr(temp)){count++;}
		}
	
	return count;
			}
int ApplicationManager:: GetFigsCountWithSameType(CFigure* FigCopy[],CFigure::Type x,int N) {
	int count=0;
	for (int i = 0; i < N; i++)
	{
	
		if(FigCopy[i]->GetType()==x){count++;}
	}
	return count;
}
int ApplicationManager:: GetfilledFigsCountWithSameColorType(CFigure* FigCopy[],color C,CFigure::Type x,int N) {
	int count=0; color temp;
	for (int i = 0; i < N; i++)
	{
		if(FigCopy[i]->Getfillclr(temp)){
			if(FigCopy[i]->GetType()==x&&C.ucBlue==temp.ucBlue&&C.ucGreen==temp.ucGreen&&C.ucRed==temp.ucRed) {count++;}}
		
	}
	return count;
}
int ApplicationManager:: GetnonfilledFigsCountWithSameType(CFigure* FigCopy[],CFigure::Type x,int N){
	int count=0; color temp;
	for (int i = 0; i < N; i++)
	{
		if(!FigCopy[i]->Getfillclr(temp)&&FigCopy[i]->GetType()==x){count++;}
	}
	return count;

}
void ApplicationManager:: SortFromLargeToSmall(CFigure* FigCopy[],int N){
	CFigure * temp;
	for (int i = 0; i <N; ++i)
    {
		for (int j = i + 1; j < N; ++j)
        {
			if (FigCopy[i]->GetArea() < FigCopy[j]->GetArea())
            {
                temp = FigCopy[i];
                FigCopy[i] = FigCopy[j];
                FigCopy[j] = temp;
            }
        }
	}
}
void ApplicationManager:: SortFromSmallToLarge(CFigure* FigCopy[], int N){

	CFigure * temp;
	for (int i = 0; i <N; ++i)
    {
		for (int j = i + 1; j < N; ++j)
        {
			if (FigCopy[i]->GetArea() > FigCopy[j]->GetArea())
            {
                temp = FigCopy[i];
                FigCopy[i] = FigCopy[j];
                FigCopy[j] = temp;
            }
        }
	}

}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(Point P) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i=FigCount-1; i>=0 ;i--)
	{
		if (FigList[i]->Belong(P))
		{
			return FigList[i];
		}
	}

	///Add your code here to search for a figure given a point x,y	

	return NULL;
}
int ApplicationManager:: GetFigureIndex(CFigure* FigCopy[],int N,Point P){
	for (int i = 0; i < N; i++)
	{
		if (FigCopy[i]->Belong(P))
		{
			return i;
		}
	}

	return -1;  //empty area click

}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Draw(pOut);
	}	//Call Draw function (virtual member fn)
	pOut->SetTempHLCL(UI.HighlightColor);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
 void ApplicationManager::Chdrawcolor(color a)
 {
	 if (FigCount == 0)
	 {
		 UI.DrawColor = a;
		 return;
	 }
	 if (FigSelCount == 0)
	 {
		 UI.DrawColor = a;
		 return;
	 }

 int i = 0;
 while (i<FigCount)
 {
	 if (FigList[i]->IsSelected())
	 {
		 FigList[i]->ChngDrawClr(a);
		 pOut->SetTempHLCL(a);
	 }
 i++;
 }
 }
 void ApplicationManager::Chfillcolor(color a)
 {
	 if (FigCount == 0)
		 return;
 int i = 0;
 if (FigSelCount == 0)
 {
	 pOut->PrintMessage("Please Select a figure first");
	 return;
 }

 while (i<FigCount)
 {
	 if (FigList[i]->IsSelected())
	 {
		 FigList[i]->ChngFillClr(a);
		 pOut->SetTempHLCL(FigList[i]->Getdrawclr());
	 }
 i++;
 }
 }
 void ApplicationManager::Chbkcolor(color a)
 {
		 pOut->ChangebkColor(a);
 }
 void ApplicationManager::Sel(CFigure* a)
 {
	 if (a->IsSelected())
	 {
		 a->SetSelected(false);
		 FigSelCount--;
	 }
	 else
	 {
		 a->SetSelected(true);
		 FigSelCount++;
	 }
 }
 void ApplicationManager::Endsel()
 {
	 for (int i = 0; i < FigCount; i++)
	 {
		 FigList[i]->SetSelected(false);
	 }
	 FigSelCount = 0;
	 UpdateInterface();
 }
 void ApplicationManager::ClickDrawArea()
 {
	 Endsel();
	
	 pOut->PrintMessage("A click on drawing area.Unselect all figures if exists");
 }
 void ApplicationManager::ClickEmptyArea()
 {
	 Endsel();
	 pOut->PrintMessage("A click on empty area.Unselect all figures if exists");
 }
 void ApplicationManager::Deletefig()
 {
	 if (FigCount == 0)
	 {
		 pOut->PrintMessage("No Figures drawn");
		 return;
	 }
	 if (FigSelCount==0)
	 {
		 pOut->PrintMessage("No selected figures");
		 return;
	 }

	 int i = 0;
	 if (FigCount == 1)
	 {
		 FigCount--;
		 delete FigList[i];
		 FigList[i] = NULL;
		 return;
	 }
	 while (i<FigCount)
	 {
		 if (!FigList[i]->IsSelected())
		 {
			 i++;
		 }
		 else{
			 delete FigList[i];
			 FigList[i] = NULL;
			 for (int k = i; k < FigCount-1; k++)
			 {
				 FigList[k] = FigList[k + 1];
			 }
			 FigCount--;
		 }
	 }
 }
 void ApplicationManager::DeleteFromList(CFigure* FigCopy[],int i,int &N)
 {
	 
			 delete FigCopy[i];
			 FigCopy[i] = NULL;
			 for (int k = i; k < N-1; k++)
			 {
				 FigCopy[k] = FigCopy[k + 1];
			 }
			N--;
}
	 
 void ApplicationManager:: DeleteFigureList(CFigure *FigCopy[],int N){

	 for (int i = 0; i < N; i++)
			{
				delete FigCopy[i];
			}
			
			delete[] FigCopy;
 }

 
 void ApplicationManager::SendtoFront()
 {
	 if (FigCount == 0)
	 {
		 pOut->PrintMessage("No drawn figures");
		 return;
	 }
	 if (FigSelCount == 0)
	 {
		 pOut->PrintMessage("No selected figures");
		 return;
	 }

	 int finalfree = FigCount - 1;
	 if (FigCount == 1)
	 {
		 	 Endsel();
			 return;
	 }
	 for (int i = FigCount - 1; i >= 0; i--)
	 {
		 if (FigList[i]->IsSelected())
		 {
			 for (int k = i; k < finalfree; k++)
			 {
				 CFigure* temp = FigList[k];
				 FigList[k] = FigList[k + 1];
				 FigList[k + 1] = temp;
			 }
			 finalfree--;
		 }
	 }
	 Endsel();
 }
 /*void ApplicationManager:: SendFirstFigtoFront(CFigure* FigCopy[],int N){
	 int finalfree = N - 1; cout<<"as"<<endl;
			 for (int k = 0; k < finalfree; k++)
			 {
				 CFigure* temp = FigCopy[k];
				 FigCopy[k] = FigCopy[k + 1];
				 FigCopy[k + 1] = temp;
			 }

 }*/

 void ApplicationManager::SendtoBack()
 {
	 if (FigCount == 0)
	 {
		 pOut->PrintMessage("No drawn figures");
		 return;
	 }
	 if (FigSelCount == 0)
	 {
		 pOut->PrintMessage("No selected figures");
		 return;
	 }

	 int firstfree = 0;
	 if (FigCount == 1)
	 {
		 
			 Endsel();
			 return;
	 }
	 for (int i = 0; i < FigCount; i++)
	 {
		 if (FigList[i]->IsSelected())
		 {
			 for (int k = i; k > firstfree; k--)
			 {
				 CFigure* temp = FigList[k-1];
				 FigList[k-1] = FigList[k];
				 FigList[k] = temp;
			 }
			 firstfree++;
		 }
	 }
	 Endsel();
 }
 void ApplicationManager::Move(Point P)
 {
	 if (FigCount == 0)
	 {
		 pOut->PrintMessage("No drawn figures");
		 return;
	 }
	 if (FigSelCount == 0)
	 {
		 pOut->PrintMessage("No selected figures");
		 return;
	 }

	 if (FigCount == 1)
	 {
		 FigList[0]->Move(P);
		 Endsel();
		 return;
	 }
	 int i = 0;
	 Point Rel;
	 while( i < FigCount)
	 {
		 if (FigList[i]->IsSelected())
		 {
			 Rel= FigList[i]->GetMainPoint();
			 FigList[i]->Move(P);
			 i++;
			 break;
		 }
		 i++;
	 }
	 if (FigSelCount == 1)
	 {
		 Endsel();
		 return;
	 }
	 else
	 {
		 Point temp;
		 while ( i < FigCount)
		 {
			 if (FigList[i]->IsSelected())
			 {
				 temp.x = FigList[i]->GetMainPoint().x + (P.x - Rel.x);
				 temp.y = FigList[i]->GetMainPoint().y + (P.y - Rel.y);
				 FigList[i]->Move(temp);
			 }
			 i++;
		 }
	 }
	 Endsel();
 }
 void ApplicationManager:: RandomMove(CFigure* FigCopy[],int N){
	 for (int i = 0; i < N; i++)
	 {
		 FigCopy[i]->RandomMove();
	 }
 }

 void ApplicationManager::Resize(float a)
 {
	 if (FigCount == 0)
	 {
		 pOut->PrintMessage("No drawn figures");
		 return;
	 }
	 if (FigSelCount == 0)
	 {
		 pOut->PrintMessage("No selected figures");
		 return;
	 }
	 if (FigCount == 1)
	 {
		 FigList[0]->Resize(a);
		 Endsel();
		 return;
	 }
	 for (int i = 0; i < FigCount; i++)
	 {
		 if (FigList[i]->IsSelected())
		 {
			 FigList[i]->Resize(a);
		 }
	 }
	 Endsel();
 }
 void ApplicationManager::Zoom(float x)
 {
	 Endsel();
	 for (int i = 0; i < FigCount; i++)
	 {
		 FigList[i]->Zoom(x);
	 }
 }
 void ApplicationManager::EndZoom()
 {
	 for (int i = 0; i < FigCount; i++)
	 {
		 FigList[i]->EndZoom();
	 }
 }
 void ApplicationManager::Paste(Point P)
 {
	 Endsel();
	 for (int i = 0; i < CB.count; i++)
	 {
		 AddFigure(CB.Figs[i]);
		 FigList[FigCount - 1] = CB.Figs[i]->Paste(P);
	 }
	 Endsel();
 }
 void ApplicationManager::Copy()
 {
	 while (CB.count != 0)
	 {
		 delete CB.Figs[--CB.count];
		 CB.Figs[CB.count] = NULL;
	 }
	 if (FigCount == 0)
	 {
		 pOut->PrintMessage("No drawn figures");
		 return;
	 }
	 if (FigSelCount == 0)
	 {
		 pOut->PrintMessage("No selected figures");
		 return;
	 }

	 if (FigCount == 1)
	 {
		 CB.Figs[0] = FigList[0]->ACopy();
		 CB.count++;
		 Endsel();
		 return;
	 }
	 for (int i = 0; i < FigCount; i++)
	 {
		 if (FigList[i]->IsSelected())
		 {
			 CB.Figs[CB.count++] = FigList[i]->ACopy();
			 
		 }
	 }
	 Endsel();
 }
 void ApplicationManager::Cut()
 {
	 while (CB.count != 0)
	 {
		 delete CB.Figs[--CB.count];
		 CB.Figs[CB.count] = NULL;
	 }
	 if (FigCount == 0)
	 {
		 pOut->PrintMessage("No drawn figures");
		 return;
	 }
	 if (FigSelCount == 0)
	 {
		 pOut->PrintMessage("No selected figures");
		 return;
	 }

	 if (FigCount == 1)
	 {
		 CB.Figs[CB.count++] = FigList[0];
		 FigCount--;
		 Endsel();
		 return;
	 }
	 int i = 0;
	 while (i<FigCount)
	 {
		 if (!FigList[i]->IsSelected())
		 {
			 i++;
		 }
		 else {
			 CB.Figs[CB.count++] = FigList[i];
			for (int k = i; k < FigCount - 1; k++)
			 {
				 FigList[k] = FigList[k + 1];
			 }
			 FigCount--;
		 }
	 }
	 Endsel();
 }
 void ApplicationManager::Rotate(int x)
 {
	 if (FigCount == 0)
	 {
		 pOut->PrintMessage("No drawn figures");
		 return;
	 }
	 if (FigSelCount == 0)
	 {
		 pOut->PrintMessage("No selected figures");
		 return;
	 }
	 if (FigCount == 1)
	 {
		 FigList[0]->Rotate(x);
		 Endsel();
		 return;
	 }
	 for (int i = 0; i < FigCount; i++)
	 {
		 if (FigList[i]->IsSelected())
		 {
			 FigList[i]->Rotate(x);
		 }
	 }
	 Endsel();
 }
