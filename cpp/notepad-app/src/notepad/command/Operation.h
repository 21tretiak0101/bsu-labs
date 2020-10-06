
#include "../exception/OperationExistsException.h"

enum Operation {
    CREATE = 1,
    GET_ONE = 2,
    REMOVE = 3,
    GET_ALL = 4,
    EXIT = 5,
    NONE
};

Operation getOperationByNumber(int number) {
    switch (number) {
        case 1:
            return CREATE;
        case 2:
            return GET_ONE;
        case 3:
            return REMOVE;
        case 4:
            return GET_ALL;
        case 5:
            return EXIT;
        default:
            return NONE;
    }
}