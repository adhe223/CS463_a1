#include "Cube.h"
#include <iostream>
#include <random>
#include <time.h>
#include <string>
#include <map>
using namespace std;

Cube::Cube() {
	char orig[24] = { 'y', 'y', 'y', 'y', 'o', 'o', 'b', 'b', 'r', 'r', 'g', 'g', 'o', 'o', 'b', 'b', 'r', 'r', 'g', 'g', 'w', 'w', 'w', 'w' };
	for (int i = 0; i < 24; i++) {
		cube[i] = orig[i];
	}

	for (int i = 0; i < 3; i++) { //3 because of size of history array
		history[i] = "";
	}

	moveCounter = 0;

	//Initialize the maps that will translate moves on different faces to a move based on a single
	//perspective.
	trans0["leftFlipUp"] = "leftFlipUp";
	trans0["leftFlipDown"] = "leftFlipDown";
	trans0["rightFlipUp"] = "rightFlipUp";
	trans0["rightFlipDown"] = "rightFlipDown";
	trans0["topRotateRight"] = "poleFarRight";
	trans0["topRotateLeft"] = "poleFarLeft";
	trans0["bottomRotateRight"] = "poleCloseRight";
	trans0["bottomRotateLeft"] = "poleCloseLeft";
	trans0["poleCloseRight"] = "topRotateLeft";
	trans0["poleCloseLeft"] = "topRotateRight";
	trans0["poleFarLeft"] = "bottomRotateRight";
	trans0["poleFarRight"] = "bottomRotateLeft";

	trans1["leftFlipUp"] = "poleFarRight";
	trans1["leftFlipDown"] = "poleFarLeft";
	trans1["rightFlipUp"] = "poleCloseRight";
	trans1["rightFlipDown"] = "poleCloseLeft";
	trans1["topRotateRight"] = "topRotateRight";
	trans1["topRotateLeft"] = "topRotateLeft";
	trans1["bottomRotateRight"] = "bottomRotateRight";
	trans1["bottomRotateLeft"] = "bottomRotateLeft";
	trans1["poleCloseRight"] = "leftFlipDown";
	trans1["poleCloseLeft"] = "leftFlipUp";
	trans1["poleFarLeft"] = "rightFlipUp";
	trans1["poleFarRight"] = "rightFlipDown";

	trans2["leftFlipUp"] = "leftFlipUp";
	trans2["leftFlipDown"] = "leftFlipDown";
	trans2["rightFlipUp"] = "rightFlipUp";
	trans2["rightFlipDown"] = "rightFlipDown";
	trans2["topRotateRight"] = "topRotateRight";
	trans2["topRotateLeft"] = "topRotateLeft";
	trans2["bottomRotateRight"] = "bottomRotateRight";
	trans2["bottomRotateLeft"] = "bottomRotateLeft";
	trans2["poleCloseRight"] = "poleCloseRight";
	trans2["poleCloseLeft"] = "poleCloseLeft";
	trans2["poleFarLeft"] = "poleFarLeft";
	trans2["poleFarRight"] = "poleFarRight";

	trans3["leftFlipUp"] = "poleCloseLeft";
	trans3["leftFlipDown"] = "poleCloseRight";
	trans3["rightFlipUp"] = "poleFarLeft";
	trans3["rightFlipDown"] = "poleFarRight";
	trans3["topRotateRight"] = "topRotateRight";
	trans3["topRotateLeft"] = "topRotateLeft";
	trans3["bottomRotateRight"] = "bottomRotateRight";
	trans3["bottomRotateLeft"] = "bottomRotateLeft";
	trans3["poleCloseRight"] = "rightFlipUp";
	trans3["poleCloseLeft"] = "rightFlipDown";
	trans3["poleFarLeft"] = "leftFlipDown";
	trans3["poleFarRight"] = "leftFlipUp";

	trans4["leftFlipUp"] = "rightFlipDown";
	trans4["leftFlipDown"] = "rightFlipUp";
	trans4["rightFlipUp"] = "leftFlipDown";
	trans4["rightFlipDown"] = "leftFlipUp";
	trans4["topRotateRight"] = "topRotateRight";
	trans4["topRotateLeft"] = "topRotateLeft";
	trans4["bottomRotateRight"] = "bottomRotateRight";
	trans4["bottomRotateLeft"] = "bottomRotateLeft";
	trans4["poleCloseRight"] = "poleFarLeft";
	trans4["poleCloseLeft"] = "poleFarRight";
	trans4["poleFarLeft"] = "poleCloseRight";
	trans4["poleFarRight"] = "poleCloseLeft";

	trans5["leftFlipUp"] = "leftFlipUp";
	trans5["leftFlipDown"] = "leftFlipDown";
	trans5["rightFlipUp"] = "rightFlipUp";
	trans5["rightFlipDown"] = "rightFlipDown";
	trans5["topRotateRight"] = "poleCloseLeft";
	trans5["topRotateLeft"] = "poleCloseRight";
	trans5["bottomRotateRight"] = "poleFarLeft";
	trans5["bottomRotateLeft"] = "poleFarRight";
	trans5["poleCloseRight"] = "bottomRotateRight";
	trans5["poleCloseLeft"] = "bottomRotateLeft";
	trans5["poleFarLeft"] = "topRotateLeft";
	trans5["poleFarRight"] = "topRotateRight";
}

