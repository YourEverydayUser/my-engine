#pragma once

#include "MyEngine/IWindow.h"

#include <GLFW/glfw3.h>

namespace MyEngine {

	class WindowsWindow : public IWindow {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// here EventCallbackFn is a type alias which will simply be replaced by the preprocessor to:
		// std::function<void(Event&)>
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		void CreateWindowResizeEventCallback();
		void CreateWindowCloseEventCallback();
		void CreateKeyEventCallback();

		GLFWwindow* m_Window;

		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}