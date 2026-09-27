/*
 * CSE 3206 | Lab 3 | Group 6 | Pattern: Command
 * File   : Command.h
 * Author : Roll 137
 * Role   : Command interface - every action can execute and undo itself
 */
#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual std::string describe() const = 0;
};

#endif
