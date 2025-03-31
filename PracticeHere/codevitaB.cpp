#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// Function to check if position is reachable with given dice rolls and board configuration
bool isReachable(int target, const vector<int>& diceRolls, const map<int, int>& board) {
    int currentPos = 1; // Starting position
    
    for(int roll : diceRolls) {
        currentPos += roll;
        
        // If position has a snake or ladder, move accordingly
        auto it = board.find(currentPos);
        if(it != board.end()) {
            currentPos = it->second;
        }
    }
    
    return currentPos == target;
}

string identifyFaultyCell(const vector<pair<int, int>>& snakesAndLadders, 
                         const vector<int>& diceRolls, 
                         int targetPosition) {
    // Create original board configuration
    map<int, int> board;
    for(const auto& transition : snakesAndLadders) {
        board[transition.first] = transition.second;
    }
    
    // Check if target position has a snake or ladder
    if(board.find(targetPosition) != board.end()) {
        return "Not reachable";
    }
    
    // Check if position is reachable without any switches
    if(isReachable(targetPosition, diceRolls, board)) {
        return "Not affected";
    }
    
    // Try switching each snake/ladder
    for(const auto& transition : snakesAndLadders) {
        int start = transition.first;
        int end = transition.second;
        
        // Create new board configurations for both possible switches
        map<int, int> boardSnakeToLadder = board;
        map<int, int> boardLadderToSnake = board;
        
        // Try converting snake to ladder (if it's a snake)
        if(end < start) {
            boardSnakeToLadder.erase(start);
            boardSnakeToLadder[end] = start;
            if(isReachable(targetPosition, diceRolls, boardSnakeToLadder)) {
                return "Ladder " + to_string(end) + " " + to_string(start);
            }
        }
        
        // Try converting ladder to snake (if it's a ladder)
        if(end > start) {
            boardLadderToSnake.erase(start);
            boardLadderToSnake[end] = start;
            if(isReachable(targetPosition, diceRolls, boardLadderToSnake)) {
                return "Snake " + to_string(end) + " " + to_string(start);
            }
        }
    }
    
    return "Not reachable";
}

int main() {
    int n;
    cout << "The number of snakes and ladders on the board: ";
    cin >> n;

    cout << "\nEnter the snakes and ladders as two space-separated values (start end):\n";
    vector<pair<int, int>> snakesAndLadders(n);
    for (int i = 0; i < n; ++i) {
        cin >> snakesAndLadders[i].first >> snakesAndLadders[i].second;
    }

    cout << "\nEnter the dice rolls separated by space: ";
    vector<int> diceRolls;
    int roll;
    while (cin >> roll) {
        diceRolls.push_back(roll);
        if (cin.peek() == '\n') break;  // Stop input when newline is encountered
    }

    cout << "\nEnter the target position: ";
    int targetPosition;
    cin >> targetPosition;

    // Output the result
    cout << "Output: " << identifyFaultyCell(snakesAndLadders, diceRolls, targetPosition) << endl;

    return 0;
}