/*
 * main.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: user
 */
#include "STC/Node.h"
#include <iostream>
#include "Robot/Robot.h"
#include "Managers/Manager.h"
#include "Plans/ObstacleAvoidPlan.h"
#include "Map/Map.h"
#include "Managers/ConfigurationManager.h"
#include <vector>
#include "Managers/WaypointsManager.h"
#include "STC/STC.h"

using namespace std;
int main()
{
	//load the file data into the ConfigurationManager data members
	ConfigurationManager ConfigMgr(CONFIGURATION_PATH);
	//defines a new Map
	Map map(ConfigMgr.map_resolution, ConfigMgr.robot_length);
	//loads the map from the ConfigurationManager

	map.loadMapFromFile(ConfigMgr.map_path);
	map.inflateObstacles();

	map.buildFineGrid();
	map.buildCoarseGrid();
	Position startPos;

	//initialized the startPos with data from ConfigMgr
	startPos.first = ConfigMgr.start_x;
	startPos.second = ConfigMgr.start_y;
	cout<<"startPos.second: " << startPos.second<< ",startPos.first: " << startPos.first << endl;

	STC stc(map, startPos);
	vector<vector <Node *> >  vec = stc.getGraph();
	map.addPathToFile("MapWithPath.png", stc.getGraph(),stc.getGraphHeight(), stc.getGraphWidth());
    map.printMap();
    WaypointsManager(stc.convertVector2dTo1d(vec),ConfigMgr.grid_resolution,ConfigMgr.map_resolution);
 	return 0;
}


