#ifndef CENTRAL_H_
#define CENTRAL_H_

#include "Util.h"
#include "Call.h"

class Central {
private:
	priority_queue<Call*> calls;

public:
	Central();
	const priority_queue<Call*>& getCalls() const;
	void addCalls(Call *call);
};

#endif /* CENTRAL_H_ */
