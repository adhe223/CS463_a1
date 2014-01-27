#include <string>
#include <map>
using namespace std;

class Cube {
public:
	Cube();
	~Cube();

	void printCube();
	void shuffleCube(int numMoves);

	//Method that allows user input. It takes in a face number and maps that to the
	//equivalent move from the perspective of out "front" side (the unsolved blue side).
	//[Top is 0, Left is 1, Front is 2, Right is 3, Back is 4, Bottom is 5]
	bool move(int face, std::string move);

private:
	char cube[24];
	int moveCounter; //Counter for the move function to manipulate so we know how long it takes to solve
	std::string history[3];	//History we use to prevent wasteful moves
	const int HISTORY_SIZE = 3;
	std::map<string, string> trans0;
	std::map<string, string> trans1;
	std::map<string, string> trans2;
	std::map<string, string> trans3;
	std::map<string, string> trans4;
	std::map<string, string> trans5;

	//Helper function to take a move on a face and translate it to the front perspective
	string translate(int face, string move);
	void executeMove(string move);

	//Helper functions to turn the cube
	//All descriptions for the following methods are relative to the perspective
	//that blue is facing us with yellow on top 
	void leftFlipUp();			//Left half of the front is rotated up
	void leftFlipDown();		//Left half of the front is rotated down
	void rightFlipUp();			//Right half of the front is rotated up
	void rightFlipDown();		//Right half of the front is rotated down
	void topRotateRight();		//Top half of the front is rotated to the right
	void topRotateLeft();		//Top half of the front is rotated to the left
	void bottomRotateRight();	//Bottom half of the front is rotated to the right
	void bottomRotateLeft();	//Bottom half of the front is rotated to the left
	void poleCloseRight();		//The half of the top of the cube closest is rotated right
	void poleCloseLeft();		//The half of the top of the cube closest is rotated left
	void poleFarRight();		//The half of the top of the cube furthest is rotated right
	void poleFarLeft();			//The half of the top of the cube furthest is rotated left
};