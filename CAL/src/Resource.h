
#ifndef SRC_RESOURCE_H_
#define SRC_RESOURCE_H_

#include "Util.h"

class Resource {
private:
	string name;
	unsigned int localization;
	bool available;
	static vector<Resource> ambulances;
	static vector<Resource> firemen;
	static vector<Resource> police;
	static vector<Resource> inem;


public:
	Resource(string name, unsigned int localization, bool available);
	bool isAvailable() const;
	void setAvailable(bool available);
	unsigned int getLocalization() const;
	void setLocalization(unsigned int localization);
	const string& getName() const;
	void setName(const string& name);
};

#endif /* SRC_RESOURCE_H_ */
