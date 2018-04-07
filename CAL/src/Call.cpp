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

const Urgency& Call::getUrgency() const {
	return urgency;
}

void Call::setUrgency(const Urgency& urgency) {
	this->urgency = urgency;
}

bool Call::operator < (const Call & c) const{
	return this->urgency.getPriority() < c.getUrgency().getPriority();
}
