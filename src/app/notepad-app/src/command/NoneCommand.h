class NoneCommand: public Command {
public:
    void execute(FileNotepadService &service) override {
        ConsoleHelper::println(OperationExistsException().what());
    }
};