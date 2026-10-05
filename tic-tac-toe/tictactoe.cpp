#include<iostream>
using namespace std;

void drawBoard(char board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j =0; j<3; j++){
            cout << " " << board[i][j];
            if (j<2) cout << " |";
        }
        cout<<endl;
    if (i<2) cout << "---|---|---" << endl;
    }
}

int checkWinner(char board[3][3]) {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1; // row match found
    }

    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1; // column match found
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0; // no winner yet
}

int main(){

    char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};
 
char player1_marker, player2_marker;

cout << "Player 1, choose your marker (X or O): ";
cin >> player1_marker;

if (player1_marker == 'X' || player1_marker == 'x') player2_marker = 'O';
else player2_marker = 'X';
 
cout << "Player 1 = " << player1_marker << endl;
cout << "Player 2 = " << player2_marker << endl;
cout << "Let's play!"<<endl;

for (int i = 0; i < 9; i++) {
char current_marker;
string current_player;

if (i % 2 == 0) {
    current_player = "Player 1";
    current_marker = player1_marker;
} else {
    current_player = "Player 2";
    current_marker = player2_marker;
    }

    int slot;
cout << current_player << ", enter slot (1-9): ";
cin >> slot;

int row = (slot - 1) / 3;
int col = (slot - 1) % 3;

board[row][col] = current_marker;
drawBoard(board);

if (checkWinner(board)) {
    cout << current_player << " wins! 🎉" << endl;
    break;
}

}
if (checkWinner(board) !=1) {
cout << "It's a draw! 😐" << endl;
}
// int slot;
// cout << "Player 1, Enter the slot number(1-9): ";
// cin >> slot;
// int row = (slot - 1) / 3;
// int col = (slot - 1) % 3;
// board[row][col] = player1_marker;
// drawBoard(board);

// cout << "Player 2, Enter the slot number(1-9): ";
// cin >> slot;
//  row = (slot - 1) / 3;
//  col = (slot - 1) % 3;
// board[row][col] = player2_marker;
// drawBoard(board);

    return 0;
}