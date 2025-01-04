#pragma once

#include "Core.h"
#include "IWindow.h"

namespace MyEngine {

	class MYENGINE_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<IWindow> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
