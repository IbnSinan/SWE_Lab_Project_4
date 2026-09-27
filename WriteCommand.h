/*
 * CSE 3206 | Lab 3 | Group 6 | Pattern: Command
 * File   : WriteCommand.h
 * Author : Roll 137
 * Role   : Concrete command - appends text; undo removes it again
 */
#ifndef WRITE_COMMAND_H
#define WRITE_COMMAND_H

#include <stdexcept>
#include <string>
#include "Command.h"
#include "TextEditor.h"

class WriteCommand : public Command {
private:
    TextEditor& editor;
    std::string words;

public:
    WriteCommand(TextEditor& editor, const std::string& words) : editor(editor), words(words) {
        if (words.empty()) {
            throw std::invalid_argument("Cannot write empty text.");
        }
    }

    void execute() override { editor.write(words); }
    void undo() override { editor.erase(words.size()); }
    std::string describe() const override { return "Write \"" + words + "\""; }
};

#endif
