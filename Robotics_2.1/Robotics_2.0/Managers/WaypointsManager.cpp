/*
 * WaypointsManager.cpp
 *
 *  Created on: Jun 14, 2015
 *      Author: colman
 */

#include "WaypointsManager.h"
#include <math.h>
using namespace std;

WaypointsManager::WaypointsManager(vector<Node> path, double gridResolution, double mapResolution)
{
	stc_path = path;
	_gridResolution = gridResolution;
	_mapResolution = mapResolution;
}

// Creating way point every "num_of_cells" item on the path
void WaypointsManager::build_way_point_vector(int num_of_cells)
{
	set<wayPoint>::iterator iter = wayPoints.begin();
	int counter = 0;
	double m;

	for (int i = 0; i < stc_path.size(); i++)
	{
		if(i == 0)
		{
			m = calc_incline(stc_path[i],stc_path[i+1]);
			wayPoint wp(stc_path[i].col, stc_path[i].row , calc_yaw(m, stc_path[i], stc_path[i+1]));
			wayPoints.insert(iter,wp);
			++iter;

			currWayPoint.x_Coordinate = wp.x_Coordinate;
			currWayPoint.y_Coordinate = wp.y_Coordinate;
			currWayPoint.yaw = wp.yaw;

			nextWayPoint.x_Coordinate = wp.x_Coordinate;
			nextWayPoint.y_Coordinate = wp.y_Coordinate;
			nextWayPoint.yaw = wp.yaw;

		}
		else if ( i== (stc_path.size() - 1))
		{
			wayPoint wp(stc_path[i].col, stc_path[i].row , calc_yaw(m, stc_path[i-1], stc_path[i]));
			wayPoints.insert(iter,wp);
			++iter;
		}
		else if (counter == num_of_cells)
		{
			m = calc_incline(stc_path[i], stc_path[i+1]);

			wayPoint wp(stc_path[i].col, stc_path[i].row , calc_yaw(m, stc_path[i], stc_path[i+1]));
			wayPoints.insert(iter,wp);
			++iter;
			counter = 0;
		}
		else
		{
			double new_m;
			bool is_old_varticle;
			is_old_varticle = is_verticle;
			new_m = calc_incline(stc_path[i], stc_path[i+1]);
			if((new_m != m)||(is_old_varticle != is_verticle))
			{
				wayPoint wp(stc_path[i].col, stc_path[i].row, calc_yaw(new_m, stc_path[i], stc_path[i+1]));
				wayPoints.insert(iter,wp);
				++iter;
				counter = 0;
			}
			m = new_m;
		}

		counter++;
	}
}

double WaypointsManager::calc_yaw(double m, Node node_from, Node node_to)
{
	double angle;

	if(!is_verticle)
	{
		angle = 180 * atan(m) / M_PI;
	}

	if (is_verticle)
	{
		if (node_to.row > node_from.row)
		{
			return (270);
		}
		else
		{
			return (90);
		}
	}
	else if ( m == 0)
	{
		if (node_to.col > node_from.col)
		{
			return (angle);
		}
		else
		{
			return (180 + angle);
		}
	}
	else if (m > 0)
	{
		if (node_to.row > node_from.row)
		{
			return (360 - angle);
		}
		else
		{
			return (180 - angle);
		}
	}
	else
	{
		if (node_to.row > node_from.row)
		{
			return (180 + angle);
		}
		else
		{
			return (angle);
		}
	}
}

double WaypointsManager::calc_incline(Node node_from, Node node_to)
{
	is_verticle = 0;
	if(node_from.col == node_to.col)
	{
		is_verticle = 1;
		return(9999);
	}
	else
	{
		return((node_to.row - node_from.row) / (node_to.col - node_from.col));
	}
}

void WaypointsManager::setNextWayPoint(wayPoint Next)
{
	currWayPoint.x_Coordinate = nextWayPoint.x_Coordinate;
	currWayPoint.y_Coordinate = nextWayPoint.y_Coordinate;
	currWayPoint.yaw = nextWayPoint.yaw;

	nextWayPoint.x_Coordinate = Next.x_Coordinate;
	nextWayPoint.y_Coordinate = Next.y_Coordinate;
	nextWayPoint.yaw = Next.yaw;
}


bool WaypointsManager::isInWayPoint(double x,double y)
{
	double dx = nextWayPoint.x_Coordinate - x;
	double dy = nextWayPoint.y_Coordinate - y;
	double distance = sqrt(pow(dx, 2) + pow(dy, 2));

	cout << "Next way point x: "<< nextWayPoint.x_Coordinate << " ---> current x: " << x << endl;
	cout << "Next way point y: "<< nextWayPoint.y_Coordinate << " ---> current y: " << y << endl;
	cout << "Next way point yaw" << nextWayPoint.yaw <<  endl;
	cout << "Distance to next way point: " << (distance) << endl;
	cout << endl;

	// Checking if the robot hit the way point, considering tolerance
	if (distance*_gridResolution <= TOLERANCE)
	{
		return true;
	}
	return false;
}

WaypointsManager::~WaypointsManager() {
	// TODO Auto-generated destructor stub
}
