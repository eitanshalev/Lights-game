#pragma once
#include <vector>
#include <cmath>     /* abs */
#include "Point.h"
#include <array>
#include <algorithm>    // std::count
#include <cstdlib>
#include "Point.h"
#include <random>


//-----------------------------------------------------------
//_____________________Graph_________________________________
//
//This Class manages all the things connect to manage mathematical interaction eith user
// this class controls of the thinking the way everithing should work backgrounds.
//-----------------------------------------------------------

class Graph {  //each light contain point in the game axctulally
public:

	void clearLevel();
	void createEdges();	
	bool checkFinish();
	void shuffleEdges();
	void uncheckPoints();
	void setPointsNeighbors();
	~Graph() { m_points.clear(); }
	void createTree(int index, int edgeIndex);
	void connectPoints(int index, int edgeIndex);
	int rotate(double x, double y, int direction);
	std::vector<Point> getPoints() const { return m_points; } 
	void updateCurrentLevel(std::vector<std::pair<double, double>>& allpointsgraph);
	bool validNeighbor(const std::pair<double, double> myLocation, const std::pair<double, double> neighborLocation, int edgeIndex) const;

private:
	std::vector<Point> m_points;
};


