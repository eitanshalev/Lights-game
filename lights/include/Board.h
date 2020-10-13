#pragma once
#include <SFML/Graphics.hpp>
#include "GraphInterface.h"
#include "Graph.h"
#include "Globals.h"
//-----------------------------------------------------------
//_____________________Board_________________________________
//
//This Class manages all the things connect to manage board
// for instance, here we create a new board, 
// here we run the game, getting commands fron user, clearing 
// current level . 
//-----------------------------------------------------------

class Board{
public:
	void clearLevel();
	void Create_level();
	void run(int level);
	void continu_game(sf::Text & message, int level);
	void GraphsManufacture(int size); // ולגרף הרגיל ונשלח לכל אחד את כל הנקודותm_graphInterfaceפה נייצר את הגרף ונקרא ל
private:

	std::vector<std::pair<double, double>> m_points;//כאן ממירים את הנקודות עבור דאבלים כדי שלא נשתמש בכלל בממשק של אס אף אם אל כנדרש בתרגיל
	GraphInterface m_graphInterface;
	Graph m_graph;
	sf::Font font;
};