#include <pch.h>

// Debug logs
#include <fstream>
std::ofstream logfile("debug.log");



void Application::Initialize(HMODULE _Module)
{
	InputsManager::Register();

	ScriptRegister(_Module, []
	{
			while (true)
			{



				logfile.flush();
				WAIT(0);
			}
	});
}



void Application::Shutdown(HMODULE _Module)
{
	ScriptUnregister(_Module);

	InputsManager::Unregister();
}