#ifndef SRC_URGENCY_H_
#define SRC_URGENCY_H_

#include "Util.h"
#include "Resource.h"

class Urgency {
	string nome;
	unsigned int priority;
	vector<Resource> resources;
	static vector<Urgency> tiposUrgencia;

public:
	Urgency();
	Urgency(string nome, unsigned int priority, vector<Resource> resources);
	const string& getNome() const;
	void setNome(const string& nome);
	unsigned int getPriority() const;
	void setPriority(unsigned int priority);
	const vector<Resource>& getResources() const;
	void setResources(const vector<Resource>& resources);
	void addUrgency(Urgency u);
};

#endif /* SRC_URGENCY_H_ */
