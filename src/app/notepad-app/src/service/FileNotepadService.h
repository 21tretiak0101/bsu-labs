#include "NotepadService.h"
#include "../repository/FileNotepadRepository.h"

class FileNotepadService: public NotepadService {
private:
    FileNotepadRepository notepadRepository;

public:
    explicit FileNotepadService(FileNotepadRepository& bookRepository) {
        this->notepadRepository = bookRepository;
    }

public:
    void createNote(Note& note) override {
        notepadRepository.save(note);
    }

    void removeNote(int id) override {
        notepadRepository.remove(id);
    }

    Note getNote(int id) override {
        return notepadRepository.findOne(id);
    }

    vector<Note> getAllNotes() override {
        return notepadRepository.findAll();
    }

    bool exists(int id) override {
        return notepadRepository.existsById(id);
    }
};

