#pragma once

#include "IEngine.h"

namespace Viewer
{

	class Engine : public IEngine
	{
	public:
		Engine();
		virtual ~Engine() override = default;
		virtual std::string HelloWorld() const override;
		virtual void Render() const override;
		virtual void SetBackgroundColor(float r, float g, float b, float a = 1.f) override;

	private:
		bool m_Initialized = false;

		// Background colors
		float m_R = 0.f;
		float m_G = 0.f;
		float m_B = 0.f;
		float m_A = 1.f;
	};

}
