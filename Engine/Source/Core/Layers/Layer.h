#pragma once

#include "Core/Core.h"
#include <string.h>

namespace Core
{
    class CORE_API Layer
    {
    protected:
        const char *name;

    public:
        Layer(const char *name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnImGuiRender() {}
    };

}