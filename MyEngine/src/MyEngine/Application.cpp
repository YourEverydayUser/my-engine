#include "mepch.h"
#include "Application.h"

#include "MyEngine/Log.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace MyEngine {

	Application::Application() {
		m_Window = std::unique_ptr<IWindow>(IWindow::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}