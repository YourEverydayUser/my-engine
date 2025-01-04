#include "mepch.h"
#include "Application.h"

#include "MyEngine/Log.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"

namespace MyEngine {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.GetEventType() == EventType::WindowResize) {
			ME_CORE_CRITICAL(e);
		} 
		if (e.GetEventType() == EventType::AppRender) {
			ME_CORE_TRACE(e);
		}
		while (true);
	}
}