#include "ECore.h"
#include "EException.h"
#include "EColor.h"
#include <iostream>

int main() {
	{
		Echoes::Core core;
		Echoes::Color col(0xFF00FF);
		if (!core.initialize()) return -1;

		Echoes::Window* wnd = core.createWindow("Echoes v0.1", 800, 600);
		for (int i = 0; i < 10; i++){
			wnd->close();
			wnd->create();
		}
		while (wnd->isOpen())
		{
			core.render(0);
		}
		core.destroyWindow("Echoes v0.1");

		core.destroy();
	}
	return 0;
}