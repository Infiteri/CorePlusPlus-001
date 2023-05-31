#include <ClientCore.h>
#include <iostream>

class EgLayer : public Core::Layer
{
public:
    void OnAttach()
    {
        CE_INFO("Hello Layer");
    }

    void OnUpdate()
    {
    }
};

class Sandbox : public Core::Application
{
    void OnInit()
    {
        EgLayer *layer = new EgLayer();
        this->PushLayer(layer);
    }
};

Core::Application *
Core::CreateApplication()
{
    return new Sandbox();
}