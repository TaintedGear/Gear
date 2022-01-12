#include <Gear.h>

class Sandbox : public Gear::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Gear::Application* Gear::CreateApp()
{
	return new Sandbox();
}