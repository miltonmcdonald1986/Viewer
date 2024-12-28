#pragma once

#include "IEngine.h"
#include "Shader.h"

namespace Viewer
{

	class Engine : public IEngine
	{
	public:
		Engine();
		virtual ~Engine() override;
		virtual auto GetShader(const std::string& name) -> IShaderSPtr const override;
		virtual auto HelloTriangle() -> void override;
		virtual auto Init() -> bool override;
		virtual auto Render() -> void const override;
		virtual auto SetBackgroundColor(float r, float g, float b, float a = 1.f) -> void override;

	private:
		auto RenderEverything() -> void const;
		auto RenderHelloTriangle() -> void const;

		// Info for "Hello Triangle" mode.
		bool m_HelloTriangle = false;
		GLuint m_HelloTriangleVAO = 0;
		GLuint m_idVBO;
		GLuint m_HelloTriangleEBO = 0;

		// Background colors
		float m_R = 0.f;
		float m_G = 0.f;
		float m_B = 0.f;
		float m_A = 1.f;

		// Shaders
		std::map<std::string, IShaderSPtr> m_Shaders;
	};

}
