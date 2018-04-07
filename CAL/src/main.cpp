#include "Util.h"

int main() {
	GraphViewer *gv = new GraphViewer(3257, 2301, true);
	Graph<int> *grafo = new Graph<int>();

	menuInicial();

	/*
	gv->setBackground("mapa.png");
	gv->createWindow(3257, 2301);
	gv->defineVertexColor("green");

	gv->defineEdgeColor("black");

	gv->addNode(0);
	gv->rearrange();
	gv->addNode(1);
	gv->rearrange();

	gv->addEdge(2,0,1,EdgeType::UNDIRECTED);
	 */
	/*
	readVertexs(grafo);
	readEdges(grafo);
	printGraph(gv, grafo);
	 */

	getchar();
	return 0;
}
