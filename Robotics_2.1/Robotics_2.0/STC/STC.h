
#include "../Map/Map.h"
#include "Node.h"

using namespace std;


class STC {
private:
	Map &map;
	vector<vector<Node *> > graph;
	int graphWidth;
    int graphHeight;
	void buildGraph();
	void DFS(Node* n);
	void printGraph();
	void printDFS();
public:
	STC(Map &map, Position startPos);
	vector<vector<Node *> > getGraph();
	vector<Node> convertVector2dTo1d(vector<vector<Node *> > graph);
	void buildSpanningTree();
	void drawSpanningTree();
	unsigned int getGraphWidth();
	unsigned int getGraphHeight();
	virtual ~STC();
};


