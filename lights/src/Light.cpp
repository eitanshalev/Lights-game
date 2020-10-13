#include "Light.h"


Light::Light(sf::Vector2f location) : m_location(location), m_light(lightSize)
{
	m_light.setOrigin(m_light.getRadius(), m_light.getRadius());
	m_light.setPosition(m_location);
	m_light.setFillColor(pointColor);
}


void Light::draw(sf::RenderTarget& window) const
{
	window.draw(m_light);

	for (const auto& e : m_edges)
	{
		window.draw(e);
	}
}



void Light::setEdgesCurrPoint(std::array<int, 6> edges)
{
	static bool firstTime = true;
	//const auto edgeCount = rand() % maxEdges;
	for (auto i = 0; i < edges.size(); ++i)
	{
		if (edges[i] == 1) {

			m_edges.push_back(sf::RectangleShape({ edgeWidth, edgeLength }));
			auto& e = m_edges.back();
			e.setFillColor(edgeColor);
			e.setOrigin(e.getSize().x / TWO, -m_light.getRadius());
			e.setPosition(m_light.getPosition());

			e.setRotation((rotation * (-i)) + 270.f);
			firstTime = false;
		}
	}
}

void Light::changeColor()
{
	m_light.setFillColor(sf::Color::Green);
}



void Light::rotate(int direction) {

	{
		if (direction == RIGHT)
		{
			for (auto& e : m_edges)
			{
				e.rotate(rotation);
			}
		}
		else
		{
			for (auto& e : m_edges)
			{
				e.rotate(-rotation);
			}
		}
	}
}