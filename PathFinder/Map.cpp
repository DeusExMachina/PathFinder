//
// Created by zairai on 25/11/16.
//

#include <iostream>
#include <SFML/Window/Event.hpp>
#include <fstream>
#include "Map.h"
#include "MapSearchNode.h"

Map &Map::get_instance() {
    static Map instance;
    return instance;
}

int Map::getSelectedCell(int x, int y) {
    if(x < 0 || x >= width || y < 0 || y >= height )
        return 9;
    return tile[x*width + y]->getValue();
}

Map::Map() {
    width = 10;
    height = 10;
}

sf::Sprite *Map::getSelectedSprite(int x, int y) {
    if(x < 0 || x >= width || y < 0 || y >= height )
        return nullptr;
    return tile[x*width + y]->getSprite();
}

int Map::startPF(int startX , int startY , int endX , int endY) {

    AStarSearch<MapSearchNode> astarsearch;
    unsigned int SearchCount = 0;
    const unsigned int NumSearches = 1;

    while(SearchCount < NumSearches)
    {
        // Create a start state
        MapSearchNode nodeStart;
        nodeStart.x = startX;
        nodeStart.y = startY;
        std::cout<<"NodeStart : x ("<<nodeStart.x<<") y ("<<nodeStart.y<<") value:"<<Map::get_instance().getSelectedCell(nodeStart.x , nodeStart.y)<<std::endl;

        // Define the goal state
        MapSearchNode nodeEnd;
        nodeEnd.x = endX;
        nodeEnd.y = endY;
        std::cout<<"NodeEnd : x ("<<nodeEnd.x<<") y ("<<nodeEnd.y<<") value:"<<Map::get_instance().getSelectedCell(nodeStart.x , nodeStart.y)<<std::endl;

        // Set Start and goal states
        astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );

        // Variable to return
        int fSteps;

        unsigned int SearchState;
        unsigned int SearchSteps = 0;

        do
        {
            SearchState = astarsearch.SearchStep();
            SearchSteps++;

#if DEBUG_LISTS

            cout << "Steps:" << SearchSteps << "\n";
            int len = 0;
			cout << "Open:\n";
			MapSearchNode *p = astarsearch.GetOpenListStart();
			while( p )
			{
				len++;
	#if !DEBUG_LIST_LENGTHS_ONLY
				((MapSearchNode *)p)->PrintNodeInfo();
	#endif
				p = astarsearch.GetOpenListNext();

			}

			cout << "Open list has " << len << " nodes\n";
			len = 0;
			cout << "Closed:\n";
			p = astarsearch.GetClosedListStart();
			while( p )
			{
				len++;
	#if !DEBUG_LIST_LENGTHS_ONLY
				p->PrintNodeInfo();
	#endif
				p = astarsearch.GetClosedListNext();
			}
			cout << "Closed list has " << len << " nodes\n";
#endif

        }
        while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );

        if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED )
        {
            cout << "Search found goal state\n";
            MapSearchNode *node = astarsearch.GetSolutionStart();

#if DISPLAY_SOLUTION
            cout << "Displaying solution\n";
#endif
            int steps = 0;
            node->PrintNodeInfo();
            for( ;; )
            {
                node = astarsearch.GetSolutionNext();
                if( !node )
                {
                    break;
                }
                Map::get_instance().getGround(node->x,node->y)->trackedPath(
                        node->x , node->y , Map::get_instance().getSelectedSprite(node->x,node->y));
                node->PrintNodeInfo();
                steps ++;
            };

            cout << "Solution steps " << steps << endl;

            // Once you're done with the solution you can free the nodes up
            astarsearch.FreeSolutionNodes();
            fSteps = steps;
        }

        else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED )
        {
            cout << "Search terminated. Did not find goal state\n";
            return -1 ;
        }

        // Display the number of loops the search went through
        cout << "SearchSteps : " << SearchSteps << "\n";
        SearchCount ++;
        astarsearch.EnsureMemoryFreed();
        return fSteps;
    }

}

void Map::display() {
    window = new sf::RenderWindow(sf::VideoMode(500 , 500), "PathFinder");
    int x;
    int y;
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    int pf_state = Map::get_instance().startPF(2,4,8,8);
                    cout << pf_state;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    Map::get_instance().getGround(1,1)->trackedPath(1,1,Map::get_instance().getSelectedSprite(1,1));
                }
            }
        }
        window->clear(sf::Color::Black);
        for(x = 0; x < width; x++) {
            for (y = 0; y < height; y++)
                window->draw(*Map::getSelectedSprite(x, y));
        }
        window->display();
    }
}

int Map::loadFromTxt() {
    ifstream inMap;
    bool load = false;
    inMap.open("txt/text.txt");
    int ** data = new int*[width];
    for(int i = 0 ; i < width ; i++) {
        data[i] = new int [height];
        for (int j = 0; j < height; j++) {
            inMap >> data[i][j];
            tile.push_back(new Ground(i,j,data[i][j]));
        }
        load = true;
    }
    inMap.close();
    if(load == false)
        return 0;
    else
        return 1;

}

Terrain * Map::getGround(int x , int y) {
    return tile[x*width + y];
}


