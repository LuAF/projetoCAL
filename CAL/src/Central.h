#ifndef CENTRAL_H_
#define CENTRAL_H_

#include "Util.h"
#include "Call.h"

struct CallCompare
{
    bool operator()(Call *t1, Call *t2) const
    {
        return t2->getUrgency().getPriority() < t1->getUrgency().getPriority();
    }
};

class Central {
private:
	priority_queue<Call*, vector<Call*>, CallCompare> calls;
	vector<Resource> ambulances;
	vector<Resource> firemen;
	vector<Resource> police;
	vector<Resource> inem;

public:
	Central();
	priority_queue<Call*, vector<Call*>, CallCompare> getCalls() ;
	void addCalls(Call *call);
	Call* treatCall();
	void ignoreCall();

	vector<Resource> getAmbulances() ;
	vector<Resource> getFiremen() ;
	vector<Resource> getInem() ;
	vector<Resource> getPolice() ;
	void setUnavailable(string resource, int i);
	void addAmbulances(Resource a);
	void addFiremen(Resource a);
	void addInem(Resource a);
	void addPolice(Resource a);
};

#endif /* CENTRAL_H_ */
