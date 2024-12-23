#pragma once

#include "IEngine.h"
#include "Shader.h"

namespace Viewer
{

	class Engine : public IEngine
	{
	public:
		Engine();
		virtual ~Engine() override = default;
		virtual void HelloTriangle() override;
		virtual bool Init() override;
		virtual void Render() const override;
		virtual void SetBackgroundColor(float r, float g, float b, float a = 1.f) override;

	private:
		void RenderEverything() const;
		void RenderHelloTriangle() const;

		// Info for "Hello Triangle" mode.
		bool m_HelloTriangle = false;
		GLuint m_HelloTriangleVAO = 0;
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
