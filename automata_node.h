#ifndef AUTOMATA_NODE_H
#define AUTOMATA_NODE_H

#endif // AUTOMATA_NODE_H

#include <string>

class automata_node {
private:
    bool final;
    automata_node* destinations[256];

public:
    void action(std::string output, int index) {};

    bool is_final() {
        return final;
    }

    void set_final(bool boolian) {
        final = boolian;
    }

    automata_node* get_destination(char address) {
        return destinations[address];
    }

    void set_destination(automata_node* destination) {
        for (int i = 0 ; i < 256 ; i++) {
            destinations[i] = destination;
        }
    }

    void set_destination(automata_node* destination, char address) {
        destinations[address] = destination;
    }
};
