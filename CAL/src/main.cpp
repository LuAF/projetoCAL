#include "Util.h"

int main() {
	GraphViewer *gv = new GraphViewer(1000, 706, false);
	Graph<int> *grafo = new Graph<int>();
	//menuInicial(grafo);

	gv->setBackground("mapa.png");
	gv->createWindow(1000, 706);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");
	gv->defineEdgeCurved(false);

	readVertexs(grafo);
	readEdges(grafo);
	readResources(gv, grafo);
	printGraph(gv, grafo);

	gv->rearrange();


	getchar();
	return 0;
}
