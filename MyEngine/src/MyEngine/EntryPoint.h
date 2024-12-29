#pragma once
#include "Application.h"

#ifdef ME_PLATFORM_WINDOWS

extern MyEngine::Application* MyEngine::CreateApplication();

int main(int argc, char** argv) {
	printf("MyEngine started.");
	auto app = MyEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif