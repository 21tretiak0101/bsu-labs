#include <stdexcept>
#include <map>
#include <utility>
#include "CreateCommand.h"
#include "GetOneCommand.h"
#include "RemoveCommand.h"
#include "GetAllCommand.h"
#include "ExitCommand.h"
#include "NoneCommand.h"

using std::invalid_argument;
using std::map;

class CommandExecutor {
private:
    static map<Operation, Command*> commands;

public:
    static void execute(Operation operation, FileNotepadService& service) {
        commands[operation]->execute(service);
    }
};

map<Operation, Command*> CommandExecutor::commands = {
        {CREATE, new CreateCommand()},
        {GET_ONE, new GetOneCommand()},
        {REMOVE, new RemoveCommand()},
        {GET_ALL, new GetAllCommand()},
        {EXIT, new ExitCommand()},
        {NONE, new NoneCommand()}
};


