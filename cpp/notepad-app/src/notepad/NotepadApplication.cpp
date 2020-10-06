#include "command/CommandExecutor.h"

class NotepadApplication {
public:
    static void run() {
        FileNotepadRepository repository;
        repository.init();
        FileNotepadService service(repository);
        Operation operation;
        do {
            operation = ConsoleHelper::askOperation();
            CommandExecutor::execute(operation, service);
        } while (operation != EXIT);
        repository.destroy();
    }
};

int main() {
    NotepadApplication::run();
}