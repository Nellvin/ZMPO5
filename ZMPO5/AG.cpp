#include "AG.h"

#ifndef AG
#define AG

template <>
CIndividual<bool>::CIndividual(int iSizeGenotype,double dCrossProbb, double dMutProbb)
{
	//cout << "Tworzenie INDIV" << endl;

	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(0, 1);

	for (int i = 0; i < iSizeGenotype; i++)
	{
		int genn = dis(gen);
		genotype.push_back(genn);
		if (DEBUGE) cout << genn<<",";
	}
	dCrossProb = dCrossProbb;
	dMutProb = dMutProbb;
}

template <>
CIndividual<int>::CIndividual(int iSizeGenotype, double dCrossProbb, double dMutProbb)
{
	//cout << "Tworzenie INDIV" << endl;

	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(0, MAX_GENERATE_OF_ITEM);

	for (int i = 0; i < iSizeGenotype; i++)
	{
		int genn = dis(gen);
		genotype.push_back(genn);
		if (DEBUGE) cout << genn << ",";
	}
	dCrossProb = dCrossProbb;
	dMutProb = dMutProbb;
}

template <>
CIndividual<double>::CIndividual(int iSizeGenotype, double dCrossProbb, double dMutProbb)
{
	//cout << "Tworzenie INDIV" << endl;

	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(0, MAX_GENERATE_OF_ITEM*1000);

	for (int i = 0; i < iSizeGenotype; i++)
	{
		double genn = dis(gen);
		genotype.push_back(genn/1000);
		if (DEBUGE) cout << genn / 1000 << ",";
	}
	dCrossProb = dCrossProbb;
	dMutProb = dMutProbb;
}

template <class T>
CIndividual<T>::~CIndividual()
{
	//cout << "Usuwanie Idiv" << endl;
}

template <class T>
CIndividual<T>::CIndividual(CIndividual<T> & cIndivToCopy)
{
	//cout << "Tworzenie INDIV" << endl;

	for (int i = 0; i < cIndivToCopy.genotype.size(); i++)
	{
		//if (DEBUGE) cout << "przepisywanie " << i << endl;
		genotype.push_back(cIndivToCopy.genotype[i]);
	}
	dMutProb = cIndivToCopy.dMutProb;
	dCrossProb = cIndivToCopy.dCrossProb;
}


template <>
void CIndividual<bool>::vMuteIndividual(double dMutProbb)
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(0, 999);

	for (int i = 0; i < genotype.size(); i++)
	{
		if (dis(gen) < (dMutProbb * 1000))
		{
			if (genotype[i] == 0)
				genotype[i] = 1;
			else
				genotype[i] = 0;
		}
	}
}

template <>
void CIndividual<int>::vMuteIndividual(double dMutProbb)
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(0, 999);
	uniform_int_distribution<> change(-MUT_RANGE, MUT_RANGE);
		
	for (int i = 0; i < genotype.size(); i++)
	{
		if (dis(gen) < (dMutProbb * 1000))
		{
			genotype[i] = genotype[i] + change(gen);
			if (genotype[i] < 0)
				genotype[i] = 0;
		}
	}
}

template <>
void CIndividual<double>::vMuteIndividual(double dMutProbb)
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(0, 999);
	uniform_int_distribution<> change(-MUT_RANGE*1000, MUT_RANGE*1000);

	for (int i = 0; i < genotype.size(); i++)
	{
		if (dis(gen) < (dMutProbb * 1000))
		{
			genotype[i] = genotype[i] + change(gen)/1000;
			if (genotype[i] < 0)
				genotype[i] = 0;
		}
	}
}

