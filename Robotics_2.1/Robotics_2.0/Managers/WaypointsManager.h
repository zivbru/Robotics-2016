/*
 * WaypointsManager.h
 *
 *  Created on: Jun 14, 2015
 *      Author: colman
 */

#ifndef WAYPOINTSMANAGER_H_
#define WAYPOINTSMANAGER_H_

#include <iostream>
#include <vector>
#include "../WayPoint/wayPoint.h"
#include "../STC/Node.h"
#include<set>
#include "../Defines.h"
#include <math.h>
using std::vector;
using std::set;

class WaypointsManager {
public:

	set<wayPoint> wayPoints;
	wayPoint currWayPoint;

	WaypointsManager(vector<Node> path, double gridResolution, double mapResolution);
	void build_way_point_vector(int num_of_cells);
	void setNextWayPoint(wayPoint Next);
	bool isInWayPoint(double x,double y);
	virtual ~WaypointsManager();

private:
	vector<Node> stc_path;
	bool is_verticle;
	wayPoint nextWayPoint;
	double _gridResolution;
	double _mapResolution;

	double calc_yaw(double m, Node node_from, Node node_to);
	double calc_incline(Node node_from, Node node_to);

};

#endif /* WAYPOINTSMANAGER_H_ */
