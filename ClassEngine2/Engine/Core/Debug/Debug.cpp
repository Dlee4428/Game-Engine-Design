#include "Debug.h"

MessageType Debug::currentSev = MessageType::TYPE_NONE;

void Debug::DebugInit() {
	std::ofstream out;
	out.open("GAME301_EngineLog.txt", std::ios::out);
	out.close();
	currentSev = MessageType::TYPE_FATAL_ERROR;
}

void Debug::SetSeverity(MessageType type_) {
	currentSev = type_;
}

void Debug::Info(const std::string& message_, const std::string& fileName_, const int line_) {
	Log(MessageType::TYPE_INFO, "INFO: " + message_, fileName_, line_);
}

void Debug::Trace(const std::string& message_, const std::string& fileName_, const int line_) {
	Log(MessageType::TYPE_TRACE, "TRACE: " + message_, fileName_, line_);
}

void Debug::Warning(const std::string& message_, const std::string& fileName_, const int line_) {
	Log(MessageType::TYPE_WARNING, "WARNING: " + message_, fileName_, line_);
}

void Debug::Error(const std::string& message_, const std::string& fileName_, const int line_) {
	Log(MessageType::TYPE_ERROR, "ERROR: " + message_, fileName_, line_);
}

void Debug::FatalError(const std::string& message_, const std::string& fileName_, const int line_) {
	Log(MessageType::TYPE_FATAL_ERROR, "FATAL_ERROR: " + message_, fileName_, line_);
}

void Debug::Log(const MessageType type_, const std::string& message_, const std::string& fileName_, const int line_) {
	std::ofstream file;
	file.open("GAME301_EngineLog.txt", std::ios::app | std::ios::out);

	if (type_ <= currentSev && currentSev > MessageType::TYPE_NONE) {
		file << message_ << " in: " << fileName_ << " on line: " << line_ << std::endl;
	}
	file.flush();
	file.close();
}