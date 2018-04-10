#include "Call.h"

Call::Call(Urgency urgency, unsigned int localization) {
	this->urgency = urgency;
	this->localization = localization;
}

unsigned int Call::getLocalization() const {
	return localization;
}

void Call::setLocalization(unsigned int localization) {
	this->localization = localization;
}

Urgency Call::getUrgency() const{
	return this->urgency;
}

void Call::setUrgency(const Urgency urgency) {
	this->urgency = urgency;
}

bool Call::operator < ( Call * c) const{
	if(c->getUrgency().getPriority() == urgency.getPriority())
		return c->getLocalization( ) < this->getLocalization();

	cout << "c: " << c->getUrgency().getPriority() << "  u: " << urgency.getPriority() << endl;
	return c->getUrgency().getPriority() < urgency.getPriority();
}

