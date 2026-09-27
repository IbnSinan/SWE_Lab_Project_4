CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

text_editor: main.cpp $(wildcard *.h)
	$(CXX) $(CXXFLAGS) -o $@ main.cpp

run: text_editor
	./text_editor

clean:
	rm -f text_editor text_editor.exe

.PHONY: run clean
