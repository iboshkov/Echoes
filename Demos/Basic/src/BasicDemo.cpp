#include "ECore.h"
#include "EException.h"
#include "EColor.h"
#include <iostream>

int main() {
	Echoes::Core core;
	Echoes::Color col(0xFF00FF);
	core.initialize();

	while (true)
		core.render(0);

	core.destroy();


	return 0;
}