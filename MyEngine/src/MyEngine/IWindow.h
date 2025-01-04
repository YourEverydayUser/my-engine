#pragma once

#include "mepch.h"

#include "MyEngine/Core.h"
#include "MyEngine/Events/Event.h"

namespace MyEngine {

	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "My Engine",
					unsigned int width = 1280,
					unsigned int height = 720)
			:Title(title), Width(width), Height(height) {}
	};

	// Interface representing a desktop system based Window
	class MYENGINE_API IWindow {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~IWindow() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static IWindow* Create(const WindowProps& props = WindowProps());
	};
}