# Lights game  :mouse:
"Lights" is a puzzle, originally for Android phones, using a simple idea. Connect the path and win the game. Each Curvy puzzle consists of a grid of hexagonal tiles.
Lights allows a variety of different puzzle sizes, providing puzzles that can be quickly solved as well as more complex versions depending on the size you choose. Originally an Android application, you can now play Curvy online or on the go.




[![](https://github.com/eitanshalev/Lights-game/blob/master/Lights_game_-_SFML___CC%2B%2B_BY_Eitan_Shalev_and_Yona_Harel.gif)](https://www.youtube.com/watch?v=kKJWvTO5axQ "my video game")
 
==================================Desing:==================================

Classes + objects:

1. Globals: Responsible for all the variables set in the program.
2. Board: This is the basic class -Explanation: The class that is responsible for fun algorithms algorithmically- where all the steps are created (we created a function to create steps - it gets a number that represents the number of vertices that will be in the main row, and from it builds rows - it is important to note that it works for all A really positive whole index. Responsible for the whole matter of the step-by-step delete - delete a step that ended to proceed to the next step, etc. We did a function that destroys all the fun data at the end of a step for some reason.
We now have 2 more classes for the logic of the game which are: Graph, Point
And 2 more classes for graphical realization which are: GraphInterface, Light.
3. Graph: Contains a data structure that contains pairs of coordinates (x, y) of which each coordinate is basically a Point type object. The board uses its calculations to transfer to the Graph Interface class
4. Point: The basic structure of each geometric point in a graph, a graph class uses it to make all the calculations that need to be calculated.
5. Graph Interface: Retains all the relevant data for displaying the graph. Contains a vector of light that saves all data. Saves vector of lights.
6. Light: Saves all the data for a point we use it during the program run to present the board to the user in a user experience. And to that end each vertex contains a vector of RectangleShape that preserves all its sides. And using Vector2f saves the position of each vertex.

These pairs of classes (pink and green I described above) work in harmony together so that on one role - for the user experience to tag the game while one role is to calculate, save, provide relevant data about the game. Through the Board Department they seemingly 'communicate, together. It was important for us to separate in this way as there is a clear role for each and this is a different role and there is no programmatic reason to mix them for our poor minds.

We used iterators to efficiently go over the data structures, any function that passes over the ribs or all the vertices - any function with its realization. We learned to use it and it helped us a lot.


* Data structures and their function: The program contains a vector of points for the mathematical graph and a vector of points for the graph to be displayed using sfml. It is important to note that within each of them there is a vector as described above that corresponds to a rib corresponding to each vertex according to its position - if it is a point then its position will be a pair of X-Way versus light which otherwise retains its position and ribs.
We used the learn function to go over data structures more efficiently. We also used the functions of the language - in the algorithm to go over data structures according to each function for example we used the for_if function to go over all the vertices that perform some action.

* The interaction between the various objects is done cleanly through the Board class.

Vector of points, vector of point to sfml-. Vector of ribs for the regular dot and for the dot to sfml.
Remarks:
1.  We supported the creation of the stage determined by an algorithm we performed. It should be noted that the computer can plan a stage of infinite size and it is not limited to 3 stages but the game itself stops a stage of 9 vertices in the center, depending on the requirements of the exercise. We will finish. Attached in the appendix are the three steps required for the specific submission of this exercise but the project works for each type of step in principle.
2.  We created the code in a generic way - the global variables determine the nature of the game: for example our DIFICULTY variable determines after creating a minimal spreading tree - we add a few more ribs to each vertex and then after creating the phase we add a maximum of x ribs to each vertex, The difficulty will be 3 then to each vertex will be added another 3 ribs but a maximum of another 3 - can be added one two or not even added and it is selected randomly as well.
