#ifndef COMMANDLINEARG_H
#define COMMANDLINEARG_H

#include "Global.h"

class CommandLineArg {
public:
	String m_ArgName;
	String m_ArgHelp;
	String* m_ArgValue;
	bool m_ArgOptional;

public:
	CommandLineArg(String argName, String argHelp, String* argValue = nullptr, bool argOptional = false);
	~CommandLineArg();

private:
	bool m_DelArgValueVar;
};

#endif // COMMANDLINEARG_H
