
#ifndef SRC_RESOURCE_H_
#define SRC_RESOURCE_H_

#include "Util.h"

class Resource {
private:
	int id;
	string name;
	unsigned int localization;
	bool available;
	static vector<Resource> ambulances;
	static vector<Resource> firemen;
	static vector<Resource> police;
	static vector<Resource> inem;

public:
	Resource();
	Resource(string name);
	Resource(int id, string name, unsigned int localization, bool available);
	bool isAvailable() const;
	void setAvailable(bool available);
	unsigned int getLocalization() const;
	void setLocalization(unsigned int localization);
	string getName() ;
	void setName(const string& name);
	vector<Resource> getAmbulances() ;
	vector<Resource> getFiremen() ;
	vector<Resource> getInem() ;
	vector<Resource> getPolice() ;
	void addAmbulances(Resource a);
	void addFiremen(Resource a);
	void addInem(Resource a);
	void addPolice(Resource a);

};

#endif /* SRC_RESOURCE_H_ */
