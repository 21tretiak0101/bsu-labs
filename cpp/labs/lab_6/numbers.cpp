#include <iostream>
#include <fstream>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;
using std::endl;
using std::ios;
using std::invalid_argument;

enum Format {
    BINARY,
    TEXT
};

/**
 * POSITIVE, NEGATIVE, ZERO
 */
const int TYPES_NUMBER = 3;

string file_not_open(const string& path) {
    return "File with path: [" + path + "] cannot be opened.";
}

void writeInt(ofstream& out, int value, Format format = BINARY) {
    if (format == BINARY) {
        out.write((char*) &value, sizeof(value));
    } else {
        out << value << " ";
    }
}

int readInt(ifstream& in, Format format = BINARY) {
    int value;
    if (format == BINARY) {
        in.read((char*) &value, sizeof(value));
    } else {
        in >> value;
    }
    return value;
}

/**
 *
 * @param readFrom - path to the file with numbers
 * @param writeTo - path to new file with sorted numbers
 */
void sortNumbers(const string& readFrom, const string& writeTo, Format format = BINARY) {
    for (int i = 0; i < TYPES_NUMBER; ++i) {
        ifstream in(readFrom, format == BINARY ? ios::binary : ios::in);
        ofstream writer(readFrom, format == BINARY ? ios::binary : ios::in);
        if (!in.is_open()) {
            throw invalid_argument(file_not_open(readFrom));
        }
        if (!writer.is_open()) {
            throw invalid_argument(file_not_open(writeTo));
        }
        while (!in.eof()) {
            int number = readInt(in, format);
            if (in.fail()) {
                break;
            }
            if ((i == 0 && number < 0)
                    || (i == 1 && number == 0)
                    || (i == 2 && number > 0)) {
                writeInt(writer, number, format);
            }
        }
        in.close();
        writer.close();
    }
}

void writeNumbers(const string& path, int* numbers, int size, Format format = BINARY) {
    ofstream out(path, format == BINARY ? ios::binary : ios::in);
    if (!out.is_open()) {
        throw invalid_argument(file_not_open(path));
    }
    for (int i = 0; i < size; ++i) {
        writeInt(out, numbers[i], format);
    }
    out.close();
}

void printNumbers(const string& path, Format format = BINARY) {
    ifstream in(path, format == BINARY ? ios::binary : ios::in);
    if (!in.is_open()) {
        throw invalid_argument(file_not_open(path));
    }
    while (!in.eof()) {
        int number = readInt(in, format);
        if (in.fail()) {
            break;
        }
        cout << number << endl;
    }
    in.close();
}

int main() { }