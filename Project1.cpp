#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
//#include "Node.h"
//#include "Tree.h"

void printBoard(vector<int> board) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << board.at((i*3)+j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
} 


bool correctBoard(vector<int> board) {
    return  board.at(0) == 1 && board.at(1) == 2 && board.at(2) == 3 &&
            board.at(3) == 4 && board.at(4) == 5 && board.at(5) == 6 &&
            board.at(6) == 7 && board.at(7) == 8 && board.at(8) == 0;
}

vector<int> moveBlankDown(vector<int> board, int zeroCoordinate) {
    vector<int> newBoard = board;
    swap(newBoard.at(zeroCoordinate), newBoard.at(zeroCoordinate+3));
    return newBoard;
}
vector<int> moveBlankUp(vector<int> board, int zeroCoordinate) {
    vector<int> newBoard = board;
    swap(newBoard.at(zeroCoordinate), newBoard.at(zeroCoordinate-3));
    return newBoard;
}
vector<int> moveBlankLeft(vector<int> board, int zeroCoordinate) {
    vector<int> newBoard = board;
    swap(newBoard.at(zeroCoordinate), newBoard.at(zeroCoordinate-1));
    return newBoard;
}
vector<int> moveBlankRight(vector<int> board, int zeroCoordinate) {
    vector<int> newBoard = board;
    swap(newBoard.at(zeroCoordinate), newBoard.at(zeroCoordinate+1));
    return newBoard;
}


bool notExplored(vector<vector<int>> exploredBoards, vector<int> currBoard) {
    bool seen;
    for(int i = 0; i < exploredBoards.size(); i++) {
        seen = true;
        for(int j = 0; j < 9; j++) {
            if(exploredBoards.at(i).at(j) != currBoard.at(j)) {
                seen = false;
            }
        }
        if(seen) {
            return false;
        }
    }
    return true;
}

bool valid(int coordinate) {
    return coordinate >= 0 && coordinate < 9;
}
bool sideValid(int coordinate) {
    return coordinate < 3;
}

int findZero(vector<int> board) {
    for(int i = 0; i < board.size(); i++) {
        if(board.at(i) == 0) {
            return i;
        }
    }
    return 0;
}
int incorrectTiles(vector<int> board) {
    int count = 0;
    for(int i = 0; i < board.size(); i++) {
        if(board.at(i) != ((i+1)%9)) {
            count++;
        }
    }
    return count;
}


int totDistance(vector<int> board) {
    int count = 0;
    int index = 0;
    int indexNumY = 0;
    int indexNumX = 0;
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board.size(); j++) {
            if(board.at(j) == i+1) {
                index = j;
                indexNumX = j%3;
                indexNumY = j/3;
            }
        }
        int currNumX = i%3;
        int currNumY = (i/3);
        
        count += (abs(indexNumX - currNumX) + abs(indexNumY - currNumY));
    }
    return count;
}

vector<int> UCS(vector<int> startBoard, int coordinate) {
    queue<vector<int>> possibleBoards;
    vector<vector<int>> exploredBoards;
    
    possibleBoards.push(startBoard);
    while(!possibleBoards.empty()) {
        vector<int> currBoard = possibleBoards.front();
        possibleBoards.pop();
        printBoard(currBoard);
        coordinate = findZero(currBoard);
        if(correctBoard(currBoard)) {
            std::cout << "good" << endl;
            return currBoard;
        }
        else {
            if(sideValid((coordinate%3)+1) && notExplored(exploredBoards, moveBlankRight(currBoard,coordinate))) {
                possibleBoards.push(moveBlankRight(currBoard,coordinate));
            }
            if(valid((coordinate%3)-1) && notExplored(exploredBoards, moveBlankLeft(currBoard,coordinate))) {
                possibleBoards.push(moveBlankLeft(currBoard,coordinate));
            }
            if(valid(coordinate+3) && notExplored(exploredBoards, moveBlankDown(currBoard,coordinate))) {
                possibleBoards.push(moveBlankDown(currBoard,coordinate));
            }
            if(valid(coordinate-3) && notExplored(exploredBoards, moveBlankUp(currBoard,coordinate))) {
                possibleBoards.push(moveBlankUp(currBoard,coordinate));
            }
        }
        exploredBoards.push_back(currBoard);
    }
    std::cout << "fail" << endl;
    return startBoard;
}

vector<int> missingTile(vector<int> startBoard, int coordinate) {
    multimap<int,vector<int>> possibleBoards;
    vector<vector<int>> exploredBoards;
    int numMissing = incorrectTiles(startBoard);
    possibleBoards.insert(std::pair<int,vector<int>>(numMissing,startBoard));
    while(!possibleBoards.empty()) {
        vector<int> currBoard = (*(possibleBoards.begin())).second;
        possibleBoards.erase(possibleBoards.begin());
        //printBoard(currBoard);
        coordinate = findZero(currBoard);
        if(correctBoard(currBoard)) {
            std::cout << "good" << endl;
            return currBoard;
        }
        else {
            if(sideValid((coordinate%3)+1) && notExplored(exploredBoards, moveBlankRight(currBoard,coordinate))) {
                numMissing = incorrectTiles(currBoard);
                possibleBoards.insert(std::pair<int,vector<int>>(numMissing,moveBlankRight(currBoard,coordinate)));
            }
            if(valid((coordinate%3)-1) && notExplored(exploredBoards, moveBlankLeft(currBoard,coordinate))) {
                numMissing = incorrectTiles(currBoard);
                possibleBoards.insert(std::pair<int,vector<int>>(numMissing,moveBlankLeft(currBoard,coordinate)));
            }
            if(valid(coordinate+3) && notExplored(exploredBoards, moveBlankDown(currBoard,coordinate))) {
                numMissing = incorrectTiles(currBoard);
                possibleBoards.insert(std::pair<int,vector<int>>(numMissing,moveBlankDown(currBoard,coordinate)));
            }
            if(valid(coordinate-3) && notExplored(exploredBoards, moveBlankUp(currBoard,coordinate))) {
                numMissing = incorrectTiles(currBoard);
                possibleBoards.insert(std::pair<int,vector<int>>(numMissing,moveBlankUp(currBoard,coordinate)));
            }
        }
        exploredBoards.push_back(currBoard);
    }
    std::cout << "fail" << endl;
    return startBoard;
}

