#include <vector>

class Node {
    private:
        vector<int> board;
        int depth;
        Node* blankLeft;
        Node* blankRight;
        Node* blankUp;
        Node* blankDown;
        Node* parentNode;
    public:
        Node(vector<int> slideBoard, int depth);
        vector<int> getBoard();
        int getDepth();
        Node* getBlankDown();
        Node* getBlankUp();
        Node* getBlankLeft();
        Node* getBlankRight();
        Node* getParentNode();
        void setBlankDown(Node* newDown);
        void setBlankUp(Node* newUp);
        void setBlankLeft(Node* newLeft);
        void setBlankRight(Node* newRight);
        void setParentNode(Node* parent);
        void setBoard();
};