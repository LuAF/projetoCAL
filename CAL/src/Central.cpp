#include "Central.h"

Central::Central() {

}

 priority_queue<Call*> Central::getCalls()  {
	return calls;
}

void Central::addCalls(Call *call) {
	calls.push(call);
}

Call* Central::treatCall(){
	Call *temp = calls.top();
	calls.pop();
	return temp;
}

void Central::ignoreCall(){
	Call* temp = calls.top();

	calls.pop();
	delete temp;
}

vector<Resource> Central::getAmbulances()  {
	return ambulances;
}

vector<Resource> Central::getFiremen()  {
	return firemen;
}

vector<Resource> Central::getInem()  {
	return inem;
}

vector<Resource> Central::getPolice()  {
	return police;
}

void Central::addAmbulances(Resource a)  {
	ambulances.push_back(a);
}

void Central::addFiremen(Resource a)  {
	firemen.push_back(a);
}

void Central::addInem(Resource a)  {
	inem.push_back(a);
}

void Central::addPolice(Resource a)  {
	police.push_back(a);
}


void Central::setUnavailable(string resource, int i){
	if(resource == "bombeiro")
		firemen.at(i).setAvailable(false);
	else if (resource == "ambulancia")
		ambulances.at(i).setAvailable(false);
	else if (resource == "policia")
		police.at(i).setAvailable(false);
	else inem.at(i).setAvailable(false);
}

