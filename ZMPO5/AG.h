#ifndef AR
#define AR

#include <random>
#include <iostream>
#include <time.h>
#include "Problems.h"
#define DEFAULT_POP_SIZE 40
#define DEFAULT_CROSS_PROB 0.6
#define DEFAULT_MUT_PROB 0.2
#define DEAFAULT_ITER 2000
#define DEAFAULT_4PAR 1
#define DEBUGE false
#define MAX_GENERATE_OF_ITEM 3
#define MUT_RANGE 3
#define DEAFAULT_TIME 100000000




using namespace std;

template <class T>
class CIndividual
{
public:
	//CIndividual(int iSizeGenotype);
	CIndividual(int iSizeGenotype, double dCrossProbb, double dMutProbb);
	CIndividual(CIndividual<T>& cIndivToCopy);
	~CIndividual();

	void vMuteIndividual(double dMutProbb);
	bool cCrossIndividuals(CIndividual<T>& two, vector< CIndividual<T>*>* tabOfPopulation, double dMutProbb, int* populationSize);
	bool cAnotherCrossIndividuals(CIndividual<T> & two, vector<CIndividual<T>*>* tabOfPopulation, double dMutProbb, int* populationSize);
	void vSetFitness(double dFitnesss) { dFitness = dFitnesss; };
	double dGetFitness() { return dFitness; };
	vector<double>* getGenotype() { return &genotype; };
	//POPRAWIC 
	template <class T>
	void vSetValueIndexGenotype(int iIndexx, T iValuee) { if (iIndexx >= 0 || iIndexx < genotype.size()) genotype[iIndexx] = iValuee; };
	double iGetValueIndexGenotype(int iIndexx);

	void operator ++(int);
	CIndividual<T>& operator+(CIndividual<T>& two);


protected:
	vector<double> genotype;
	double dFitness;
	double dCrossProb;
	double dMutProb;

};
/**/

template <class T>
class CGeneticAlgorithm
{
public:
	CGeneticAlgorithm();
	CGeneticAlgorithm(CProblem<T>* problem);
	CGeneticAlgorithm(CProblem<T>* problem, int iPopSizee, double dCrossProbb, double dMutProbb, int iIterationss);
	//CGeneticAlgorithm(CProblem<T>* problem, int iPopSizee, double dCrossProbb, double dMutProbb, int iIterationss,int sec);
	CGeneticAlgorithm(CProblem<T>* problem, int iPopSizee, double dCrossProbb, double dMutProbb, int iIterationss, double secc);

	void vRun();
	double vGetBestResult() { return iValueOfBestIndividual; };
	void vDeleteOldPopulation();
	void vAssignFitnessForIndiviuals();

private:
	int iPopSize;
	double dCrossProb;
	double dMutProb;
	vector <int> vResults;
	vector< CIndividual<T>*> vPopulation;
	CProblem<T>* pointerOnProblem;
	int iSizeOfGenetype;
	int iIterations;
	vector<double> vBestGenotype;
	double iValueOfBestIndividual;
	double d4Par;
	int sec;
	
	
};

#endif
