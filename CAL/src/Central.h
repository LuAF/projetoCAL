#ifndef CENTRAL_H_
#define CENTRAL_H_

#include "Util.h"
#include "Call.h"

class Central {
private:
	priority_queue<Call*> calls;

public:
	Central();
	priority_queue<Call*> getCalls() ;
	void addCalls(Call *call);
	Call* treatCall();
	void ignoreCall();
};

#endif /* CENTRAL_H_ */
