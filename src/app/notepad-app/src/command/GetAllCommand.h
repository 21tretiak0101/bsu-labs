
#include "../exception/EmptyVectorException.h"

using std::to_string;

class GetAllCommand: public Command {
public:
    void execute(FileNotepadService& service) override {
        vector<Note> notes = service.getAllNotes();
        if (!notes.empty()) {
            for (int i = 0; i < notes.size(); ++i) {
                string note = "\t#" + to_string(i) + ": " + notes[i].getTitle();
                ConsoleHelper::println(note);
            }
        }
        else {
            ConsoleHelper::println(EmptyVectorException().what());
        }
    }
};