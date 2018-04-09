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
#include <cmath>
#include <climits>

using namespace std;


void menuInicial(Graph<int> * grafo);
void menuOpt1();
void menuOpt2(Graph<int> * grafo);
void calculateShortestPath(Graph<int> * grafo);
void showShortestPath();
int distance(Graph<int> *g, vector<int> v);
vector<int> closerResource(Graph<int> *g, vector<vector<int>> v);

void readVertexs(Graph<int> *grafo);
void readEdges(Graph<int> *grafo);
void printGraph(GraphViewer *gv ,Graph<int> *grafo);
void adicionaUrgencias();
double distancia(double latitude1, double longitude1, double latitude2, double longitude2);


#endif /* SRC_UTIL_H_ */
