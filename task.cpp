#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
bool draw = false;

void display_board() {
    system("cls"); // Use system("clear") for Unix-based systems
    cout << "\n\n  Welcome to Tic Tac Toe Game" << endl;
    cout << "\tPlayer1 [X] \n\tPlayer2 [O]\n\n";
    cout << "\t\t      |     |     \n";
    cout << "\t\t   " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "\t\t _____|_____|_____\n";
    cout << "\t\t      |     |     \n";
    cout << "\t\t   " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "\t\t______|_____|_____\n";
    cout << "\t\t      |     |     \n";
    cout << "\t\t   " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "\t\t      |     |     \n";
}

void player_turn() {
    int choice;
    if (turn == 'X')
        cout << "\nPlayer1 [X] turn:";
    else
        cout << "\nPlayer2 [O] turn:";
    cin >> choice;

    int row = -1, column = -1;
    switch (choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid choice! Try again.\n";
            player_turn();
            return;
    }

    if (row != -1 && column != -1 && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    } else {
        cout << "Box is already filled! Try again.\n";
        player_turn();
    }
}

bool gameover() {
    // Check for win condition
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return false;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return false;
    }
    // Check for draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true; // Game still ongoing
        }
    }
    draw = true;
    return false;
}

int main() {
    while (gameover()) {
        display_board();
        player_turn();
    }
    display_board();
    if (turn == 'X' && !draw)
        cout << "Player 2 [O] wins! Congratulations!\n";
    else if (turn == 'O' && !draw)
        cout << "Player 1 [X] wins! Congratulations!\n";
    else
        cout << "Game draw!\n";

    return 0;
}
