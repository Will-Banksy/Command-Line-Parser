#include "parser/CommandLineParser.h"

CommandLineParser::CommandLineParser(String progName, String progVersion, String progExeName) : m_ProgName(progName), m_ProgVersion(progVersion), m_ProgExeName(progExeName) {
	if(m_ProgExeName == "") {
		m_ProgExeName = m_ProgName;
	}
}

CommandLineParser::~CommandLineParser() {
	for(CommandLineOption* option : m_Options) {
		delete option;
	}
	for(CommandLineArg* arg : m_Args) {
		delete arg;
	}
}

void CommandLineParser::AddOptions(std::initializer_list<CommandLineOption*> options) {
	for(CommandLineOption* option : options) {
		AddOption(option);
	}
}

void CommandLineParser::AddOption(CommandLineOption* option) {
	m_Options.push_back(option);
}

void CommandLineParser::AddArgs(std::initializer_list<CommandLineArg*> args) {
	for(CommandLineArg* arg : args) {
		AddArg(arg);
	}
}

void CommandLineParser::AddArg(CommandLineArg* arg) {
	m_Args.push_back(arg);
}

void CommandLineParser::Parse(int argc, char** argv) {
	Vector<String> args;
	// Start at 1 - Want to skip the program executable name which is always the first argument
	for(int i = 1; i < argc; i++) {
		args.push_back(String(argv[i]));
	}

	int argIndex = 0;
	CommandLineOption* currOpt = nullptr;
	int currOptArgsIndex = 0;
	for(int i = 0; i < args.size(); i++) {
		CommandLineOption* opt = MatchesOption(args.at(i));
		if(opt) {
			*opt->m_IsPresent = true;
			if(opt->m_Args.size() > 0) {
				currOpt = opt;
				currOptArgsIndex = 0;
			}
		} else {
			if(currOpt) {
				// currOptArgsIndex should always be a valid index in currOpt->m_Args
				*currOpt->m_Args.at(currOptArgsIndex)->m_ArgValue = args.at(i);
				currOptArgsIndex++;
				if(currOptArgsIndex >= currOpt->m_Args.size()) {
					currOpt = nullptr;
					currOptArgsIndex = 0;
				}
			} else if(argIndex >= m_Args.size()) {
				std::cout << "[WARN]: Unexpected argument: " << args.at(i) << std::endl;
			} else {
				*m_Args.at(argIndex)->m_ArgValue = args.at(i);
				argIndex++;
			}
		}
	}

	// This is commented out cause when you use like --help or whatnot, these will still throw errors, and I can't be bothered to fix it right now
// 	for(CommandLineArg* arg : m_Args) {
// 		if(!arg->m_ArgOptional && *arg->m_ArgValue == "") {
// 			std::cout << "[ERROR]: Missing argument " << arg->m_ArgName << std::endl;
// 		}
// 	}
//
// 	for(CommandLineOption* opt : m_Options) {
// 		if(*opt->m_IsPresent) {
// 			for(CommandLineArg* arg : opt->m_Args) {
// 				if(*arg->m_ArgValue == "") {
// 					std::cout << "[ERROR]: Missing argument for " << opt->m_Flags.at(0) << ": " << arg->m_ArgName << std::endl;
// 				}
// 			}
// 		}
// 	}
}

void CommandLineParser::Help() {
	std::cout << "Usage: " << m_ProgExeName;
	for(CommandLineArg* arg : m_Args) {
		if(arg->m_ArgOptional) {
			std::cout << " [" << arg->m_ArgName << "]";
		} else {
			std::cout << " <" << arg->m_ArgName << ">";
		}
	}
	for(CommandLineOption* option : m_Options) {
		std::cout << " [" << option->m_Flags.at(0);
		for(CommandLineArg* arg : option->m_Args) {
			// Can't have optional arguments after an option - This is taken care of in CommandLineOption::AddArg
			std::cout << " <" << arg->m_ArgName << ">";
		}
		std::cout << "]";
	}
	std::cout << "\n\nArguments:\n";
	for(CommandLineArg* arg : m_Args) {
		std::cout << "\t" << arg->m_ArgName << "\t - " << arg->m_ArgHelp << "\n";
	}
	std::cout << "\n\nOptions:\n";
	for(CommandLineOption* option : m_Options) {
		std::cout << "\t";
		for(int i = 0; i < option->m_Flags.size(); i++) {
			std::cout << option->m_Flags.at(i);
			if(i < option->m_Flags.size() - 1) {
				std::cout << ", ";
			}
		}
		for(CommandLineArg* arg : option->m_Args) {
			// Can't have optional arguments after an option - This is taken care of in CommandLineOption::AddArg
			std::cout << " <" << arg->m_ArgName << ">";
		}
		std::cout << "\t - " << option->m_OptionHelp << std::endl;
	}
}

void CommandLineParser::Version() {
	std::cout << m_ProgName << " version " << m_ProgVersion << "\n";
}

CommandLineOption* CommandLineParser::MatchesOption(String str) {
	for(CommandLineOption* option : m_Options) {
		for(String& flag : option->m_Flags) {
			if(str == flag) {
				return option;
			}
		}
	}
	return nullptr;
}