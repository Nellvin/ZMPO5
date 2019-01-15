#include "CMenu.h"
#include <algorithm>
#include "CMenuCommand.h"
#include "TreeCreator.h"
#include <fstream>



CMenu::~CMenu()
{
	cout << "USUWANIE CMENU "<<sGetName() << endl;
	for (int i = 0; i < (int)v_list.size(); i++)
	{
		delete v_list.at(i);
		
	}
	v_list.clear();
	
}

void CMenu::vRun()
{
	vRun("");
}

void CMenu::vRun(string p)
{
	bool b_isRun = true;
	bool b_correctCommand = false;
	string s_user;
	while (b_isRun)
	{
		b_correctCommand = false;
		system("cls");
		vPrint();
		cout << "Co chcesz zrobic: " ;
		string s_temp;
		getline(cin, s_temp);
		int i_first_space_index = s_temp.find(" ");
		string command;
		string cointerner = s_temp.substr((i_first_space_index + 1), (s_temp.size() - 1));
		if (DEBUGE) cout << "\\" << cointerner << "\\" << endl;
		if (DEBUGE) system("pause");
		command = s_temp.substr(0, i_first_space_index);
		for (int i = 0; i < v_list.size(); i++)
		{
			if (v_list[i]->sGetCommand() == command)
			{
				if (cointerner == command.substr(0, command.size() - 1))
				{
					v_list[i]->vRun();
					b_correctCommand = true;
				}
				else
					cout << "zle dodano: '" << cointerner <<"'"<< endl;
			}

		}
		if (command == "back"|| command == "exit"|| command == "close")
		{
			b_isRun = false;
		}
		if (command == "search")
		{
			this->vSearch(cointerner);
			b_correctCommand = true;
		}
		if (command == "createTree")
		{
			bool error = false;
			CMenu* temp;
			//////////////////////////////////////////////
			string line;
			ifstream myfile("readTree.txt");
			if (myfile.good())  // same as: if (myfile.good())
			{
				getline(myfile, cointerner);
				TreeCreator creator;
				temp = creator.CreateTree(cointerner, error);
				myfile.close();
			}
			//////////////////////////////////////////////

			TreeCreator creator;
			temp = creator.CreateTree("('aaa''dddd';('gggg','hhhh';))", error);
			if (!error)
			{
				for (int i = 0; i < (int)v_list.size(); i++)
				{
					delete v_list.at(i);
				}
				v_list.clear();
				temp->vRun();

				delete temp;
				b_isRun = false;
			}
			b_correctCommand = true;
		}
		if (command == "help")
		{
			this->bHelp(cointerner);
			b_correctCommand = true;
		}
		if (command == "changeRoot")
		{
			CMenuItem* temp1=(this->vChangeRoot(cointerner));
			if (temp1 != NULL)
			{
				temp1->vRun();
				b_isRun = false;
			}

			b_correctCommand = true;
		}

		if (command == "printTree")
		{
			this->vPrintTree();
			system("pause");
			b_correctCommand = true;
		}
		if (command == "\n"|| command == "")
		{
			b_correctCommand = true;
		}
		if (b_isRun == true && b_correctCommand == false) {
			cout << "Podano zla komende" << endl;
			system("pause");
		}
	}
}

void CMenu::vPrint()
{
	cout << sGetName() << endl;
	cout << "------------------"<< endl;
	for (int i = 0; i < v_list.size(); i++) {
		cout <<i+1<<". "<<sGetPath()<<" -->"<< v_list[i]->sGetCommand()<<" " <<v_list[i]->sGetName() << " (" << v_list[i]->sGetCommand()<<")" << endl;
	}
	cout << "------------------" << endl;
	cout << "Akutalne parametry" << endl;
	int iRodzajProblemu = pManag->getRodziajProblemu();
	if(iRodzajProblemu ==INTPROBLEM)
		cout << "CKnapsackProblem<int>" << endl;
	if(iRodzajProblemu ==BOOLPROBLEM)
		cout << "CKnapsackProblem<bool>" << endl;
	if(iRodzajProblemu ==DOUBLEPROBLEM)
		cout << "CKnapsackProblem<double>" << endl;
	cout << "Pojemnosc plecaka: "<<pManag->getPojemnoœæPlecaka() << endl;
	cout << "Wielkosc populacji: "<<pManag->getWielkoœæPopulacjiu()<< endl;
	cout << "Prawdopodobienstwo krzyzowania: "<< pManag->getPrawdopodobieñstwoKrzy¿owania()<< endl;
	cout << "Prawdopodobienstwo mutowania: "<< pManag->getPrawdopodobieñstwoMutacji()<< endl;
	cout << "Czas dzialania: "<< pManag->getCzasDzia³aniaAlgorytmu() << endl;

}
 
