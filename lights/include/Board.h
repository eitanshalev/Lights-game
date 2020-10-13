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
	void GraphsManufacture(int size); // ����� ����� ����� ��� ��� �� �� �������m_graphInterface�� ����� �� ���� ����� �
private:

	std::vector<std::pair<double, double>> m_points;//��� ������ �� ������� ���� ������ ��� ��� ����� ���� ����� �� �� �� �� �� ����� ������
	GraphInterface m_graphInterface;
	Graph m_graph;
	sf::Font font;
};