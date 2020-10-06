class RemoveCommand : public Command {
public:
    void execute(FileNotepadService& service) override {
        ConsoleHelper::printIdMessage();
        int id = ConsoleHelper::readInt();

        if (service.exists(id)) {
            service.removeNote(id);
            ConsoleHelper::success();
        } else {
            ConsoleHelper::println(NoteExistsException().what());
        }
    }
};