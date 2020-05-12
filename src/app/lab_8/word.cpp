#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::invalid_argument;

class Word {

private:
    string value;

public:
    Word(const string& value) {
        this->value = value;
    }

    Word(char c, int size) {
        if (size < 0) {
            throw invalid_argument("word size must not be negative");
        }
        this->value.append(size, c);
    }

    Word() {}

    Word(const Word& word) {
        this->value = word.value;
    }

    string& getValue() {
        return value;
    }

    void readValue() {
        cin >> this->value;
    }

    void print() {
        cout << value;
    }
};

int main() {
    Word word;
    word.readValue();

    int asciiSum = 0;
    for (char& c : word.getValue()) {
        asciiSum += c;
    }

    Word copy(word);
    for (char& c: copy.getValue()) {
        if (c > 'n') {
            c = 'f';
        }
    }
    copy.print();
}
