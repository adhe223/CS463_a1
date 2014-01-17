#include "Cube.h"
#include <iostream>
using namespace std;

Cube::Cube() {
	char orig[24] = { 'y', 'y', 'y', 'y', 'o', 'o', 'b', 'b', 'r', 'r', 'g', 'g', 'o', 'o', 'b', 'b', 'r', 'r', 'g', 'g', 'w', 'w', 'w', 'w' };
	for (int i = 0; i < 24; i++) {
		cube[i] = orig[i];
	}
}

Cube::~Cube() {}

void Cube::printCube() {
	cout << "  " << cube[0] << cube[1] << endl;
	cout << "  " << cube[2] << cube[3] << endl;
	for (int i = 4; i < 12; i++) { cout << cube[i]; }
	cout << endl;
	for (int i = 12; i < 20; i++) { cout << cube[i]; }
	cout << endl;
	cout << "  " << cube[20] << cube[21] << endl;
	cout << "  " << cube[22] << cube[23];
}

//Left half of the front is rotated up
void Cube::leftFlipUp() {
	char temp0 = cube[0];
	char temp2 = cube[2];

	cube[0] = cube[6];
	cube[2] = cube[14];
	cube[6] = cube[20];
	cube[14] = cube[22];
	cube[20] = temp0;
	cube[22] = temp2;
}

//Left half of the front is rotated down
void Cube::leftFlipDown() {
	char temp0 = cube[0];
	char temp2 = cube[2];

	cube[0] = cube[20];
	cube[2] = cube[22];
	cube[20] = cube[6];
	cube[22] = cube[14];
	cube[6] = temp0;
	cube[14] = temp2;
}

//Right half of the front is rotated up
void Cube::rightFlipUp() {
	char temp1 = cube[1];
	char temp3 = cube[3];

	cube[1] = cube[7];
	cube[3] = cube[15];
	cube[7] = cube[21];
	cube[15] = cube[23];
	cube[21] = temp1;
	cube[23] = temp3;
}

//Right half of the front is rotated down
void Cube::rightFlipDown() {
	char temp1 = cube[1];
	char temp3 = cube[3];

	cube[1] = cube[21];
	cube[3] = cube[23];
	cube[21] = cube[7];
	cube[23] = cube[15];
	cube[7] = temp1;
	cube[15] = temp3;

}

//Top half of the front is rotated to the right
void topRotateRight() {}

//Top half of the front is rotated to the left
void topRotateLeft() {}

//Bottom half of the front is rotated to the right
void bottomRotateRight() {}

//Bottom half of the front is rotated to the left
void bottomRotateLeft() {}

void poleCloseRight() {}
void poleCloseLeft() {}
void poleFarRight() {}
void poleFarLeft() {}