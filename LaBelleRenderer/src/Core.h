#pragma once

#include <iostream>

#ifdef LBR_DEBUG
	#define ASSERT(x, ...) { if(!(x)) { std::cout << "Assertion Failed: " << __VA_ARGS__ << "\n"; __debugbreak(); } }
#else
	#define ASSERT(x, ...) {}
#endif