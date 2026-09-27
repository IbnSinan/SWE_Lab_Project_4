/*
 * CSE 3206 | Lab 3 | Group 6 | Pattern: Command
 * File   : TextEditor.h
 * Author : Roll 136
 * Role   : Receiver - knows how to actually change the text
 */
#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include <string>

class TextEditor {
private:
    std::string text;

public:
    void write(const std::string& words) {
        text += words;
    }

    // Removes the last `count` characters and returns what was removed
    std::string erase(std::size_t count) {
        if (count > text.size()) {
            count = text.size();
        }
        std::string removed = text.substr(text.size() - count);
        text.erase(text.size() - count);
        return removed;
    }

    const std::string& getText() const { return text; }
};

#endif
