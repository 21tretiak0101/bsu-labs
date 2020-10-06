#include <iostream>
#include <string>
#include <time.h>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>

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

    Note() {}

    Note(const string &title, const string &text, time_t date) : title(title), text(text), date(date) {}

    /**
    * definition of serialization members for cereal lib
    */
    template<class Archive>
    void serialize(Archive & ar)
    {
        ar(CEREAL_NVP(title), CEREAL_NVP(text), CEREAL_NVP(date));
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

    string getText() {
        return text;
    }
};