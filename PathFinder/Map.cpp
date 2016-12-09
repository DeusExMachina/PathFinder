//
// Created by zairai on 25/11/16.
//

#include <iostream>
#include <SFML/Window/Event.hpp>
#include "Map.h"
#include "MapSearchNode.h"

void Map::printNodeInfo() {
    std::vector<Terrain *>::const_iterator i;
    int counter = 0;
    for(i = green_node.begin() ; i != green_node.end() ; i++)
    {
        if(counter%width != 0)
            std::cout<<(*i)->getValue()<<"\t";
        else if(counter%width == 0)
            std::cout<<"\n"<<(*i)->getValue()<<"\t";
        counter++;
    }
    std::cout<<std::endl;
}

void Map::init() {

    green_node.push_back(new WalkableNode(0, 0, 1));
    green_node.push_back(new WalkableNode(0, 1, 1));
    green_node.push_back(new WalkableNode(0, 2, 1));
    green_node.push_back(new WalkableNode(0, 3, 1));
    green_node.push_back(new WalkableNode(0, 4, 1));
    green_node.push_back(new WalkableNode(0, 5, 1));
    green_node.push_back(new WalkableNode(0, 6, 1));
    green_node.push_back(new WalkableNode(0, 7, 1));
    green_node.push_back(new WalkableNode(0, 8, 1));
    green_node.push_back(new WalkableNode(0, 9, 1));

    green_node.push_back(new WalkableNode(1, 0, 1));
    green_node.push_back(new WalkableNode(1, 1, 9));
    green_node.push_back(new WalkableNode(1, 2, 9));
    green_node.push_back(new WalkableNode(1, 3, 9));
    green_node.push_back(new WalkableNode(1, 4, 9));
    green_node.push_back(new WalkableNode(1, 5, 9));
    green_node.push_back(new WalkableNode(1, 6, 9));
    green_node.push_back(new WalkableNode(1, 7, 9));
    green_node.push_back(new WalkableNode(1, 8, 9));
    green_node.push_back(new WalkableNode(1, 9, 1));

    green_node.push_back(new WalkableNode(2, 0, 1));
    green_node.push_back(new WalkableNode(2, 1, 9));
    green_node.push_back(new WalkableNode(2, 2, 1));
    green_node.push_back(new WalkableNode(2, 3, 1));
    green_node.push_back(new WalkableNode(2, 4, 9));
    green_node.push_back(new WalkableNode(2, 5, 1));
    green_node.push_back(new WalkableNode(2, 6, 9));
    green_node.push_back(new WalkableNode(2, 7, 9));
    green_node.push_back(new WalkableNode(2, 8, 1));
    green_node.push_back(new WalkableNode(2, 9, 1));

    green_node.push_back(new WalkableNode(3, 0, 1));
    green_node.push_back(new WalkableNode(3, 1, 9));
    green_node.push_back(new WalkableNode(3, 2, 1));
    green_node.push_back(new WalkableNode(3, 3, 1));
    green_node.push_back(new WalkableNode(3, 4, 9));
    green_node.push_back(new WalkableNode(3, 5, 1));
    green_node.push_back(new WalkableNode(3, 6, 9));
    green_node.push_back(new WalkableNode(3, 7, 1));
    green_node.push_back(new WalkableNode(3, 8, 1));
    green_node.push_back(new WalkableNode(3, 9, 1));

    green_node.push_back(new WalkableNode(4, 0, 1));
    green_node.push_back(new WalkableNode(4, 1, 1));
    green_node.push_back(new WalkableNode(4, 2, 9));
    green_node.push_back(new WalkableNode(4, 3, 1));
    green_node.push_back(new WalkableNode(4, 4, 9));
    green_node.push_back(new WalkableNode(4, 5, 1));
    green_node.push_back(new WalkableNode(4, 6, 5));
    green_node.push_back(new WalkableNode(4, 7, 9));
    green_node.push_back(new WalkableNode(4, 8, 1));
    green_node.push_back(new WalkableNode(4, 9, 9));

    green_node.push_back(new WalkableNode(5, 0, 1));
    green_node.push_back(new WalkableNode(5, 1, 1));
    green_node.push_back(new WalkableNode(5, 2, 9));
    green_node.push_back(new WalkableNode(5, 3, 9));
    green_node.push_back(new WalkableNode(5, 4, 1));
    green_node.push_back(new WalkableNode(5, 5, 4));
    green_node.push_back(new WalkableNode(5, 6, 1));
    green_node.push_back(new WalkableNode(5, 7, 1));
    green_node.push_back(new WalkableNode(5, 8, 9));
    green_node.push_back(new WalkableNode(5, 9, 9));

    green_node.push_back(new WalkableNode(6, 0, 1));
    green_node.push_back(new WalkableNode(6, 1, 9));
    green_node.push_back(new WalkableNode(6, 2, 1));
    green_node.push_back(new WalkableNode(6, 3, 9));
    green_node.push_back(new WalkableNode(6, 4, 1));
    green_node.push_back(new WalkableNode(6, 5, 1));
    green_node.push_back(new WalkableNode(6, 6, 1));
    green_node.push_back(new WalkableNode(6, 7, 9));
    green_node.push_back(new WalkableNode(6, 8, 1));
    green_node.push_back(new WalkableNode(6, 9, 1));

    green_node.push_back(new WalkableNode(7, 0, 1));
    green_node.push_back(new WalkableNode(7, 1, 1));
    green_node.push_back(new WalkableNode(7, 2, 9));
    green_node.push_back(new WalkableNode(7, 3, 1));
    green_node.push_back(new WalkableNode(7, 4, 1));
    green_node.push_back(new WalkableNode(7, 5, 9));
    green_node.push_back(new WalkableNode(7, 6, 9));
    green_node.push_back(new WalkableNode(7, 7, 9));
    green_node.push_back(new WalkableNode(7, 8, 1));
    green_node.push_back(new WalkableNode(7, 9, 1));

    green_node.push_back(new WalkableNode(8, 0, 1));
    green_node.push_back(new WalkableNode(8, 1, 9));
    green_node.push_back(new WalkableNode(8, 2, 9));
    green_node.push_back(new WalkableNode(8, 3, 9));
    green_node.push_back(new WalkableNode(8, 4, 1));
    green_node.push_back(new WalkableNode(8, 5, 1));
    green_node.push_back(new WalkableNode(8, 6, 9));
    green_node.push_back(new WalkableNode(8, 7, 9));
    green_node.push_back(new WalkableNode(8, 8, 9));
    green_node.push_back(new WalkableNode(8, 9, 1));

    green_node.push_back(new WalkableNode(9, 0, 1));
    green_node.push_back(new WalkableNode(9, 1, 9));
    green_node.push_back(new WalkableNode(9, 2, 1));
    green_node.push_back(new WalkableNode(9, 3, 1));
    green_node.push_back(new WalkableNode(9, 4, 9));
    green_node.push_back(new WalkableNode(9, 5, 1));
    green_node.push_back(new WalkableNode(9, 6, 1));
    green_node.push_back(new WalkableNode(9, 7, 9));
    green_node.push_back(new WalkableNode(9, 8, 1));
    green_node.push_back(new WalkableNode(9, 9, 1));

}

