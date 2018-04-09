#ifndef CENTRAL_H_
#define CENTRAL_H_

#include "Util.h"
#include "Call.h"

class Central {
private:
	priority_queue<Call*> calls;
	vector<Resource> ambulances;
	vector<Resource> firemen;
	vector<Resource> police;
	vector<Resource> inem;

public:
	Central();
	priority_queue<Call*> getCalls() ;
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
