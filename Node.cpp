#include "Node.h"
#include <vector>

Node::Node(std::vector<int> slideBoard) {
    board = slideBoard;
}
Node* Node::getBlankDown() {
    return blankDown;
}
Node* Node::getBlankLeft() {
    return blankLeft;
}
Node* Node::getBlankRight() {
    return blankRight;
}
Node* Node::getBlankUp() {
    return blankUp;
}
Node* Node::getParentNode() {
    return parentNode;
}
vector<int> Node::getBoard() {
    return board;
}
void Node::setBlankDown(Node* newDown) {
    blankDown = newDown;
}
void Node::setBlankUp(Node* newUp) {
    blankUp = newUp;
}
void Node::setBlankRight(Node* newRight) {
    blankRight = newRight;
}
void Node::setBlankLeft(Node* newLeft) {
    blankLeft = newLeft;
}
void Node::setParentNode(Node* parent) {
    parentNode = parent;
}