#include "Resource.h"

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


void Resource::setName(const string& name) {
	this->name = name;
}
