#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <Windows.h>
#include <string>

// Define keys
#define VK_W 0x57
#define VK_A 0x41
#define VK_D 0x44
#define VK_S 0x53

class Engine {
private:
	// Game variables
	bool isRunning; // For game loop
	bool gettingInput; // For input loop
	std::string keyPressed; // Last key pressed
	std::string msg; // Message displayed on screen
	char map[11][13] = {
		"############",
		"#          #",
		"#          #",
		"#          #",
		"#          #",
		"#          #",
		"#          #",
		"#          #",
		"#          #",
		"#          #",
		"############"
	};

	// Player variables
	int spawnpoint[2] = { 4, 5 }; // Player's starting position
	int playerY = spawnpoint[0]; // Player's Y position
	int playerX = spawnpoint[1]; // Player's X position
	char playerModel = 'P'; // Character that represents the player
public:

	// Functions
	inline void run() { this->isRunning = true; }

	char getInput(double delay) {
		// Gets arrow keys states
		gettingInput = true;
		while (this->gettingInput) {
			if (GetAsyncKeyState(VK_RIGHT)) {
				// Right arrow key
				this->playerX++;
				this->movePlayer(0, 1, false);
				this->keyPressed = "Right arrow";
				break;
			}
			else if (GetAsyncKeyState(VK_LEFT)) {
				// Left arrow key
				this->playerX--;
				this->movePlayer(0, -1, false);
				this->keyPressed = "Left arrow";
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN)) {
				// Up arrow key
				this->playerY++;
				this->movePlayer(1, 0, true);
				this->keyPressed = "Down arrow";
				break;
			}
			else if (GetAsyncKeyState(VK_UP)) {
				// Down arrow key
				this->playerY--;
				this->movePlayer(-1, 0, true);
				this->keyPressed = "Up arrow";
				break;
			}
			else if (GetAsyncKeyState(VK_END)) {
				exit(0);
			}
		}
		Sleep(delay);
		this->clearScreen();
	}

	void renderMap(bool centralize=false) {
		if (!centralize) {
			for (signed int i = 0; i < std::size(map); i++) {
				std::cout << "\r" << map[i] << "\n";
			}
		}
		else {
			// Centralize map
			for (signed int i = 0; i < std::size(map); i++) {
				std::cout << "\r\t" << map[i] << "\n";
			}
		}
	}

	void movePlayer(int y, int x, bool vertical) {
		int pY = this->playerY;
		int pX = this->playerX;
		if (map[playerY][playerX] == ' ') {
			map[playerY][playerX] = this->playerModel;
			map[pY-y][pX-x] = ' ';
		}
		else if(map[playerY][playerX] == '#' && vertical == true) {
			playerY -= y;
		}
		else if (map[playerY][playerX] == '#' && vertical == false) {
			playerX -= x;
		}
	}

	inline bool checkIfRunning() { return isRunning; }

	void endGame() { isRunning = !isRunning; }

	inline void clearScreen() { system("cls"); }

	void displayMessage(std::string text) { msg = text; std::cout << "\n Message: " << msg;}

	void endMessage() { msg = ""; }

	inline int getPlayerX() { return playerX; }

	inline int getPlayerY() { return playerY; }

	inline std::string getKeyPressed() { return keyPressed; }
};

#endif
