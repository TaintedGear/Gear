#pragma once

#ifdef GR_PLATFORM_WINDOWS

extern Gear::Application* Gear::CreateApp();

int main(int argc, char** argv)
{
	Gear::Log::Init();

	auto app = Gear::CreateApp();
	app->Run();
	delete app;
}

#else
	#error Gear only supports Windows!
#endif