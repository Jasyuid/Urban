#include "cbpch.h"
#include "LayerStack.h"

namespace Cobalt {

	LayerStack::LayerStack()
	{
	}

	LayerStack::~LayerStack()
	{
		// Delete all layers
		for (Layer* layer : m_Layers)
		{
			layer->OnDetatch();
			// TODO: Not sure if layer stack needs to delete layers
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		// Push layer to the end of all regular layers in the layer stack
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		// Add overlay layers to the end of the layer stack
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		// Remove a specified layer from the layer stack
		auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
		if (it != m_Layers.begin() + m_LayerInsertIndex)
		{
			layer->OnDetatch();
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}

	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		// Remove a specified overlay layer from the end of the layer stack
		auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			overlay->OnDetatch();
			m_Layers.erase(it);
		}
	}



}
