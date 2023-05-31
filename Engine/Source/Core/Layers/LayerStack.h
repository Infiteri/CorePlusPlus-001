#pragma once

#include "Layer.h"

#include <vector>

namespace Core
{

    class LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer *layer);
        void PopLayer(Layer *layer);
        void Update();

        std::vector<Layer *>::iterator begin() { return layers.begin(); }
        std::vector<Layer *>::iterator end() { return layers.end(); }

    private:
        std::vector<Layer *> layers;
        std::vector<Layer *>::iterator layerInsert;
    };

}