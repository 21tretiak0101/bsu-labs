#include <exception>
#include <iostream>

using std::exception;
using std::string;
using std::to_string;

class OperationExistsException: public exception {
private:
    const string NOT_EXISTS_MESSAGE = "[WARN] Operation with this number doesn't exist.";

public:
    const char *what() const noexcept override {
        return NOT_EXISTS_MESSAGE.c_str();
    }
};