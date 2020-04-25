class ExitCommand: public Command {
public:
    void execute(FileNotepadService& service) override {
        ConsoleHelper::println("~~~Bye!~~~");
    }
};