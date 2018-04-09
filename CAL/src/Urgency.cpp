#include "Urgency.h"

vector<Urgency> Urgency::tiposUrgencia = {};

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

unsigned int Urgency::getPriority()  {
	return priority;
}

void Urgency::setPriority(unsigned int priority) {
	this->priority = priority;
}

 vector<Resource>& Urgency::getResources()  {
	return resources;
}

void Urgency::setResources(const vector<Resource>& resources) {
	this->resources = resources;
}

void Urgency::addUrgency (Urgency u) {
	tiposUrgencia.push_back(u);
}

void Urgency::addResources(Resource r){
	resources.push_back(r);
}

vector<Urgency> Urgency::getTiposUrgencia(){
	return tiposUrgencia;
}

void Urgency::cleanResources(){
	this->resources = {};
}
