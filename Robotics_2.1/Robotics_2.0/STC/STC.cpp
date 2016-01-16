/*
 * STC.cpp
 *
 *  Created on: Dec 9, 2015
 *      Author: colman
 */

#include "STC.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

STC::STC(Map &map, Position startPos):map(map) {
	buildGraph();
	printGraph();
	//cout<<startPos.first<< " "<< startPos.second<<endl;
	cout<<startPos.first/25<< " "<< startPos.second/25<<endl;
	Node node(startPos.first/25,startPos.second/25);
	DFS(&node);
	printDFS();
}

void STC::buildGraph() {
	cout<<"build graph"<<endl;
	Grid coarseGrid = map.getCoarseGrid();
	this->graphHeight  = coarseGrid.size();
	this->graphWidth= coarseGrid[0].size();
	graph.resize(graphHeight);
	for (int i = 0; i < graphHeight; i++)
		graph[i].resize(graphWidth);

	for (int i=0;i<graphHeight;i++) {
		for (int j=0;j<graphWidth;j++) {
			// Node is not occupied in coarseGrid
			if (!coarseGrid[i][j]) {
				Node* node = new Node(i, j);
				graph[i][j] = node;
			}
		}
	}
	for (int i=0;i<graphHeight;i++) {
			for (int j=0;j<graphWidth;j++) {
				// cell is not occupied in coarseGrid
				if (coarseGrid[i][j] == NULL) {
					cout<<"0";
				}
				else{
					cout<<"1";
				}
			}
			cout<<endl;
		}
	cout<<"build graph end"<<endl;

}

void STC::printGraph() {
	int gridRows = graph.size();
	int gridCols = graph[0].size();
		for (int i=0;i<gridRows;i++) {
			for (int j=0;j<gridCols;j++) {
				if (graph[i][j]) {
					cout << setw(2) << i << ":" << setw(2) <<  j << " ";
				} else {
					cout << "  :   ";
				}
			}
			cout << endl;
		}
}

void STC::printDFS() {
	int gridRows = graph.size();
	int gridCols = graph[0].size();
cout<<"gridRows:"<<gridRows<<"gridCols:"<<gridCols;
	for (int i=0;i<gridRows;i++) {
		for (int j=0;j<gridCols;j++) {
			if (graph[i][j] != NULL) {
				for (int k=0;k<4;k++) {
					if (graph[i][j]->neighborsInSpanningTree[k] != NULL) {

						cout << "(" << graph[i][j]->getPosition().first << "," << graph[i][j]->getPosition().second << ")";
						cout << " -> ";
						cout << "(" << graph[i][j]->neighborsInSpanningTree[k]->getPosition().first << "," << graph[i][j]->neighborsInSpanningTree[k]->getPosition().second << ")" << endl;
					}
				}

			}
		}
	}
}

void STC::DFS(Node* n) {
	//cout<<"DFS"<<endl;
	/*cout << "graph.size(): " << graph.size() <<endl;
	cout << "graph[0].size(): " << graph[0].size() <<endl;
	cout << n->col<<endl;*/

	n->visited=true;

	//cout << "x: " << x <<endl;
	//cout << "y: " << y <<endl;

	int x = n->getPosition().first;
	int y = n->getPosition().second;



	// right
	int row = x+1;
	int col = y;
	if (row >= 0 && row < graph.size() && col >=0 && col < graph[0].size()) {
		//check if exist node in this  field
		if (graph[row][col] != NULL && !graph[row][col]->visited) {
			n->neighborsInSpanningTree[0] = graph[row][col];
			DFS(graph[row][col]);
		}
	}

	// up
	row = x;
	col = y-1;
	if (col >= 0 && col < graph.size() && row >=0 && row < graph[0].size()) {
		if (graph[row][col] != NULL && !graph[row][col]->visited) {
			n->neighborsInSpanningTree[1] = graph[row][col];
			DFS(graph[row][col]);
		}
	}

	// left
	row = x-1;
	col = y;
	if (col >= 0 && col < graph.size() && row >=0 && row < graph[0].size()) {
		if (graph[row][col] != NULL && !graph[row][col]->visited) {
			n->neighborsInSpanningTree[2] = graph[row][col];
			DFS(graph[row][col]);
		}
	}

	// down
	row = x;
	col = y+1;
	if (col >= 0 && col < graph.size() && row >=0 && row < graph[0].size()) {
		if (graph[row][col] != NULL && !graph[row][col]->visited) {
			n->neighborsInSpanningTree[3] = graph[row][col];
			DFS(graph[row][col]);
		}
	}
//	cout<<"DFS end"<<endl;
}

vector<Node > STC::convertVector2dTo1d(vector<vector<Node *> > graph){
	int k=0;
	vector<Node> v;
	for(int i = 0; i < graph.size(); i++){
	        for(int j = 0; j < graph[i].size(); j++){
	        	v[k]=*graph[i][j];
	        	k++;
	        }
	}
return v;

}

vector<vector<Node *> > STC::getGraph(){
	//convertVector2dTo1d(graph)
	return graph;
	//return convertVector2dTo1d(graph);
}

unsigned int STC::getGraphWidth(){
return this->graphWidth;
}
unsigned int STC::getGraphHeight(){
	return this->graphHeight;
}

STC::~STC() {
	// TODO Auto-generated destructor stub
}

