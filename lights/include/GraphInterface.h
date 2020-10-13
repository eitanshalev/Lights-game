#pragma once
#include <vector>
#include "Light.h"
#include "Point.h"
#include <algorithm>
#include "Globals.h"

//-----------------------------------------------------------
//_____________________GraphInterface_________________________________
//
//This Class manages all the things connect to manage interface interaction eith user
// this class controls of ewhat the user should see while playing this game.
// for instance, the way the points seems of the board, their color, etc...
//-----------------------------------------------------------

class GraphInterface {  //each light contain point in the game axctulally
public:
	~GraphInterface();
	void rotate(int, int direction);
	void clearLevel() { m_lights.clear(); }
	void draw(sf::RenderTarget& target) const;
	//an interatoer that run all over the points.
	void setEdges(const std::vector<Point>& points);
	void updateLights(const std::vector<Point>& points);
	//print all points(corrent garph with his update details).
	void updateCurrentLevel(std::vector<sf::Vector2f > &allpoints);


private:
	std::vector<Light> m_lights; // all the data srtucture
	//data dtructur of points*.


};