template <class T>
bool CIndividual<T>::cCrossIndividuals(CIndividual<T> & two, vector<CIndividual<T>*>* tabOfPopulation, double dMutProbb, int* populationSize)
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	if (DEBUGE) cout << "GENOTYPE SIZE" << genotype.size() << endl;
	uniform_int_distribution<> dis(1, genotype.size() - 1);

	int iHowManyGenotypeToStayFromFirstGenotype = dis(gen);

	CIndividual<T>* newIndv1 = new CIndividual<T>(this->genotype.size(),dCrossProb,dMutProb);
	CIndividual<T>* newIndv2 = new CIndividual<T>(this->genotype.size(), dCrossProb, dMutProb);

	for (int i = 0; i < iHowManyGenotypeToStayFromFirstGenotype; i++)
	{
		if (DEBUGE) cout << "Miejsce przeciecia" << iHowManyGenotypeToStayFromFirstGenotype << endl;
		newIndv1->genotype[i] = this->genotype[i];
		newIndv2->genotype[i] = two.genotype[i];
	}
	for (int i = iHowManyGenotypeToStayFromFirstGenotype; i < genotype.size(); i++)
	{
		newIndv2->genotype[i] = this->genotype[i];
		newIndv1->genotype[i] = two.genotype[i];
	}
	//newIndv1->vMuteIndividual(dMutProbb);
	//newIndv2->vMuteIndividual(dMutProbb);

	(*newIndv1)++;
	(*newIndv2)++;
	if (tabOfPopulation->size() < *populationSize)
		tabOfPopulation->push_back(newIndv1);
	else
		delete newIndv1;

	if (tabOfPopulation->size() < *populationSize)
		tabOfPopulation->push_back(newIndv2);
	else
		delete newIndv2;

	delete &two;
	delete this;

	return false;
}
template <class T>
bool CIndividual<T>::cAnotherCrossIndividuals(CIndividual<T> & two, vector<CIndividual<T>*>* tabOfPopulation, double dMutProbb, int* populationSize)
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(0, 1);

	CIndividual<T>* newIndv1 = new CIndividual<T>(this->genotype.size(), dCrossProb, dMutProb);
	CIndividual<T>* newIndv2 = new CIndividual<T>(this->genotype.size(), dCrossProb, dMutProb);

	for (int i = 0; i < genotype.size(); i++)
	{
		if(dis(gen)==0)
		{
			newIndv1->genotype[i] = this->genotype[i];
			newIndv2->genotype[i] = two.genotype[i];
		}
		else
		{
			newIndv2->genotype[i] = this->genotype[i];
			newIndv1->genotype[i] = two.genotype[i];
		}
	}
	(*newIndv1)++;
	(*newIndv2)++;
	if (tabOfPopulation->size() < *populationSize)
		tabOfPopulation->push_back(newIndv1);
	else
		delete newIndv1;

	if (tabOfPopulation->size() < *populationSize)
		tabOfPopulation->push_back(newIndv2);
	else
		delete newIndv2;

	delete &two;
	delete this;

	return false;
}
template<class T>
double CIndividual<T>::iGetValueIndexGenotype(int iIndexx)
{
	if (DEBUGE) cout << "getvalue0000" << genotype[iIndexx] << endl;
	return genotype[iIndexx];
	
}

template<>
void CIndividual<bool>::operator++(int)
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(0, 999);

	for (int i = 0; i < genotype.size(); i++)
	{
		if (dis(gen) < (dMutProb * 1000))
		{
			if (genotype[i] == 0)
				genotype[i] = 1;
			else
				genotype[i] = 0;
		}
	}

}

