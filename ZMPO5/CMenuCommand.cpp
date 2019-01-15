#include "CMenuCommand.h"

CMenuCommand::~CMenuCommand()
{
	if (p_command != NULL)delete p_command;
	cout << "USUWANIE CMENUCOMMAND " << sGetName() << endl;
}

void CMenuCommand::vRun()
{
	if (p_command != NULL)
		p_command->runCommand();
	else
	{
		std::cout << "pusta komenda" << std::endl;
		system("pause");
	}
}

void CMenuCommand::vRun(string p)
{
	if (p_command != NULL)
		p_command->runCommand();
	else
	{
		std::cout << "pusta komenda" << std::endl;
		system("pause");
	}
}

void CMenuCommand::vPrintHelp()
{
	cout << s_help << endl;
}

string CMenuCommand::sGetHelp()
{
	return s_help;
}

void CMenuCommand::vPrintCMenuItem()
{
	cout << "['" << sGetName() << "','" << sGetCommand() << "','"<<sGetHelp()<<"']";
}
	
