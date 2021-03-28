#include "CommandLineArg.h"

CommandLineArg::CommandLineArg(String argName, String argHelp, String* argValue, bool argOptional) : m_ArgName(argName), m_ArgHelp(argHelp), m_ArgValue(argValue), m_ArgOptional(argOptional) {
	if(!m_ArgValue) {
		m_ArgValue = new String("");
		m_DelArgValueVar = true;
	} else {
		m_DelArgValueVar = false;
	}
}

CommandLineArg::~CommandLineArg() {
	if(m_DelArgValueVar) {
		delete m_ArgValue;
	}
}
