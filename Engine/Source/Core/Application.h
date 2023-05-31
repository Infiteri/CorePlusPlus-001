#pragma once

#include "Core.h"
#include "Layers/LayerStack.h"

#include "glad/glad.h"
#include "Window.h"

namespace Core
{
    class CORE_API Application
    {
    public:
        Application();
        ~Application();

        Core::Window *window;

        void Run();
        void Init();

        void ClearScreen(int r, int g, int b);

        virtual void OnInit();

        LayerStack layerStack;

        void PushLayer(Layer *layer);
    };

    Application *CreateApplication();

} // namespace Core
