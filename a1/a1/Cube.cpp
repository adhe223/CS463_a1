#include "Cube.h"
#include <iostream>
#include <random>
#include <time.h>
#include <string>
using namespace std;

Cube::Cube() {
	char orig[24] = { 'y', 'y', 'y', 'y', 'o', 'o', 'b', 'b', 'r', 'r', 'g', 'g', 'o', 'o', 'b', 'b', 'r', 'r', 'g', 'g', 'w', 'w', 'w', 'w' };
	for (int i = 0; i < 24; i++) {
		cube[i] = orig[i];
	}

	moveCounter = 0;
}

Cube::~Cube() {}

void Cube::printCube() {
	cout << "  " << cube[10] << cube[11] << endl;
	cout << "  " << cube[18] << cube[19] << endl;
	cout << "  " << "--" << endl;
	cout << "  " << cube[0] << cube[1] << endl;
	cout << "  " << cube[2] << cube[3] << endl;
	cout << "  " << "--" << endl;
	for (int i = 4; i < 10; i++) { cout << cube[i]; }
	cout << endl;
	for (int i = 12; i < 18; i++) { cout << cube[i]; }
	cout << endl;
	cout << "  " << "--" << endl;
	cout << "  " << cube[20] << cube[21] << endl;
	cout << "  " << cube[22] << cube[23];
}

void Cube::shuffleCube(int numMoves) {
	srand(time(NULL));

	int count = 1;
	int oCount = 0;
	int bCount = 0;
	int gCount = 0;
	int rCount = 0;
	int wCount = 0;
	int yCount = 0;
	string operation;

	while (count <= numMoves) {
		if (count == 5) {
			int foo = 5;
		}

		int move = rand() % 12;

		switch (move) {
		case 0:
			leftFlipUp();
			operation = "leftFlipUp";
			break;
		case 1:
			leftFlipDown();
			operation = "leftFlipDown";
			break;
		case 2:
			rightFlipUp();
			operation = "rightFlipUp";
			break;
		case 3:
			rightFlipDown();
			operation = "rightFlipDown";
			break;
		case 4:
			topRotateRight();
			operation = "topRotateRight";
			break;
		case 5:
			topRotateLeft();
			operation = "topRotateLeft";
			break;
		case 6:
			bottomRotateRight();
			operation = "bottomRotateRight";
			break;
		case 7:
			bottomRotateLeft();
			operation = "bottomRotateLeft";
			break;
		case 8:
			poleCloseRight();
			operation = "poleCloseRight";
			break;
		case 9:
			poleCloseLeft();
			operation = "poleCloseLeft";
			break;
		case 10:
			poleFarRight();
			operation = "poleFarRight";
			break;
		case 11:
			poleFarLeft();
			operation = "poleFarLeft";
			break;
		default:
			break;
		}

		//Debugging
		for (int i = 0; i < 24; i++) {
			char c = cube[i];

			switch (c) {
			case 'o':
				oCount++;
				break;
			case 'y':
				yCount++;
				break;
			case 'r':
				rCount++;
				break;
			case 'b':
				bCount++;
				break;
			case 'g':
				gCount++;
				break;
			case 'w':
				wCount++;
				break;
			default:
				break;
			}
		}

		if (oCount > 4 || bCount > 4 || gCount > 4 || rCount > 4 || wCount > 4 || yCount > 4) {
			cout << endl << "Data Leak: " << "Iter: " << count << " - On operation " << operation << endl << endl;
		}

		if (count == numMoves) {
			cout << endl << "Iteration: " << count << endl;
			cout << "Orange Count: " << oCount << endl;
			cout << "Yellow Count: " << yCount << endl;
			cout << "Red Count: " << rCount << endl;
			cout << "Blue Count: " << bCount << endl;
			cout << "Green Count: " << gCount << endl;
			cout << "White Count: " << wCount << endl << endl;
		}

		oCount = 0;
		bCount = 0;
		gCount = 0;
		rCount = 0;
		wCount = 0;
		yCount = 0;

		count++;
	}
}

//Left half of the front is rotated up
void Cube::leftFlipUp() {
	char temp0 = cube[0];
	char temp2 = cube[2];
	char temp20 = cube[20];
	char temp22 = cube[22];

	cube[0] = cube[6];
	cube[2] = cube[14];
	cube[20] = cube[19];
	cube[22] = cube[11];
	cube[6] = temp20;
	cube[14] = temp22;
	cube[19] = temp0;
	cube[11] = temp2;

	//Will also alter the side
	char temp4 = cube[4];
	char temp13 = cube[13];

	cube[4] = cube[5];
	cube[13] = cube[12];
	cube[12] = temp4;
	cube[5] = temp13;
}

