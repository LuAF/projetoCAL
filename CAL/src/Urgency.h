#ifndef SRC_URGENCY_H_
#define SRC_URGENCY_H_

#include "Util.h"
#include "Resource.h"

class Urgency {
	string nome;
	int priority;
	vector<Resource> resources;
	static vector<Urgency> tiposUrgencia;

public:
	Urgency();
	Urgency(string nome, unsigned int priority, vector<Resource> resources);
	const string& getNome() const;
	void setNome(const string& nome);
	int getPriority() const;
	void setPriority(int priority);
	vector<Resource>& getResources() ;
	void setResources(const vector<Resource>& resources);
	void addUrgency(Urgency u);
	void addResources(Resource r);
	vector<Urgency> getTiposUrgencia();
	void cleanResources();

};

#endif /* SRC_URGENCY_H_ */
