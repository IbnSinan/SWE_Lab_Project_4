/*
 * CSE 3206 | Lab 3 | Group 6 | Pattern: Command
 * File   : DeleteCommand.h
 * Author : Roll 137
 * Role   : Concrete command - deletes characters; undo puts them back
 */
#ifndef DELETE_COMMAND_H
#define DELETE_COMMAND_H

#include <stdexcept>
#include <string>
#include "Command.h"
#include "TextEditor.h"

class DeleteCommand : public Command {
private:
    TextEditor& editor;
    std::size_t count;
    std::string deletedText;   // remembered so that undo can restore it

public:
    DeleteCommand(TextEditor& editor, std::size_t count) : editor(editor), count(count) {
        if (count == 0) {
            throw std::invalid_argument("Delete count must be at least 1.");
        }
    }

    void execute() override { deletedText = editor.erase(count); }
    void undo() override { editor.write(deletedText); }
    std::string describe() const override { return "Delete " + std::to_string(count) + " char(s)"; }
};

#endif
