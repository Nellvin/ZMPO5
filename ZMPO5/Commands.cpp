//#ifndef Commands
//#define Commands
#include "CCommand.h"
#include "CTable.h"
#include "Manager.h"
#include "AG.h"
#include <vector>
#include <cstdlib>

class CChangeRemainingTime : public CCommand
{
public:
	CChangeRemainingTime(CManager* man) { pMM = man; }
private:
	void runCommand()
	{
		int iTime;

		cout << "Podaj dlgosc dzialania algorytmu: " ;
		cin >> iTime;
		cin.good();
		cin.clear();
		cin.sync();
		//cin.ignore(1000, "/n");

		if (iTime < 1 || iTime>60)
		{
			cout << "podano zla dlugosc " ;
			system("pause");
		}
		else
			pMM->setCzasDzia³aniaAlgorytmu(iTime);
	}
	CManager* pMM;
};

class CAddItem : public CCommand
{
public:
	
	CAddItem(CManager* man) { pMM = man; }
private:
	void runCommand()
	{
		double dValue;
		double dSize;

		cout << "Podaj wartosc przedmiotu: " ;
		cin >> dValue;
		cin.clear();

		cout << "Podaj rozmiar przedmiotu: " ;
		cin >> dSize;
		cin.clear();
		if(dValue>0&&dSize>0)
			pMM->vAddItem(dSize, dValue);
	}
	
	CManager* pMM;
};

class CShowItems : public CCommand
{
public:

	CShowItems(CManager* man) { pMM = man; }
private:
	void runCommand()
	{
		pMM->vPrintItems();
	}

	CManager* pMM;
};

class CChangePopSize : public CCommand
{
public:
	CChangePopSize(CManager* man) { pMM = man; }
private:
	void runCommand()
	{
		int iPopSize;

		cout << "Podaj wielkosc populacji: ";
		cin >> iPopSize;
		cin.clear();

		if (iPopSize < 2 || iPopSize>1000)
		{
			cout << "podano zla dlugosc " << endl;
			system("pause");
		}
		else
			pMM->setWielkoœæPopulacjiu(iPopSize);
	}
	CManager* pMM;
};

class CChangeBackpackSize : public CCommand
{
public:
	CChangeBackpackSize(CManager* man) { pMM = man; }
private:
	void runCommand()
	{
		int iBackpackSize;

		cout << "Podaj Pakownoœæ plecaka: ";
		cin >> iBackpackSize;
		cin.clear();

		if (iBackpackSize < 1 || iBackpackSize>1000)
		{
			cout << "podano zla dlugosc " << endl;
			system("pause");
		}
		else
			pMM->setPojemnoœæPlecaka(iBackpackSize);
	}
	CMenuItem* pMainMenu;
	CManager* pMM;
};

class CChangeTemplateType : public CCommand
{
public:
	CChangeTemplateType(CManager* man) { pMM = man; }
private:
	void runCommand()
	{
		string sType;

		cout << "Podaj Typ Wzorca: ";
		cin >> sType;

		if (sType == "int") 
		{
			pMM->setRodziajProblemu(INTPROBLEM);
		}
		else if (sType == "bool")
		{
			pMM->setRodziajProblemu(BOOLPROBLEM);
		}
		else if (sType == "double")
		{
			pMM->setRodziajProblemu(DOUBLEPROBLEM);
		}
		else
		{
			cout << "Podano neprawidlowy typ" << endl;
		}
	}
	CManager* pMM;
};

class CChangeMutProb : public CCommand
{
public:
	CChangeMutProb(CManager* man) { pMM = man; }
private:
	void runCommand()
	{
		double dMutProb;

		cout << "Podaj Prawdopodobienstwo Mutowania: ";
		cin >> dMutProb;
		cin.clear();

		if (dMutProb < 0 || dMutProb>1)
		{
			cout << "podano zla dlugosc " << endl;
			system("pause");
		}
		else
			pMM->setPrawdopodobieñstwoMutacji(dMutProb);
	}
	CManager* pMM;
};

class CChangeCrossProb : public CCommand
{
public:
	CChangeCrossProb(CManager* man) { pMM = man; }
private:
	void runCommand()
	{
		double dCrossProb;

		cout << "Podaj Prawdopodobienstwo Krzyzowania1: ";
		
		cin >> dCrossProb;
		if (cin.fail())
			dCrossProb = 0.1; 
		cin.clear();

		if (dCrossProb < 0 || dCrossProb>1)
		{
			cout << "podano zla dlugosc " << endl;
			system("pause");
		}
		else
			pMM->setPrawdopodobieñstwoKrzy¿owania(dCrossProb);
	}
	CManager* pMM;
};

class CRun : public CCommand
{
public:
	CRun(CManager* man) { pMM = man; }
private:
	void runCommand()
	{
		if (pMM->getRodziajProblemu() == INTPROBLEM)
		{
			CKnapsackProblem<int> backpackprob(pMM->getPojemnoœæPlecaka());
			for (int i = 0; i < pMM->iVectorSize(); i++) {
				backpackprob.vAddItem(pMM->dGetSizeItemIndex(i), pMM->dGetValueItemIndex(i));
			}
			CGeneticAlgorithm<int> ar(&(backpackprob), pMM->getWielkoœæPopulacjiu(), pMM->getPrawdopodobieñstwoKrzy¿owania(), pMM->getPrawdopodobieñstwoMutacji(),10, pMM->getCzasDzia³aniaAlgorytmu());
			ar.vRun();
		}
		if (pMM->getRodziajProblemu() == DOUBLEPROBLEM)
		{
			CKnapsackProblem<double> backpackprob(pMM->getPojemnoœæPlecaka());
			
			for (int i = 0; i < pMM->iVectorSize(); i++) {
				backpackprob.vAddItem(pMM->dGetSizeItemIndex(i), pMM->dGetValueItemIndex(i));
			}
			CGeneticAlgorithm<double> ar(&(backpackprob), pMM->getWielkoœæPopulacjiu(), pMM->getPrawdopodobieñstwoKrzy¿owania(), pMM->getPrawdopodobieñstwoMutacji(), 10, pMM->getCzasDzia³aniaAlgorytmu());
			ar.vRun();
		}
		if (pMM->getRodziajProblemu() == BOOLPROBLEM)
		{
			CKnapsackProblem<bool> backpackprob(pMM->getPojemnoœæPlecaka());
			for (int i = 0; i < pMM->iVectorSize(); i++) {
				backpackprob.vAddItem(pMM->dGetSizeItemIndex(i), pMM->dGetValueItemIndex(i));
			}
			CGeneticAlgorithm<bool> ar(&(backpackprob), pMM->getWielkoœæPopulacjiu(), pMM->getPrawdopodobieñstwoKrzy¿owania(), pMM->getPrawdopodobieñstwoMutacji(), 10, pMM->getCzasDzia³aniaAlgorytmu());
			ar.vRun();
		}
		system("pause");
	}
	CMenuItem* pMainMenu;
	CManager* pMM;
};

//#endif Commands