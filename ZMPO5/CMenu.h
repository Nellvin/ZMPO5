#pragma once
#include "CMenuItem.h"
#include <vector>
#include <string>
#define DEBUGE false


using namespace std;

class CMenu : public CMenuItem
{
protected:
	std::vector<CMenuItem*> v_list;

public:
	CMenu(string name, string command) :CMenuItem(name, command) {};
	CMenu(string name, string command, CManager* man) :CMenuItem(name, command,man) {};
	~CMenu();
	void vRun();
	void vRun(string p);
	void vPrint();
	bool bAdd(CMenuItem &cmi);
	bool bHelp(string command);
	string sGetHelp() { return ""; };
	void vPrintHelp() {};
	void vSearch(string command);
	CMenuItem * pFindRoot();
	bool vFindCommand(string command);
	void vPrintTree();
	void vPrintCMenuItem();
	void vChangeRoot(string s_new_root,CMenuItem& new_root );
	CMenuItem* vChangeRoot(string s_new_root);
	};