//Left half of the front is rotated down
void Cube::leftFlipDown() {
	char temp0 = cube[0];
	char temp2 = cube[2];
	char temp20 = cube[20];
	char temp22 = cube[22];

	cube[0] = cube[19];
	cube[2] = cube[11];
	cube[20] = cube[6];
	cube[22] = cube[14];
	cube[6] = temp0;
	cube[14] = temp2;
	cube[11] = temp22;
	cube[19] = temp20;

	//Will also alter the side
	char temp5 = cube[5];
	char temp12 = cube[12];

	cube[5] = cube[4];
	cube[12] = cube[13];
	cube[13] = temp5;
	cube[4] = temp12;
}

//Right half of the front is rotated up
void Cube::rightFlipUp() {
	char temp1 = cube[1];
	char temp3 = cube[3];
	char temp21 = cube[21];
	char temp23 = cube[23];

	cube[1] = cube[7];
	cube[3] = cube[15];
	cube[21] = cube[18];
	cube[23] = cube[10];
	cube[7] = temp21;
	cube[15] = temp23;
	cube[10] = temp3;
	cube[18] = temp1;

	//Will also alter the side
	char temp8 = cube[8];
	char temp17 = cube[17];

	cube[8] = cube[16];
	cube[17] = cube[9];
	cube[16] = temp17;
	cube[9] = temp8;
}

//Right half of the front is rotated down
void Cube::rightFlipDown() {
	char temp1 = cube[1];
	char temp3 = cube[3];
	char temp21 = cube[21];
	char temp23 = cube[23];

	cube[1] = cube[18];
	cube[3] = cube[10];
	cube[21] = cube[7];
	cube[23] = cube[15];
	cube[7] = temp1;
	cube[15] = temp3;
	cube[10] = temp23;
	cube[18] = temp21;

	//Will also alter the side
	char temp8 = cube[8];
	char temp17 = cube[17];

	cube[8] = cube[9];
	cube[17] = cube[16];
	cube[16] = temp8;
	cube[9] = temp17;
}

//Top half of the front is rotated to the right
void Cube::topRotateRight() {
	char temp6 = cube[6];
	char temp7 = cube[7];
	char temp10 = cube[10];
	char temp11 = cube[11];

	cube[6] = cube[4];
	cube[7] = cube[5];
	cube[10] = cube[8];
	cube[11] = cube[9];
	cube[8] = temp6;
	cube[9] = temp7;
	cube[4] = temp10;
	cube[5] = temp11;

	//Will also alter the top
	char temp0 = cube[0];
	char temp3 = cube[3];

	cube[0] = cube[1];
	cube[3] = cube[2];
	cube[1] = temp3;
	cube[2] = temp0;
}

//Top half of the front is rotated to the left
void Cube::topRotateLeft() {
	char temp6 = cube[6];
	char temp7 = cube[7];
	char temp10 = cube[10];
	char temp11 = cube[11];

	cube[6] = cube[8];
	cube[7] = cube[9];
	cube[10] = cube[4];
	cube[11] = cube[5];
	cube[8] = temp10;
	cube[9] = temp11;
	cube[4] = temp6;
	cube[5] = temp7;

	//Will also alter the top
	char temp0 = cube[0];
	char temp3 = cube[3];

	cube[0] = cube[2];
	cube[3] = cube[1];
	cube[1] = temp0;
	cube[2] = temp3;
}

//Bottom half of the front is rotated to the right
void Cube::bottomRotateRight() {
	char temp14 = cube[14];
	char temp15 = cube[15];
	char temp18 = cube[18];
	char temp19 = cube[19];

	cube[14] = cube[12];
	cube[15] = cube[13];
	cube[18] = cube[16];
	cube[19] = cube[17];
	cube[16] = temp14;
	cube[17] = temp15;
	cube[12] = temp18;
	cube[13] = temp19;

	//Will alter the bottom
	char temp21 = cube[21];
	char temp22 = cube[22];

	cube[21] = cube[20];
	cube[22] = cube[23];
	cube[20] = temp22;
	cube[23] = temp21;
}

