#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

//APAGAR DO TRABALHO

void exercicio1();
void exercicio2();
void exercicio3();


void exercicio1()
{
	GraphViewer *gv = new GraphViewer(600, 600, true);
	gv->createWindow(600, 600);

	gv->defineVertexColor("green");

	gv->defineEdgeColor("black");

	gv->addNode(0);
	gv->rearrange();
	gv->addNode(1);
	gv->rearrange();

	gv->addEdge(2,0,1,EdgeType::UNDIRECTED);


}

void exercicio2()
{

}

void exercicio3()
{

}


int main() {
	exercicio1();
	//exercicio2();
	//exercicio3();
	getchar();
	return 0;
}
