#ifndef BK_COLORING_H
#define BK_COLORING_H

#include "defs.h"
#include "GUI\Output.h"
class  BKColoring {
public:
	virtual void SetBKcolor() = 0;
	virtual ~BKColoring() {};
};
class BKBlue :public BKColoring
{
public:
	virtual void SetBKcolor();
};
class BKRed :public BKColoring
{
public:
	virtual void SetBKcolor();
};

class BKGreen :public BKColoring
{
public:
	virtual void SetBKcolor();
};

class BKBlack :public BKColoring
{
public:
	virtual void SetBKcolor();
};

class BKWhite :public BKColoring
{
public:
	virtual void SetBKcolor();
};

class BKYellow :public BKColoring
{
public:
	virtual void SetBKcolor();
};

class BKPurple :public BKColoring
{
public:
	virtual void SetBKcolor();
};

class BKPink :public BKColoring
{
public:
	virtual void SetBKcolor();
};

class BKGrey :public BKColoring
{
public:
	virtual void SetBKcolor();
};

class BKOrange :public BKColoring
{
public:
	virtual void SetBKcolor();
};



#endif 
