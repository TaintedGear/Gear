#pragma once

#ifdef GR_PLATFORM_WINDOWS
	#ifdef GR_BUILD_DLL
		#define GEAR_API __declspec(dllexport)
	#else
		#define GEAR_API __declspec(dllimport)
	#endif
#else
	#error Gear only supports Windows!
#endif