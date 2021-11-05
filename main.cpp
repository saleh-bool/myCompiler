#include <iostream>
#include <sstream>
#include "automata.h"
#include <fstream>
std::ifstream infile("C:\\Users\\Administrator\\Documents\\myCompiler\\keywords.txt");

//master origin

void read_keywords(automata* automata) {
    std::string line;
    while (std::getline(infile, line))
    {
        automata->make(line);
    }
}

int main()
{
    automata* a = new automata();
    read_keywords(a);
    std::cout << a->search("double") << std::endl;
    std::cout << a->search("int") << std::endl;
    std::cout << a->search("primery") << std::endl;
    std::cout << a->search("auto") << std::endl;
    delete a;
}
