#include "parser/CommandLineOption.h"

CommandLineOption::CommandLineOption(std::initializer_list<String> flags, String optionHelp, bool* isPresent, std::initializer_list<CommandLineArg*> args) : m_Flags(flags), m_OptionHelp(optionHelp), m_IsPresent(isPresent), m_Args(args) {
	if(!m_IsPresent) {
		m_IsPresent = new bool(false);
		m_DelIsPresentVar = true;
	} else {
		m_DelIsPresentVar = false;
	}
}

CommandLineOption::~CommandLineOption() {
	for(CommandLineArg* arg : m_Args) {
		delete arg;
	}
	if(m_DelIsPresentVar) {
		delete m_IsPresent;
	}
}

void CommandLineOption::AddArgs(std::initializer_list<CommandLineArg*> args) {
	for(CommandLineArg* arg : args) {
		AddArg(arg);
	}
}

void CommandLineOption::AddArg(CommandLineArg* arg) {
	arg->m_ArgOptional = false;
	m_Args.push_back(arg);
}
