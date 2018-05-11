#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 54;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.TempHLCL = UI.HighlightColor;
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


						//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}
void Output::ChangebkColor(color a)
{
	pWind->SetBrush(a);
	pWind->SetPen(a, 1);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height);
}
//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearToolBar() const
{
	pWind->SetPen(UI.ToolBarHeight, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

}

//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_Line] = "images\\MenuItems\\Line 3.jpg";
	MenuItemImages[ITM_Triangle] = "images\\MenuItems\\Triangle.jpg";
	MenuItemImages[ITM_DRAW_CLR] = "images\\MenuItems\\color.jpg";
	MenuItemImages[ITM_FILL_CLR] = "images\\MenuItems\\filling color.jpg";
	MenuItemImages[ITM_BK_CLR] = "images\\MenuItems\\background color.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\delete-image.jpg";

	MenuItemImages[ITM_COPY] = "images\\MenuItems\\copy-icon.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Cut-icon.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Paste-icon.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Undo-icon.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Redo-icon.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\resize.jpg";
	MenuItemImages[ITM_ROTATE] = "images\\MenuItems\\rotate.jpg";
	MenuItemImages[ITM_ZOOM_IN] = "images\\MenuItems\\Zoom-In.jpg";
	MenuItemImages[ITM_ZOOM_OUT] = "images\\MenuItems\\Zoom-Out.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Select-icon.jpg";
	MenuItemImages[ITM_SEND_BACK] = "images\\MenuItems\\send to.jpg";
	MenuItemImages[ITM_BRNG_FRNT] = "images\\MenuItems\\ToFront.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\upload.jpg";
	MenuItemImages[ITM_TO_PLAY] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[PICK] = "images\\MenuItems\\Menue_PickAndHide.jpg";
	MenuItemImages[SCRAMBLE] = "images\\MenuItems\\Menue_ScrambleAndFind.jpg";
	MenuItemImages[SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[LOAD] = "images\\MenuItems\\upload.jpg";
	MenuItemImages[DRAW_TOOL_BAR] = "images\\MenuItems\\draw.jpg";
	MenuItemImages[EXIT] = "images\\MenuItems\\Menu_Exit.jpg";




	//Draw menu item one image at a time
	for (int i = 0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void Output::CreatePickToolBar() const{

	UI.InterfaceMode=MODE_PICK;
	ClearToolBar();
	string MenuItemImages[PICK_ITM_COUNT];
	MenuItemImages[FIG_TYPE] = "images\\MenuItems\\figuretype.jpg";
	MenuItemImages[FIG_FILL_COLOR] = "images\\MenuItems\\filling color.jpg";
	MenuItemImages[FIG_TYPE_FILL_COLOR] = "images\\MenuItems\\fillingtype.jpg";
	MenuItemImages[FIG_AREA] = "images\\MenuItems\\area.jpg";
	MenuItemImages[PLAY_TOOL_BAR] = "images\\MenuItems\\play.jpg";
	//Draw menu item one image at a time
	for (int i = 0; i<PICK_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateColorToolBar() const
{
	UI.InterfaceMode = MODE_COLOR;
	///TODO: write code to create Play mode menu
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[Back_TO_DRAW] = "images\\MenuItems\\draw.jpg";
	MenuItemImages[Blue] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[Red] = "images\\MenuItems\\red.jpg";
	MenuItemImages[Green] = "images\\MenuItems\\Green.jpg";
	MenuItemImages[Black] = "images\\MenuItems\\black.jpg";
	MenuItemImages[White] = "images\\MenuItems\\white.jpg";
	MenuItemImages[Yellow] = "images\\MenuItems\\Yellow.jpg";
	MenuItemImages[Purple] = "images\\MenuItems\\Purple.jpg";
	MenuItemImages[Pink] = "images\\MenuItems\\pink.jpg";
	MenuItemImages[Grey] = "images\\MenuItems\\grey.jpg";
	MenuItemImages[Orange] = "images\\MenuItems\\orange.jpg";


	//Draw menu item one image at a time
	for (int i = 0; i<COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::CreateFillColorToolBar() const
{
	UI.InterfaceMode = MODE_FILL;
	///TODO: write code to create Play mode menu
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[Back_TO_DRAW] = "images\\MenuItems\\draw.jpg";
	MenuItemImages[Blue] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[Red] = "images\\MenuItems\\red.jpg";
	MenuItemImages[Green] = "images\\MenuItems\\Green.jpg";
	MenuItemImages[Black] = "images\\MenuItems\\black.jpg";
	MenuItemImages[White] = "images\\MenuItems\\white.jpg";
	MenuItemImages[Yellow] = "images\\MenuItems\\Yellow.jpg";
	MenuItemImages[Purple] = "images\\MenuItems\\Purple.jpg";
	MenuItemImages[Pink] = "images\\MenuItems\\pink.jpg";
	MenuItemImages[Grey] = "images\\MenuItems\\grey.jpg";
	MenuItemImages[Orange] = "images\\MenuItems\\orange.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i<COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::CreatebkColorToolBar() const
{
	UI.InterfaceMode = MODE_BK;
	///TODO: write code to create Play mode menu
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[Back_TO_DRAW] = "images\\MenuItems\\draw.jpg";
	MenuItemImages[Blue] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[Red] = "images\\MenuItems\\red.jpg";
	MenuItemImages[Green] = "images\\MenuItems\\Green.jpg";
	MenuItemImages[Black] = "images\\MenuItems\\black.jpg";
	MenuItemImages[White] = "images\\MenuItems\\white.jpg";
	MenuItemImages[Yellow] = "images\\MenuItems\\Yellow.jpg";
	MenuItemImages[Purple] = "images\\MenuItems\\Purple.jpg";
	MenuItemImages[Pink] = "images\\MenuItems\\pink.jpg";
	MenuItemImages[Grey] = "images\\MenuItems\\grey.jpg";
	MenuItemImages[Orange] = "images\\MenuItems\\orange.jpg";


	//Draw menu item one image at a time
	for (int i = 0; i<COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::CreateResizeToolBar() const
{
	UI.InterfaceMode = MODE_RESIZE;
	///TODO: write code to create Play mode menu
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[Resize_ITM_COUNT];
	MenuItemImages[Go_TO_DRAW] = "images\\MenuItems\\draw.jpg";
	MenuItemImages[Half] = "images\\MenuItems\\half.jpg";
	MenuItemImages[Quarter] = "images\\MenuItems\\quarter.jpg";
	MenuItemImages[Double] = "images\\MenuItems\\double.jpg";
	MenuItemImages[Quadratic] = "images\\MenuItems\\quadratic.jpg";
	//Draw menu item one image at a time
	for (int i = 0; i<Resize_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

void Output::CreateRotateToolBar() const
{
	UI.InterfaceMode = MODE_ROTATE;
	///TODO: write code to create Play mode menu
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[Rotate_ITM_COUNT];
	MenuItemImages[Go_Back_TO_DRAW] = "images\\MenuItems\\draw.jpg";
	MenuItemImages[Ro90] = "images\\MenuItems\\R90.jpg";
	MenuItemImages[Ro180] = "images\\MenuItems\\R180.jpg";
	MenuItemImages[Ro270] = "images\\MenuItems\\R270.jpg";
	//Draw menu item one image at a time
	for (int i = 0; i<Rotate_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage_string(string msg, string m) const
{
	ClearStatusBar();	//First clear the status bar
	string msgs = msg + m;
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msgs);

}
void Output:: PrintPicks(string msg1 , int Valid,string msg2,int InValid) const
{
	ClearStatusBar();
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg1);
	pWind->DrawInteger(135, UI.height - (int)(UI.StatusBarHeight / 1.5), Valid);
	pWind->DrawString(150, UI.height - (int)(UI.StatusBarHeight / 1.5), msg2);
	pWind->DrawInteger(270, UI.height - (int)(UI.StatusBarHeight / 1.5), InValid);
}

void Output:: PrintGrade(string msg1 , double Percent , string msg2) const
{
	ClearStatusBar();
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg1);
	pWind->DrawDouble(75, UI.height - (int)(UI.StatusBarHeight / 1.5), Percent);
	pWind->DrawString(160, UI.height - (int)(UI.StatusBarHeight / 1.5), msg2);
}

//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//
void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.TempHLCL;
	else
		DrawingClr = TriGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, TriGfxInfo.BorderWdth);
	drawstyle style;

	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);



}

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.TempHLCL; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.TempHLCL; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (LineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LineGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawCircle(Point P1, int radius, GfxInfo CirGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.TempHLCL;
	else
		DrawingClr = CirGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CirGfxInfo.BorderWdth);

	drawstyle style;

	if (CirGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CirGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(P1.x, P1.y, radius, style);



}



//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

void Output::SetTempHLCL(color a)
{
	UI.TempHLCL = a;
}