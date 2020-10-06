#include <vector>
#include <fstream>
#include <iostream>

using std::ifstream;
using std::ofstream;

using std::vector;

class Notepad {
private:
    static Notepad* instance;

    vector<Note> notes;
    /**
     * The path to the JSON file that stores notes
     */
    const string FILENAME_PATH = "src/app/notepad-app/resources/data.json";

    Notepad() {}
    Notepad( const Notepad& );
    void operator=(const Notepad &);

public:
    static Notepad* getInstance();

    void remove(int id) {
        notes.erase(notes.begin() + id);
    }

    void save(Note& note) {
        notes.push_back(note);
    }

    Note findOne(int id) {
        return notes.at(id);
    }

    vector<Note> findAll() {
        return notes;
    }

    /**
     * loading data from the file when the app starts
     */
    void deserialize() {
        ifstream inputStream(FILENAME_PATH);
        {
            cereal::JSONInputArchive inputArchive(inputStream);
            inputArchive(notes);
        }
        inputStream.close();
    }

    /**
     * definition of serialization members for cereal lib
     */
    template<class Archive>
    void serialize(Archive & ar)
    {
        ar(notes);
    }

    /**
     * saving data to the file when the app ends
     */
    void serialize() {
        ofstream outputStream(FILENAME_PATH);
        {
            cereal::JSONOutputArchive outputArchive(outputStream);
            outputArchive(CEREAL_NVP(notes));
        }
        outputStream.close();
    }
};

Notepad* Notepad::instance = 0;

Notepad* Notepad::getInstance() {
    if (!instance) {
        instance = new Notepad();
    }
    return instance;
}