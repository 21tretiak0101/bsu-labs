#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::istream;
using std::ostream;
using std::to_string;
using std::invalid_argument;
using std::ios;

string file_not_open(string& path) {
    return "File with path: [" + path + "] cannot be opened.";
}

void writeString(string& value, ostream& out) {
    size_t size = value.size() + 1;
    out.write((char*) &size, sizeof(size));
    out.write(value.c_str(), size);
}

string readString(istream& in) {
    size_t size;
    in.read((char*) &size, sizeof(size));
    char* buffer = new char[size];
    in.read(buffer, size);
    string value = buffer;
    delete [] buffer;
    return value;
}

class Student {
private:
    int cardNumber;
    string firstName;
    string lastName;
    int age;
    int course;
    int group;
    double averageMark;

public:
    Student() { }

    Student(int cardNumber, const string& firstName, const string& lastName, int age,
            int course, int group, double averageMark) {
        this->cardNumber = cardNumber;
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->course = course;
        this->group = group;
        this->averageMark = averageMark;
    }

    Student(const Student& student) {
        this->cardNumber = student.cardNumber;
        this->firstName = student.firstName;
        this->lastName = student.lastName;
        this->age = student.age;
        this->course = student.course;
        this->group = student.group;
        this->averageMark = student.averageMark;
    }

    int getAge() const {
        return age;
    }

    int getCourse() const {
        return course;
    }

    double getAverageMark() const {
        return averageMark;
    }

    int getGroup() const {
        return group;
    }

    int getCardNumber() const {
        return cardNumber;
    }

    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    void serialize(ostream& out) {
        writeString(firstName, out);
        writeString(lastName, out);
        out.write((char*) &cardNumber, sizeof(cardNumber));
        out.write((char*) &age, sizeof(age));
        out.write((char*) &course, sizeof(course));
        out.write((char*) &group, sizeof(group));
        out.write((char*) &averageMark, sizeof(averageMark));
    }

    void deserialize(istream& in) {
        firstName = readString(in);
        lastName = readString(in);
        in.read((char*) &cardNumber, sizeof(cardNumber));
        in.read((char*) &age, sizeof(age));
        in.read((char*) &course, sizeof(course));
        in.read((char*) &group, sizeof(group));
        in.read((char*) &averageMark, sizeof(averageMark));
    }

    string toString() const {
        return "{card number: " + to_string(cardNumber) +
               ", first name: " + firstName +
               ", last name: " + lastName +
               ", age: " + to_string(age) +
               ", course: " + to_string(course) +
               ", group: " + to_string(group) +
               ", average mark: " + to_string(averageMark) + "}";
    }

    ~Student() { }
};

/**
 *
 * @param path - path to the file
 * @param students - vector with students to be written to the file
 */
void writeStudents(string& path, vector<Student> students) {
    ofstream out(path, ios::binary);
    if (!out.is_open()) {
        throw invalid_argument(file_not_open(path));
    }
    size_t studentsSize = students.size();
    out.write((char*) &studentsSize, sizeof(studentsSize));
    for (Student& student: students) {
        student.serialize(out);
    }
    out.close();
}

/**
 *
 * @param path - path to the file with students
 * @param course - students course number
 * @return course average mark
 */
double getCourseAverageMark(string& path, int course) {
    double totalMark = 0;
    int courseStudentsNumber = 0;
    ifstream in(path, ios::binary);
    if (!in.is_open()) {
        throw invalid_argument(file_not_open(path));
    }
    size_t allStudentsNumber;
    in.read((char*) &allStudentsNumber, sizeof(allStudentsNumber));
    for (int i = 0; i < allStudentsNumber; ++i) {
        Student student;
        student.deserialize(in);
        if (student.getCourse() == course) {
            totalMark += student.getAverageMark();
            courseStudentsNumber++;
        }
    }
    in.close();
    return totalMark / courseStudentsNumber;
}

/**
 *
 * @param path - path to the file with students
 * @param course - students course number
 * @return best students number
 */
int getBestStudentsNumber(string& path, int course) {
    double courseAverageMark = getCourseAverageMark(path, course);
    ifstream in(path, ios::binary);
    if (!in.is_open()) {
        throw invalid_argument(file_not_open(path));
    }
    size_t allStudentsNumber;
    in.read((char*) &allStudentsNumber, sizeof(allStudentsNumber));

    int bestStudentsNumber = 0;
    for (int i = 0; i < allStudentsNumber; ++i) {
        Student student;
        student.deserialize(in);
        if ((student.getCourse() == course) && (student.getAverageMark() > courseAverageMark)) {
            bestStudentsNumber++;
        }
    }
    in.close();
    return bestStudentsNumber;
}

int main() { }
