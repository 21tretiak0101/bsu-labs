#include <vector>
#include <fstream>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::cout;

using std::vector;

class Notepad {
private:
    static Notepad* instance;

    vector<Note>* notes = new vector<Note>();
    /**
     * The path to the file that stores notes
     */
    const string FILENAME_PATH = "src/app/notepad-app/resources/data.txt";

    Notepad() {}

public:
    static Notepad* getInstance();

    void remove(int id) {
        notes->erase(notes->begin() + id);
    }

    void save(Note& note) {
        notes->push_back(note);
    }

    Note findOne(int id) {
        return notes->at(id);
    }

    vector<Note> findAll() {
        /**
         * TODO date sorting
         */
        return *notes;
    }

    void serialize() {
        /**
         * TODO
         */
        cout << "serialize";
    }

    void deserialize() {
        /**
        * TODO
        */
        cout << "deserialize";
    }
};

Notepad* Notepad::instance = 0;

Notepad* Notepad::getInstance() {
    if (!instance) {
        instance = new Notepad();
    }
    return instance;
}