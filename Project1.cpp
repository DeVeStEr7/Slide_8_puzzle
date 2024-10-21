#include <iostream>
#include <string>
#include <queue>
#include "Node.h"
#include "Tree.h"

void printBoard(int board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
} 



int main() {
    std::cout << "Welcome to dalex017 8 puzzle solver." << std::endl;
    std::cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle" << std::endl;

    int input;
    int board[3][3];
    std::cin >> input;
    if(input == 1) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                board[i][j] = (j+1)+(i*3) % 9;
            }
        }
    }
    else if(input == 2) {
        std::string row;
        int first,second,third;
        std::cout << "Enter your puzzle, use a zero to represent the blank" << std::endl;
        std::cout << "Enter the first row, use space or tabs between numbers" << std::endl;
        std::cin >> first >> second >> third;
        board[0][0] = first;
        board[0][1] = second;
        board[0][2] = third;
        std::cout << "Enter the second row, use space or tabs between numbers" << std::endl;
        std::cin >> first >> second >> third;
        board[1][0] = first;
        board[1][1] = second;
        board[1][2] = third;
        std::cout << "Enter the third row, use space or tabs between numbers" << std::endl;
        std::cin >> first >> second >> third;
        board[2][0] = first;
        board[2][1] = second;
        board[2][2] = third;
    }
    else {
        std::cout << "Invalid Number";
    }
    
    std::cout << "Enter your choice of algorithm" << std::endl;
    std::cout << "Uniform Cost Search" << std::endl;
    std::cout << "A* with the Misplaced Tile heuristic" << std::endl;
    std::cout << "A* with the Euclidean distance heuristic" << std::endl;

    cin >> input;
    if(input == 1) {
        //uniform cost search
    }
    else if(input == 2) {
        //A* with the Misplaced Tile heuristic
    }
    else if(input == 3) {
        //A* with the Euclidean distance heuristic
    }
    else {
        std::cout << "Not a valid input" << std::endl;
        return 0;
    }
    printBoard(board);
}

void UCS(int board[3][3], ) {
    queue<int[3][3]> possibleBoards;
    
    possibleBoards.
    while()
}

bool valid(int xPosBlank, int yPosBlank) {
    return (xPosBlank >= 0 && xPosBlank < 3) || (yPosBlank >= 0 && yPosBlank < 3);
}

void moveBlankDown(int board[3][3],int xPosBlank,int yPosBlank) {
    int tempNum = board[xPosBlank+1][yPosBlank];
    board[xPosBlank][yPosBlank] = tempNum;
    board[xPosBlank+1][yPosBlank] = 0;
}
void moveBlankUp(int board[3][3],int xPosBlank,int yPosBlank) {
    int tempNum = board[xPosBlank-1][yPosBlank];
    board[xPosBlank][yPosBlank] = tempNum;
    board[xPosBlank-1][yPosBlank] = 0;
}
void moveBlankLeft(int board[3][3],int xPosBlank,int yPosBlank) {
    int tempNum = board[xPosBlank][yPosBlank-1];
    board[xPosBlank][yPosBlank] = tempNum;
    board[xPosBlank][yPosBlank-1] = 0;
}
void moveBlankRight(int board[3][3],int xPosBlank,int yPosBlank) {
    int tempNum = board[xPosBlank][yPosBlank+1];
    board[xPosBlank][yPosBlank] = tempNum;
    board[xPosBlank][yPosBlank+1] = 0;
}