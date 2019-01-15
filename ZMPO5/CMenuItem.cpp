#include "CMenuItem.h"

CMenuItem::~CMenuItem()
{
	//cout << "USUWANIE CMENUITEM " << sGetName() << endl;
}

CMenuItem::CMenuItem(string name, string command)
{
	s_command = command;
	s_name = name;
	p_parent = NULL;
	s_path = name;
	//cout << p_parent;
}

CMenuItem::CMenuItem(string name, string command, CManager* man)
{
	s_command = command;
	s_name = name;
	p_parent = NULL;
	s_path = name;
	pManag = man;
	//cout << p_parent;
}

void CMenuItem::vRun(string p)
{
	cout << "" << endl;
}

string CMenuItem::sGetCommand()
{
	return s_command;
}

void CMenuItem::vSetCommand(string command)
{
	s_command = command;
}

string CMenuItem::sGetName()
{
	return s_name;
}

void CMenuItem::vSetName(string name)
{
	s_name = name;
}

string CMenuItem::sGetPath()
{
	return s_path;
}

void CMenuItem::vSetPath(string pat)
{
	s_path = pat;
}

CMenuItem * CMenuItem::cGetParent()
{
	if(p_parent!=NULL)
		return p_parent;
	return NULL;
}

void CMenuItem::vSetParent(CMenuItem * parent)
{
	if(this!=NULL)
	p_parent = parent;
	//p_parent = this;
}



