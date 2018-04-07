#include "Urgency.h"

Urgency::Urgency(){
	this->nome = "";
	this->priority = 0;
	this->resources = {};
}

Urgency::Urgency(string nome, unsigned int priority, vector<Resource> resources) {
	this->nome = nome;
	this->priority = priority;
	this->resources = resources;
}

const string& Urgency::getNome() const {
	return nome;
}

void Urgency::setNome(const string& nome) {
	this->nome = nome;
}

unsigned int Urgency::getPriority() const {
	return priority;
}

void Urgency::setPriority(unsigned int priority) {
	this->priority = priority;
}

const vector<Resource>& Urgency::getResources() const {
	return resources;
}

void Urgency::setResources(const vector<Resource>& resources) {
	this->resources = resources;
}

/*
void Urgency::addUrgency (Urgency u) {
	this->tiposUrgencia.push_back(u);
}
*/
