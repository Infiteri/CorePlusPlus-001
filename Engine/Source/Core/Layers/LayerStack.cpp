#include "LayerStack.h"

namespace Core
{
    LayerStack::LayerStack()
    {
        layerInsert = layers.begin();
    }

    LayerStack::~LayerStack()
    {
    }

    void LayerStack::PushLayer(Layer *layer)
    {
        layer->OnAttach();
        layerInsert = layers.emplace(layerInsert, layer);
    }

    void LayerStack::PopLayer(Layer *layer)
    {
    }

    void LayerStack::Update()
    {
        for (Layer *layer : layers)
            layer->OnUpdate();
    }
}