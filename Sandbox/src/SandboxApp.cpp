#include <Cobalt.h>

class ExampleLayer : public Cobalt::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//CB_INFO("ExampleLayer::Update");
	}

	void OnEvent(Cobalt::Event& event) override
	{
		CB_TRACE("{0}", event);
	}
};

class Sandbox : public Cobalt::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Cobalt::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Cobalt::Application* Cobalt::CreateApplication()
{
	return new Sandbox();
}