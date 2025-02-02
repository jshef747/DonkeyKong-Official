#pragma once
#include "point.h"
#include "npc.h"

class ghost : public npc
{
	static constexpr Direction directionsGhost[] = { {-1, 0}, {1, 0} };
	enum directions {dir_LEFT, dir_RIGHT };
	static constexpr int  LEFT = -1, RIGHT = 1;
	static constexpr char icon = 'x';
	static constexpr char SGHOST = 'X';
public:
	ghost();
	void move(bool silent = false) override;
	bool checkFloorEdge();
	virtual void changeDirection();
	void handleGhostCollision(int x, int y) const;
};