//Bottom half of the front is rotated to the left
void Cube::bottomRotateLeft() {
	char temp14 = cube[14];
	char temp15 = cube[15];
	char temp18 = cube[18];
	char temp19 = cube[19];

	cube[14] = cube[16];
	cube[15] = cube[17];
	cube[18] = cube[12];
	cube[19] = cube[13];
	cube[16] = temp18;
	cube[17] = temp19;
	cube[12] = temp14;
	cube[13] = temp15;

	//Will alter the bottom
	char temp21 = cube[21];
	char temp22 = cube[22];

	cube[21] = cube[23];
	cube[22] = cube[20];
	cube[20] = temp21;
	cube[23] = temp22;
}

//The half of the top of the cube closest is rotated right
void Cube::poleCloseRight() {
	char temp2 = cube[2];
	char temp3 = cube[3];
	char temp20 = cube[20];
	char temp21 = cube[21];

	cube[2] = cube[13];
	cube[3] = cube[5];
	cube[20] = cube[16];
	cube[21] = cube[8];
	cube[8] = temp2;
	cube[16] = temp3;
	cube[5] = temp20;
	cube[13] = temp21;

	//Changes the front
	char temp6 = cube[6];
	char temp15 = cube[15];

	cube[6] = cube[14];
	cube[15] = cube[7];
	cube[14] = temp15;
	cube[7] = temp6;
}

//The half of the top of the cube closest is rotated left
void Cube::poleCloseLeft() {
	char temp2 = cube[2];
	char temp3 = cube[3];
	char temp20 = cube[20];
	char temp21 = cube[21];

	cube[2] = cube[8];
	cube[3] = cube[16];
	cube[20] = cube[5];
	cube[21] = cube[13];
	cube[8] = temp21;
	cube[16] = temp20;
	cube[5] = temp3;
	cube[13] = temp2;

	//Changes the front
	char temp6 = cube[6];
	char temp15 = cube[15];

	cube[6] = cube[7];
	cube[15] = cube[14];
	cube[14] = temp6;
	cube[7] = temp15;
}

//The half of the top of the cube furthest is rotated right
void Cube::poleFarRight() {
	char temp0 = cube[0];
	char temp1 = cube[1];
	char temp22 = cube[22];
	char temp23 = cube[23];

	cube[0] = cube[12];
	cube[1] = cube[4];
	cube[22] = cube[17];
	cube[23] = cube[9];
	cube[9] = temp0;
	cube[17] = temp1;
	cube[4] = temp22;
	cube[12] = temp23;

	//Changes the back
	char temp10 = cube[10];
	char temp19 = cube[19];

	cube[10] = cube[11];
	cube[19] = cube[18];
	cube[11] = temp19;
	cube[18] = temp10;
}

//The half of the top of the cube furthest is rotated left
void Cube::poleFarLeft() {
	char temp0 = cube[0];
	char temp1 = cube[1];
	char temp22 = cube[22];
	char temp23 = cube[23];

	cube[0] = cube[9];
	cube[1] = cube[17];
	cube[22] = cube[4];
	cube[23] = cube[12];
	cube[9] = temp23;
	cube[17] = temp22;
	cube[4] = temp1;
	cube[12] = temp0;

	//Changes the back
	char temp10 = cube[10];
	char temp19 = cube[19];

	cube[10] = cube[18];
	cube[19] = cube[11];
	cube[11] = temp10;
	cube[18] = temp19;
}

