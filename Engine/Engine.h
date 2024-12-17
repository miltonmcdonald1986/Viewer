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

	private:
		bool m_Initialized = false;
	};

}
