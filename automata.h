#ifndef AUTOMATA_H
#define AUTOMATA_H

#endif // AUTOMATA_H

#include "automata_node.h"

class automata {
    automata_node* nodes[300];
    int last_newd_node = 0;

public:
    automata_node* make_new_node() {
        nodes[last_newd_node] = new automata_node();
        nodes[last_newd_node]->set_final(0);
        nodes[last_newd_node]->set_destination(nodes[0]);
        last_newd_node++;
        return nodes[last_newd_node - 1];
    }

    automata() {
        make_new_node();
        make_new_node();
    }

    void make(std::string keywords[], int size) {
        for(int i = 0; i  < size; i++) {
            make(keywords[i]);
        }
    }

    void make(std::string keyword) {
        automata_node* corrent_node = nodes[1];
        for (int i = 0; i < keyword.size(); i++) {
            if(corrent_node->get_destination(keyword[i]) == nodes[0]) {
                automata_node* new_node = make_new_node();
                corrent_node->set_destination(new_node, keyword[i]);
                corrent_node = new_node;
            }
            else {
                corrent_node = corrent_node->get_destination(keyword[i]);
            }
            if (i == keyword.size() - 1) {
                corrent_node->set_final(1);
            }
        }
    }

    bool search(std::string word) {
        automata_node* corrent_node = nodes[1];
        for (int i =0; i < word.size(); i++) {
            corrent_node = corrent_node->get_destination(word[i]);
        }
        return corrent_node->is_final();
    }

    ~automata() {
        for(int i =0 ;i < last_newd_node; i++) {
            delete nodes[i];
        }
    }
};
