#include <iostream>
#include <vector>
#include "command/Operation.h"
#include "exception/NumberFormatException.h"
#include <cstdio>
#include <cmath>
#include <regex>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::regex;
using std::regex_match;

class ConsoleHelper {
private:
    /**
    * The message for successful operations
    */
    static string SUCCESS_MESSAGE;
    /**
     * The message requesting an identifier from the user
     */
    static string GET_ID_MESSAGE;
    /**
     * Default response for format errors
     */
    static int DEFAULT_ERROR_NUMBER;
    /**
     * Check if the string contains only numbers
     */
    static string NUMBERS_REGEX;
    /**
    * The message for the main program menu
    */
    static string OPERATION_LIST;

public:
    static Operation askOperation() {
        println(OPERATION_LIST);
        int operationNumber = readInt();
        cin.ignore();
        return getOperationByNumber(operationNumber);
    }

    static void println(const string& text) {
        cout << text << endl;
    }

    static string readLine() {
        string line;
        cin >> line;
        return line;
    }

    /**
     * @param delimiter - reading ends after this symbol
     */
    static string readManyLines(char delimiter) {
        string text;
        getline(cin, text, delimiter);
        return text;
    }

    static void success(){
        println(SUCCESS_MESSAGE);
    }

    static int readInt() {
        try {
            string line = readLine();
            return parseInt(line);
        }
        catch (NumberFormatException& e) {
            ConsoleHelper::println(e.what());
        }
        return DEFAULT_ERROR_NUMBER;
    }

    static void printIdMessage(){
        println(GET_ID_MESSAGE);
    }

private:
    static bool isNumber(string& str) {
        return regex_match(str, regex(NUMBERS_REGEX));
    }

    static int parseInt(string& str) {
        if (!isNumber(str))
            throw NumberFormatException(str);
        return stoi(str);
    }
};

string ConsoleHelper::OPERATION_LIST = "\nType the operation number to continue"
                                       "\n1: Create the note"
                                       "\n2: Show one note"
                                       "\n3. Remove the note"
                                       "\n4: Show all notes"
                                       "\n5: Exit";

string ConsoleHelper::SUCCESS_MESSAGE = "[INFO] Successful action.";

string ConsoleHelper::GET_ID_MESSAGE = "Type the note id:";

int ConsoleHelper::DEFAULT_ERROR_NUMBER = -1;

string ConsoleHelper::NUMBERS_REGEX = "\\d+";