Cube::~Cube() {}

void Cube::printCube() {
	cout << "  " << cube[0] << cube[1] << endl;
	cout << "  " << cube[2] << cube[3] << endl;
	cout << "  " << "--" << endl;
	for (int i = 4; i < 12; i++) { cout << cube[i]; }
	cout << endl;
	for (int i = 12; i < 20; i++) { cout << cube[i]; }
	cout << endl;
	cout << "  " << "--" << endl;
	cout << "  " << cube[20] << cube[21] << endl;
	cout << "  " << cube[22] << cube[23];
}

void Cube::shuffleCube(int numMoves) {
	srand(time(NULL));

	int count = 1;
	string operation;
	bool execute = true;

	while (count <= numMoves) {
		int action = rand() % 12;
		int face = rand() % 6;

		switch (action) {
		case 0:
			execute = move(face, "leftFlipUp");
			operation = "leftFlipUp";
			break;
		case 1:
			execute = move(face, "leftFlipDown");
			operation = "leftFlipDown";
			break;
		case 2:
			execute = move(face, "rightFlipUp");
			operation = "rightFlipUp";
			break;
		case 3:
			execute = move(face, "rightFlipDown");
			operation = "rightFlipDown";
			break;
		case 4:
			execute = move(face, "topRotateRight");
			operation = "topRotateRight";
			break;
		case 5:
			execute = move(face, "topRotateLeft");
			operation = "topRotateLeft";
			break;
		case 6:
			execute = move(face, "bottomRotateRight");
			operation = "bottomRotateRight";
			break;
		case 7:
			execute = move(face, "bottomRotateLeft");
			operation = "bottomRotateLeft";
			break;
		case 8:
			execute = move(face, "poleCloseRight");
			operation = "poleCloseRight";
			break;
		case 9:
			execute = move(face, "poleCloseLeft");
			operation = "poleCloseLeft";
			break;
		case 10:
			execute = move(face, "poleFarRight");
			operation = "poleFarRight";
			break;
		case 11:
			execute = move(face, "poleFarLeft");
			operation = "poleFarLeft";
			break;
		default:
			break;
		}

		if (execute) {
			count++;
		}
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
bool Cube::move(int face, string inMove) {
	//Defend against cases in which the movement would be pointless
	bool execute = false;

	inMove = translate(face, inMove);	//First translate to the front perspective

	//Defend against the same move four times in a row. Use the history array
	//First check if the proposed move and face are the same as the previous 3
	bool same = true;
	for (int i = 0; i < 3; i++) {
		if (inMove != history[i]) {
			same = false;
		}
	}

	//Defend against opposing moves are made back to back (leftFlipUp then leftFlipDown)
	//I figured out that if the first 5 characters of two moves are the same but the strings
	//as a whole are not the same then the moves will cancel. Thus I use this rule to test
	//that two moves that will cancel each other are not used consecutively.
	bool cancel = false;
	if (inMove.substr(0, 5) == history[0].substr(0, 5) && inMove != history[0]) {	//0 is the most recent move
		cancel = true;
	}

	//If conditions are met, then execute the move
	if (!same && !cancel) {
		execute = true;
	}
	if (execute) {
		executeMove(inMove);
	}

	return execute;	//Allows us to know if a move was decided to be useful and made
}

string Cube::translate(int face, string move) {
	switch (face) {
	case 0:
		move = trans0[move];
		/*if (move == "leftFlipUp") { leftFlipUp(); }
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
		else if (move == "poleFarRight") { bottomRotateLeft(); }*/
		break;
	case 1:
		move = trans1[move];
		/*if (move == "leftFlipUp") { poleFarRight(); }
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
		else if (move == "poleFarRight") { rightFlipDown(); }*/
		break;
		//case 2 is our front
	case 2:
		move = trans2[move];
		/*if (move == "leftFlipUp") { leftFlipUp(); }
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
		else if (move == "poleFarRight") { poleFarRight(); }*/
		break;
	case 3:
		move = trans3[move];
		/*if (move == "leftFlipUp") { poleCloseLeft(); }
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
		else if (move == "poleFarRight") { leftFlipUp(); }*/
		break;
	case 4:
		move = trans4[move];
		/*if (move == "leftFlipUp") { rightFlipDown(); }
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
		else if (move == "poleFarRight") { poleCloseLeft(); }*/
		break;
	case 5:
		move = trans5[move];
		/*if (move == "leftFlipUp") { leftFlipUp(); }
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
		else if (move == "poleFarRight") { topRotateRight(); }*/
		break;
	default:	//If face input is invalid
		cout << "Face input is invalid" << endl;
		break;
	}

	return move;
}

void Cube::executeMove(string move) {
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

	//Update the history array
	for (int i = HISTORY_SIZE - 1; i > 0; i--) {
		history[i] = history[i - 1];	//Move values back to make room for the new move
	}
	history[0] = move;	//Set the most recent move

	moveCounter++;
}