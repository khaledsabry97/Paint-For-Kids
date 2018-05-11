#ifndef TOOL_BARS_H
#define TOOL_BARS_H
#include "defs.h"
#include "GUI\Output.h"
class TB {
public:
	virtual void draw_tb(Output* pOut) = 0;
	virtual~TB() {};
};
class DrawClrTB :public TB {
public:
	virtual void draw_tb(Output* pOut);
};
class FillClrTB :public TB {
public:
	virtual void draw_tb(Output* pOut);
};
class BKClrTB :public TB {
public:
	virtual void draw_tb(Output* pOut);
};
class ToDrawTB : public TB {
public:
	virtual void draw_tb(Output* pOut);
};
class ToPlayTB : public TB {
public:
	virtual void draw_tb(Output* pOut);
};
class ResizeTB : public TB {
public:
	virtual void draw_tb(Output* pOut);
};
class RotateTB : public TB {
public:
	virtual void draw_tb(Output* pOut);
};
class PickTB : public TB {
public:
	virtual void draw_tb(Output* pOut);
};

#endif 
