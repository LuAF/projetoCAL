#include "Util.h"
#include "Graph.h"
#include "Urgency.h"
#include "Call.h"
#include "Central.h"
#include "Resource.h"
#include <iomanip>

Central *central = new Central();

void menuInicial(Graph<int> * grafo) {
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
			menuOpt2(grafo);
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

void menuOpt2(Graph<int> * grafo) {
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

void calculateShortestPath(Graph<int> * grafo){
	//first in priority queue, get localizacao
	//recursos needed
	//guardar em vetor as distancias para cada recurso disponivel
	//devolver vetor com vetores dos caminhos
	vector<vector<int>> caminhosBombeiros;
	vector<vector<int>> caminhosAmbulancias;
	vector<vector<int>> caminhosINEM;
	vector<vector<int>> caminhosPolicia;

	vector<vector<int>> caminhosMaisCurtos;

	Call* call = central->treatCall();

	for(unsigned int i = 0; i < call->getUrgency().getResources().size(); i++){
		if(call->getUrgency().getResources().at(i).getName() == "Bombeiro")
			for(unsigned int j = 0; j < call->getUrgency().getResources().at(i).getFiremen().size(); j++){
				if(call->getUrgency().getResources().at(i).getFiremen().at(j).isAvailable())
					caminhosBombeiros.push_back(grafo->getPath(call->getLocalization(), call->getUrgency().getResources().at(i).getFiremen().at(j).getLocalization()));
			}

		if(call->getUrgency().getResources().at(i).getName() == "Ambulancias")
			for(unsigned int j = 0; j < call->getUrgency().getResources().at(i).getAmbulances().size(); j++){
				if(call->getUrgency().getResources().at(i).getAmbulances().at(j).isAvailable())
					caminhosAmbulancias.push_back(grafo->getPath(call->getLocalization(), call->getUrgency().getResources().at(i).getAmbulances().at(j).getLocalization()));
			}

		if(call->getUrgency().getResources().at(i).getName() == "INEM")
			for(unsigned int j = 0; j < call->getUrgency().getResources().at(i).getInem().size(); j++){
				if(call->getUrgency().getResources().at(i).getInem().at(j).isAvailable())
					caminhosINEM.push_back(grafo->getPath(call->getLocalization(), call->getUrgency().getResources().at(i).getInem().at(j).getLocalization()));
			}

		if(call->getUrgency().getResources().at(i).getName() == "Policia")
			for(unsigned int j = 0; j < call->getUrgency().getResources().at(i).getPolice().size(); j++){
				if(call->getUrgency().getResources().at(i).getPolice().at(j).isAvailable())
					caminhosPolicia.push_back(grafo->getPath(call->getLocalization(), call->getUrgency().getResources().at(i).getPolice().at(j).getLocalization()));
			}
	}

	if(!caminhosBombeiros.empty())
		closerResource(grafo,caminhosBombeiros);

	if(!caminhosAmbulancias.empty())
		closerResource(grafo,caminhosAmbulancias);

	if(!caminhosINEM.empty())
		closerResource(grafo,caminhosINEM);

	if(!caminhosPolicia.empty())
		closerResource(grafo,caminhosPolicia);


}

int distance(Graph<int> *g, vector<int> v){
	int contador = 0;
	for(int i = v.size() - 1; i > 0; i--){
		contador += g->findEdge(v.at(i), v.at(i-1)).getWeight();
	}

	return contador;
}


vector<int> closerResource(Graph<int> *g, vector<vector<int>> v){
	int result = INT_MAX;
	int dist = -1;
	int pos = -1;
	for(unsigned int i = 0; i < v.size(); i++){
		dist = distance(g,v.at(i));
		if(result > dist){
			result = dist;
			pos = i;
		}
	}

	return v.at(pos);
}

void showShortestPath(){

}

void adicionaUrgencias() {

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

}

void readVertexs(Graph<int> *grafo){
	ifstream streamVertexs;
	streamVertexs.open("nos.txt");
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
	streamB.open("estradas.txt");
	streamC.open("ligacoes.txt");

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

		while (!streamC.eof()){
			getline(streamC, line);

			stringstream ssC(line);
			ssC >> idRuaC >> ign >> infO >> ign >> infD;

			grafo->findVertex(infO)->addEdge(grafo->findVertex(infD), idRuaC, nomeRua, sent);
		}

	}
}

void readResources(GraphViewer *gv, Graph<int> *grafo){
	ifstream streamAmbulancias, streamPolice, streamINEM, streamBombeiros;
	streamAmbulancias.open("ambulancias.txt");
	streamPolice.open("police.txt");
	streamINEM.open("inem.txt");
	streamBombeiros.open("bombeiros.txt");
	string line;
	int id;
	int localizacao; //id no
	char ignore;

	while (!streamAmbulancias.eof()){

		getline(streamAmbulancias, line);
		stringstream ssFicheiro(line);
		ssFicheiro >> id;
		ssFicheiro >> ignore;
		ssFicheiro >> localizacao;

		Resource ambulancia(id,"ambulancia",localizacao,true);
		ambulancia.addAmbulances(ambulancia);
		gv->setVertexIcon(localizacao,"images/ambulance.png");
;
	}

	while (!streamPolice.eof()){

		getline(streamPolice, line);
		stringstream ssFicheiro(line);
		ssFicheiro >> id;
		ssFicheiro >> ignore;
		ssFicheiro >> localizacao;

		Resource police(id,"policia",localizacao,true);
		police.addPolice(police);
		gv->setVertexIcon(localizacao,"images/police.png");

	}

	while (!streamINEM.eof()){

		getline(streamINEM, line);
		stringstream ssFicheiro(line);
		ssFicheiro >> id;
		ssFicheiro >> ignore;
		ssFicheiro >> localizacao;

		Resource INEM(id,"inem",localizacao,true);
		INEM.addInem(INEM);
		gv->setVertexIcon(localizacao,"images/inem.png");

	}

	while (!streamBombeiros.eof()){

		getline(streamBombeiros, line);
		stringstream ssFicheiro(line);
		ssFicheiro >> id;
		ssFicheiro >> ignore;
		ssFicheiro >> localizacao;

		Resource bombeiros(id,"bombeiro",localizacao,true);
		bombeiros.addFiremen(bombeiros);
		gv->setVertexIcon(localizacao,"images/fire-truck.png");

	}
}

void printGraph(GraphViewer *gv ,Graph<int> *grafo){
	int id;
	long double x, y;
	int contador = 0;

	for(unsigned int i=0; i <grafo->getVertexSet().size(); i++){

		id = grafo->getVertexSet().at(i)->getInfo();

		x = grafo->getVertexSet().at(i)->getX();
		y = grafo->getVertexSet().at(i)->getY();

		gv->addNode(id, x, y);
		gv->setVertexSize(id, 10);

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
