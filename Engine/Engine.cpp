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
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	IEngineSPtr CreateEngine()
	{
		return std::shared_ptr<IEngine>(new Engine());
	}

}
