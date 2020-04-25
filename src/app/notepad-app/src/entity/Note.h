#include <iostream>
#include <string>
#include <time.h>

using std::string;
using std::to_string;

class Note {
private:
    string title;
    string text;
    time_t date;

public:
    Note(const string &title, const string &text) {
        this->title = title;
        this->text = text;
        this->date = time(nullptr);
    }

    /**
     * @return date in string format
     */
    string getDate() {
        return ctime(&date);
    }

    string toString() {
        return "\n[Date]: " + getDate() +
               "[Title]: " + getTitle() + "\n" +  text + "\n";
    }

    /**
     * @return title without last '\n'
     */
    string getTitle()  {
        return title.erase(title.find_last_not_of('\n') + 1);
    }
};