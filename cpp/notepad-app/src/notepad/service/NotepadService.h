#include <iostream>
#include <list>
#include <vector>
#include "../entity/Note.h"

using std::vector;

class NotepadService {

public:

    virtual void createNote(Note& note){};

    virtual void removeNote(int id) = 0;

    virtual Note getNote(int id) = 0;

    virtual vector<Note> getAllNotes() = 0;

    virtual bool exists(int id) = 0;

};
