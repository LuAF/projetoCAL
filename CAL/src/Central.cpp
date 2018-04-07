#include "Central.h"

Central::Central() {

}

const priority_queue<Call*>& Central::getCalls() const {
	return calls;
}

void Central::addCalls(Call *call) {
	calls.push(call);
}


