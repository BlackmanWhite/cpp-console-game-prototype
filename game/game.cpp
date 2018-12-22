#include "engine.h"
#include <iomanip>

int main() {
	Engine eng;
	eng.run();
	std::cout << "Use the arrow keys to move\n\n";
	std::cout << std::setw(5);
	while (eng.checkIfRunning()) {
		eng.getInput(100);
		std::cout << " X = " << eng.getPlayerX();
		std::cout << "| Y = " << eng.getPlayerY();
		std::cout << "| Key = " << eng.getKeyPressed() << "   ";
		std::cout << "\n\n";
		eng.renderMap(true);
		eng.displayMessage("Hello world");
	}
	return 0;
}