//Translates the move on a certain face to the equivalent move from the perspective of the front (solved blue side, 2)
void Cube::move(int face, string move) {
	switch (face) {
	case 0:
		if (move == "leftFlipUp") { leftFlipUp(); }
		else if (move == "leftFlipDown") { leftFlipDown(); }
		else if (move == "rightFlipUp") { rightFlipUp(); }
		else if (move == "rightFlipDown") { rightFlipDown(); }
		else if (move == "topRotateRight") { poleFarRight(); }
		else if (move == "topRotateLeft") { poleFarLeft(); }
		else if (move == "bottomRotateRight") { poleCloseRight(); }
		else if (move == "bottomRotateLeft") { poleCloseLeft(); }
		else if (move == "poleCloseRight") { topRotateLeft(); }
		else if (move == "poleCloseLeft") { topRotateRight(); }
		else if (move == "poleFarLeft") { bottomRotateRight(); }
		else if (move == "poleFarRight") { bottomRotateLeft(); }
		moveCounter++;
		break;
	case 1:
		if (move == "leftFlipUp") { poleFarRight(); }
		else if (move == "leftFlipDown") { poleFarLeft(); }
		else if (move == "rightFlipUp") { poleCloseRight(); }
		else if (move == "rightFlipDown") { poleCloseLeft(); }
		else if (move == "topRotateRight") { topRotateRight(); }
		else if (move == "topRotateLeft") { topRotateLeft(); }
		else if (move == "bottomRotateRight") { bottomRotateRight(); }
		else if (move == "bottomRotateLeft") { bottomRotateLeft(); }
		else if (move == "poleCloseRight") { leftFlipDown(); }
		else if (move == "poleCloseLeft") { leftFlipUp(); }
		else if (move == "poleFarLeft") { rightFlipUp(); }
		else if (move == "poleFarRight") { rightFlipDown(); }
		moveCounter++;
		break;
		//case 2 is our front
	case 2:
		if (move == "leftFlipUp") { leftFlipUp(); }
		else if (move == "leftFlipDown") { leftFlipDown(); }
		else if (move == "rightFlipUp") { rightFlipUp(); }
		else if (move == "rightFlipDown") { rightFlipDown(); }
		else if (move == "topRotateRight") { topRotateRight(); }
		else if (move == "topRotateLeft") { topRotateLeft(); }
		else if (move == "bottomRotateRight") { bottomRotateRight(); }
		else if (move == "bottomRotateLeft") { bottomRotateLeft(); }
		else if (move == "poleCloseRight") { poleCloseRight(); }
		else if (move == "poleCloseLeft") { poleCloseLeft(); }
		else if (move == "poleFarLeft") { poleFarLeft(); }
		else if (move == "poleFarRight") { poleFarRight(); }
		moveCounter++;
		break;
	case 3:
		if (move == "leftFlipUp") { poleCloseLeft(); }
		else if (move == "leftFlipDown") { poleCloseRight(); }
		else if (move == "rightFlipUp") { poleFarLeft(); }
		else if (move == "rightFlipDown") { poleFarRight(); }
		else if (move == "topRotateRight") { topRotateRight(); }
		else if (move == "topRotateLeft") { topRotateLeft(); }
		else if (move == "bottomRotateRight") { bottomRotateRight(); }
		else if (move == "bottomRotateLeft") { bottomRotateLeft(); }
		else if (move == "poleCloseRight") { rightFlipUp(); }
		else if (move == "poleCloseLeft") { rightFlipDown(); }
		else if (move == "poleFarLeft") { leftFlipDown(); }
		else if (move == "poleFarRight") { leftFlipUp(); }
		moveCounter++;
		break;
	case 4:
		if (move == "leftFlipUp") { rightFlipDown(); }
		else if (move == "leftFlipDown") { rightFlipUp(); }
		else if (move == "rightFlipUp") { leftFlipDown(); }
		else if (move == "rightFlipDown") { leftFlipUp(); }
		else if (move == "topRotateRight") { topRotateRight(); }
		else if (move == "topRotateLeft") { topRotateLeft(); }
		else if (move == "bottomRotateRight") { bottomRotateRight(); }
		else if (move == "bottomRotateLeft") { bottomRotateLeft(); }
		else if (move == "poleCloseRight") { poleFarLeft(); }
		else if (move == "poleCloseLeft") { poleFarRight(); }
		else if (move == "poleFarLeft") { poleCloseRight(); }
		else if (move == "poleFarRight") { poleCloseLeft(); }
		moveCounter++;
		break;
	case 5:
		if (move == "leftFlipUp") { leftFlipUp(); }
		else if (move == "leftFlipDown") { leftFlipDown(); }
		else if (move == "rightFlipUp") { rightFlipUp(); }
		else if (move == "rightFlipDown") { rightFlipDown(); }
		else if (move == "topRotateRight") { poleCloseLeft(); }
		else if (move == "topRotateLeft") { poleCloseRight(); }
		else if (move == "bottomRotateRight") { poleFarLeft(); }
		else if (move == "bottomRotateLeft") { poleFarRight(); }
		else if (move == "poleCloseRight") { bottomRotateRight(); }
		else if (move == "poleCloseLeft") { bottomRotateLeft(); }
		else if (move == "poleFarLeft") { topRotateLeft(); }
		else if (move == "poleFarRight") { topRotateRight(); }
		moveCounter++;
		break;
	default:	//If face input is invalide
		cout << "Face input is invalid" << endl;
		break;
	}
}