template<class T>
CIndividual<T>& CIndividual<T>::operator+(CIndividual<T>& two)
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	if (DEBUGE) cout << "GENOTYPE SIZE" << genotype.size() << endl;
	uniform_int_distribution<> dis(1, genotype.size() - 1);

	int iHowManyGenotypeToStayFromFirstGenotype = dis(gen);

	CIndividual<T>* newIndv1 = new CIndividual<T>(this->genotype.size(), dCrossProb, dMutProb);

	for (int i = 0; i < iHowManyGenotypeToStayFromFirstGenotype; i++)
	{
		if (DEBUGE) cout << "Miejsce przeciecia" << iHowManyGenotypeToStayFromFirstGenotype << endl;
		newIndv1->genotype[i] = this->genotype[i];
	}
	for (int i = iHowManyGenotypeToStayFromFirstGenotype; i < genotype.size(); i++)
	{
		newIndv1->genotype[i] = two.genotype[i];
	}
	//newIndv1->vMuteIndividual(dMutProbb);
	//newIndv2->vMuteIndividual(dMutProbb);

	(*newIndv1)++;

	delete &two;
	delete this;

	return *newIndv1;
	
	
	
	// TODO: insert return statement here
}
template<>
void CIndividual<int>::operator++(int)
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(0, 999);
	uniform_int_distribution<> change(-MUT_RANGE, MUT_RANGE);

	for (int i = 0; i < genotype.size(); i++)
	{
		if (dis(gen) < (dMutProb * 1000))
		{
			genotype[i] = genotype[i] + change(gen);
			if (genotype[i] < 0)
				genotype[i] = 0;
		}
	}

}
template<>
void CIndividual<double>::operator++(int)
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(0, 999);
	uniform_int_distribution<> change(-MUT_RANGE * 1000, MUT_RANGE * 1000);

	for (int i = 0; i < genotype.size(); i++)
	{
		if (dis(gen) < (dMutProb * 1000))
		{
			genotype[i] = genotype[i] + change(gen) / 1000;
			if (genotype[i] < 0)
				genotype[i] = 0;
		}
	}

}
/*
template<>
double CIndividual<bool>::iGetValueIndexGenotype(int iIndexx)
{
	cout << "getvalue1111" << genotype[iIndexx] << endl;
	cout << "getvalue1111" << genotype[iIndexx] << endl;
	return genotype[iIndexx];

}
*/

template <>
CGeneticAlgorithm<int>::CGeneticAlgorithm()
{
	
}
template <>
CGeneticAlgorithm<bool>::CGeneticAlgorithm()
{
	
}
template <>
CGeneticAlgorithm<double>::CGeneticAlgorithm()
{
	
}

template <class T>
CGeneticAlgorithm<T>::CGeneticAlgorithm(CProblem<T> * problem)
{
	iPopSize = DEFAULT_POP_SIZE;
	dCrossProb = DEFAULT_CROSS_PROB;
	dMutProb = DEFAULT_MUT_PROB;
	pointerOnProblem = problem;
	iSizeOfGenetype = problem->iGetSizeOfIndividualArray();
	iIterations = DEAFAULT_ITER;
	iValueOfBestIndividual = 0;
	d4Par = DEAFAULT_4PAR;
	sec = DEAFAULT_TIME;
}
template <class T>
CGeneticAlgorithm<T>::CGeneticAlgorithm(CProblem<T> * problem, int iPopSizee, double dCrossProbb, double dMutProbb, int iIterationss)
{
	if (iPopSizee % 2 == 0)
		iPopSize = iPopSizee;
	else
		iPopSize = iPopSizee + 1;
	dCrossProb = dCrossProbb;
	dMutProb = dMutProbb;
	pointerOnProblem = problem;
	iSizeOfGenetype = problem->iGetSizeOfIndividualArray();
	iIterations = iIterationss;
	iValueOfBestIndividual = 0;
	d4Par = DEAFAULT_4PAR;
	sec = DEAFAULT_TIME;
}
template <class T>
CGeneticAlgorithm<T>::CGeneticAlgorithm(CProblem<T> * problem, int iPopSizee, double dCrossProbb, double dMutProbb, int iIterationss, double secc)
{
	if (iPopSizee % 2 == 0)
		iPopSize = iPopSizee;
	else
		iPopSize = iPopSizee + 1;
	dCrossProb = dCrossProbb;
	dMutProb = dMutProbb;
	pointerOnProblem = problem;
	iSizeOfGenetype = problem->iGetSizeOfIndividualArray();
	iIterations = iIterationss;
	iValueOfBestIndividual = 0;
	d4Par = DEAFAULT_4PAR;
	sec = secc;
}

