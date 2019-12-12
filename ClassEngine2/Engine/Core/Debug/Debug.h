#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>
#include <fstream>

enum class MessageType : unsigned short {
	TYPE_NONE = 0,
	TYPE_FATAL_ERROR,
	TYPE_ERROR,
	TYPE_WARNING,
	TYPE_TRACE,
	TYPE_INFO
};

class Debug
{
public:
	//Singleton design pattern
	Debug(const Debug&) = delete;
	Debug(Debug&&) = delete;
	Debug& operator=(const Debug&) = delete;
	Debug& operator=(Debug&&) = delete;

	Debug() = delete;
	static void DebugInit();
	static void SetSeverity(MessageType type_);
	static void Info(const std::string& message_, 
		const std::string& fileName_, 
		const int line_);
	static void Trace(const std::string& message_,
		const std::string& fileName_,
		const int line_);
	static void Warning(const std::string& message_,
		const std::string& fileName_,
		const int line_);
	static void Error(const std::string& message_,
		const std::string& fileName_,
		const int line_);
	static void FatalError(const std::string& message_,
		const std::string& fileName_,
		const int line_);

private:
	static void Log(const MessageType type,
		const std::string& message_,
		const std::string& fileName_,
		const int line_);
		static MessageType currentSev;
};

#endif // !DEBUG_H

