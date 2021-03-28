#ifndef COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_H

#include "parser/Global.h"
#include "parser/CommandLineOption.h"
#include "parser/CommandLineArg.h"

// Maybe include some "add parser" sort of thing, like 'steghide extract' and 'steghide embed' act like two different programs

class CommandLineParser {
private:
	Vector<CommandLineOption*> m_Options;
	Vector<CommandLineArg*> m_Args;
	String m_ProgName;
	String m_ProgVersion;
	String m_ProgExeName;

public:
	explicit CommandLineParser(String progName, String progVersion, String progExeName = "");
	~CommandLineParser();

	void AddOptions(std::initializer_list<CommandLineOption*> options);
	void AddOption(CommandLineOption* option);

	void AddArgs(std::initializer_list<CommandLineArg*> args);
	void AddArg(CommandLineArg* arg);

	void Parse(int argc, char** argv);

	void Help();
	void Version();

private:
	/// If the string <code>str</code> is an option flag, then return that option
	CommandLineOption* MatchesOption(String str);
};

#endif // COMMANDLINEPARSER_H