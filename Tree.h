#include "Node.h"

class Tree {
    private:
        Node* root;
    public:
        Tree(Node* startBoard);
        Node* getRoot();
};