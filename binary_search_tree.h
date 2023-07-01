//
// Created by rrivas on 26/06/2023.
//

#ifndef PROG3_TEO2_20231_ARBOLES_BINARY_SEARCH_TREE_H
#define PROG3_TEO2_20231_ARBOLES_BINARY_SEARCH_TREE_H

#include <memory>
#include <functional>
#include <queue>
#include <stack>
#include <unordered_set>
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

    template<typename Callable>
    void _in_order(shared_ptr_t current, const Callable& fun) {
        // 1. Si árbol es vacío terminar
        if (!current) return;

        // 2. Ir al subárbol izquierda
        _in_order(current->left, fun);
        // 3. Obtener el nodo
        fun(current->item);
        // 4. Ir al subárbol derecho
        _in_order(current->right, fun);
    }

public:
    binary_search_tree() = default;

    void insert(const item_t& item) {
        // Verificar si tiene root
        if (!root) { // Si no hay root
            root = make_shared<node_t>(item, nullptr);
            return;
        }
        // Creo el concurrente
        auto current = root;
        while (current) {
            if (item.first < current->item.first) {
                // Colocar a la izquierda
                if (!current->left) { // Si no existe hijo de izquierda
                    current->left = make_shared<node_t>(item, current);
                    break;
                }
                else {
                    current = current->left;
                }
            }
            else {
                // Colocar a la derecha
                if (!current->right) { // Si no existe hijo de izquierda
                    current->right = make_shared<node_t>(item, current);
                    break;
                }
                else {
                    current = current->right;
                }
            }
        }
    }

    template<typename Callable>
    void bfs(const Callable& fun) {
        // Definir un queue
        queue<shared_ptr_t> q;
        // 1. Agregar (push) del nodo raíz al queue
        q.push(root);
        // 2. Mientras el queue no este vacía (empty)
        while (!q.empty()) {
            // 3. Obtener (front) el primer valor del queue
            auto current = q.front();
            fun(current->item);
            // 4. Retirar(pop) el primer valor del queue
            q.pop();
            // 5. Agregar (push) todos los nodos hijos de nodo extraído hacia el queue.
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    template<typename Callable>
    void dfs(const Callable& fun) {
        // Definir el queue y el unordered_set
        stack<shared_ptr_t> s;
        unordered_set<shared_ptr_t> no_available;
        auto is_available = [&no_available](auto node) {
            return no_available.find(node) == no_available.end(); };
        // 1. Agregar (push) el nodo raíz al stack
        s.push(root);
        // 2. Mientras stack no este vacío (empty)
        while (!s.empty()) {
            // 3. Obtener (top) nodo del stack y hacer no disponible
            auto current = s.top();
            if (is_available(current)) {
                fun(current->item);
            }
            no_available.insert(current);
            // 4. Si tiene hijos disponibles:
            //      Agregar (push) el primer nodo hijo disponible al stack.
            if (current->left && is_available(current->left)) {
                s.push(current->left);
            }
            else if (current->right && is_available(current->right)) {
                s.push(current->right);
            }
            // 5. Sino:
            else {
                //      Retirar (pop) nodo del stack
                s.pop();
            }
        }
    }

    template<class Callable>
    void in_order(const Callable& fun) {
        _in_order(root, fun);
    }

    bool is_balanced() {

    }
};

#endif //PROG3_TEO2_20231_ARBOLES_BINARY_SEARCH_TREE_H
