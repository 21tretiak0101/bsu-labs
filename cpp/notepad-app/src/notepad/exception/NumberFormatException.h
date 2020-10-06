#include <exception>
#include <iostream>

using std::exception;
using std::string;

class NumberFormatException: public exception {
private:
    /**
     * the string that failed the number format check
     */
    string str;
    /**
     * message
     */
    const string EXCEPTION_MESSAGE = "[WARN] It is not a number. For input string: ";

public:
    explicit NumberFormatException(const string &str) : str(str) {}

public:
    const char *what() const noexcept override {
        return (EXCEPTION_MESSAGE + str).c_str();
    }
};