#ifndef SRC_CALL_H_
#define SRC_CALL_H_

#include "Util.h"
#include "Urgency.h"

class Call {
private:
	Urgency urgency;
	unsigned int localization;

public:
	Call(Urgency urgency, unsigned int localization);
	unsigned int getLocalization() const;
	void setLocalization(unsigned int localization);
	const Urgency& getUrgency() const;
	void setUrgency(const Urgency& urgency);
	bool operator < (const Call & c) const;
};

#endif /* SRC_CALL_H_ */
