#pragma once

#ifndef MYEXCEPTIONS
#define MYEXCEPTIONS

#include <string>
#include <stdexcept>

class MyExceptions {
private:
	std::string message;
public:
	MyExceptions() {}
	MyExceptions(std::string input) {
		this->message = input;
	}

	std::string getMessage() {
		return this->message;
	}

};
#endif // !MYEXCEPTIONS
