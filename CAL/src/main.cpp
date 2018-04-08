#include "Util.h"

int main() {
	GraphViewer *gv = new GraphViewer(1000, 706, false);
	Graph<int> *grafo = new Graph<int>();
	//menuInicial();

	cout << (distancia(-8.62063, 41.14517, -8.61066, 41.14517)*1000)/
			distancia(-8.62063, 41.15047, -8.61066, 41.15047) << endl;

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


	cout << (distancia(-8.62063, 41.15047, -8.61075, 41.15047) ) << endl;


	getchar();
	return 0;
}
