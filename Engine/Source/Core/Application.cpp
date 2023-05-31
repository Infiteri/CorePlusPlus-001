#include "Application.h"
#include "Logger.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

namespace Core
{

    Application::Application()
    {
        glfwInit();

        this->window = new Core::Window(10, 10, 1024, 576, "Hello");

        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        // ImGui::StyleColorsLight();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(this->window->window, true);
        ImGui_ImplOpenGL3_Init("#version 400");
    }

    Application::~Application()
    {
    }
    void Application::Run()
    {
        bool show_demo_window = true;

        while (!this->window->ShouldClose())
        {
            glfwPollEvents();

            // Start the Dear ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            // ImGUI::OnRender
            if (show_demo_window)
                ImGui::ShowDemoWindow(&show_demo_window);

            layerStack.Update();

            // Rendering
            glClear(GL_COLOR_BUFFER_BIT);

            // Note that ImGUI should render after the renderer and rendering bcz if done first, the gui will be hidden by glad when glClear
            //  Post GUI Setup render
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            this->window->Display();
        }
    }

    void Application::Init()
    {
        this->OnInit();
    }

    void Application::ClearScreen(int r, int g, int b)
    {
        glClearColor(r, g, b, 1);
    }

    void Application::OnInit()
    {
    }

    void Application::PushLayer(Layer *layer)
    {
        layerStack.PushLayer(layer);
    }

}