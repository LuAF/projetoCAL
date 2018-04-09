#include "Util.h"

int main() {
	GraphViewer *gv = new GraphViewer(1000, 706, false);
	Graph<int> *grafo = new Graph<int>();
	//menuInicial(grafo);

	gv->setBackground("mapa.png");
	gv->createWindow(1000, 706);
	gv->defineVertexColor("green");
	gv->defineEdgeColor("black");
	gv->defineEdgeCurved(false);
	//gv->addNode(1000, 1000, 706);
	readVertexs(grafo);
	readEdges(grafo);
	printGraph(gv, grafo);

	gv->rearrange();


	getchar();
	return 0;
}
