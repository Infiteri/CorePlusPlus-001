#include "Window.h"

namespace Core
{

    Window::Window(int x, int y, int width, int height, const char *name)
    {
        this->window = glfwCreateWindow(width, height, name, NULL, NULL);
        glfwSetWindowPos(this->window, x, y);

        glfwMakeContextCurrent(this->window);
    }

    Window::~Window()
    {
        glfwDestroyWindow(this->window);
    }

    bool Window::ShouldClose()
    {
        return glfwWindowShouldClose(this->window);
    }
    void Window::Display()
    {
        glfwSwapBuffers(this->window);
    }
    void Window::Show()
    {
        glfwShowWindow(this->window);
    }
    void Window::Maximize()
    {
        glfwMaximizeWindow(this->window);
    }
    void Window::SetVSyncOn()
    {
        glfwSwapInterval(1);
    }
    void Window::SetVSyncOff()
    {
        glfwSwapInterval(0);
    }
}