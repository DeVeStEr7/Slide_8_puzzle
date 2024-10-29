#include "Node.h"

class Tree {
    private:
        Node* root;
        int height;
    public:
        Tree(Node* startBoard);
        Node* getRoot();
};