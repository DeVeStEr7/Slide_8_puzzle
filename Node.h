#include <vector>

class Node {
    private:
        vector<int> board;
        int depth;
        double heuristic;
        Node* blankLeft;
        Node* blankRight;
        Node* blankUp;
        Node* blankDown;
        Node* parentNode;
    public:
        Node(vector<int> slideBoard, int nodeDepth, double nodeHeuristic);
        vector<int> getBoard();
        int getDepth();
        double getHeuristic();
        Node* getBlankDown();
        Node* getBlankUp();
        Node* getBlankLeft();
        Node* getBlankRight();
        Node* getParentNode();
        void setHeuristic(double heuristic);
        void setBlankDown(Node* newDown);
        void setBlankUp(Node* newUp);
        void setBlankLeft(Node* newLeft);
        void setBlankRight(Node* newRight);
        void setParentNode(Node* parent);
        void setBoard();
};