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
	void setPojemnoœæPlecaka(int sizePlecak);
	void setWielkoœæPopulacjiu(int pop);
	void setPrawdopodobieñstwoKrzy¿owania(double probkrzyz);
	void setPrawdopodobieñstwoMutacji(double probmut);
	void setCzasDzia³aniaAlgorytmu(int sec);
	int getRodziajProblemu() { return iRodziajProblemu; }
	int  getPojemnoœæPlecaka() {return iPojemnoœæPlecaka;}
	int getWielkoœæPopulacjiu() { return iWielkoœæPopulacji; }
	double getPrawdopodobieñstwoKrzy¿owania() { return dPrawdopodobieñstwoKrzy¿owania; }
	double getPrawdopodobieñstwoMutacji() {return dPrawdopodobieñstwoMutacji;}
	int getCzasDzia³aniaAlgorytmu() { return iCzasDzia³aniaAlgorytmu; }
	void vAddItem(int iSize, double dValue){ przedmioty.push_back(new Item(iSize, dValue)); }
	void vPrintItems();
	double dGetValueItemIndex(int index) { return  przedmioty[index]->dGetValue(); };
	double dGetSizeItemIndex(int index) { return  przedmioty[index]->dGetSize(); };
	int iVectorSize() { return przedmioty.size(); }

private:
	int iRodziajProblemu;
	int iPojemnoœæPlecaka;
	int iWielkoœæPopulacji;
	double dPrawdopodobieñstwoKrzy¿owania;
	double dPrawdopodobieñstwoMutacji;
	int iLiczbaIteracji;
	int iCzasDzia³aniaAlgorytmu;
	vector<Item*>przedmioty;
};
#endif M