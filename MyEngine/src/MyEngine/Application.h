#pragma once

#include "Core.h"
#include "IWindow.h"
#include "Events/ApplicationEvent.h"

namespace MyEngine {

	class MYENGINE_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<IWindow> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
