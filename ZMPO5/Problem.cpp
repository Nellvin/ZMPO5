#include "Problems.h"

template <class T>
CKnapsackProblem<T>::CKnapsackProblem()
{
	iSizeOfBackPack = DEAFAULT_BACKPACK_SIZE;
	bProblem = false;
}
template <class T>
CKnapsackProblem<T>::CKnapsackProblem(int iSizeOFKnapsak)
{
	iSizeOfBackPack = iSizeOFKnapsak;
	bProblem = false;
}
template <class T>
CKnapsackProblem<T>::~CKnapsackProblem()
{
	for (int i = 0; i < backpack.size(); i++)
	{
		delete backpack[i];
	}
	//backpack.clear();
	iSizeOfBackPack = 0;

}

template <class T>
void CKnapsackProblem<T>::vAddItem(int iSize, double dValue)
{
	if (iSize < 1)
	{
		cout << "Size must be greater than 0" << endl;
		bProblem = true;
	}
	if (dValue <= 0)
	{
		cout << "Value must be greater than 0" << endl;
		bProblem = true;
	}
	backpack.push_back(new Item(iSize, dValue));
//	cout << "ELOPUSZCH BACK" << endl;
}


double CKnapsackProblem<bool>::dCountFitnes(vector<double>* vTab)
{

	double dValue = 0;
	double iTotalSize = 0;
	for (int i = 0; i < vTab->size(); i++)
	{
		if ((*vTab)[i] == 1)
		{
			dValue += (*(backpack[i])).dGetValue();
			iTotalSize += (*(backpack[i])).dGetSize();
		}

	}

	if (iTotalSize > iSizeOfBackPack)
		return 0.0;
	else

		return dValue;

	return 0.0;
}

double CKnapsackProblem<int>::dCountFitnes(vector<double>* vTab)
{

	double dValue = 0;
	double iTotalSize = 0;
	for (int i = 0; i < vTab->size(); i++)
	{
		dValue += ((*(backpack[i])).dGetValue()*(*vTab)[i]);
		iTotalSize += ((*(backpack[i])).dGetSize()*(*vTab)[i]);
	}

	if (iTotalSize > iSizeOfBackPack)
		return 0.0;
	else
		return dValue;

	return 0.0;
}

double CKnapsackProblem<double>::dCountFitnes(vector<double>* vTab)
{

	double dValue = 0;
	double iTotalSize = 0;
	for (int i = 0; i < vTab->size(); i++)
	{
		dValue += ((*(backpack[i])).dGetValue()*(*vTab)[i]);
		iTotalSize += ((*(backpack[i])).dGetSize()*(*vTab)[i]);
	}

	if (iTotalSize > iSizeOfBackPack)
		return 0.0;
	else
		return dValue;

	return 0.0;
}


Item::Item(double iSizee, double dValuee)
{
	iSize = iSizee;
	dValue = dValuee;
}

template class CKnapsackProblem<int>;
template class CKnapsackProblem<double>;
template class CKnapsackProblem<bool>;