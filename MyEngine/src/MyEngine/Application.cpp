#include "mepch.h"
#include "Application.h"

#include "MyEngine/Log.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace MyEngine {
//std::bind is a utility function that creates a callable object by 
//binding specific arguments to a function. Here we create a callable
//for the member function x of the current class instance (this), with
//one argument left unbound. _1 is a placeholder which indicates that 
//the first argument to the resulting callable will be provided later.

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1));

	Application::Application() {
		m_Window = std::unique_ptr<IWindow>(IWindow::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent);
	}

	Application::~Application() {

	}

	void Application::OnEvent(Event& e) {
		ME_CORE_INFO("{0}", e);
	}

	void Application::Run() {
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}