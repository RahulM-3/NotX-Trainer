#include <pch.h>
#include "util.h"

enum MenuType {PARENT, TOGGLE, FUNCTIONAL};

using menuoptions = std::unordered_map<const char*, MenuType>;

class Menu
{
private:
	const char* title = "";
	menuoptions MenuOptions;
	std::unordered_map <const char*, menuoptions> SubMenu;
	std::unordered_map<const char*, bool> ToggleMenu;
	int currentOption = 0;
	const char* currentSubMenu = "";

public:
	Menu(const char* title)
	{
		this->title = concatCharArr(3, "<red>", title, "\n");
	}

	// Add Parent Menu and Submenu
	void add_parent_option(const char* optionName, menuoptions submenus)
	{
		MenuOptions.insert({ optionName, MenuType::PARENT });
		SubMenu.insert({ optionName, submenus });
	}

	// Add Toggle Menu
	void add_toggle_option(const char* optionName, bool defaultToggle)
	{
		MenuOptions.insert({ optionName, MenuType::TOGGLE });
		ToggleMenu.insert({ optionName, defaultToggle });
	}

	// Activate/Update Menu
	void update()
	{
		int i = 0;
		const char* menulist = title;
		for (auto it = MenuOptions.begin(); it != MenuOptions.end(); ++it) 
		{
			if (currentOption == i)
			{
				menulist = concatCharArr(4, menulist, "<purple>>", it->first, "\n");
			}
			else
			{
				menulist = concatCharArr(4, menulist, "<blue>", it->first, "\n");
			}
			i++;
		}

		_PRINT_HELP(menulist, 100000.f, true, 1, 0, 0, 0, 0);
	}

	// Deactivate Menu
	void deactivate()
	{
		HUD_CLEAR_HELP_QUEUE();
	}

	// Go to Next Menu Option
	void next_option()
	{
		currentOption++;
		if (currentOption >= MenuOptions.size())
		{
			currentOption = 0;
		}
		deactivate();
		update();
	}

	// Go to Prev Menu Option
	void prev_option()
	{
		currentOption--;
		if (currentOption < 0)
		{
			currentOption = MenuOptions.size()-1;
		}
		deactivate();
		update();
	}
};