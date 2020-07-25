#include "cbpch.h"
#include "LayerStack.h"

namespace Cobalt {

	LayerStack::LayerStack()
	{
		// Start pushing layers at the beginning of the list
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		// Push layer to the end of all regular layers in the list
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		// Add overlay layers to the end of the list
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		// Remove a specified layer from the list
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsert--;
		}

	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		// Remove a specified overlay layer from the list
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
			m_Layers.erase(it);
	}



}
