#include "../exception/EmptyVectorException.h"

using std::to_string;

class GetAllCommand: public Command {
public:
    void execute(FileNotepadService& service) override {
        vector<Note> notes = service.getAllNotes();
        if (!notes.empty()) {
            int notesSize = notes.size();
            for (int i = 0; i < notesSize; ++i) {
                string note = "\t#" + to_string(i) + ": "+
                        notes[i].getTitle() +
                        "\n\t[Date]: " + notes[i].getDate();
                ConsoleHelper::println(note);
            }
        } else {
            ConsoleHelper::println(EmptyVectorException().what());
        }
    }
};