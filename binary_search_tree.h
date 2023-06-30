//
// Created by rrivas on 26/06/2023.
//

#ifndef PROG3_TEO2_20231_ARBOLES_BINARY_SEARCH_TREE_H
#define PROG3_TEO2_20231_ARBOLES_BINARY_SEARCH_TREE_H

#include <memory>
#include <functional>
using namespace std;

template <
        typename KeyType,
        typename ValueType,
        typename Compare=less<KeyType>
        >
class binary_search_tree {
    // Seccion de tipos
    struct node_t; // Declaracion adelantada o forward
    using item_t = pair<KeyType, ValueType>;
    using shared_ptr_t = shared_ptr<node_t>;
    using weak_ptr_t = weak_ptr<node_t>;

    struct node_t {
        item_t item{};
        shared_ptr_t left;
        shared_ptr_t right;
        weak_ptr_t parent;
        node_t(const item_t& item, shared_ptr_t parent)
            : item(item), parent(parent) {}
    };

    shared_ptr_t root;

public:
    binary_search_tree() = default;

    void insert(item_t item) {
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
