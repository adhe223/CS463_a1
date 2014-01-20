#include "Cube.h"
#include <iostream>
using namespace std;

int main()
{
	Cube * rubik = new Cube();

	rubik->printCube();
	cout << endl << endl << endl;

	rubik->shuffleCube(100000);

	rubik->printCube();

	cin.ignore(200, '\n');
	return 0;
}

