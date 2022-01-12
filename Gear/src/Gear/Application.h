#pragma once

#include "Core.h"

namespace Gear
{
	class GEAR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined by client
	Application* CreateApp();
}