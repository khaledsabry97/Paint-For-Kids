#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include"ToolBars.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
	struct ClipBoard {
		CFigure* Figs[MaxFigCount];
		int count;
	};
private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)						
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	int FigSelCount;
	ClipBoard CB;
public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it
	void Sel(CFigure* a);
									// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	void AddFigureToList(CFigure* FigCopy[],CFigure* pFig,int N);   //Adds a new figure to a list
	int GetFigCount() const;
	int GetMaxFigCount() const;
	CFigure::Type GetFigType(CFigure* FigCopy[],int i,string& T);          //returns figure type at index i as string
	bool GetFillClr(CFigure* FigCopy[],int i,color& C, string& T);               //returns Figure fill color at index i and count all figures with same color
	int GetFigCountWithSameFillColor(CFigure* FigCopy[],color c,int N);     //returns number of figures in list with same color
	int GetNonFilledFigsCount(CFigure* FigCopy[],int N);                    //returns number of non filled figures in list
	int GetFigsCountWithSameType(CFigure* FigCopy[],CFigure::Type x,int N) ; //returns number of figures in list with same type
	int GetfilledFigsCountWithSameColorType(CFigure* FigCopy[],color C,CFigure::Type x,int N) ; //returns number of filled figures in list with same type and color
	int GetnonfilledFigsCountWithSameType(CFigure* FigCopy[],CFigure::Type x,int N) ; //returns number of non filled figures in list with same type
	void SortFromLargeToSmall(CFigure* FigCopy[],int N);          //by area
	void SortFromSmallToLarge(CFigure*FigCopy[],int N);
	void CopyFigList(CFigure* FigCopy[]);
	void DrawFigList(CFigure* FigCopy[],int N) const; //draws a list of figures
	void DrawFigLists(CFigure* FigList1[],CFigure* FigList2[],int N,int M) const;  //draws 2 figure lists at same time
	CFigure* CentreLine() ; //returns s a line to divide screen
	void Move_To_Left(CFigure *FigCopy[],int N);
	void ResizeFigList(CFigure *FigCopy[],int N);    //resize figures to half
	CFigure *GetFigure(Point P) const; //Search for a figure given a point inside the figure
	int GetFigureIndex(CFigure* FigCopy[],int N,Point P);       //Search for a figure in a list given a point inside the figure and return its index
	void Drawtb(TB* Bar);
	void Chdrawcolor(color a);
	void Chfillcolor(color a);
	void Chbkcolor(color a);
	void Endsel();
	void Deletefig();
	void DeleteFromList(CFigure* FigCopy[],int i,int& N);
	void DeleteFigureList(CFigure *FigCopy[],int N);
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void ClickDrawArea();
	void ClickEmptyArea();
	void SendtoFront();
	void SendFirstFigtoFront(CFigure* FigCopy[], int N);
	void SendtoBack();
	void Move(Point P);
	void RandomMove(CFigure* FigCopy[],int N);
	void Resize(float a);
	void Zoom(float x);
	void EndZoom();
	void Paste(Point P);
	void Copy();
	void Cut();
	void Rotate(int x);
	bool Is_Empty(CFigure* FigCopy[]);       //checks if a list is empty
};


#endif