#include "Board.h"

//-----------------------------------------------------------
//_____________________Board_________________________________
//
//This Class manages all the things connect to manage board
// for instance, here we create a new board, 
// here we run the game, getting commands fron user, clearing 
// current level . 
//-----------------------------------------------------------

//-----------------------------------------------------------
//this function creates a new stage by a randomalization
//input and by that way the user recive a veraiety different games hw can play!
//-----------------------------------------------------------
void Board::GraphsManufacture(int size)
{
	int midLine = size;
	std::vector<sf::Vector2f > allpoints;

	sf::Vector2f center(WIDTH / 2.0f, HEIGHT / 2.0f);
	int ROWS = 0;
	ROWS = (midLine - 3) * 2 + 1;

	int startY = (int)center.y - ((ROWS - 1) / 2) * SPACE;
	int startX = (int)center.x - SPACE;

	int cols = 3;
	int currX = startX;
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			sf::Vector2f position(currX, startY);
			allpoints.emplace_back(position);//כאן נעשה פוש באק לוקטור של הנקודות שלנו שמכיל וקטור טו איי
			currX += SPACE;
		}

		startY += SPACE - 7;
		if (row <= ROWS / 2 - 1)
		{
			currX = startX - SPACE / TWO;
			cols++;
		}
		else
		{
			cols--;
			currX = startX + SPACE / TWO;
		}
		startX = currX;
	}
	m_graphInterface.updateCurrentLevel(allpoints);//כאן נשלח קודקוד לגרף ספמלי

	std::vector<std::pair<double, double>> allpointsgraph;//כאן ממירים את הנקודות עבור דאבלים כדי שלא נשתמש בכלל בממשק של אס אף אם אל כנדרש בתרגיל

	for (int i = 0; i < allpoints.size(); i++)
	{
		allpointsgraph.push_back(std::make_pair(allpoints[i].x, allpoints[i].y));
	}
	m_graph.updateCurrentLevel(allpointsgraph);//כאן נשלח קודקוד לגרף הרגיל. זה אותו וקטור עם אותם ערכי נקודות של הגרף 
	m_graph.setPointsNeighbors();
	m_points = allpointsgraph;
	Create_level();//אחרי שיצרנו את כל הנקודות עכשיו אנחנו מבקשים מפונקציה זו שתיצור לנו שלב בבקשה 
}


//-----------------------------------------------------------
//here me manage all about creating new stage - this is the 'brain' of the game 
//firstly-creating new points as a base for a new stage,
//secoundly ,then, creating new level, 
//thirdly , after creating a minimum spanning tree,  by the Global DIFFICULTY we can add (+- random )another edges to each point to make the game easier (DIFFICULTY= 1 means we do not adding more adges == it is the hard dificault)
//fourthly, shuffling all edges by a random int that makes the stage a starting point the player can start to play
//-----------------------------------------------------------
void Board::Create_level()              	//...he we create a spaning tree minims
{
	std::vector<sf::RectangleShape> allpointsedgesSFML;//מערך הצלעות עבור כל הנקודות שבגרף המתמטי
	std::vector<std::pair<double, double>> allpointsgraphedges;//מערך הצלעות עבור כל הנקודות שבגרף הלא ציורי

	auto centerPoint = (m_points.size() - 1) / TWO;//find the central point//then we will pass al over his neighvors and add them to the spanning tree

	m_graph.uncheckPoints();//for each neighbor, call again the same act

	int edge = rand() % MAXEDGES;//נעשה פה פונקצייה שקובעת לכל קודקוד את הצלעות שלו (כמה יהיו ואיפה יהיו בתוך ה6 מקומות של כל אחד

	int startingPoint = rand() % m_points.size();
	m_graph.createTree(startingPoint, -1);
	m_graph.createEdges();
	m_graph.shuffleEdges();	////here we can add another edges to each pooint to make the game easier
	m_graphInterface.setEdges(m_graph.getPoints());// פה היא שולחת לגרף האספמלי את המידע אודות כל קודקוד// באותות אופן נשלח לגרף הרגיל שלנו את המידע של הצלעות עבור כל קודקוד
}


//-----------------------------------------------------------
//here this is the place we running the game
//-----------------------------------------------------------
void Board::run(int level)
{
	auto window = sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Lights - Made by Yona harel and Eitan shalev");
	while (level != ENDGAME) // send 
	{
		GraphsManufacture(level);
		auto centerPoint = (m_points.size() - 1) / 2;
		while (window.isOpen())
		{
			window.display();
			window.clear();
			if (auto event = sf::Event{}; window.waitEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					clearLevel();

					return;


				case sf::Event::MouseButtonPressed:

					const auto location = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });//(
					switch (event.mouseButton.button) //update graf
					{
					case sf::Mouse::Button::Left:

						m_graphInterface.rotate(m_graph.rotate(location.x, location.y, RIGHT), RIGHT); //update sfml

						break;
					case sf::Mouse::Button::Right:
						m_graphInterface.rotate(m_graph.rotate(location.x, location.y, LEFT), LEFT); //update sfml
						break;
					}
					break;
				}
			}
			m_graph.uncheckPoints();
			m_graph.connectPoints(centerPoint, -1);
			m_graphInterface.updateLights(m_graph.getPoints());
			m_graphInterface.draw(window);
			if (m_graph.checkFinish())
			{
				
				//window.clear();
				sf::Text levelPassed;

				continu_game(levelPassed, level);

				window.draw(levelPassed);	//print congratulation!
						//window.draw(levelPassed);
				bool continewaiting = true;
				window.display();
				auto event = sf::Event{};
				bool next = true;
				while (next == true)
				{
					auto event = sf::Event{}; window.waitEvent(event);
					window.pollEvent(event);

					if (event.type == sf::Event::Closed)
					{
						window.close();
						clearLevel();
						return;
					}
					if ( sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Right))
					{
						next = false;
					}

				}
				clearLevel();
				break;
			}
		}
		level += NEXTLEVEL;
	}

	sf::Text text;
	text.setColor(sf::Color::Red);
	text.setString("Play Game");
}


//-----------------------------------------------------------
//  this function helps the distructor to distruct beautifly all the objects that are not relevant to the next level
//-----------------------------------------------------------
void Board::clearLevel()
{
	m_graph.clearLevel();
	m_graphInterface.clearLevel();
	m_points.clear();
}


//-----------------------------------------------------------
//this function controls of the data the user gets after finishing a level
//-----------------------------------------------------------
void Board::continu_game(sf::Text& levelPassed, int level)
{
	
	//static sf::Font font;
	font.loadFromFile("SF-UI-Display-Regular.otf");
	levelPassed.setFont(font);
	if (level == ENDGAME-2)
	{
		levelPassed.setString("CONGRATIULATIONS! \n YOU WON! :)");
	}
	else
		levelPassed.setString("           Level Completed !!!            \n     please click anywhere to continue :)");
	levelPassed.setPosition((WIDTH / 4) - PLACE, HEIGHT / TWO+ PLACE);
	levelPassed.setFillColor( sf::Color::Yellow);
	levelPassed.setCharacterSize(50);
	levelPassed.setStyle(sf::Text::Bold);


}