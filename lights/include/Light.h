#pragma once
#include <array>
#include "Globals.h"
#include <SFML/Graphics.hpp>


//-----------------------------------------------------------
//_____________________light_________________________________
//
//This Class manages all about simple point - helps the Graph do
// some mathematic graphic interface the user should see. 
//-----------------------------------------------------------

constexpr auto maxEdges = MAXEDGES;
constexpr auto lightSize = FIVE;
constexpr auto edgeWidth = EDGEWIDBASE / TWO;
constexpr auto edgeLength = ((SPACE + EDGEADDITION) / 3);
constexpr auto& edgeColor = sf::Color::White;
constexpr auto& centerColor = sf::Color::Green;
constexpr auto& pointColor = sf::Color::Magenta;
constexpr auto rotation = 60.f;


class Light {  //each light contain point in the game axctulally
public:
	void changeColor();
	void rotate(int direction);
	Light(sf::Vector2f location);
	void draw(sf::RenderTarget& window) const;
	void setEdgesCurrPoint(std::array<int, 6> edges);
	void reset() { m_light.setFillColor(pointColor); }
	void setGreen() { m_light.setFillColor(centerColor); }

private:
	bool m_isON = false;
	std::vector<sf::RectangleShape> m_edges;
	sf::Vector2f m_location;    //the corrent location of a point
	sf::CircleShape m_light;	//to draw the corrent cicrle			 //represents the lines.  the (maximum) 6  point that aroud each point 

};


