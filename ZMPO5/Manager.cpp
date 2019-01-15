#include "Manager.h"

CManager::CManager() 
{
	iRodziajProblemu = INTPROBLEM;
	iPojemno��Plecaka = 10;
	iWielko��Populacji = 50;
	dPrawdopodobie�stwoKrzy�owania = 0.6;
	dPrawdopodobie�stwoMutacji = 0.1;
	iLiczbaIteracji = 100;
	iCzasDzia�aniaAlgorytmu = 10;
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

void CManager::setPojemno��Plecaka(int sizePlecak)
{
	iPojemno��Plecaka = sizePlecak;
}

void CManager::setWielko��Populacjiu(int pop)
{
	iWielko��Populacji = pop;
}

void CManager::setPrawdopodobie�stwoKrzy�owania(double probkrzyz)
{
	dPrawdopodobie�stwoKrzy�owania = probkrzyz;
}

void CManager::setPrawdopodobie�stwoMutacji(double probmut)
{
	dPrawdopodobie�stwoMutacji = probmut;
}

void CManager::setCzasDzia�aniaAlgorytmu(int sec)
{
	iCzasDzia�aniaAlgorytmu = sec;
}

void CManager::vPrintItems()
{
	for (int i = 0; i < przedmioty.size(); i++)
	{
		cout << "wartosc: " << przedmioty[i]->dGetValue() << " wielkosc: " << przedmioty[i]->dGetSize() << endl;
	}
	system("pause");

}

