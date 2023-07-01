#include <iostream>
#include "binary_search_tree.h"
using namespace std;

int main() {
    binary_search_tree<string, int> bst;
    // Insercion de valores
    bst.insert({"M", 10});
    bst.insert({"F", 20});
    bst.insert({"P", 30});
    bst.insert({"A", 40});
    bst.insert({"T", 50});
    // Recorrido a lo largo
    bst.bfs([](auto& item) {
        cout << item.first << " " << item.second << endl;
    });
    cout << "-----\n";
    bst.dfs([](auto& item) {
        cout << item.first << " " << item.second << endl;
    });
    cout << "-----\n";
    // Recorrido a la profundidad (in order)
    bst.in_order([](auto& item) {
        cout << item.first << " " << item.second << endl;
    });
    return 0;
}
