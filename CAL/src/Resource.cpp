#include "Resource.h"

	vector<Resource> Resource::ambulances = {};
	vector<Resource> Resource::firemen = {};
	vector<Resource> Resource::police = {};
	vector<Resource> Resource::inem = {};

Resource::Resource() {
	this->id = 0;
	this->name = "";
}

Resource::Resource(string name){
	this->name = name;
}

Resource::Resource(int id, string name, unsigned int localization, bool available) {
	this->id = id;
	this->name = name;
	this->localization = localization;
	this->available = available;
}

bool Resource::isAvailable() const {
	return available;
}

void Resource::setAvailable(bool available) {
	this->available = available;
}

unsigned int Resource::getLocalization() const {
	return localization;
}

void Resource::setLocalization(unsigned int localization) {
	this->localization = localization;
}

 string Resource::getName()  {
	return name;
}

vector<Resource> Resource::getAmbulances()  {
	return ambulances;
}

vector<Resource> Resource::getFiremen()  {
	return firemen;
}

vector<Resource> Resource::getInem()  {
	return inem;
}

vector<Resource> Resource::getPolice()  {
	return police;
}

void Resource::addAmbulances(Resource a)  {
	ambulances.push_back(a);
}

void Resource::addFiremen(Resource a)  {
	firemen.push_back(a);
}

void Resource::addInem(Resource a)  {
	inem.push_back(a);
}

void Resource::addPolice(Resource a)  {
	police.push_back(a);
}

void Resource::setName(const string& name) {
	this->name = name;
}
