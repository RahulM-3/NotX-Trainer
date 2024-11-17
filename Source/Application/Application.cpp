#include <pch.h>

// Debug logs
#include <fstream>
std::ofstream logfile("debug.log");



void Application::Initialize(HMODULE _Module)
{
	InputsManager::Register();

	ScriptRegister(_Module, []
	{
			// Global Variable
			bool menuActive = false;

			while (true)
			{

				// Open Trainer
				if (Input::IsKeyJustPressed(KEY_F4))
				{
					menuActive = !menuActive;
					if (menuActive)
					{
						_PRINT_HELP(
							"<red>NotX Trainer\n"
							"<purple>>Player\n"
							"<blue>Teleport\n"
							"<blue>Spawner\n",
							10000.0f, true, 1, 0, 0, 0, 0
						);
					}
					else
					{
						HUD_CLEAR_HELP_QUEUE();
					}
				}
				
				// Enter Player options (test)
				if (menuActive && Input::IsKeyJustPressed(KEY_ENTER))
				{
					HUD_CLEAR_HELP_QUEUE();
					_PRINT_HELP(
						"<red>NotX Trainer\n"
						
						"<purple>>Invincible: " 
						"<red>OFF\n"

						"<blue>drunk: "
						"<red>OFF\n",
						10000.0f, true, 1, 0, 0, 0, 0
					);
				}

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