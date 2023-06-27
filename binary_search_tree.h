//
// Created by rrivas on 26/06/2023.
//

#ifndef PROG3_TEO2_20231_ARBOLES_BINARY_SEARCH_TREE_H
#define PROG3_TEO2_20231_ARBOLES_BINARY_SEARCH_TREE_H

#include <memory>
using namespace std;

template <typename KeyType, typename ValueType>
class binary_search_tree {
    struct node_t {
        pair<KeyType, ValueType> item{};
        shared_ptr<node_t> left;
        shared_ptr<node_t> right;
        weak_ptr<node_t> parent;
        node_t(pair<KeyType, ValueType> item): item(item) {}
    };
    shared_ptr<node_t> root;

public:
    binary_search_tree() = default;
    void insert(pair<KeyType, ValueType> item) {
        // Verificar si tiene root
        if (!root) {
            root = make_shared<node_t>(item);
            return;
        }
        // Creo el concurrente
        auto current = root;
        while (current) {
            if (item.first < current.item.first) {
                // Colocar a la izquierda
            }
            else {
                // Colocar a la derecha
                
            }
        }
    }
};

#endif //PROG3_TEO2_20231_ARBOLES_BINARY_SEARCH_TREE_H
