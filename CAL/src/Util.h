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
#include<cmath>

using namespace std;

void menuInicial();
void menuOpt1();
void menuOpt2();

void readVertexs(Graph<int> *grafo);
void readEdges(Graph<int> *grafo);
void printGraph(GraphViewer *gv ,Graph<int> *grafo);
void adicionaUrgencias();
double distancia(double latitude1, double longitude1, double latitude2, double longitude2);


#endif /* SRC_UTIL_H_ */
