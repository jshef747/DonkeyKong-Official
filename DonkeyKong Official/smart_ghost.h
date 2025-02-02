#pragma once
#include "ghost.h"

class smart_ghost : public ghost
{
	enum directions { LEFT, RIGHT, UP , DOWN };
	static constexpr Direction directionsSGhost[] = { {-1,0}, {1, 0}, {0, -1}, {0, 1} };
	static constexpr char icon = 'X';
	static constexpr char GHOST = 'x';
	bool climb = false;
	bool down = false;
public:
	smart_ghost();
	bool checkBelowLadder() const; // can up
	bool checkAboveLadder() const; // can down
	void changeVerticalDirection();
	void changeDirection() override;
	void move(bool silent = false) override;
	void smartMoveLogic(int marioX, int marioY, int currX, int currY);
	void handleVerCollision(int x, int y) const;
};

