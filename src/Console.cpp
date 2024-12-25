#include "Console.h"
#include <stdarg.h>
#include <iostream>
#include <sstream>
#include "imgui.h"
#include "imgui_impl_glut.h"
#include "imgui_impl_opengl2.h"
#include "main.h"

// Set buffer size for user input
#define INPUT_BUFFER_SIZE 256

// Constructor
Console::Console() : scrollToBottom(false) {
    AddLog("Console Initialized. Type 'help' for commands.");
    memset(inputBuffer, 0, sizeof(inputBuffer));
}

// Destructor
Console::~Console() {
    Clear();
}

// Clears the log buffer
void Console::Clear() {
    logBuffer.clear();
}

// Adds a log to the console (formatted string support)
void Console::AddLog(const char* fmt, ...) {
    char buffer[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    logBuffer.push_back(std::string(buffer));
    scrollToBottom = true;
}

// Executes the command entered
void Console::ExecuteCommand(const std::string& command) {
    AddLog("> %s", command.c_str());

    if (command == "clear") {
        Clear();
    } 
    else if (command == "help") {
        AddLog("Available commands:");
        AddLog("- clear  : Clears the console.");
        AddLog("- help   : Lists available commands.");
        AddLog("- exit   : Exits the application.");
        AddLog("- verbose: Toggles verbose mode.");
    }
    else if (command == "verbose") {
        verboseMode = !verboseMode;
        AddLog("Verbose mode %s.", verboseMode ? "ON" : "OFF");
        if (verboseMode) {
            PrintVerboseState();
        }
    }
    else if (command == "exit") {
        AddLog("Exiting application...");
        exit(0);
    }
    else {
        AddLog("Unknown command: '%s'. Type 'help' for available commands.", command.c_str());
    }
}

void Console::PrintVerboseState() {
    AddLog("------ APP STATE ------");
    AddLog("Viewport: %dx%d at %d, %d", viewport.viewportWidth, viewport.viewportHeight, viewport.viewportX, viewport.viewportY);
    AddLog("Rotation: X: %.2f Y: %.2f Z: %.2f", rotation.angleX, rotation.angleY, rotation.angleZ);
    AddLog("Rotation Speeds: X: %.2f Y: %.2f Z: %.2f", rotation.speedX, rotation.speedY, rotation.speedZ);
    AddLog("Current Camera: %d", currentCameraIndex);
    AddLog("Camera Position: X: %.2f Y: %.2f Z: %.2f", 
           cameras[currentCameraIndex].posX, cameras[currentCameraIndex].posY, cameras[currentCameraIndex].posZ);
    AddLog("FreeCam Position: X: %.2f Y: %.2f Z: %.2f", 
           freeCamera.posX, freeCamera.posY, freeCamera.posZ);
    AddLog("----------------------");
}

void Console::Render() {
    if (ImGui::GetCurrentContext() == nullptr) return;  // Prevent crash

    // Start Console Window
    ImGui::Begin("Console", nullptr, ImGuiWindowFlags_NoCollapse);

    ImGui::TextUnformatted("Console Output:");
    ImGui::Separator();

    // Console Scrolling Region
    ImGui::BeginChild("ScrollingRegion", ImVec2(0, -30), false, ImGuiWindowFlags_HorizontalScrollbar);
    for (const std::string& line : logBuffer) {
        ImGui::TextUnformatted(line.c_str());
    }
    if (scrollToBottom) {
        ImGui::SetScrollHereY(1.0f);
        scrollToBottom = false;
    }
    ImGui::EndChild();

    // If the console window is clicked, focus the input field
    if (ImGui::IsWindowFocused(ImGuiFocusedFlags_RootAndChildWindows)) {
        if (!ImGui::IsAnyItemActive()) {  // Only focus if no ImGui item is active
            ImGui::SetKeyboardFocusHere();
        }
    }

// Input Box for Commands
    if (ImGui::InputText("##Input", inputBuffer, IM_ARRAYSIZE(inputBuffer), ImGuiInputTextFlags_EnterReturnsTrue) && inputBuffer[0] != '\0') {
        ExecuteCommand(inputBuffer);
        inputBuffer[0] = '\0';  // Clear buffer after execution
    }


    ImGui::SameLine();
    if (ImGui::Button("Submit")) {
        ExecuteCommand(std::string(inputBuffer));
        inputBuffer[0] = '\0';
    }

    ImGui::End();
}


