#ifndef COMMANDLINEOPTION_H
#define COMMANDLINEOPTION_H

#include "parser/Global.h"
#include "parser/CommandLineArg.h"

class CommandLineOption {
public:
	Vector<String> m_Flags;
	String m_OptionHelp;
	bool* m_IsPresent;
	Vector<CommandLineArg*> m_Args;

public:
	CommandLineOption(std::initializer_list<String> flags, String optionHelp, bool* isPresent = nullptr, std::initializer_list<CommandLineArg*> args = {});
	~CommandLineOption();

	void AddArgs(std::initializer_list<CommandLineArg*> args);
	void AddArg(CommandLineArg* arg);

private:
	/// Whether or not the <code>m_IsPresent</code> should be deleted in the destructor
	bool m_DelIsPresentVar;
};

#endif // COMMANDLINEOPTION_H