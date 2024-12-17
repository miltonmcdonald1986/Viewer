#include "pch.h"

#include "GL/glew.h"

#include "Engine.h"

namespace Viewer
{
	Engine::Engine()
	{
		// Initialize GLEW
		GLenum err = glewInit();
		if (GLEW_OK != err)
			return;

		m_Initialized = true;
	}

	std::string Engine::HelloWorld() const
	{
		return "Hello, world! Viewer::Engine salutes you!";
	}

	void Engine::Render() const
	{
		glClearColor(m_R, m_G, m_B, m_A);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Engine::SetBackgroundColor(float r, float g, float b, float a)
	{
		m_R = r;
		m_G = g;
		m_B = b;
		m_A = a;
	}

	IEngineSPtr CreateEngine()
	{
		return std::shared_ptr<IEngine>(new Engine());
	}

}
