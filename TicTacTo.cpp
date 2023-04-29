#include<iostream>
#include<vector>
using namespace std;

void display(string board[10]) {                    // Create Display board
    //system("cls");
    cout << "             +-------------+" << endl;
    cout << "             |             |"  << endl;
    cout << "             |    " + board[7] + '|' + board[8] + '|' + board[9] + "    |" << endl;
    cout << "             |    " + board[4] + '|' + board[5] + '|' + board[6] + "    |" << endl;
    cout << "             |    " + board[1] + '|' + board[2] + '|' + board[3] + "    |" << endl;
    cout << "             |             |" << endl;
    cout << "             +-------------+" << endl;
}
vector<char> player_input() {                       // Take input from user if they want to be '0' or 'X'
    string marker="A";
    bool x=true;
    while(x) {
        cout << "\nPlayer 1: Do you want to be X or O: ";
        cin >> marker;
        if(marker == "x") marker = "X";
        if(marker == "o") marker = "O";

        if (marker == "X" || marker == "O") {
            break;
        }
    }

    if (marker == "X")
        return {'X','O'};
    else
        return {'O','X'};
}
void place_marker(string board[10], char marker,int position) {     // fill the user value on board
    board[position] = marker;
}
bool win_check(string board[10],char mark) {        // winning goal
    string m(1, mark);
    return( (board[7] == m && board[8] == m && board[9] == m) ||  // across the top
            (board[4] == m && board[5] == m && board[6] == m) ||  // across the middle
            (board[1] == m && board[2] == m && board[3] == m) ||  // across the bottom
            (board[7] == m && board[4] == m && board[1] == m) ||  // down the left 
            (board[8] == m && board[5] == m && board[2] == m) ||  // down the middle
            (board[9] == m && board[6] == m && board[3] == m) ||  // down the right 
            (board[7] == m && board[5] == m && board[3] == m) ||  // 2 diagnols
            (board[9] == m && board[5] == m && board[1] == m) );
}
bool space_check(string board[10],int position) {   // If board is empty
    return (board[position] == " ");
}
int choose_first() {                                // Decide whose turn in first
    int a=rand();
    if (a%2 == 0) return 1;
    else return 2;
}
bool full_board_check(string board[10]) {           // If board is already full
    int empty_space = 0;
    for (int i=1; i<10; i++) {
        if (space_check(board,i)) empty_space++;
    }
    return (empty_space == 0);
}
int player_choice(string board[10]) {               // Take the input from user
    int position = 0;
    do {
        try {
            cout << "Please Enter position (1-9): ";
            cin >> position;
        } catch(...) {
            position = 0;
        }
    } while (position !=0 && !space_check(board,position));
    return position;
}
bool replay() {                                     // if user wants to play it again
    string b;
    cout << "You want to play again (yes , no): ";
    cin >> b;
    if (b[0] == 'Y' || b[0] == 'y') return true;
    else return false;
}

//Main Page


int main() {
    cout << "+------------------------------+" << endl;
    cout << "|         Tic Tac Toe          |" << endl;
    cout << "+------------------------------+" << endl;
    cout << " Positions on board" << endl;
    cout << "                  7|8|9" << endl;
    cout << "                  4|5|6" << endl;
    cout << "                  1|2|3" << endl;
    while (true) {
        string theBoard[10] = {" "," "," "," "," "," "," "," "," "," "};
        int position =0;
        vector<char> arr = player_input();
        char player1_marker = arr[0], player2_marker = arr[1];
        
        int turn = choose_first();
        bool game_on = true;
        //cout << player1_marker << "\n" << player2_marker << "\n" << turn << endl;
        while (game_on) {
            //system("cls");
            if (turn == 1) {
                display(theBoard);
                cout << "Player 1 turn [ " << player1_marker << " ]" << endl;
                position = player_choice(theBoard);
                place_marker(theBoard,player1_marker,position);
                
                if (win_check(theBoard,player1_marker)) {
                    display(theBoard);
                    cout << "Congratulation! \nPlayer 1 have won the game" << endl;
                    game_on = false;
                } else {
                    if (full_board_check(theBoard)) {
                        display(theBoard);
                        cout << "the game is a draw!!" << endl;
                        game_on = false;
                    } else turn = 2;
                }
            } else {
                display(theBoard);
                cout << "Player 2 turn [ " << player2_marker << " ]" << endl;
                position = player_choice(theBoard);
                place_marker(theBoard,player2_marker,position);
                
                if (win_check(theBoard,player2_marker)) {
                    display(theBoard);
                    cout << "Congratulation! \nPlayer 2 have won the game" << endl;
                    game_on = false;
                } else
                    if (full_board_check(theBoard)) {
                        display(theBoard);
                        cout << "the game is a draw!!" << endl;
                        game_on = false;
                    } else turn = 1;
            }
        }
        if (!replay()) break;
    }
    return 0;
}
