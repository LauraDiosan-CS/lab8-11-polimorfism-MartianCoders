#pragma once

#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <vector>
#include <string>

class Validator {
public:
	bool employeeValidator(std::vector<std::string>);
	std::vector<std::string> drugsValidator(std::vector<std::string>);
	std::string deleteValidator(std::string);

	std::string drugSearchValidator(std::string);
	std::string changeGradeValidator(std::vector<std::string>);

	bool fileChecker(std::string, std::string);
};
#endif // !VALIDATOR

