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

 Urgency & Call::getUrgency()  {
	return urgency;
}

void Call::setUrgency(const Urgency urgency) {
	this->urgency = urgency;
}

bool Call::operator < ( Call & c) {
	return this->urgency.getPriority() < c.getUrgency().getPriority();
}
