#include "Util.h"
#include "Graph.h"
#include <iomanip>

void readVertexs(){
	ifstream streamVertexs;
	streamVertexs.open("A.txt");
	istringstream ssFicheiro;
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

		cout << std::setprecision(10) << "Info: " << informacao << "Latitude: " << latitude << "Longitude: " << longitude << endl << endl;
	}
}

