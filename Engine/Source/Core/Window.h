#pragma once

#include "Core.h"
#include "GLFW/glfw3.h"

namespace Core
{
    class CORE_API Window
    {
    public:
        GLFWwindow *window;

        Window(int x, int y, int width, int height, const char *name);
        ~Window();

        bool ShouldClose();

        void Display();

        void Show();
        void Maximize();
        void SetVSyncOn();
        void SetVSyncOff();
    };
}