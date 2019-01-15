#include "TreeCreator.h"
#include <algorithm>

CMenu * TreeCreator::CreateTree(string path, bool & error)
{
	int i = 0;
	string message = "ERROR";
	bool errorofCreating = false;
	CMenu* temp = NULL;

	path.erase(remove_if(path.begin(), path.end(), isspace), path.end());

	///////////////////////////////////////////////////
	/*
	int i_number_of_closing_brackets = 0;
	int i_number_of_opening_brackets = 0;
	int i_number_of_closing_parentheses = 0;
	int i_number_of_opening_parentheses = 0;

	for (int i = 0; i < path.size(); i++)
	{
		if (path.at(i) == '[')
			i_number_of_opening_brackets++;
		if (path.at(i) == ']')
			i_number_of_closing_brackets++;
		if (path.at(i) == '(')
			i_number_of_opening_parentheses++;
	}

	if (i_number_of_closing_brackets < i_number_of_opening_brackets)
	{
		cout << "expected a ']' " << endl;
		system("pause");
		return NULL;
	}
	if (i_number_of_closing_brackets > i_number_of_opening_brackets)
	{
		cout << "expected a '[' " << endl;
		system("pause");
		return NULL;
	}
	if (i_number_of_closing_parentheses > i_number_of_opening_parentheses)
	{
		cout << "expected a '(' " << endl;
		system("pause");
		return NULL;
	}
	if (i_number_of_closing_parentheses < i_number_of_opening_parentheses)
	{
		cout << "expected a ')' " << endl;
		system("pause");
		return NULL;
	}
	if (DEBUGE)
	cout << "nawiasy" << i_number_of_closing_parentheses << "kwadratowe nawiasy" << i_number_of_closing_brackets << "apostrofy"  << endl;
	system("pause");
	*/
	///////////////////////////////////////////////////
	
	if (path.find("(") == -1 || path.find("(") != 0)
	{
		errorofCreating = true;
		message = "expected '('";
		if (DEBUGE) cout << "b³¹ddddd" << endl;
		if (DEBUGE) system("pause");
	}
	else
	{
		temp = cCreateMenu(path, i, errorofCreating, message);
	}
	if (DEBUGE) cout << "zrobilem return" << endl;
	if (DEBUGE) system("pause");
	if (errorofCreating == true)
	{
		error = true;
		cout << "pos " << i << " ";
		cout << message << endl;
		system("pause");
		return NULL;
	}

	if (DEBUGE) cout << "dellet" << endl;
	if (DEBUGE) system("pause");
	//delete this;
	//this->sGetName();
	if (DEBUGE) cout << temp->sGetName() << temp->sGetCommand() << endl;
	if (DEBUGE) cout << "add" << endl;
	if (DEBUGE) system("pause");
	return temp;
	/*
	int i_number_of_closing_brackets = 0;
	int i_number_of_opening_brackets = 0;
	int i_number_of_closing_parentheses = 0;
	int i_number_of_opening_parentheses = 0;
	int i_number_of_apostrophe = 0;
	int i_number_of_semicolon = 0;
	int i_number_of_comma = 0;

	for (int i = 0; i < path.size(); i++)
	{
		if (path.at(i) == '[')
			i_number_of_opening_brackets++;
		if (path.at(i) == ']')
			i_number_of_closing_brackets++;
		if (path.at(i) == '(')
			i_number_of_opening_parentheses++;
		if (path.at(i) == '\'')
			i_number_of_apostrophe++;
		if (path.at(i) == ')')
			i_number_of_closing_parentheses++;
		if (path.at(i) == ';')
			i_number_of_semicolon++;
		if (path.at(i) == ',')
			i_number_of_comma++;
	}

	if(i_number_of_closing_brackets < i_number_of_opening_brackets)
	{
		cout << "expected a ']' "<<endl;
		return;
	}
	if (i_number_of_closing_brackets > i_number_of_opening_brackets)
	{
		cout << "expected a '[' " << endl;
		return;
	}
	if (i_number_of_closing_parentheses > i_number_of_opening_parentheses)
	{
		cout << "expected a '(' " << endl;
		return;
	}
	if (i_number_of_closing_parentheses < i_number_of_opening_parentheses)
	{
		cout << "expected a ')' " << endl;
		return;
	}
	if (i_number_of_semicolon<i_number_of_closing_parentheses)
	{
		cout << "expected a ';' " << endl;
		return;
	}
	if (i_number_of_semicolon > i_number_of_closing_parentheses)
	{
		cout << "too many a ';' " << endl;
		return;
	}
	if (i_number_of_apostrophe > i_number_of_apostrophe+i_number_of_opening_brackets)
	{
		cout << "too many a ';' " << endl;
		return;
	}
	if (DEBUGE)
		cout << "nawiasy" << i_number_of_closing_parentheses << "kwadratowe nawiasy" << i_number_of_closing_brackets << "apostrofy" << i_number_of_apostrophe << "œredniki" << i_number_of_semicolon << "przecinki" << i_number_of_comma << endl;
	system("pause");
	*/
	/*
	string s_com= path;
	int i_next_pos = 0;
	int i_first_space_index = s_com.find("'");
	int i_second_space_index = s_com.find("'",i_first_space_index+1);
	int i_third_space_index = s_com.find("'", i_second_space_index+1);
	int i_fourth_space_index = s_com.find("'", i_third_space_index+1);
	vSetName(s_com.substr(i_first_space_index + 1, i_second_space_index - i_first_space_index-1));
	vSetCommand(s_com.substr(i_third_space_index + 1, i_fourth_space_index -  i_third_space_index-1));
	string rest=s_com.substr(i_fourth_space_index+2);
	for (int i = 0; i < (int)v_list.size(); i++)
	{
		delete v_list.at(i);
	}
	v_list.clear();

	this->bAdd(*(new CMenu("Nazwa", "Komenda")));

	if (rest.at(0) == ')')
		return;
	i_next_pos = i_fourth_space_index + 2;
	while(i_next_pos<path.size())
	{
		if (path.at(i_next_pos) == '(')
		{
			cout << "Utwórz CMenu" << endl;
		}
		else if (path.at(i_next_pos) == '[')
		{
			cout << "Utwórz komende" << endl;
		}
	}
	system("pause");

	*/
	//this->bAdd(*cCreateMenu(rest));

}

