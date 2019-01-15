#ifndef PROBLEMS
#define PROBLEMS
#include <vector>
#include <iostream>



#define DEAFAULT_ITEM_SIZE 5
#define DEAFAULT_ITEM_Value 1
#define DEAFAULT_BACKPACK_SIZE 10

using namespace std;


class Item
{
public:
	Item(double iSizee, double dValuee);
	double dGetSize() { return iSize; };
	void vSetSize(int iSizee) { iSize = iSizee; };
	double dGetValue() { return dValue; };
	void vSetValue(double dValuee) { dValue = dValuee; };

private:
	int iSize;
	double dValue;
};

template <class T>
class CProblem
{
public:
	virtual double dCountFitnes(vector <double>* vTab) = 0;
	virtual int iGetSizeOfIndividualArray() = 0;
	virtual vector<Item*> getBackpack() = 0;
	bool bGetIsProblemWithItems() { return bProblem; };
protected:
	bool bProblem;
};

template <class T>
class CKnapsackProblem: public CProblem<T>
{

public:
	CKnapsackProblem();
	CKnapsackProblem(int iSizeOFKnapsak);
	~CKnapsackProblem();

	void vAddItem(int iSize, double dValue);
	double dCountFitnes(vector <double>* vTab);
	vector<Item*> getBackpack() { return backpack; }
	int iGetSizeOfIndividualArray() { return backpack.size(); }

protected:
	vector<Item*> backpack;
	int iSizeOfBackPack;
	bool bProblem;
};

#endif