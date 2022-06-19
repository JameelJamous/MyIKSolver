#pragma once

#include "Visitor.h"
#include <string>

class Joint : public Visitor {
public:
	Joint(float distanceToNext=0, float maxAngle=0, float minAngle=0, std::string jointType="");
	Joint(const Joint& aCopy);
	Joint& operator=(const Joint& aCopy);
	~Joint();


	std::string save() const override;
	void load(std::string theData) override;

private:

	float distanceToNext;
	float maxAngle;
	float minAngle;
	std::string type;
};