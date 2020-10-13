
#include "GraphInterface.h"

GraphInterface::~GraphInterface()
{
	m_lights.clear();
}


void GraphInterface::updateCurrentLevel(std::vector<sf::Vector2f >& allpoints)
{
	//	std::for_each(allpoints.begin(), allpoints.end(), [m_lights](auto& p) {m_lights.emplace_back(p); });
	for (const auto e : allpoints)
	{
		m_lights.emplace_back(e);
	}
}


void GraphInterface::updateLights(const std::vector<Point>& points)
{
	for (int i = 0; i < m_lights.size(); i++)
	{
		if (points[i].isConnected())
			m_lights[i].setGreen();

		else m_lights[i].reset();
	}
}

void GraphInterface::setEdges(const std::vector<Point>& points)
{
	for (int i = 0; i < m_lights.size(); i++)
		m_lights[i].setEdgesCurrPoint(points[i].getEdges());
}

void GraphInterface::draw(sf::RenderTarget& target) const
{

	//for(const auto& light : m_lights)
	//{
	//	light.draw(target);
	//}

	std::for_each(m_lights.begin(), m_lights.end(), [&target](auto light) {light.draw(target); });

}

void GraphInterface::rotate(int rotationIndex, int direction)
{
	if (rotationIndex <= m_lights.size() - 1)
	{
		if (direction == RIGHT)
		{
			m_lights[rotationIndex].rotate(direction);
		}
		else
		{
			m_lights[rotationIndex].rotate(direction);
		}
	}
}


