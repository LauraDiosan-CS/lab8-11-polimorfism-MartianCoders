#include "Validator.h"
#include "MyExceptions.h"
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

bool Validator::employeeValidator(std::vector<std::string> strings) throw (MyExceptions)
{
	if (strings[0].empty())
		throw MyExceptions("Empty ID");
	else {
		if (strings[0].find_first_not_of("0123456789") != std::string::npos)
			throw MyExceptions("ID needs to be a number");
	}

	if (strings[1].empty())
		throw MyExceptions("Empty Name");
	else {
		if (strings[1].find_first_of("0123456789") != std::string::npos || strings[1].find_first_of(".,~`/?.>,<;:']}[{=+-_)(*&^%$#@!") != std::string::npos)
			throw MyExceptions("Name needs to contain only letters");
	}

	if (strings[2].empty())
		throw MyExceptions("Empty Email");
	else {
		if (strings[2].find_first_of("@") == std::string::npos || strings[2].find_first_of(".") == std::string::npos)
			throw MyExceptions("Wrong Email input ( Use @ and . )");
	}

	if (strings[3].empty())
		throw MyExceptions("Empty Grade");
	else {
		if (strings[3].find_first_not_of("0123456789") != std::string::npos)
			throw MyExceptions("Grade needs to be a number");
	}

	return false;
}

std::vector<std::string> Validator::drugsValidator(std::vector<std::string> strings) throw(MyExceptions)
{
	if (strings[0].empty())
		throw MyExceptions("Empty ID");
	else {
		if (strings[0].find_first_not_of("0123456789") != std::string::npos)
			throw MyExceptions("ID needs to be a number");
	}

	if (strings[1].empty())
		throw MyExceptions("Empty Name");
	else {
		if (strings[1].find_first_of("0123456789") != std::string::npos || strings[1].find_first_of(".,~`/?.>,<;:']}[{=+-_)(*&^%$#@!") != std::string::npos)
			throw MyExceptions("Name needs to contain only letters");
	}

	if (strings[2].empty())
		throw MyExceptions("Empty Recipe");
	else {
		if (strings[2] != "true" && strings[2] != "false")
			throw MyExceptions("Recipe needs true/false");
	}

	if (strings[3].empty())
		throw MyExceptions("Empty Stock");
	else {
		if (strings[3].find_first_not_of("0123456789") != std::string::npos)
			throw MyExceptions("Stock needs to be a number");
	}

	if (strings[4].empty())
		throw MyExceptions("Empty Producer");
	else {
		if (strings[4].find_first_of("0123456789") != std::string::npos || strings[1].find_first_of(".,~`/?.>,<;:']}[{=+-_)(*&^%$#@!") != std::string::npos)
			throw MyExceptions("Producer needs to contain only letters");
	}

	return std::vector<std::string>();
}

std::string Validator::deleteValidator(std::string string) throw (MyExceptions)
{
	if (string.empty())
		throw MyExceptions("Empty ID");
	else {
		if (string.find_first_not_of("0123456789") != std::string::npos)
			throw MyExceptions("ID needs to be a number");
	}
	return std::string();
}

std::string Validator::drugSearchValidator(std::string string)
{
	if (string.empty())
		throw MyExceptions("Empty Drug name");
	else {
		if (string.find_first_of("0123456789") != std::string::npos || string.find_first_of(".,~`/?.>,<;:']}[{=+-_)(*&^%$#@!") != std::string::npos)
			throw MyExceptions("Drug name needs to contain only letters");
	}

	return std::string();
}

std::string Validator::changeGradeValidator(std::vector<std::string> strings)
{
	if (strings[0].empty())
		throw MyExceptions("Empty ID");
	else {
		if (strings[0].find_first_not_of("0123456789") != std::string::npos)
			throw MyExceptions("ID needs to be a number");
	}

	if (strings[1].empty())
		throw MyExceptions("Empty new Grade");
	else {
		if (strings[1].find_first_not_of("0123456789") != std::string::npos)
			throw MyExceptions("New Grade needs to be a number");
	}

	return std::string();
}

bool Validator::fileChecker(std::string employeeFile, std::string drugFile) {
	bool file1 = false;
	bool file2 = false;

	std::string path = "D:/C++/lab8-11";
	for (auto& entry : fs::directory_iterator(path)) {
		std::string pat = entry.path().string();
		pat.erase(0, 15);
		if (pat == employeeFile)
			file1 = true;
		else if (pat == drugFile)
			file2 = true;
	}

	if (file1 == true && file2 == true)
		return true;
	return false;
}