#pragma once

#include "Visitor.h"
#include <string>
#include <optional>
#include <list>
#include <vector>

using listOpt = std::optional<std::list<std::string>> ;
class Joint : public Visitor {
public:
	Joint(float distanceToNext=0, float maxAngle=0, float minAngle=0, std::string jointType="");
	Joint(const Joint& aCopy);
	Joint& operator=(const Joint& aCopy);
	~Joint();


	std::string save() const override;
	void load(std::string theData) override;

private:

	listOpt splitCSV(std::string theData);

	std::vector<float> jointParams; //1st - distanceToNext, 2nd - maxAngle, 3rd - minAngle
	std::string type;
};