#include <pch.h>
#include "menu.h"


void Application::Initialize(HMODULE _Module)
{
	InputsManager::Register();

	ScriptRegister(_Module, []
	{
			// Global Variable
			bool menuActive = false;
			Menu menu("                             NotX Trainer");
			menuoptions submenu = {
						{"option1", MenuType::TOGGLE},
						{"option2", MenuType::TOGGLE},
						{"option3", MenuType::TOGGLE},
						{"option4", MenuType::TOGGLE},
			};

			menu.add_parent_option("Player", submenu);
			menu.add_parent_option("Teleport", submenu);
			menu.add_parent_option("Spawner", submenu);

			while (true)
			{

				// Open Trainer
				if (Input::IsKeyJustPressed(KEY_F4))
				{
					menuActive = !menuActive;
					if (menuActive)
					{
						menu.update();
					}
					else
					{
						menu.deactivate();
					}
				}

				// Go to Next Option
				if (menuActive && Input::IsKeyJustPressed(KEY_NUMPAD_2))
				{
					menu.next_option();
				}

				// Go to Prev Option
				if (menuActive && Input::IsKeyJustPressed(KEY_NUMPAD_8))
				{
					menu.prev_option();
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