#include <exception>
#include <iostream>

using std::exception;
using std::string;
using std::to_string;

class NoteExistsException: public exception {
private:
    const string NOT_EXISTS_MESSAGE = "[WARN] Note doesn't exist with this id.";
public:

public:
    const char *what() const noexcept override {
        return NOT_EXISTS_MESSAGE.c_str();
    }
};