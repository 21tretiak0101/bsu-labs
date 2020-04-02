#include "students/students.h"

int main() {

        Student ilia = {
                "ilia",
                18,
                MALE,
                FIRST,
                {
                        {"math", 6},
                        {"geometry", 9}}
        };

        ilia.addSubject({"geometry", 10});

        double mark = ilia.getAverageMark();
        printf("%f", mark);
}
