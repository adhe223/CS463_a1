#include "Cube.h"
#include <iostream>
using namespace std;

int main()
{
	Cube * rubik = new Cube();

	rubik->shuffleCube(100);
	rubik->printCube();

	bool  quit = false;
	while (!quit) {
		int face = -1;
		cout << endl << endl << "Please enter the face you'd like to manipulate (integer, info in documentation) or -1 if you'd like to quit: ";
		cin >> face;
		if (face == -1) { quit = true; }

		if (!quit) {
			string move;
			cout << "Now enter the move you'd like to make (options can be found in the documentation): ";
			cin >> move;

			if (!rubik->move(face, move)) {
				cout << "That is not a valid move!" << endl;
			}
			else {
				rubik->printCube();
			}
		}		
	}

	rubik->printCube();

	cin.ignore(200, '\n');
	cin.ignore(200, '\n');
	return 0;
}