CMenu * TreeCreator::cCreateMenu(string & path, int & pos, bool & error, string & error_message)
{
	bool adding = true;
	int trys = 0;
	int i_first_space_index = path.find("'", pos);
	int i_semicolon_index = path.find(";", pos);
	int i_second_space_index = path.find("'", i_first_space_index + 1);
	int i_third_space_index = path.find("'", i_second_space_index + 1);
	int i_fourth_space_index = path.find("'", i_third_space_index + 1);

	if (DEBUGE) cout << i_first_space_index << " " << i_second_space_index << " " << i_third_space_index << " " << i_fourth_space_index << " " << i_semicolon_index << endl;
	if (DEBUGE) system("pause");


	if (i_semicolon_index != -1 && ((i_fourth_space_index + 1) == i_semicolon_index))
	{
		if (!(i_first_space_index == -1 || i_second_space_index == -1 || i_third_space_index == -1 || i_fourth_space_index == -1))
		{
			if (DEBUGE) cout << "Tu sie Wywala1" << endl;
			if (DEBUGE) system("pause");
			if ((i_first_space_index < i_semicolon_index && i_second_space_index < i_semicolon_index && i_third_space_index < i_semicolon_index && i_fourth_space_index < i_semicolon_index))
			{
				if (DEBUGE) cout << "Tu sie Wywala2" << endl;
				if (DEBUGE) system("pause");
				if (path.at(i_second_space_index + 1) == ',')
				{
					if (DEBUGE) cout << "Tu sie Wywala3" << endl;
					if (DEBUGE) system("pause");
					CMenu* nowy;
					if ((i_first_space_index + 1) == i_second_space_index && (i_third_space_index + 1) == i_fourth_space_index)
					{
						error_message = "required name and command";
						error = true;
						return NULL;
					}
					else if ((i_first_space_index + 1) == i_second_space_index)
					{
						error_message = "required name";
						error = true;
						return NULL;
					}
					else if ((i_third_space_index + 1) == i_fourth_space_index)
					{
						error_message = "required command";
						error = true;
						return NULL;
					}
					else
						nowy = new CMenu(path.substr(i_first_space_index + 1, i_second_space_index - i_first_space_index - 1), path.substr(i_third_space_index + 1, i_fourth_space_index - i_third_space_index - 1));
					
					if (DEBUGE) cout << "NOWY OBIEKT O NAZWIE" << nowy->sGetName() << " I KOMENDZIE: " << nowy->sGetCommand() << endl;
					if (DEBUGE) cout << "NOWY " << nowy->sGetPath() << endl;
					if (DEBUGE) system("pause");

					if (DEBUGE) cout << "Tu sie Wywala4" << endl;
					if (DEBUGE) system("pause");
					pos = i_semicolon_index + 1;
					while (adding)
					{
						if (DEBUGE) cout << "Tu sie Wywala5" << endl;
						if (DEBUGE) cout << pos << " " << path << endl;
						if (DEBUGE) system("pause");

						if (pos < path.length())
						{
							//cout << trys;
							if (pos < path.length() && path.at(pos) == ')')
							{
								if (DEBUGE) cout << "KONIEC " << endl;
								pos++;
								adding = false;
								trys = 0;
								return nowy;
							}
							if (pos < path.length() && path.at(pos) == '(')
							{
								if (DEBUGE) cout << "dodawnie menu" << endl;
								CMenu* next = cCreateMenu(path, pos, error, error_message);
								if (error)
								{
									return nullptr;
								}
								if (DEBUGE) cout << next->sGetName() << endl;
								nowy->bAdd(*next);
								trys = 0;
							}
							if (pos < path.length() && path.at(pos) == '[')
							{
								if (DEBUGE) cout << "dodawnie command" << endl;
								CMenuItem* next = cCreateCommand(path, pos, error, error_message);
								if (error)
								{
									return nullptr;
								}
								nowy->bAdd(*next);
								trys = 0;
							}
							if (pos < path.length() && path.at(pos) == ',')
							{
								pos++;
							}
							trys++;
							if (trys == 5)
							{
								error = true;
								error_message = "missing initializing symbol";
								return nullptr;
							}
						}//if(pos<path.length())
						else
						{
							error_message = "expected a ')'";
							error = true;
							adding = false;

							//cout << "robie return" << endl;
							//system("pause");
							//return nowy;
						}	
					}//while(adding)
				}//if (path.at(i_second_space_index + 1) == ',')
				else
				{
					pos = i_second_space_index + 1;
					error_message = "expected ' , '";
					error = true;
				}
			}//if((i_first_space_index< i_semicolon_index|| i_second_space_index< i_semicolon_index|| i_third_space_index<i_semicolon_index||i_fourth_space_index<<i_semicolon_index))
			else
			{
				error_message = "expected ' ' '";
				error = true;
			}
		}//if (!(i_first_space_index == -1 || i_second_space_index == -1 || i_third_space_index == -1 || i_fourth_space_index == -1))
		else
		{
			error_message = "expected ' ' '";
			error = true;
		}
	}//if (i_semicolon_index == -1)
	else
	{
	if (i_fourth_space_index != -1)
		pos = i_fourth_space_index + 1;
		error_message = "expected ' ; '";
		error = true;
	}


	return nullptr;
}

