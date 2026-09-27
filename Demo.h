/*
 * CSE 3206 | Lab 3 | Group 6 | Pattern: Command
 * File   : Demo.h
 * Author : Roll 136
 * Role   : Client (part 1) - automatic demo of execute, undo and redo
 */
#ifndef DEMO_H
#define DEMO_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include "TextEditor.h"
#include "WriteCommand.h"
#include "DeleteCommand.h"
#include "EditorInvoker.h"

inline void show(const TextEditor& editor) {
    std::cout << "   Text     : \"" << editor.getText() << "\"\n";
}

inline void runDemo() {
    TextEditor editor;
    EditorInvoker invoker;

    std::cout << "\n--- Automatic demo ---\n";
    invoker.executeCommand(std::make_unique<WriteCommand>(editor, "Hello"));
    show(editor);
    invoker.executeCommand(std::make_unique<WriteCommand>(editor, " RUET"));
    show(editor);
    invoker.executeCommand(std::make_unique<DeleteCommand>(editor, 4));
    show(editor);

    std::cout << "\n[Undo]\n";
    invoker.undo();
    show(editor);
    std::cout << "[Undo]\n";
    invoker.undo();
    show(editor);
    std::cout << "[Redo]\n";
    invoker.redo();
    show(editor);

    std::cout << "\n[New command clears redo history]\n";
    invoker.executeCommand(std::make_unique<WriteCommand>(editor, "!"));
    show(editor);
    std::cout << "[Redo]\n";
    invoker.redo();

    std::cout << "\n[Invalid command]\n";
    try {
        invoker.executeCommand(std::make_unique<DeleteCommand>(editor, 0));
    } catch (const std::invalid_argument& e) {
        std::cout << "   [ERROR] " << e.what() << "\n";
    }
}

#endif
