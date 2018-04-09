#include "Util.h"
#include "Graph.h"
#include "Urgency.h"
#include "Central.h"
#include "Resource.h"
#include <iomanip>

Central *central = new Central();
Call * call;

void menuInicial(GraphViewer *gv, Graph<int> * grafo) {
	cout << "Central de atendimento de urgencias" << endl;
	cout << "[1] Efetuar Chamada" << endl;
	cout << "[2] Tratar Chamadas" << endl << endl;

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
			menuOpt1(gv, grafo);
			break;
		}
		case 2:
		{
			menuOpt2(gv, grafo);
			break;
		}
	}

}

void menuOpt1(GraphViewer *gv, Graph<int> * grafo) {
	cout << endl << "Efetuar Chamada\n" << endl;
	cout << "Tipo de Urgencia: \n\n";

	Urgency* u = new Urgency();
	for(unsigned int i = 0; i < u->getTiposUrgencia().size();i++ ){
		cout << "[" << i+1 << "] " << u->getTiposUrgencia().at(i).getNome() << endl;
	}

	unsigned int opt;
	cout << "\n> ";
	cin >> opt;


	while (opt < 1 && opt > u->getTiposUrgencia().size()){
		cout << "Escolha uma opcao valida! " << endl;
		cin >> opt;
	}

	opt--;

	cout << "\nLocalizacao(ID do no): ";

	unsigned int localizacao;
	cin >> localizacao;


	while (localizacao < 1 || localizacao > 35){
		cout << "Escolha uma opcao valida (Entre 1 e 35) ! " << endl;
		cout << "\n\nLocalizacao(ID do no): ";
		cin >> localizacao;
	}

	Call* call = new Call(u->getTiposUrgencia().at(opt),localizacao);
	central->addCalls(call);
	cout << endl << endl;
	menuInicial(gv,grafo);

}

void menuOpt2(GraphViewer *gv, Graph<int> * grafo) {
	cout << "Tratar Chamada" << endl;

	call = central->treatCall();

	printGraph(gv,grafo);
	getchar();
	cout << "Tratamento da chamada de maior prioridade concluido \n\n" << endl << endl;
	menuInicial(gv,grafo);
}

vector<int> caminhoHospital(Graph<int> * grafo){
	vector<int> caminhoHospital;
	for(unsigned int i = 0; i < call->getUrgency().getResources().size(); i++){
		if(call->getUrgency().getResources().at(i).getName() == "Ambulancia" || call->getUrgency().getResources().at(i).getName() == "INEM"){
			if(call->getLocalization() != 5)
				caminhoHospital = grafo->getPath(call->getLocalization(),5);
		}
	}

	return caminhoHospital;
}

