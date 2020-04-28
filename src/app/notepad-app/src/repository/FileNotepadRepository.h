
#include "NotepadRepository.h"
#include "../entity/Notepad.h"

class FileNotepadRepository: public NotepadRepository {
private:
     Notepad* notepad;
public:
    FileNotepadRepository() {
        notepad = Notepad::getInstance();
    }

    void save(Note note) override {
        notepad->save(note);
    }

    void remove(int id) override {
        notepad->remove(id);
    }

    Note findOne(int id) override {
        return notepad->findOne(id);
    }

    vector<Note> findAll() override {
        return notepad->findAll();
    }

    bool existsById(int id) override {
        return notepad->findAll().size() > id && id >= 0;
    }

    void init() override {
        notepad->deserialize();
    }

    void destroy() override {
        notepad->serialize();
    }
};

