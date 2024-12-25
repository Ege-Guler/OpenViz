#ifndef CONSOLE_H
#define CONSOLE_H

#include <vector>
#include <string>
#include <imgui.h>

class Console {
public:
    Console();
    ~Console();

    void Clear();
    void AddLog(const char* fmt, ...);
    void ExecuteCommand(const std::string& command);
    void Render();

private:
    std::vector<std::string> logBuffer;
    char inputBuffer[256];  // Fixed-size buffer for user input
    bool scrollToBottom;
};

#endif // CONSOLE_H
