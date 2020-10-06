#include <exception>
#include <iostream>

using std::exception;
using std::string;
using std::to_string;

class EmptyVectorException: public exception {

private:
    const string NOT_EXISTS_MESSAGE = "[WARN] Notes not found.";

public:
    const char *what() const noexcept override {
        return NOT_EXISTS_MESSAGE.c_str();
    }
};