#include "Joint.h"

Joint::Joint(float distanceToNext, float maxAngle,
	float minAngle, std::string jointType) {
	this->distanceToNext = distanceToNext;
	this->maxAngle = maxAngle;
	this->minAngle = minAngle;
	type = jointType;
}

Joint::Joint(const Joint& aCopy) { *this = aCopy; }

Joint& Joint::operator=(const Joint& aCopy) {
	distanceToNext = aCopy.distanceToNext;
	maxAngle = aCopy.maxAngle;
	minAngle = aCopy.minAngle;
	type = aCopy.type;

	return *this;
}

Joint::~Joint(){ /* Do Nothing */ }

std::string Joint::save() const {
	std::string outStr;
	outStr += std::to_string(distanceToNext) + "," + std::to_string(maxAngle) + 
		"," + std::to_string(minAngle) + "," + type;

	return outStr;
}

void Joint::load(std::string theData) {
              
}