#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::endl;
using std::to_string;
using std::pair;
using std::make_pair;

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

    void readCardNumber() {
        cin >> cardNumber;
    }

    void readFirstName() {
        cin >> firstName;
    }

    void readLastName() {
        cin >> lastName;
    }
    void readCourse() {
        cin >> course;
    }

    void readAge() {
        cin >> age;
    }

    void readAverageMark() {
        cin >> averageMark;
    }

    void readGroup() {
        cin >> group;
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

    string& getFirstName() {
        return firstName;
    }

    string& getLastName() {
        return lastName;
    }

    void serialize(std::ostream& out) const {
        size_t firstNameSize = firstName.size() + 1;
        out.write((char*) &firstNameSize, sizeof(firstNameSize));
        out.write(firstName.c_str(), firstNameSize);

        size_t lastNameSize = lastName.size() + 1;
        out.write((char*) &lastNameSize, sizeof(lastNameSize));
        out.write(lastName.c_str(), lastNameSize);

        out.write((char*) &cardNumber, sizeof(cardNumber));
        out.write((char*) &age, sizeof(age));
        out.write((char*) &course, sizeof(course));
        out.write((char*) &group, sizeof(group));
        out.write((char*) &averageMark, sizeof(averageMark));
    }

    void deserialize(std::istream& in) {
        size_t firstNameSize;
        in.read((char*) &firstNameSize, sizeof(firstNameSize));
        char* fn_buffer = new char[firstNameSize];
        in.read(fn_buffer, firstNameSize);
        firstName = fn_buffer;
        delete [] fn_buffer;

        size_t lastNameSize;
        in.read((char*) &lastNameSize, sizeof(lastNameSize));
        char* ln_buffer = new char[lastNameSize];
        in.read(ln_buffer, lastNameSize);
        lastName = ln_buffer;
        delete [] ln_buffer;

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

class Database {
private:
    string filename;
    vector<Student> students;

public:
    Database(const string& filename) {
        this->filename = filename;
        this->loadAll();
    }

    Database(const Database& database) {
        this->filename = database.filename;
        this->students = database.students;
        this->loadAll();
    }

    void setFilename(const string& fileName) {
        this->filename = fileName;
    }

    void addStudents(const vector<Student>& vector) {
        this->students = vector;
    }

    void createStudent() {
        Student student;
        student.readCardNumber();
        student.readFirstName();
        student.readLastName();
        student.readAge();
        student.readCourse();
        student.readGroup();
        student.readAverageMark();
        saveStudent(student);
    }

    void saveStudent(const Student& student) {
        students.push_back(student);
    }

    pair<Student, bool> findByCardNumber(int cardNumber) {
        for (Student& student: students) {
            if (student.getCardNumber() == cardNumber) {
                return make_pair(student, true);
            }
        }
        return make_pair(Student(), false);
    }

    void printAll() {
        for (Student& student: students) {
            cout << student.toString() << endl;
        }
    }

    string& getFilename() {
        return filename;
    }

private:
    void saveAll() {
        ofstream fout(filename, std::ios::binary);
        if (fout.is_open()) {
            size_t studentsSize = students.size();
            fout.write((char*) &studentsSize, sizeof(studentsSize));
            for (Student& student: students) {
                student.serialize(fout);
            }
        }
        fout.close();
    }

    void loadAll() {
        ifstream fin(filename, std::ios::binary);
        if (fin.is_open()) {
            size_t studentsSize;
            fin.read((char*) &studentsSize, sizeof(studentsSize));
            for (int i = 0; i < studentsSize; ++i) {
                Student student;
                student.deserialize(fin);
                students.push_back(student);
            }
        }
        fin.close();
    }

public:
    ~Database() {
        this->saveAll();
    }
};

double getCourseAverageMark(Database& database, int course) {
    double totalMark = 0;
    int courseStudentsNumber = 0;
    ifstream fin(database.getFilename(), std::ios::binary);
    if (fin.is_open()) {
        size_t allStudentsNumber;
        fin.read((char*) &allStudentsNumber, sizeof(allStudentsNumber));
        for (int i = 0; i < allStudentsNumber; ++i) {
            Student student;
            student.deserialize(fin);
            if (student.getCourse() == course) {
                totalMark += student.getAverageMark();
                courseStudentsNumber++;
            }
        }
    }
    fin.close();
    cout << totalMark / courseStudentsNumber;
    return totalMark / courseStudentsNumber;
}

int getBestStudentsNumber(Database& database, int course) {
    int number = 0;
    double courseAverageMark = getCourseAverageMark(database, course);
    ifstream fin(database.getFilename(), std::ios::binary);
    if (fin.is_open()) {
        size_t allStudentsNumber;
        fin.read((char*) &allStudentsNumber, sizeof(allStudentsNumber));
        for (int i = 0; i < allStudentsNumber; ++i) {
            Student student;
            student.deserialize(fin);
            if (student.getCourse() == course && student.getAverageMark() > courseAverageMark) {
                number++;
            }
        }
    }
    fin.close();
    return number;
}

double getCourseAverageMark(const vector<Student>& students, int course) {
    double totalMark = 0;
    for (const Student& student : students) {
        if (student.getCourse() == course) {
            totalMark += student.getAverageMark();
        }
    }
    return totalMark / students.size();
}

vector<Student> getBestStudents(const vector<Student>& students, int course) {
    vector<Student> bestStudents;
    double courseAverageMark = getCourseAverageMark(students, course);
    for (const Student& student : students) {
        if (student.getCourse() == course && student.getAverageMark() > courseAverageMark) {
            bestStudents.push_back(student);
        }
    }
    return bestStudents;
}

int main() {}