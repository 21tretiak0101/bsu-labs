#include <string>
#include <utility>
#include <vector>

using std::string;
using std::vector;
using std::invalid_argument;

/**
 * 6.2 (11) - solution
 */
enum Course {
    FIRST, SECOND, THIRD, FOURTH, FIFTH
};

enum Sex {
    MALE, FEMALE, OTHER
};

class Subject {

private:
    string name;
    int mark;

public:
    Subject(string name, int mark) : name(std::move(name)), mark(mark) {}

    const string &getName() const {
        return name;
    }

    int getMark() const {
        return mark;
    }
};

class Student {

private:
    string fullName;
    int age;
    Sex sex;
    double averageMark = 0;
    Course course;
    vector<Subject> subjects;

public:

    Student(string fullName, int age, Sex sex, Course course, vector<Subject> subjects)
            : fullName(std::move(fullName)), age(age), sex(sex), course(course), subjects(std::move(subjects)) {
        updateAverageMark();
    }

    double getAverageMark() const {
        return averageMark;
    }

    Course getCourse() const {
        return course;
    }

    void addSubject(const Subject& subject) {
        if(!isValidSubject(subject)){
            throw invalid_argument("subject " + subject.getName() + " already exists");
        }
        subjects.push_back(subject);
        updateAverageMark();
    }

private:
    bool isValidSubject(const Subject& subject) {
        for(const Subject& s: subjects){
            if(s.getName() == subject.getName())
                return false;
        }
        return true;
    }

    void updateAverageMark() {
        double totalMark = 0;

        for(const Subject& s: subjects){
            totalMark += s.getMark();
        }
        averageMark = totalMark / subjects.size();
    }
};

class University {

public:
    static vector<Student> getBestStudents(const vector<Student>& students, Course course) {
        vector<Student> bestStudents;
        double courseAverageMark = getCourseAverageMark(students, course);

        for (const Student& student : students) {
            if(student.getCourse() == course && student.getAverageMark() > courseAverageMark)
                bestStudents.push_back(student);
        }

        return bestStudents;
    }

    static double getCourseAverageMark(const vector<Student>& students, Course course) {
        double totalMark = 0;
        for (const Student& student : students) {
            if(student.getCourse() == course)
                totalMark += student.getAverageMark();
        }
        return totalMark / students.size();
    }
};


