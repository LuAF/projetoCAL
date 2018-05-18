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


void menuInicial(GraphViewer *gv, Graph<int> * grafo);
void menuOpt1(GraphViewer *gv, Graph<int> * grafo);
void menuOpt2(GraphViewer *gv, Graph<int> * grafo);
void menuOpt3(GraphViewer *gv, Graph<int> * grafo);
vector<int> caminhoHospital(Graph<int> * grafo);
vector<vector<int>> calculateShortestPath(GraphViewer *gv, Graph<int> * grafo);
void showShortestPath();
double distance(Graph<int> *g, vector<int> v);
vector<int> closerResource(Graph<int> *g, vector<vector<int>> v);

void readVertexs(Graph<int> *grafo);
void readEdges(Graph<int> *grafo);
void readResources(GraphViewer *gv, Graph<int> *grafo);
void printResources(GraphViewer *gv);
void printGraph(GraphViewer *gv ,Graph<int> *grafo);
void adicionaUrgencias();
double distancia(double latitude1, double longitude1, double latitude2, double longitude2);

void setBooleans(string name, bool &b, bool &a, bool &p, bool &i);

void findResource(vector<int> ids);

#endif /* SRC_UTIL_H_ */