CMenuItem * TreeCreator::cCreateCommand(string & path, int & pos, bool & error, string & error_message)
{
	int i_first_space_index = path.find("'", pos);
	int i_second_space_index = path.find("'", i_first_space_index + 1);
	int i_third_space_index = path.find("'", i_second_space_index + 1);
	int i_fourth_space_index = path.find("'", i_third_space_index + 1);
	int i_fifth_space_index = path.find("'", i_fourth_space_index + 1);
	int i_sixth_space_index = path.find("'", i_fifth_space_index + 1);
	int i_oppening_bracket = path.find("[", pos);
	int i_closing_bracket = path.find("]", pos);
	if (!(i_closing_bracket == -1 || i_first_space_index == -1 || i_second_space_index == -1 || i_third_space_index == -1 || i_fourth_space_index == -1 || i_fifth_space_index == -1 || i_sixth_space_index == -1))
	{
		if (!(i_first_space_index > i_closing_bracket || i_second_space_index > i_closing_bracket || i_third_space_index > i_closing_bracket || i_fourth_space_index > i_closing_bracket || i_fifth_space_index > i_closing_bracket || i_sixth_space_index > i_closing_bracket))
		{
			if (path.at(i_second_space_index + 1) == ',' && path.at(i_third_space_index - 1) == ',' && path.at(i_fourth_space_index + 1) == ',' && path.at(i_fifth_space_index - 1) == ',')
			{
				if ((i_sixth_space_index + 1) == i_closing_bracket)
				{
					CMenuItem* nowy;
					if ((i_first_space_index + 1) == i_second_space_index && (i_third_space_index + 1) == i_fourth_space_index)
					{
						
						error_message = "required name and command";
						error = true;
						return NULL;
					}
					else if ((i_first_space_index + 1) == i_second_space_index)
					{
						error_message = "required name";
						error = true;
						return NULL;
					}
					else if ((i_third_space_index + 1) == i_fourth_space_index)
					{
						error_message = "required command";
						error = true;
						return NULL;
					}
					else
						nowy = new CMenuCommand(path.substr(i_first_space_index + 1, i_second_space_index - i_first_space_index - 1), path.substr(i_third_space_index + 1, i_fourth_space_index - i_third_space_index - 1), path.substr(i_fifth_space_index + 1, i_sixth_space_index - i_fifth_space_index - 1));
					if (DEBUGE) cout << "NOWY OBIEKT O NAZWIE" << nowy->sGetName() << " I KOMENDZIE: " << nowy->sGetCommand() << endl;
					system("pause");
					pos = i_closing_bracket + 1;
					return nowy;
				}//if (path.at(i_sixth_space_index) == ']')
				else
				{
					pos = i_sixth_space_index + 1;
					error = true;
					error_message = "expected ' ] '";
				}
			}//if (path.at(i_second_space_index + 1) == ',' && path.at(i_third_space_index - 1) == ',' && path.at(i_fourth_space_index + 1) == ',' && path.at(i_fifth_space_index - 1) == ',')
			else
			{
				pos = i_second_space_index + 1;
				error = true;
				error_message = "expected ' , '";
			}
		}//if (!(i_first_space_index > i_closing_bracket || i_second_space_index > i_closing_bracket || i_third_space_index > i_closing_bracket || i_fourth_space_index > i_closing_bracket))
		else
		{
			error = true;
			error_message = "expected ' ' '";
		}
	}//if (!(i_closing_bracket == -1 ||i_first_space_index == -1 || i_second_space_index == -1 || i_third_space_index == -1 || i_fourth_space_index == -1))
	else
	{
		error = true;
		error_message = "expected ' ' '";
	}

	return nullptr;
}
