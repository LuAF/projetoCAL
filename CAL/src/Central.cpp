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
	calls.pop();
}

