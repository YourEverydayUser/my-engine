#pragma once
#include "Application.h"

#ifdef ME_PLATFORM_WINDOWS
#define ME_ENABLE_ASSERTS = true;

extern MyEngine::Application* MyEngine::CreateApplication();

int main(int argc, char** argv) {
	MyEngine::Log::Init();
	ME_CORE_WARN("Initialized Log!");
	int a = 5;
	ME_INFO("Welcome to MyEngine! Var={0}", a);

	auto app = MyEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif