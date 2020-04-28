

#include "../exception/NoteExistsException.h"

class GetOneCommand: public Command {
public:
    void execute(FileNotepadService& service) override {
        ConsoleHelper::printIdMessage();

        int id = ConsoleHelper::readInt();

        if (service.exists(id)) {
            Note note = service.getNote(id);
            ConsoleHelper::println(note.toString());
        } else {
            ConsoleHelper::println(NoteExistsException().what());
        }
    }
};