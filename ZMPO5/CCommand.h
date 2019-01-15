#ifndef CCOM
#define CCOM

#include "CMenuItem.h"

class CCommand
{
public:
	~CCommand();
	virtual void runCommand()=0;
};

#endif CCOM