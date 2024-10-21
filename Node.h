

class Node {
    private:
        int board[3][3];
        Node* blankLeft;
        Node* blankRight;
        Node* blankUp;
        Node* blankDown;
    public:
        Node();
        Node* getBlankDown();
        Node* getBlankUp();
        Node* getBlankLeft();
        Node* getBlankRight();
        void setBlankDown();
        void setBlankUp();
        void setBlankLeft();
        void setBlankRight();
}