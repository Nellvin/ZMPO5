#ifndef CTABLE
#define CTABLE
#include <iostream>
#include <string>

#define b_DEBUG false
#define i_DEFAULT_TAB_LENGHT 10
#define s_DEFAULT_S_STRING "Domyslny Kot"

using namespace std;

class CTable
{

public:

	CTable();
	CTable(string sName, int iTabLen);
	CTable(CTable &pcOther);
	~CTable();

	void vChangeSize(int isize);
	int iGetSize();
	bool bSetValue(int pos, int value);
	int iGetValue(int pos);
	void vSetName(string name);
	string sGetName();
	void vClone(CTable b);
	int* pGetArray();
	string sPrint();
	int* pi_tab;

private:

	string s_name;
	
	int i_size;
	void fill_array();

};//class CTable

#endif CTABLE