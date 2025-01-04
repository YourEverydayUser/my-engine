#include "Application.h"

#include "MyEngine/Log.h"
#include "Events/MouseEvent.h"

namespace MyEngine {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		MouseButtonPressedEvent e(4);
		ME_CORE_TRACE(e);

		while (true);
	}
}