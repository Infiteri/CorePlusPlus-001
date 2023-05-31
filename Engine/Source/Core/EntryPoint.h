#pragma once

#ifdef CE_PLATFORM_WIN32

extern Core::Application *Core::CreateApplication();

int main(int argc, char const *argv[])
{

    Core::Logger::Init();

    auto app = Core::CreateApplication();
    app->Init();    
    app->Run();
    delete app;

    return 0;
}

#endif