
#include "../service/FileNotepadService.h"

class Command {
public:
    virtual void execute(FileNotepadService& service) = 0;
};

