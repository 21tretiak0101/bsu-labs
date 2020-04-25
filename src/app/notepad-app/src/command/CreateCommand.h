#include "Command.h"
#include "../ConsoleHelper.h"

using std::to_string;
using std::string;

class CreateCommand: public Command {

private:
    /**
     * The message requesting a note title from the user
     */
    static string TITLE_MESSAGE;
    /**
     * The message requesting a note text from the user
     */
    static string TEXT_MESSAGE;
    /**
     * lines reading ends after this symbol
     */
    static string DELIMITER_CHARACTER;
    /**
     * hint to user about delimiter
     */
    static string HINT_MESSAGE;

public:
    void execute(FileNotepadService& service) override {
        ConsoleHelper::println(TITLE_MESSAGE + HINT_MESSAGE);
        string title = ConsoleHelper::readManyLines(DELIMITER_CHARACTER[0]);
        ConsoleHelper::println(TEXT_MESSAGE + HINT_MESSAGE);
        string text = ConsoleHelper::readManyLines(DELIMITER_CHARACTER[0]);
        Note note(title, text);
        service.createNote(note);
        ConsoleHelper::success();
    }
};

string CreateCommand::DELIMITER_CHARACTER = "~";

string CreateCommand::TITLE_MESSAGE = "Type the bookmark title:";

string CreateCommand::TEXT_MESSAGE = "Type the bookmark text: ";

string CreateCommand::HINT_MESSAGE = "\n(hint) ** type special symbol "
                                     "and press 'enter to continue: " + DELIMITER_CHARACTER;
