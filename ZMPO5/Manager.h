#ifndef M
#define M
#pragma once
#include <string>
#include "Problems.h"
#include <iostream>
#define BOOLPROBLEM 1
#define INTPROBLEM 2
#define DOUBLEPROBLEM 3

class CManager
{
public:
	CManager();
	~CManager();
	void setRodziajProblemu(int problem);
	void setPojemno��Plecaka(int sizePlecak);
	void setWielko��Populacjiu(int pop);
	void setPrawdopodobie�stwoKrzy�owania(double probkrzyz);
	void setPrawdopodobie�stwoMutacji(double probmut);
	void setCzasDzia�aniaAlgorytmu(int sec);
	int getRodziajProblemu() { return iRodziajProblemu; }
	int  getPojemno��Plecaka() {return iPojemno��Plecaka;}
	int getWielko��Populacjiu() { return iWielko��Populacji; }
	double getPrawdopodobie�stwoKrzy�owania() { return dPrawdopodobie�stwoKrzy�owania; }
	double getPrawdopodobie�stwoMutacji() {return dPrawdopodobie�stwoMutacji;}
	int getCzasDzia�aniaAlgorytmu() { return iCzasDzia�aniaAlgorytmu; }
	void vAddItem(int iSize, double dValue){ przedmioty.push_back(new Item(iSize, dValue)); }
	void vPrintItems();
	double dGetValueItemIndex(int index) { return  przedmioty[index]->dGetValue(); };
	double dGetSizeItemIndex(int index) { return  przedmioty[index]->dGetSize(); };
	int iVectorSize() { return przedmioty.size(); }

private:
	int iRodziajProblemu;
	int iPojemno��Plecaka;
	int iWielko��Populacji;
	double dPrawdopodobie�stwoKrzy�owania;
	double dPrawdopodobie�stwoMutacji;
	int iLiczbaIteracji;
	int iCzasDzia�aniaAlgorytmu;
	vector<Item*>przedmioty;
};
#endif M