
#ifndef SRC_RESOURCE_H_
#define SRC_RESOURCE_H_

#include "Util.h"

class Resource {
private:
	int id;
	string name;
	unsigned int localization;
	bool available;

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


};

#endif /* SRC_RESOURCE_H_ */
