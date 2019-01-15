#pragma once
#include <string>
#include <iostream>
#include "Manager.h"
#define BOOLPROBLEM 1
#define INTPROBLEM 2
#define DOUBLEPROBLEM 3
//#include "CMenu.h"

using namespace std;

class CMenuItem
{
protected:
	string s_command;
	string s_name;
	string s_path;
	CMenuItem *p_parent;
public:
	//CMenuItem();
	virtual ~CMenuItem()=0;
	CMenuItem(string name, string command);
	CMenuItem(string name, string command, CManager * man);
	virtual void vRun()=0;
	virtual void vRun(string p);

	string sGetCommand();
	void vSetCommand(string command);
	string sGetName();
	void vSetName(string name);
	string sGetPath();
	void vSetPath(string pat);
	CMenuItem* cGetParent();
	void vSetParent(CMenuItem * parent);

	virtual string sGetHelp()=0;
	virtual void vPrintHelp()=0;
	
	virtual bool vFindCommand(string command) { return(false); };
	virtual void vPrintTree()=0;
	virtual void vPrintCMenuItem() = 0;
	//virtual void vChangeRoot(string s_new_root)=0;
	virtual bool bAdd(CMenuItem &cmi)=0;

	CManager* pManag;

	int iRodziajProblemu = BOOLPROBLEM;
	int iPojemnoœæPlecaka = 10;
	int iWielkoœæPopulacji = 50;
	double dPrawdopodobieñstwoKrzy¿owania = 0.6;
	double dPrawdopodobieñstwoMutacji = 0.1;
	int iLiczbaIteracji = 100;
	int iCzasDzia³aniaAlgorytmu = 10;
};