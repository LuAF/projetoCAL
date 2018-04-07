#include "Util.h"

int main() {
	GraphViewer *gv = new GraphViewer(752, 598, true);
	gv->setBackground("mapa.png");
	gv->createWindow(752, 598);
	gv->defineVertexColor("green");

	gv->defineEdgeColor("black");

	gv->addNode(0);
	gv->rearrange();
	gv->addNode(1);
	gv->rearrange();

	gv->addEdge(2,0,1,EdgeType::UNDIRECTED);

	getchar();
	return 0;
}
