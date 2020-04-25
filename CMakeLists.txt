cmake_minimum_required(VERSION 3.15)
project(cpp_labs)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_labs
       #[[ src/app/functions/functions.h
        src/app/students/students.h]]
        src/app/notepad-app/src/entity/Notepad.h
        src/app/notepad-app/src/service/NotepadService.h
        src/app/notepad-app/src/NotepadApplication.cpp
        src/app/notepad-app/src/repository/NotepadRepository.h
        src/app/notepad-app/src/repository/FileNotepadRepository.h
        src/app/notepad-app/src/service/FileNotepadService.h
        src/app/notepad-app/src/command/CommandExecutor.h
        src/app/notepad-app/src/command/Command.h
        src/app/notepad-app/src/ConsoleHelper.h
        src/app/notepad-app/src/command/RemoveCommand.h
        src/app/notepad-app/src/command/GetOneCommand.h
        src/app/notepad-app/src/command/GetAllCommand.h
        src/app/notepad-app/src/command/CreateCommand.h
        src/app/notepad-app/src/entity/Note.h
        src/app/notepad-app/src/command/ExitCommand.h
        src/app/notepad-app/src/exception/EmptyVectorException.h
        src/app/notepad-app/src/exception/NoteExistsException.h
        src/app/notepad-app/src/exception/OperationExistsException.h
        src/app/notepad-app/src/command/Operation.h
        src/app/notepad-app/src/command/NoneCommand.h
        src/app/notepad-app/src/exception/NumberFormatException.h)
