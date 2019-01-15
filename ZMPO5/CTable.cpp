//#ifndef CTABLE
//#define CTABLE
#include "CTable.h"

CTable::CTable()
{
	s_name = s_DEFAULT_S_STRING;
	i_size = i_DEFAULT_TAB_LENGHT;
	pi_tab = new int [i_size];
	fill_array();
	cout << "bezp: " << s_name << endl;
	//cout << s_name << get_size() << endl;
}//CTable::CTable()

CTable::CTable(string sName, int iTabLen)
{
	s_name = sName;
	pi_tab = new int[iTabLen];
	i_size = iTabLen;
	fill_array();
	cout << "parametr: " << s_name << endl;
}//CTable::CTable(string sName, int iTabLen)

CTable::CTable(CTable &pcOther)
{
	s_name = pcOther.s_name;
	s_name += "_copy";
	pi_tab = new int[pcOther.i_size];
	for (int i = 0; i < pcOther.i_size; i++) 
	{
		pi_tab[i] = pcOther.pi_tab[i];
	}
	i_size = pcOther.i_size;
	cout << "kopiuj: " << s_name << endl;
}

CTable::~CTable()
{
	cout << "usuwam: " << s_name << endl;
	delete[] pi_tab;
	//itab = NULL;
}
//CTable::CTable(CTable & pcOther)

void CTable::vChangeSize(int isize)
{	
	if (isize < 0)
		if (b_DEBUG) 
			cout << "size can't be smaller than 0";
	int* temp = new int[isize];
	
	for (int i = 0; i < isize && i < i_size; i++) {
		temp[i] = pi_tab[i];
	}
	if (isize > i_size) {
		for (int ii = i_size; ii < isize; ii++ ) {
			temp[ii] = 0;
		}
	}
	i_size = isize;
	delete[] pi_tab;
	pi_tab = temp;

}//void CTable::vChangeSize(int isize)

int CTable::iGetSize()
{
	return i_size;
}//int CTable::iGetSize()

bool CTable::bSetValue(int pos, int value)
{
	if (pos >= i_size || pos < 0) {
		if (b_DEBUG) 
			cout << "podana z³a komórka" << endl;
		return false;
	}
	pi_tab[pos] = value;
	return true;
}//bool CTable::set_value(int pos, int value)

int CTable::iGetValue(int pos)
{
	if (pos >= i_size || pos < 0) {
		if (b_DEBUG)
			cout << "podana z³a komórka" << endl;
		return -1;
	}
	return pi_tab[pos];
}//int CTable::iGetValue(int pos)

void CTable::vSetName(string name)
{
	s_name = name;
}// int CTable::vSetValue(int pos)

string CTable::sGetName()
{
	return s_name;
}

void CTable::vClone(CTable b)
{
	if(pi_tab!=NULL)
		delete[] pi_tab;
	pi_tab= new int [b.iGetSize()];
	i_size = b.iGetSize();
	for (int i = 0; i < i_size; i++)
	{
		pi_tab[i] = b.pi_tab[i];
	}
}//void CTable::clone(CTable b)

int * CTable::pGetArray()
{
	return pi_tab;
}//int * CTable::get_array()

string CTable::sPrint()
{
	string temp = "";

	for (int i = 0; i < i_size; i++) {
		temp = temp + to_string(pi_tab[i]) +", ";
	}
	return s_name + " len: " + to_string(i_size) + " values: " + temp;
}//string CTable::print()

void CTable::fill_array()
{
	for (int i = 0; i < i_size; i++)
	{
		pi_tab[i] = i + 1;
	}
}//int CTable::getSize()


/*
int main() {

	cout << "Hello world" << endl;
	CTable t1 = { "kot", 32 };
	CTable t2 = { "pies", 15 };
	CTable t3;
	t1.change_size(21);
	CTable t4(t1);
	cout << t1.print()<<endl;
	cout << t2.print()<<endl;
	t2.clone(t1);
	cout << t2.print() << endl;
	cin.get();
	return 0;
}//int main()

*/

//#endif CTABLE