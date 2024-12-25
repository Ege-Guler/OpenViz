#ifndef CONSOLE_H
#define CONSOLE_H

#include <vector>
#include <string>

class Console {
public:
    Console();
    ~Console();

    void Clear();
    void AddLog(const char* fmt, ...);
    void ExecuteCommand(const std::string& command);
    void Render();
    bool verboseMode;  // New flag for verbose output

private:
    std::vector<std::string> logBuffer;
    char inputBuffer[256];
    bool scrollToBottom;
    void PrintVerboseState();  // Helper to print detailed state
};

#endif
