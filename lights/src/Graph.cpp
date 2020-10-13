#include "Graph.h"


void Graph::setPointsNeighbors()
{
	for (int p1 = 0; p1 < m_points.size(); p1++)
	{

		std::vector<int> neighbors; //define the neigbors for a corrent point! :)

		for (int p2 = 0; p2 < m_points.size(); p2++)
		{
			auto p1Location = m_points[p1].location();
			auto p2Location = m_points[p2].location();
			if (p1Location == p2Location)
				continue;

			if (abs(p1Location.first - p2Location.first) <= SPACE && abs(p1Location.second - p2Location.second) <= SPACE)
				neighbors.push_back(p2); //thus, we will update p2 as p1's neighbor!
		}
		m_points[p1].updateNeighbors(neighbors);
	}
}


void Graph::updateCurrentLevel(std::vector<std::pair<double, double>>& allpointsgraph)//std::vector<sf::Vector2f > &allpoints)
{
	for (const auto p : allpointsgraph)
		m_points.emplace_back(p);
}

void Graph::uncheckPoints()
{
	for (auto& p : m_points)
	{
		p.uncheck();
		p.disconnect();
	}
}

//this function helps us clearify witch is my direct neighbor.
bool Graph::validNeighbor(const std::pair<double, double> myLocation, const std::pair<double, double> neighborLocation, int edgeIndex) const
{

	switch (edgeIndex)
	{
	case 0:
		return (myLocation.second == neighborLocation.second && myLocation.first < neighborLocation.first);
		break;
	case 1:
		return (myLocation.first < neighborLocation.first && myLocation.second > neighborLocation.second);
		break;
	case 2:
		return (myLocation.first > neighborLocation.first&& myLocation.second > neighborLocation.second);
		break;
	case 3:
		return (myLocation.second == neighborLocation.second && myLocation.first > neighborLocation.first);
		break;
	case 4:
		return (myLocation.first > neighborLocation.first&& myLocation.second < neighborLocation.second);
		break;
	case 5:
		return (myLocation.first < neighborLocation.first && myLocation.second < neighborLocation.second);
		break;

	default:
		return false;
		break;
	}

	return false;
}


//this function helps us cheak if we had finished.
bool Graph::checkFinish()
{
	return std::count_if(m_points.begin(), m_points.end(), [](auto p) {return p.isConnected(); }) == m_points.size();
}

//this functin help the graph shuffle all edges then the stage wont be gr=etting as a solves - the user will do this! :)
void Graph::shuffleEdges()
{
	for (auto& p : m_points)
	{
		int direction = rand() % 2;
		for (int i = 0; i < rand() % 6; i++)
			p.rotate(direction);
	}
}

void Graph::connectPoints(int index, int edgeIndex)
{
	if (edgeIndex != -1)
		if (m_points[index].getEdges()[(edgeIndex + 3) % 6] != 1)
			return;

	if (m_points[index].isConnected()) return;
	m_points[index].connect();


	for (auto neighbor : m_points[index].getNeighbours())	//loop through neighbor indexes
		for (int i = 0; i < m_points[index].getEdges().size(); i++)
			if (m_points[index].getEdges()[i] == 1 && validNeighbor(m_points[index].location(), m_points[neighbor].location(), i))
				connectPoints(neighbor, i);

}

//this function creats the minimun spanning tree!
void Graph::createTree(int index, int prevEdge)
{
	m_points[index].checked();
	if (prevEdge != -1) {
		auto oppositeEdge = (prevEdge + 3) % 6;
		m_points[index].addEdge(oppositeEdge);
	}
	std::vector<int> neighbors = m_points[index].getNeighbours();

	std::shuffle( neighbors.begin(), neighbors.end() ,std::default_random_engine(0));  // in place no extra array
	for (std::vector<int>::iterator i=neighbors.begin(); i!=neighbors.end(); ++i)
	//for (auto& i : m_points[index].getNeighbours())
	{
		if (!m_points[*i].isChecked())	//if neighbor has not been visited yet
		{
			//create edge between me and neighbor!
			for (int newEdge = 0; newEdge < MAXEDGES; newEdge++)
				if (validNeighbor(m_points[index].location(), m_points[*i].location(), newEdge))
				{
					m_points[index].addEdge(newEdge);
					createTree(*i, newEdge);
				}
		}

	}

}


//here we creating the edges.
void Graph::createEdges()
{

	std::for_each(m_points.begin(), m_points.end(), [](auto& p) {p.createEdges(); });
}

//by clicing in one point - here we rotating it!
int Graph::rotate(double x, double y, int direction)
{
	//firstly we will run all points and allocate the currect points

	for (int i = 0; i < m_points.size(); i++)
		if (m_points[i].rotate(x, y, direction))
			return i;

}

//after fhinishing level - here we clearing it!.
void Graph::clearLevel()
{
	m_points.clear();
}