vector<int> euclidean(vector<int> startBoard, int coordinate) {
    multimap<int,vector<int>> possibleBoards;
    vector<vector<int>> exploredBoards;
    int currBoardDistance = totDistance(startBoard);
    possibleBoards.insert(std::pair<int,vector<int>>(currBoardDistance,startBoard));
    while(!possibleBoards.empty()) {
        vector<int> currBoard = (*(possibleBoards.begin())).second;
        possibleBoards.erase(possibleBoards.begin());
        //printBoard(currBoard);
        coordinate = findZero(currBoard);
        if(correctBoard(currBoard)) {
            std::cout << "good" << endl;
            return currBoard;
        }
        else {
            if(sideValid((coordinate%3)+1) && notExplored(exploredBoards, moveBlankRight(currBoard,coordinate))) {
                currBoardDistance = totDistance(currBoard);
                possibleBoards.insert(std::pair<int,vector<int>>(currBoardDistance,moveBlankRight(currBoard,coordinate)));
            }
            if(valid((coordinate%3)-1) && notExplored(exploredBoards, moveBlankLeft(currBoard,coordinate))) {
                currBoardDistance = totDistance(currBoard);
                possibleBoards.insert(std::pair<int,vector<int>>(currBoardDistance,moveBlankLeft(currBoard,coordinate)));
            }
            if(valid(coordinate+3) && notExplored(exploredBoards, moveBlankDown(currBoard,coordinate))) {
                currBoardDistance = totDistance(currBoard);
                possibleBoards.insert(std::pair<int,vector<int>>(currBoardDistance,moveBlankDown(currBoard,coordinate)));
            }
            if(valid(coordinate-3) && notExplored(exploredBoards, moveBlankUp(currBoard,coordinate))) {
                currBoardDistance = totDistance(currBoard);
                possibleBoards.insert(std::pair<int,vector<int>>(currBoardDistance,moveBlankUp(currBoard,coordinate)));
            }
        }
        exploredBoards.push_back(currBoard);
    }
    std::cout << "fail" << endl;
    return startBoard;
}

int main() {
    std::cout << "Welcome to dalex017 8 puzzle solver." << std::endl;
    std::cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle" << std::endl;

    int input;
    vector<int> board;
    std::cin >> input;
    if(input == 1) {
        for(int i = 0; i < board.size(); i++) {
            board.at(i) = i+1 % 9;
        }
    }
    else if(input == 2) {
        std::string row;
        int first,second,third;
        std::cout << "Enter your puzzle, use a zero to represent the blank" << std::endl;
        std::cout << "Enter the first row, use space or tabs between numbers" << std::endl;
        std::cin >> first >> second >> third;
        board.push_back(first);
        board.push_back(second);
        board.push_back(third);
        std::cout << "Enter the second row, use space or tabs between numbers" << std::endl;
        std::cin >> first >> second >> third;
        board.push_back(first);
        board.push_back(second);
        board.push_back(third);
        std::cout << "Enter the third row, use space or tabs between numbers" << std::endl;
        std::cin >> first >> second >> third;
        board.push_back(first);
        board.push_back(second);
        board.push_back(third);
    }
    else {
        std::cout << "Invalid Number";
    }
    
    std::cout << "Enter your choice of algorithm" << std::endl;
    std::cout << "Uniform Cost Search" << std::endl;
    std::cout << "A* with the Misplaced Tile heuristic" << std::endl;
    std::cout << "A* with the Euclidean Distance heuristic" << std::endl;

    cin >> input;
    vector<int> solvedBoard;
    int coordinate = findZero(board);
    if(input == 1) {
        solvedBoard = UCS(board, coordinate);
        if(solvedBoard == board) {
            std::cout << "Impossible to solve" << endl;
        }
        //uniform cost search
    }
    else if(input == 2) {
        solvedBoard = missingTile(board, coordinate);
        if(solvedBoard == board) {
            std::cout << "Impossible to solve" << endl;
        }
        //A* with the Misplaced Tile heuristic
    }
    else if(input == 3) {
        solvedBoard = euclidean(board, coordinate);
        if(solvedBoard == board) {
            std::cout << "Impossible to solve" << endl;
        }
        //A* with the Euclidean distance heuristic
    }
    else {
        std::cout << "Not a valid input" << std::endl;
        return 0;
    }
    printBoard(solvedBoard);
}






// void createPossibleBoards(int currBoard[3][3], int xZero, int yZero) {
//     if(valid(xZero+1,yZero)) {
//         currBoard.setBlankRight(rightNode);
//     }
//     if(valid(xZero-1,yZero)) {
//         Node* leftNode = moveBlankLeft(currBoard.getBoard());
//         currBoard.setBlankLeft(leftNode);
//     }
//     if(valid(xZero,yZero+1)) {
//         Node* downNode = moveBlankDown(currBoard.getBoard());
//         currBoard.setBlankDown(downNode);
//     }
//     if(valid(xZero,yZero-1)) {
//         Node* upNode = moveBlankUp(currBoard.getBoard());
//         currBoard.setBlankUp(upNode);
//     }
// }

