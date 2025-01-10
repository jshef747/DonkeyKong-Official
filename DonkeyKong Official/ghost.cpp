#include "ghost.h"
ghost::ghost() : npc(icon)
{
	int i = rand() % 2; // random number between 0 and 2
	setDir(directionsGhost[i]);
}

bool ghost::checkFloorEdge()
{
    int currX = getX(), currY = getY();
    if ((getChar(currX + 1, currY + 1) != '<' && getChar(currX + 1, currY + 1) != '>' && getChar(currX + 1, currY + 1) != '=') && getDirX() == RIGHT) // if the ghost is at the edge of the floor and moving right
        return true;

    if ((getChar(currX - 1, currY + 1) != '<' && getChar(currX - 1, currY + 1) != '>' && getChar(currX - 1, currY + 1) != '=') && getDirX() == LEFT) // if the ghost is at the edge of the floor and moving left
        return true;
    
    return false;
}

void ghost::changeDirection()
{
	if (getDirX() == LEFT)
		setDir(directionsGhost[dir_RIGHT]);
	else
		setDir(directionsGhost[dir_LEFT]);
}

void ghost::move()
{
	int currX = getX(), currY = getY();
	int newX = currX, newY = currY;
	int randChangeDir = 1 + rand() % 101; // random number between 1 and 100

	int currDir = getDirX();
	if (randChangeDir <= 5 || checkFloorEdge() || (getFailChart(currX + 1, currY) == icon && currDir == RIGHT) || (getFailChart(currX - 1, currY) == icon && currDir == LEFT)) // if the random number is less than 5 or the ghost is at the edge of the floor or ghost moves to each other
		changeDirection();
	currDir = getDirX();

	newX = currX + currDir; // update the new X position
	setFailChart(' '); // erase the ghost from the fail chart	
	setPosition(newX, newY); // update the position of the ghost
	if (checkSmash())
	{
		
		setFailChart(' ');
		setSmash();
		deactivate();
	}
	else
		setFailChart(icon);

	gotoxy(currX, currY);
	std::cout << getChar(currX, currY); // restore the previous character on the screen
}


