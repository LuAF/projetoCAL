#include "Util.h"

int main() {
	GraphViewer *gv = new GraphViewer(1000, 706, false);
	Graph<int> *grafo = new Graph<int>();

	readVertexs(grafo);
	readEdges(grafo);
	readResources(gv, grafo);
	adicionaUrgencias();

	menuInicial(gv,grafo);

	return 0;
}
