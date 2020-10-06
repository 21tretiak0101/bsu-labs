#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::to_string;

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
    Student() {
        this->create();
    }

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

    void create() {
        cin >> cardNumber;
        cin >> firstName;
        cin >> lastName;
        cin >> age;
        cin >> course;
        cin >> group;
        cin >> averageMark;
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

Student* createStudents(int size) {
    return new Student[size];
}

double getCourseAverageMark(const Student* students, int size, int course) {
    double totalMark = 0;
    for (int i = 0; i < size; ++i) {
        if (students[i].getCourse() == course) {
            totalMark += students[i].getAverageMark();
        }
    }
    return totalMark / size;
}

int getBestStudentsNumber(const Student* students, int size, int course) {
    double courseAverageMark = getCourseAverageMark(students, size, course);
    int bestStudentsNumber = 0;
    for (int i = 0; i < size; ++i) {
        if ((students[i].getCourse() == course) && (students[i].getAverageMark() > courseAverageMark)) {
            bestStudentsNumber++;
        }
    }
    return bestStudentsNumber;
}

int main() {
    int size = 2;
    Student* students = createStudents(size);
    int bestStudentsNumber = getBestStudentsNumber(students, size, 1);
    cout << bestStudentsNumber;
    delete [] students;
}
