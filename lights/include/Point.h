#pragma once
#include <array>
#include <vector>
#include <iostream>
#include "Light.h"
#include "Globals.h"

//-----------------------------------------------------------
//_____________________Point_________________________________
//
//This Class manages all about simple point - helps the Graph do
// some mathematic calculators 
//-----------------------------------------------------------

class Point {  //each light contain point in the game axctulally
public:
	~Point();
	void createEdges();
	void rotate(int direction);
	void checked() { m_checked = true; }
	void uncheck() { m_checked = false; }
	void connect() { m_connected = true; }
	bool isChecked() { return m_checked; }
//	void findMST(); //minimum spaning tree 
	void disconnect() { m_connected = false; }
	bool rotate(double x, double y, int	direction);
	void addEdge(int index) { m_edges[index] = 1; }
	bool isConnected() const { return m_connected ; }
	std::array<int, 6> getEdges() const { return m_edges; }
	std::vector<int> getNeighbours() { return m_neighbors; }
	void setEdges(std::array<int,6> edges) { m_edges = edges; }
	//void drawNeighbours(sf::Vector2f location, sf::RenderTarget&);
	std::pair<double, double> location() const { return m_location; }
	void updateNeighbors(std::vector<int>); //{ m_neighbors = points; }
	Point(std::pair<double, double> location) :m_location(location) {  }
private:
	bool m_connected = false;
	std::vector<int> m_neighbors;
	std::pair<double, double> m_location;
	std::array<int, 6> 	m_edges = { {0} };
	bool m_checked = false;//fro the create level functiin we use this member

};


