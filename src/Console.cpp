#include "Console.h"
#include <stdarg.h>
#include <iostream>
#include <sstream>
#include "imgui.h"
#include "imgui_impl_glut.h"
#include "imgui_impl_opengl2.h"
#include "main.h"

#define INPUT_BUFFER_SIZE 256

Console::Console() : scrollToBottom(false)
{
    AddLog("Console Initialized. Type 'help' for commands.");
    memset(inputBuffer, 0, sizeof(inputBuffer));
}

Console::~Console()
{
    Clear();
}

void Console::Clear()
{
    logBuffer.clear();
}

void Console::AddLog(const char *fmt, ...)
{
    char buffer[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    logBuffer.push_back(std::string(buffer));
    scrollToBottom = true;
}

void Console::ExecuteCommand(const std::string &command)
{
    AddLog("> %s", command.c_str());

    if (command == "clear")
    {
        Clear();
    }
    else if (command == "help")
    {
        AddLog("Available commands:");
        AddLog("- clear  : Clears the console.");
        AddLog("- help   : Lists available commands.");
        AddLog("- exit   : Exits the application.");
        AddLog("- verbose: Toggles verbose mode.");
        AddLog("- ls: List App State");
        AddLog("- freeRoam on/off: Toggles freeRoam.");
        AddLog("- translate x y z.");
        AddLog("- show camera 0,1,2");
    }
    else if(command == "ls"){
        PrintVerboseState();
    }
    else if (command.rfind("verbose", 0) == 0)
    {
        char state[10];
        if(sscanf(command.c_str(), "verbose %s", state) == 1){
            bool verboseState = (strcmp(state, "on") == 0);
            verboseMode = verboseState;
            AddLog("Verbose mode %s.", verboseMode ? "ON" : "OFF");
            
        }
        else{
            AddLog("Invalid Verbose command. Use: Verbose on/off");

        }

    }
    else if (command == "exit")
    {
        AddLog("Exiting application...");
        exit(0);
    }
    else if (command.rfind("translate", 0) == 0)
    {
        float x, y, z;
        if (sscanf(command.c_str(), "translate %f %f %f", &x, &y, &z) == 3)
        {
            translation.x = x;
            translation.y = y;
            translation.z = z;
            AddLog("Translation set to: %f %f %f", x, y, z);
        }
        else
        {
            AddLog("Invalid translate command. Use: translate x y z");
        }
    }
    else if (command.rfind("freeRoam", 0) == 0)
    {
        char state[10];
        if (sscanf(command.c_str(), "freeRoam %s", state) == 1)
        {
            bool freeRoamState = (strcmp(state, "on") == 0);
            freeRoam = freeRoamState;
            AddLog("Free roam mode %s.", freeRoamState ? "ENABLED" : "DISABLED");
        }
        else
        {
            AddLog("Invalid freeRoam command. Use: freeRoam on/off");
        }
    }

    else if(command.rfind("show", 0) == 0){
        int cam;

        if(sscanf(command.c_str(), "show %d", &cam) == 1){
            currentCameraIndex = cam;
            AddLog("Showing Camera %d", cam);
        }
    }
    else
    {
        AddLog("Unknown command: '%s'. Type 'help' for available commands.", command.c_str());
    }
}

void Console::PrintVerboseState()
{
    AddLog("------ APP STATE ------");
    AddLog("Viewport: %dx%d at %d, %d", viewport.viewportWidth, viewport.viewportHeight, viewport.viewportX, viewport.viewportY);
    AddLog("Rotation: X: %.2f Y: %.2f Z: %.2f", rotation.angleX, rotation.angleY, rotation.angleZ);
    AddLog("Rotation Speeds: X: %.2f Y: %.2f Z: %.2f", rotation.speedX, rotation.speedY, rotation.speedZ);
    AddLog("Current Camera: %d", currentCameraIndex);
    AddLog("Camera Position: X: %.2f Y: %.2f Z: %.2f",
           cameras[currentCameraIndex].posX, cameras[currentCameraIndex].posY, cameras[currentCameraIndex].posZ);
    AddLog("FreeCam Position: X: %.2f Y: %.2f Z: %.2f",
           freeCamera.posX, freeCamera.posY, freeCamera.posZ);
    AddLog("Position: X: %.2f, Y: %.2f Z: %.2f", translation.x, translation.y, translation.z);
    AddLog("FreeRoam State: %s", freeRoam ?  "ON" : "OFF");
    AddLog("----------------------");
}

void Console::Render()
{
    if (ImGui::GetCurrentContext() == nullptr)
        return;

    ImGui::Begin("Console", nullptr, ImGuiWindowFlags_NoCollapse);

    ImGui::TextUnformatted("Console Output:");
    ImGui::Separator();

    ImGui::BeginChild("ScrollingRegion", ImVec2(0, -30), false, ImGuiWindowFlags_HorizontalScrollbar);
    for (const std::string &line : logBuffer)
    {
        ImGui::TextUnformatted(line.c_str());
    }
    if (scrollToBottom)
    {
        ImGui::SetScrollHereY(1.0f);
        scrollToBottom = false;
    }
    ImGui::EndChild();

    if (ImGui::IsWindowFocused(ImGuiFocusedFlags_RootAndChildWindows))
    {
        if (!ImGui::IsAnyItemActive())
        {
            ImGui::SetKeyboardFocusHere();
        }
    }

    if (ImGui::InputText("##Input", inputBuffer, IM_ARRAYSIZE(inputBuffer), ImGuiInputTextFlags_EnterReturnsTrue) && inputBuffer[0] != '\0')
    {
        ExecuteCommand(inputBuffer);
        inputBuffer[0] = '\0';
    }

    ImGui::SameLine();
    if (ImGui::Button("Submit"))
    {
        ExecuteCommand(std::string(inputBuffer));
        inputBuffer[0] = '\0';
    }

    ImGui::End();
}
