class Cube {
public:
	Cube();
	~Cube();

	void printCube();

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

private:
	char cube[24];
};