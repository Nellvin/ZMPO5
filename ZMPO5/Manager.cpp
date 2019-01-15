#include "Manager.h"

CManager::CManager() 
{
	iRodziajProblemu = INTPROBLEM;
	iPojemnoœæPlecaka = 10;
	iWielkoœæPopulacji = 50;
	dPrawdopodobieñstwoKrzy¿owania = 0.6;
	dPrawdopodobieñstwoMutacji = 0.1;
	iLiczbaIteracji = 100;
	iCzasDzia³aniaAlgorytmu = 10;
}

CManager::~CManager()
{
	for (int i = 0; i < przedmioty.size(); i++)
	{
		delete przedmioty[i];
	}
}

void CManager::setRodziajProblemu(int problem)
{
	iRodziajProblemu = problem;
}

void CManager::setPojemnoœæPlecaka(int sizePlecak)
{
	iPojemnoœæPlecaka = sizePlecak;
}

void CManager::setWielkoœæPopulacjiu(int pop)
{
	iWielkoœæPopulacji = pop;
}

void CManager::setPrawdopodobieñstwoKrzy¿owania(double probkrzyz)
{
	dPrawdopodobieñstwoKrzy¿owania = probkrzyz;
}

void CManager::setPrawdopodobieñstwoMutacji(double probmut)
{
	dPrawdopodobieñstwoMutacji = probmut;
}

void CManager::setCzasDzia³aniaAlgorytmu(int sec)
{
	iCzasDzia³aniaAlgorytmu = sec;
}

void CManager::vPrintItems()
{
	for (int i = 0; i < przedmioty.size(); i++)
	{
		cout << "wartosc: " << przedmioty[i]->dGetValue() << " wielkosc: " << przedmioty[i]->dGetSize() << endl;
	}
	system("pause");

}

