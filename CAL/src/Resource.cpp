#include "Resource.h"

	vector<Resource> Resource::ambulances = {};
	vector<Resource> Resource::firemen = {};
	vector<Resource> Resource::police = {};
	vector<Resource> Resource::inem = {};

Resource::Resource(string name, unsigned int localization, bool available) {
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

const string& Resource::getName() const {
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

void Resource::setName(const string& name) {
	this->name = name;
}
