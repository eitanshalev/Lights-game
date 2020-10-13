#include "Point.h"

Point::~Point()
{
	m_neighbors.clear();
}

void Point::updateNeighbors(std::vector<int> indexes)
{
	m_neighbors = indexes;
}

void Point::rotate(int direction)
{
	if (direction == LEFT)
	{
		std::rotate(m_edges.begin(), m_edges.begin() + m_edges.size() - 1, m_edges.end());
	}
	else
	{
		int first = m_edges[0];
		for (int i = 0; i < m_edges.size() - 1; i++)
			m_edges[i] = m_edges[i + 1];
		m_edges[m_edges.size() - 1] = first;
	}
}

bool Point::rotate(double x, double y, int 	direction)
{
	if (abs(m_location.first - x) <= SPACE/TWO && abs(m_location.second - y) <= SPACE/TWO)
	{
		rotate(direction);
		return true;
	}
	return false;
}



void Point::createEdges()
{
	int numofedges = rand() % DIFFICULTY;// = rand() % m_neighbors.size() - 1;

	for (int i = 0; i < numofedges; i++)
	{
		auto edge = rand() % 6;
		if (m_edges[edge] == 0)
		{
			m_edges[edge] = 1;
		}
		else
			i--;
	}

}