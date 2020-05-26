#include <iostream>
#include <fstream>
#include <stack>

using std::stack;
using std::string;
using std::endl;
using std::cout;
using std::ifstream;
using std::invalid_argument;

void printStack(stack<string> stack) {
    while (!stack.empty()){
        cout << stack.top() << endl;
        stack.pop();
    }
}

void writeToStack(stack<string>& stack, const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        throw invalid_argument(
                "File with path: [" + filename + "] cannot be opened.");
    }
    while (!in.eof()) {
        string word;
        in >> word;
        if (in.fail()) {
            break;
        }
        stack.push(word);
    }
    in.close();
}

int main() { }
