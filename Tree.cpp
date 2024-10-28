#include "Node.h"
#include "Tree.h"


Tree::Tree(Node* startBoard) {
    root = startBoard;
}

Node* Tree::getRoot() {
    return root;
}