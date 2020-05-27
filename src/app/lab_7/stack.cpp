#include <iostream>
#include <fstream>
#include <stack>

using std::stack;
using std::string;
using std::endl;
using std::cout;
using std::ifstream;
using std::invalid_argument;

template <typename T>
class Node {
public:
    T value;
    Node* next;
};

template <typename T>
class Stack {
private:
    Node<T>* head;

public:
    Stack() {
        this->head = nullptr;
    };

    void push(T value) {
        Node<T>* node = new Node<T>;
        node->value = value;
        node->next = this->head;
        this->head = node;
    }

    T pop() {
        T value = this->head->value;
        Node<T>* next = this->head->next;
        delete this->head;
        this->head = next;
        return value;
    }

    T top() {
        return this->head->value;
    };

    bool empty() {
        return this->head == nullptr;
    }

    ~Stack() {
        while (this->head != nullptr) {
            this->pop();
        }
    }
};

void printStack(Stack<string> stack) {
    while (!stack.empty()){
        cout << stack.top() << endl;
        stack.pop();
    }
}

void writeToStack(Stack<string>& stack, const string& filename) {
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
