#include"ToolBars.h"
void DrawClrTB::draw_tb(Output* pOut)
{
	pOut->CreateColorToolBar();
}
void FillClrTB::draw_tb(Output* pOut)
{
	pOut->CreateFillColorToolBar();
}
void BKClrTB::draw_tb(Output* pOut)
{
	pOut->CreatebkColorToolBar();
}
void ToDrawTB::draw_tb(Output* pOut)
{
	pOut->CreateDrawToolBar();
}
void ToPlayTB::draw_tb(Output* pOut)
{
	pOut->CreatePlayToolBar();
}
void ResizeTB::draw_tb(Output* pOut)
{
	pOut->CreateResizeToolBar();
}
void RotateTB::draw_tb(Output* pOut)
{
	pOut->CreateRotateToolBar();
}
void PickTB::draw_tb(Output* pOut)
{
	pOut->CreatePickToolBar();
}