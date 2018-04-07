#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include "graphviewer.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include "Graph.h"
#include <iomanip>

using namespace std;

void readVertexs(Graph<int> *grafo);
void readEdges(Graph<int> *grafo);
void printGraph(GraphViewer *gv ,Graph<int> *grafo);


#endif /* SRC_UTIL_H_ */