vector<vector<int>> calculateShortestPath(Graph<int> * grafo){
	vector<vector<int>> caminhosBombeiros;
	vector<vector<int>> caminhosAmbulancias;
	vector<vector<int>> caminhosINEM;
	vector<vector<int>> caminhosPolicia;

	vector<vector<int>> caminhosMaisCurtos;

	for(unsigned int i = 0; i < call->getUrgency().getResources().size(); i++){
		if(call->getUrgency().getResources().at(i).getName() == "Bombeiro")
			for(unsigned int j = 0; j < call->getUrgency().getResources().at(i).getFiremen().size(); j++){
				if(call->getUrgency().getResources().at(i).getFiremen().at(j).isAvailable())
					caminhosBombeiros.push_back(grafo->getPath(call->getLocalization(), call->getUrgency().getResources().at(i).getFiremen().at(j).getLocalization()));
			}

		if(call->getUrgency().getResources().at(i).getName() == "Ambulancia")
			for(unsigned int j = 0; j < call->getUrgency().getResources().at(i).getAmbulances().size(); j++){
				if(call->getUrgency().getResources().at(i).getAmbulances().at(j).isAvailable()){
					caminhosAmbulancias.push_back(grafo->getPath(call->getLocalization(), call->getUrgency().getResources().at(i).getAmbulances().at(j).getLocalization()));
				}
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




	Resource *r = new Resource();
	vector<int> temp;

	if(!caminhosBombeiros.empty()){
		temp = closerResource(grafo,caminhosBombeiros);
		for(unsigned int i = 0; i < r->getFiremen().size();i++)
			if(temp.at(0) == r->getFiremen().at(i).getLocalization())
				r->getFiremen().at(i).setAvailable(false);

		caminhosMaisCurtos.push_back(temp);
	}

	if(!caminhosAmbulancias.empty()){
		temp = closerResource(grafo,caminhosAmbulancias);
		for(unsigned int i = 0; i < r->getAmbulances().size();i++)
			if(temp.at(0) == r->getAmbulances().at(i).getLocalization())
				r->getAmbulances().at(i).setAvailable(false);

		caminhosMaisCurtos.push_back(temp);
	}

	if(!caminhosINEM.empty()){
		temp = closerResource(grafo,caminhosINEM);
		for(unsigned int i = 0; i < r->getInem().size();i++)
			if(temp.at(0) == r->getInem().at(i).getLocalization())
				r->getInem().at(i).setAvailable(false);

		caminhosMaisCurtos.push_back(temp);
	}

	if(!caminhosPolicia.empty()){
		temp = closerResource(grafo,caminhosPolicia);
		for(unsigned int i = 0; i < r->getPolice().size();i++)
			if(temp.at(0) == r->getPolice().at(i).getLocalization())
				r->getPolice().at(i).setAvailable(false);

		caminhosMaisCurtos.push_back(temp);
	}

	temp = {};

	return caminhosMaisCurtos;

}

double distance(Graph<int> *g, vector<int> v){
	double contador = 0;
	for(int i = v.size() - 1; i > 0; i--){
		contador += g->findEdge(v.at(i), v.at(i-1)).getWeight();
	}

	return contador;
}

vector<int> closerResource(Graph<int> *g, vector<vector<int>> v){
	int result = INT_MAX;
	double dist = -1.0;
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

void adicionaUrgencias() {
	Resource policia("Policia");
	Resource bombeiro("Bombeiro");
	Resource inem("INEM");
	Resource ambulancia("Ambulancia");

	Urgency u ("Fuga de gas", 3, {});
	u.addResources(bombeiro);
	u.addResources(policia);
	u.addUrgency(u);

	u.cleanResources();
	u.setNome("Incendio Domestico");
	u.addResources(bombeiro);
	u.addResources(policia);
	u.addResources(ambulancia);
	u.setPriority(5);
	u.addUrgency(u);

	u.cleanResources();
	u.setNome("Incendio Florestal");
	u.addResources(bombeiro);
	u.addResources(policia);
	u.setPriority(2);
	u.addUrgency(u);

	u.cleanResources();
	u.setNome("Alerta Tsunami");
	u.addResources(policia);
	u.setPriority(9);
	u.addUrgency(u);

	u.cleanResources();
	u.setNome("Deslizamento de terras");
	u.addResources(bombeiro);
	u.addResources(policia);
	u.addResources(ambulancia);
	u.setPriority(8);
	u.addUrgency(u);

	u.cleanResources();
	u.setNome("Violencia domestica");
	u.addResources(policia);
	u.setPriority(6);
	u.addUrgency(u);

	u.cleanResources();
	u.setNome("Rapto");
	u.addResources(policia);
	u.setPriority(7);
	u.addUrgency(u);

	u.cleanResources();
	u.setNome("Assalto");
	u.addResources(policia);
	u.setPriority(3);
	u.addUrgency(u);

	u.cleanResources();
	u.setNome("Assistencia medica grave");
	u.addResources(ambulancia);
	u.addResources(inem);
	u.setPriority(1);
	u.addUrgency(u);

	u.cleanResources();
	u.setNome("Assistencia medica ligeira");
	u.addResources(ambulancia);
	u.setPriority(6);
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
		sent = true;

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
	gv->setBackground("mapa.png");
	gv->createWindow(1000, 706);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");
	gv->defineEdgeCurved(false);

	vector<vector<int>> temp = calculateShortestPath(grafo);
	vector<int> hospital = caminhoHospital(grafo);

	int id;
	long double x, y;
	int contador = 0;

	for(unsigned int i=0; i <grafo->getVertexSet().size(); i++){

		id = grafo->getVertexSet().at(i)->getInfo();

		x = grafo->getVertexSet().at(i)->getX();
		y = grafo->getVertexSet().at(i)->getY();

		gv->addNode(id, x, y);
		gv->setVertexSize(id, 10);
		gv->setVertexColor(id,"blue");
		if(id == 5)
			gv->setVertexIcon(id, "images/hospital.png");
		else gv->setVertexIcon(id, "images/default.png");

	}

	readResources(gv, grafo);

	for(unsigned int i=0; i <grafo->getVertexSet().size(); i++){
		for(unsigned int j = 0;j < grafo->getVertexSet().at(i)->getAdj().size(); j++){
			gv->addEdge(contador, grafo->getVertexSet().at(i)->getInfo(), grafo->getVertexSet().at(i)->getAdj().at(j).getDest()->getInfo(), EdgeType::UNDIRECTED);

			contador++;
		}
	}

	for(unsigned int i = 0; i < temp.size(); i++){
		for(unsigned int j = 0; j < temp.at(i).size() - 1; j++){
			contador++;

			if(j == temp.at(i).size() - 2){
				gv->setVertexIcon(temp.at(i).at(j+1),"images/sos.png");
			}

			gv->addEdge(contador,temp.at(i).at(j),temp.at(i).at(j+1),EdgeType::UNDIRECTED);
			gv->setVertexColor(temp.at(i).at(j),"red");
			gv->setVertexColor(temp.at(i).at(j+1),"red");
			gv->setEdgeColor(contador, "red");
			gv->setEdgeThickness(contador, 4);
		}
	}

	if(!hospital.empty())
	for(unsigned int i = 0; i < hospital.size() - 1; i++){
		contador++;
		gv->addEdge(contador,hospital.at(i),hospital.at(i+1),EdgeType::UNDIRECTED);
		gv->setVertexColor(hospital.at(i),"orange");
		gv->setVertexColor(hospital.at(i+1),"orange");
		gv->setEdgeColor(contador, "orange");
		gv->setEdgeThickness(contador, 3);
	}

	temp = {};

	gv->rearrange();


}
