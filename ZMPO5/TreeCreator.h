#pragma once
#include "CMenuItem.h"
#include "CMenu.h"
#include "CMenuCommand.h"

using namespace std;

class TreeCreator
{
public:
	CMenu * CreateTree(string path, bool& error);
	CMenu * cCreateMenu(string& path, int& pos, bool& error, string & error_message);
	CMenuItem * cCreateCommand(string& path, int& pos, bool& error, string & error_message);
};