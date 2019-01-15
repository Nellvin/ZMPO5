#pragma once
#include "CCommand.h"
#include "CMenuItem.h"
#define DEFAULT_HELP "pomagam" 

class CMenuCommand : public CMenuItem
{
	std::string s_help;
public:
	CMenuCommand(string name, string ccommad, CCommand &command) :CMenuItem(name, ccommad) {
		p_command = &command; s_help = DEFAULT_HELP;};
	CMenuCommand(string name, string ccommad) :CMenuItem(name, ccommad) { s_help = DEFAULT_HELP; };
	CMenuCommand(string name, string ccommad,string help) :CMenuItem(name, ccommad) { s_help = help; };
	~CMenuCommand();
	CCommand* p_command;
	void vRun();
	void vRun(string p);
	void vPrintHelp();
	string sGetHelp();
	bool vFindCommand(string command) { return false; };
	void vPrintTree() { cout << "nothing" << endl; };
	void vPrintCMenuItem();
	void vChangeRoot(string s_new_root) { };
	bool bAdd(CMenuItem &cmi) { return false; };

};