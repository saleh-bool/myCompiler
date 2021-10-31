#ifndef AUTOMATA_NODE_H
#define AUTOMATA_NODE_H

#endif // AUTOMATA_NODE_H

#include <string>

class automata_node {
private:
    bool final;
    automata_node* destinations[256];

public:
    void action(std::string output, int index) {
    }
};