Map &Map::get_instance() {
    static Map instance;
    return instance;
}

void Map::selectedCell(int x, int y) {
    if(x < 0 || x > width && y < 0 || y > height )
        std::cout<<"x and y not valid for research"<<std::endl;
    else if (x > 0 || x < width && y > 0 || y < height )
        std::cout<<"---------------"<<std::endl;
        std::cout<<green_node[y*width + x]->getValue()<<std::endl;
}

int Map::getSelectedCell(int x, int y) {
    if(x < 0 || x >= width || y < 0 || y >= height )
        return 9;
    return green_node[y*width + x]->getValue();
}

Map::Map() {
    width = 10;
    height = 10;
}

sf::Sprite *Map::getSelectedSprite(int x, int y) {
    if(x < 0 || x >= width || y < 0 || y >= height )
        return nullptr;
    return green_node[y*width + x]->getSprite();
}

void Map::startPathfinding() {

    AStarSearch<MapSearchNode> astarsearch;
    unsigned int SearchCount = 0;
    const unsigned int NumSearches = 1;

    while(SearchCount < NumSearches)
    {
        // Create a start state
        MapSearchNode nodeStart;
        nodeStart.x = 5;
        nodeStart.y = 4;
        std::cout<<"NodeStart : x ("<<nodeStart.x<<") y ("<<nodeStart.y<<") value:"<<Map::get_instance().getSelectedCell(nodeStart.x , nodeStart.y)<<std::endl;

        // Define the goal state
        MapSearchNode nodeEnd;
        nodeEnd.x = 6;
        nodeEnd.y = 5;
        std::cout<<"NodeEnd : x ("<<nodeEnd.x<<") y ("<<nodeEnd.y<<") value:"<<Map::get_instance().getSelectedCell(nodeStart.x , nodeStart.y)<<std::endl;

        // Set Start and goal states
        astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );

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
                node->PrintNodeInfo();
                steps ++;
            };

            cout << "Solution steps " << steps << endl;

            // Once you're done with the solution you can free the nodes up
            astarsearch.FreeSolutionNodes();
        }

        else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED )
        {
            cout << "Search terminated. Did not find goal state\n";

        }

        // Display the number of loops the search went through
        cout << "SearchSteps : " << SearchSteps << "\n";
        SearchCount ++;
        astarsearch.EnsureMemoryFreed();
    }

}

void Map::display() {
    window = new sf::RenderWindow(sf::VideoMode(600 , 600), "PathFinder");
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
                    Map::get_instance().startPathfinding();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    Map::get_instance().printNodeInfo();
                }
            }
        }
        window->clear(sf::Color::White);
        for(x = 0;x<width;x++) {
            for (y = 0; y < height; y++)
                window->draw(*Map::getSelectedSprite(x, y));
        }
        window->display();
    }
}

