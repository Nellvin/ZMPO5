#include "AG.h"
#include "Problems.h"
#include "CMenu.h"
#include "CMenuCommand.h"
#include "Commands.cpp"
#include "CMenuItem.h"
#include "Manager.h"

int main()
{
	CManager manager;
	CMenu menu("menuGowne", "menu",&manager);

	CAddItem* addItem = new CAddItem(&manager);
	CMenuCommand *addItemm = new CMenuCommand("Add Item", "ai", *addItem);
	menu.bAdd(*addItemm);

	CShowItems* showItem = new CShowItems(&manager);
	CMenuCommand *showItemm = new CMenuCommand("Show Items", "si", *showItem);
	menu.bAdd(*showItemm);

	CChangeBackpackSize* changeBackpackSize = new CChangeBackpackSize(&manager);
	CMenuCommand *changeBackpackSizee = new CMenuCommand("Change Backapack Size", "cbs", *changeBackpackSize);
	menu.bAdd(*changeBackpackSizee);

	CChangePopSize* changepop = new CChangePopSize(&manager);
	CMenuCommand *changepopp = new CMenuCommand("Change Pop Size", "cp", *changepop);
	menu.bAdd(*changepopp);

	CChangeTemplateType* changeTemplate = new CChangeTemplateType(&manager);
	CMenuCommand *changeTemplatee = new CMenuCommand("Change Template", "ctp", *changeTemplate);
	menu.bAdd(*changeTemplatee);

	CChangeMutProb*  changeMutProb = new CChangeMutProb(&manager);
	CMenuCommand *changeMutProbb = new CMenuCommand("Change Mutt Prob", "cm", *changeMutProb);
	menu.bAdd(*changeMutProbb);

	CChangeCrossProb* changeCrossProb = new CChangeCrossProb(&manager);
	CMenuCommand *changeCrossProbb = new CMenuCommand("Change Cross Prob", "cc", *changeCrossProb);
	menu.bAdd(*changeCrossProbb);

	CChangeRemainingTime* changeTime = new CChangeRemainingTime(&manager);
	CMenuCommand *changeTimee = new CMenuCommand("Change Time", "ct", *changeTime);
	menu.bAdd(*changeTimee);

	CRun* run = new CRun(&manager);
	CMenuCommand *runn = new CMenuCommand("Run", "run", *run);
	menu.bAdd(*runn);


	menu.vRun();
	
/*
	int iPojemnoœæPlecaka = 10;
	int iWielkoœæPopulacji = 50;
	double dPrawdopodobieñstwoKrzy¿owania = 0.6;
	double dPrawdopodobieñstwoMutacji = 0.1;
	int iLiczbaIteracji = 100;



	CKnapsackProblem<double> backpackprob(iPojemnoœæPlecaka);
	backpackprob.vAddItem(4, 5);
	backpackprob.vAddItem(8, 10);
	backpackprob.vAddItem(3, 3);
	backpackprob.vAddItem(5, 2);
	backpackprob.vAddItem(2, 3);

	CGeneticAlgorithm<double> ar(&(backpackprob), iWielkoœæPopulacji, dPrawdopodobieñstwoKrzy¿owania, dPrawdopodobieñstwoMutacji, iLiczbaIteracji,5);
	//ar.vRun();


	system("pause");
	*/
}