template<class T>
void CGeneticAlgorithm<T>::vRun()
{
	//bool first = true;
	clock_t startingTime = clock();
	clock_t t = clock();
	int followTime = 1;
	double time = ((double)(startingTime-t) / CLOCKS_PER_SEC);

	if (pointerOnProblem->bGetIsProblemWithItems())
	{
		cout << "There is problem with Items in Backpack :/ " << endl;
	}
	if (iPopSize <= 2)
	{
		cout << "PopSize must be greater than 2" << endl;
		return;
	}
	if (dCrossProb > 1 || dCrossProb < 0 || dMutProb>1 || dMutProb < 0 || iIterations < 0 || pointerOnProblem == NULL || iSizeOfGenetype < 0)
	{
		cout << "dCrossProb " << dCrossProb << " dMutProb " << dMutProb << " iIterations " << iIterations << " pointerOnProblem " << pointerOnProblem << " iSizeOfGenetype " << iSizeOfGenetype << " " << "Bad Parameters" << endl;
		return;
	}
	if (iSizeOfGenetype <= 1)
	{
		cout << "Ilosc przedmiotow musi byc wieksza niz 1!" << endl;
		return;
	}

	for (int i = 0; i < iSizeOfGenetype; i++)
	{
		vBestGenotype.push_back(0);
	}

	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(0, 999);

	for (int i = 0; i < iPopSize; i++)
	{
		vPopulation.push_back(new CIndividual<T>(iSizeOfGenetype, dCrossProb, dMutProb));
		if (DEBUGE) cout << i << endl;
	}

	//while (iIterations > 0||sec>time)
	while (sec>time)
	{
		if (DEBUGE) cout << "itearcja" << endl;
		if (DEBUGE) cout << "Tu" << endl;
		vAssignFitnessForIndiviuals();
		if (DEBUGE) cout << "Tam" << endl;

		vector< CIndividual<T>*> vNewPopulation;

		iPopSize = (int)iPopSize*d4Par;
		if (iPopSize < 2)
			iPopSize = 2;
		while (vNewPopulation.size() < iPopSize)
		{
			CIndividual<T>* cIndv1Pare1 = vPopulation[dis(gen) % vPopulation.size()];
			CIndividual<T>* cIndv2Pare1 = vPopulation[dis(gen) % vPopulation.size()];
			CIndividual<T>* cIndvBetterPare1;

			while (cIndv1Pare1 == cIndv2Pare1) {
				cIndv2Pare1 = vPopulation[dis(gen) % vPopulation.size()];
				if (DEBUGE) cout << cIndv2Pare1 << endl;
			}

			if (cIndv1Pare1->dGetFitness() >= cIndv2Pare1->dGetFitness())
				cIndvBetterPare1 = new CIndividual<T>(*cIndv1Pare1);
			else
				cIndvBetterPare1 = new CIndividual<T>(*cIndv2Pare1);


			CIndividual<T>* cIndv1Pare2 = vPopulation[dis(gen) % vPopulation.size()];
			CIndividual<T>* cIndv2Pare2 = vPopulation[dis(gen) % vPopulation.size()];
			CIndividual<T>* cIndvBetterPare2;
			while (cIndv1Pare2 == cIndv2Pare2) {
				cIndv2Pare2 = vPopulation[dis(gen) % vPopulation.size()];
			}
			if (cIndv2Pare2 == cIndvBetterPare1 || (cIndv1Pare2->dGetFitness() >= cIndv2Pare2->dGetFitness() && cIndv1Pare2 != cIndvBetterPare1))
				cIndvBetterPare2 = new CIndividual<T>(*cIndv1Pare2);
			else
				cIndvBetterPare2 = new CIndividual<T>(*cIndv2Pare2);
			if (dCrossProb * 1000 > dis(gen))//KRZY¯OWANIE
			{
				if (DEBUGE) cout << "Krzy¿owanie" << endl;
				//cIndvBetterPare1->cCrossIndividuals(*cIndvBetterPare2, &vNewPopulation, dMutProb, &iPopSize);
				vPopulation.push_back(&(*cIndvBetterPare1 + *cIndvBetterPare2));
				if (DEBUGE) cout << "Po Dodaniu" << vNewPopulation.size() << endl;

				if (DEBUGE) cout << vPopulation.size() << endl;
			}
			else
			{
				if (DEBUGE) cout << "Tylko Mutacja" << endl;
				//cIndvBetterPare1->vMuteIndividual(dMutProb);
				//cIndvBetterPare2->vMuteIndividual(dMutProb);

				(*cIndvBetterPare2)++;
				(*cIndvBetterPare1)++;

				if (vNewPopulation.size() < iPopSize)
					vNewPopulation.push_back(cIndvBetterPare1);
				else
					delete cIndvBetterPare1;

				if (vNewPopulation.size() < iPopSize)
					vNewPopulation.push_back(cIndvBetterPare2);
				else
					delete cIndvBetterPare2;
				if (DEBUGE) cout << "Po Dodaniu" << vNewPopulation.size() << endl;
			}
		}

		vDeleteOldPopulation();
		for (int i = 0; i < vNewPopulation.size(); i++)
		{
			vPopulation.push_back(vNewPopulation[i]);
		}

		iIterations--;
		t = clock() - startingTime;
		time = ((double)t / CLOCKS_PER_SEC);
		if ((int)time > followTime) {
			cout << "sec: " << followTime << endl;
			followTime = time;
		}
		if (DEBUGE) cout << iIterations << endl;
	}
	vAssignFitnessForIndiviuals();

	cout << "Best Result: " << vGetBestResult() << endl;
	cout << "Genotype: [";
	for (int i = 0; i < vBestGenotype.size(); i++)
	{;
		cout << vBestGenotype[i];
		if (i < vBestGenotype.size() - 1)
			cout << "|";
	}
	cout << "]" << endl;
	cout <<"sec: "<< time << endl;
	vDeleteOldPopulation();
}
template <class T>
void CGeneticAlgorithm<T>::vDeleteOldPopulation()
{
	for (int i = 0; i < vPopulation.size(); i++)
	{
		delete vPopulation[i];
	}
	vPopulation.clear();
}/*
template <>
void CGeneticAlgorithm<bool>::vAssignFitnessForIndiviuals()
{
	for (int i = 0; i < vPopulation.size(); i++)
	{
		vPopulation[i]->vSetFitness(pointerOnProblem->dCountFitnes((vPopulation[i]->getGenotype())));

		if (vPopulation[i]->dGetFitness() > iValueOfBestIndividual)
		{
			iValueOfBestIndividual = vPopulation[i]->dGetFitness();
			for (int j = 0; j < iSizeOfGenetype; j++)
			{
				cout << "tu tu tu1 " << endl;
				if (vPopulation[i]->iGetValueIndexGenotype(j) == 1) {
					cout << "TAAAAAAAAA" << endl;
					vBestGenotype[j] = 1;
				}
				else
					vBestGenotype[j] = 0;
			}
		}
	}
}
*/

template <class T>
void CGeneticAlgorithm<T>::vAssignFitnessForIndiviuals()
{
	for (int i = 0; i < vPopulation.size(); i++)
	{
		vPopulation[i]->vSetFitness(pointerOnProblem->dCountFitnes((vPopulation[i]->getGenotype())));

		if (vPopulation[i]->dGetFitness() > iValueOfBestIndividual)
		{
			iValueOfBestIndividual = vPopulation[i]->dGetFitness();
			for (int j = 0; j < iSizeOfGenetype; j++)
			{
				vBestGenotype[j] = vPopulation[i]->iGetValueIndexGenotype(j);
			}
		}
	}
}

template class CGeneticAlgorithm<int>;
template class CGeneticAlgorithm<double>;
template class CGeneticAlgorithm<bool>;

template class CIndividual<int>;
template class CIndividual<double>;
template class CIndividual<bool>;



#endif



