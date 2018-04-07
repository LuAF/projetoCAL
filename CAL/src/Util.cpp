#include "Util.h"
#include "Graph.h"
#include "Urgency.h"
#include <iomanip>

void menuInicial() {
	cout << "Central de atendimento de urgencias" << endl;
	cout << "[1] Efetuar Chamada" << endl;
	cout << "[2] Tratar Chamadas" << endl << endl;

	adicionaUrgencias();

	int opt;
	cout << "> ";
	cin >> opt;

	while (opt!=1 && opt!=2){
		cout << "Escolha uma opcao valida! " << endl;
		cin >> opt;
	}

	switch(opt) {
		case 1:
		{
			menuOpt1();
			break;
		}
		case 2:
		{
			menuOpt2();
			break;
		}
	}

}

void menuOpt1() {
	cout << endl << "Efetuar Chamada" << endl;
	cout << "Tipo de Urgencia: ";

	string tipoUrgencia;
	cin.ignore(100, '\n');
	getline(cin, tipoUrgencia);
	cout << endl;

	cout << "Localizacao: ";

	string localizacao;
	getline(cin, localizacao);
	cout << endl;

	cout << "LOC: " << localizacao << endl;

}

void menuOpt2() {
	cout << "Efetuar Chamada" << endl;
	cout << "" << endl << endl;

	int opt;
	cout << "> ";
	cin >> opt;

	while (opt!=1 && opt!=2){
		cout << "Escolha uma opcao valida! " << endl;
		cin >> opt;
	}

}

void adicionaUrgencias() {
/*
	//Bombeiros

	Urgency u ("Fuga de gas", 10, {});
	u.addUrgency(u);

	u.setNome("Incendio");
	u.setPriority(9);
	u.addUrgency(u);

	u.setNome("Tsunami");
	u.setPriority(9);
	u.addUrgency(u);

	u.setNome("Acidente com embarcacao");
	u.setPriority(9);
	u.addUrgency(u);

	u.setNome("Deslizamento de terras");
	u.setPriority(9);
	u.addUrgency(u);

	//Policia

	u.setNome("Violencia domestica");
	u.setPriority(4);
	u.addUrgency(u);

	u.setNome("Rapto de crianças");
	u.setPriority(9);
	u.addUrgency(u);

	u.setNome("Assalto");
	u.setPriority(9);
	u.addUrgency(u);

	//Ambulância

	u.setNome("Assistencia medica");
	u.setPriority(4);
	u.addUrgency(u);
	*/
}

void readVertexs(Graph<int> *grafo){
	ifstream streamVertexs;
	streamVertexs.open("A.txt");
	string line;
	int informacao;
	long double latitude, longitude;
	char ignore;

	while (!streamVertexs.eof()){

		getline(streamVertexs, line);
		stringstream ssFicheiro(line);
		ssFicheiro >> informacao;
		ssFicheiro >> ignore;
		ssFicheiro >> latitude;
		ssFicheiro >> ignore;
		ssFicheiro >> longitude;

		grafo->addVertex(informacao, latitude, longitude);

	}
}

void readEdges(Graph<int> *grafo){
	ifstream streamB, streamC;
	streamB.open("B.txt");
	streamC.open("C.txt");

	string line;

	int idRuaB, idRuaC=-1;
	int infO, infD;
	string sentido;
	char ign;
	string nomeRua;
	bool sent;

	while (!streamB.eof()){
		getline(streamB, line);
		stringstream ssB(line);

		ssB >> idRuaB >> ign;
		getline(ssB,nomeRua, ';');
		ssB >> sentido;
		sent = (sentido == "True")? true:false;

		if(idRuaC != -1){
			grafo->findVertex(infO)->addEdge(grafo->findVertex(infD), idRuaC, nomeRua, sent);
		}

		do{
			if(!streamC.eof()) {
				getline(streamC, line);

				stringstream ssC(line);
				ssC >> idRuaC >> ign >> infO >> ign >> infD;

				if(idRuaB == idRuaC){
					grafo->findVertex(infO)->addEdge(grafo->findVertex(infD), idRuaC, nomeRua, sent);
					idRuaC = -1;
				}

			}
			else break;

		}while (idRuaC == -1);

	}
}

void printGraph(GraphViewer *gv ,Graph<int> *grafo){
	int id;
	long double x, y;
	int contador = 0;

	for(unsigned int i=0; i <grafo->getVertexSet().size(); i++){

		id = grafo->getVertexSet().at(i)->getInfo();
		x = 3257 * (grafo->getVertexSet().at(i)->getX() + 8.62063)/abs(-8.62063 + 8.61066);
		y = 2301 * (grafo->getVertexSet().at(i)->getY() + 41.15047)/abs(41.15047 - 41.14517);

		gv->addNode(id, x, y);

	}

	for(unsigned int i=0; i <grafo->getVertexSet().size(); i++){
		for(unsigned int j = 0;j < grafo->getVertexSet().at(i)->getAdj().size(); j++){
			if(grafo->getVertexSet().at(i)->getAdj().at(j).getSentido())
				gv->addEdge(contador, grafo->getVertexSet().at(i)->getInfo(), grafo->getVertexSet().at(i)->getAdj().at(j).getDest()->getInfo(), EdgeType::DIRECTED);
			else gv->addEdge(contador, grafo->getVertexSet().at(i)->getInfo(), grafo->getVertexSet().at(i)->getAdj().at(j).getDest()->getInfo(), EdgeType::UNDIRECTED);

			contador++;
		}
	}

	gv->rearrange();
}








