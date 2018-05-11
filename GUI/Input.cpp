#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const
{
	string Label = " ";
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
		{

			return "";	//returns nothing as user has cancelled label
		}

		if (Key == 13)	//ENTER key is pressed
		{
			pO->PrintMessage(Label);
			//Label = "Enter key ";
			return Label;
		}
		if (Key == 8)	//BackSpace is pressed
		{
			//Label = "BackSpace";
			if (Label.size() != 0)
				Label.resize(Label.size() - 1);
			//return Label;
		}
		else
			Label += Key;
	}

}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction(int &x,int &y) const
{
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_Line: return DRAW_LINE;
			case ITM_Triangle: return DRAW_TRI;
			case ITM_DRAW_CLR: return CHNG_DRAW_CLR;
			case ITM_FILL_CLR: return CHNG_FILL_CLR;
			case ITM_BK_CLR: return CHNG_BK_CLR;
			case ITM_DEL: return DEL;
			case ITM_MOVE: return MOVE;
			case ITM_RESIZE: return RESIZE;
			case ITM_ROTATE: return ROTATE;
			case ITM_ZOOM_IN: return GET_ZOOM_IN;
			case ITM_ZOOM_OUT: return GET_ZOOM_OUT;
			case ITM_SEND_BACK: return SEND_BACK;
			case ITM_BRNG_FRNT: return BRNG_FRNT;
			case ITM_SAVE: return GET_D_SAVE;
			case ITM_LOAD: return GET_D_LOAD;
			case ITM_EMPTY: return EMPTY;
			case ITM_TO_PLAY: return TO_PLAY;
			case ITM_EXIT: return GET_EXIT;
			case ITM_SELECT: return GET_SELECT;
			case ITM_COPY: return GET_COPY;
			case ITM_CUT: return GET_CUT;
			case ITM_PASTE: return GET_PASTE;
			case ITM_UNDO: return GET_UNDO;
			case ITM_REDO: return GET_REDO;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}

	else if (UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case PICK: return GET_PICK;
			case SCRAMBLE: return GET_SCRAMBLE;
			case SAVE: return GET_SAVE;
			case LOAD: return GET_LOAD;
			case DRAW_TOOL_BAR: return TO_DRAW;
			case EXIT: return GET_EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar*/
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
		return TO_PLAY;	//just for now. This should be updated
	}



	else if (UI.InterfaceMode == MODE_COLOR)
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case Back_TO_DRAW: return TO_DRAW;
			case Blue: return GET_Blue;
			case Red: return GET_Red;
			case Green: return GET_Green;
			case Black: return GET_Black;
			case White: return GET_White;
			case Yellow: return GET_Yellow;
			case Purple: return GET_Purple;
			case Pink: return GET_Pink;
			case Grey: return GET_Grey;
			case Orange: return GET_Orange;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;







	}

	else if (UI.InterfaceMode == MODE_FILL)
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case Back_TO_DRAW: return TO_DRAW;
			case Blue: return GET_FILL_Blue;
			case Red: return GET_FILL_Red;
			case Green: return GET_FILL_Green;
			case Black: return GET_FILL_Black;
			case White: return GET_FILL_White;
			case Yellow: return GET_FILL_Yellow;
			case Purple: return GET_FILL_Purple;
			case Pink: return GET_FILL_Pink;
			case Grey: return GET_FILL_Grey;
			case Orange: return GET_FILL_Orange;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

	}

	else if (UI.InterfaceMode == MODE_BK)
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case Back_TO_DRAW: return TO_DRAW;
			case Blue: return GET_BK_Blue;
			case Red: return GET_BK_Red;
			case Green: return GET_BK_Green;
			case Black: return GET_BK_Black;
			case White: return GET_BK_White;
			case Yellow: return GET_BK_Yellow;
			case Purple: return GET_BK_Purple;
			case Pink: return GET_BK_Pink;
			case Grey: return GET_BK_Grey;
			case Orange: return GET_BK_Orange;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_RESIZE)
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case Go_TO_DRAW: return TO_DRAW;
			case Half: return HALF;
			case Quarter: return QURT;
			case Double: return DOUB;
			case Quadratic: return QUAD;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_ROTATE)
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case Go_Back_TO_DRAW: return TO_DRAW;
			case Ro90: return R90;
			case Ro180: return R180;
			case Ro270: return R270;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PICK)
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case FIG_TYPE: return GET_PICK_TYPE;
			case FIG_FILL_COLOR: return GET_PICK_FILL_COLOR;
			case FIG_TYPE_FILL_COLOR: return GET_PICK_TYPE_FILL_COLOR;
			case FIG_AREA: return GET_PICK_AREA;
			case PLAY_TOOL_BAR: return TO_PLAY;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	

}

/////////////////////////////////

Input::~Input()
{
}