bool CMenu::bAdd(CMenuItem &cmi)
{
	
	int isFree = 0;
	for (int i = 0; i < v_list.size(); i++)
	{
		if (cmi.sGetCommand() == v_list.at(i)->sGetCommand())
			isFree = -1;
		if (cmi.sGetName() == v_list.at(i)->sGetName())
			isFree = -1;
	}

	if (isFree == 0) {
		cmi.vSetParent(this);
		cmi.vSetPath(this->sGetPath() + "-->" + cmi.sGetName());
		v_list.push_back(&cmi);
	}
	return true;
}

bool CMenu::bHelp(string command)
{
	for (int i = 0; i < v_list.size(); i++) {
		if (dynamic_cast<CMenuCommand*>((v_list.at(i))))
		{
			if (DEBUGE)cout << "LOL" << endl;
			if (command == v_list.at(i)->sGetCommand()) 
			{
				v_list.at(i)->vPrintHelp();
				system("pause");
				return true;
			}
		}
		else
			if(DEBUGE)cout << ":C" << endl;
	}
	cout << "Brak komendy" << endl;
	system("pause");
	return false;
}

void CMenu::vSearch(string command)
{
	CMenuItem* p_root = this;

	p_root = pFindRoot();
	p_root->vFindCommand(command);
	system("pause");
}

CMenuItem * CMenu::pFindRoot()
{
	CMenuItem* p_root = this;
	while (p_root->cGetParent() != NULL)
	{
		p_root = p_root->cGetParent();
	}
	return  p_root;
}

bool CMenu::vFindCommand(string command)
{
	for (int i = 0; i < v_list.size(); i++) {
		if (dynamic_cast<CMenu*>((v_list.at(i))))
		{
			v_list.at(i)->vFindCommand(command);
		}
		else
		{
			if (command == v_list.at(i)->sGetCommand())
			{
				cout << v_list.at(i)->sGetPath() << endl;
			}
		}
	}
	return false;
}

void CMenu::vPrintTree()
{
	pFindRoot()->vPrintCMenuItem();
}

void CMenu::vPrintCMenuItem()
{
	//(‘<nazwa menu>’,‘<polecenie otwieraj¹ce menu>’;<dziecko1>,<dziecko2>,…,<dzieckon>) 
	cout << "('" << sGetName() << "','" << sGetCommand() << "';";
	for (int i = 0; i < v_list.size(); i++)
	{
		v_list.at(i)->vPrintCMenuItem();
		if (i != v_list.size() - 1)
			cout << ",";
	}
	cout << ")";

}

void CMenu::vChangeRoot(string s_new_root, CMenuItem& new_root)
{
	for (int i = 0; i < v_list.size(); i++) {
		if (dynamic_cast<CMenu*>((v_list.at(i))))
		{
			
			if (s_new_root == v_list.at(i)->sGetCommand())
			{
				CMenuItem* p_new_root = v_list.at(i);
				p_new_root->bAdd(*pFindRoot());
				vector<CMenuItem*> v_new_list;
				for (int ii = 0; ii < v_list.size(); ii++) {
					if(v_list.at(ii)->sGetCommand()!=s_new_root)
						v_new_list.push_back(v_list.at(ii));

				}
				v_list = v_new_list;
				new_root = *v_list.at(i);
				//CMenu* par =(CMenu)(p_new_root->cGetParent());
				//(CMenu)p_new_root.bAdd(pFindRoot());
				return;
			}
			else
			{
				//v_list.at(i)->vChangeRoot(s_new_root);
			}
			//v_list.at(i)->vFindCommand();

		}
		else
		{
			//if (command == v_list.at(i)->sGetCommand())
			//{
			//	cout << v_list.at(i)->sGetPath() << endl;
			//}
		}
	}
}

CMenuItem* CMenu::vChangeRoot(string s_new_root)
{
	for (int i = 0; i < v_list.size(); i++) {
		if (dynamic_cast<CMenu*>((v_list.at(i))))
		{
			if (s_new_root == v_list.at(i)->sGetCommand())
			{
				CMenuItem* p_new_root = v_list.at(i);
				p_new_root->bAdd(*pFindRoot());
				vector<CMenuItem*> v_new_list;
				for (int ii = 0; ii < v_list.size(); ii++) {
					if (v_list.at(ii)->sGetCommand() != s_new_root)
						v_new_list.push_back(v_list.at(ii));
				}
				v_list = v_new_list;
				return p_new_root;
			}
		}
	}
	return NULL;
}


//('mMenu','main';('Subm','sub';['MyComm','Comm','helpCom']),('Subm2','sub2';))



