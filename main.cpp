#include <iostream>
using namespace std;

// Function to display the game board
void displayBoard(char board[])
{
    cout << "\n";

    cout << "     |     |     \n";
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << "\n";

    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";

    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << "\n";

    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";

    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << "\n";

    cout << "     |     |     \n";
}

// Function to check win condition
int checkWin(char board[])
{
    // Rows
    if (board[1] == board[2] && board[2] == board[3])
        return 1;

    if (board[4] == board[5] && board[5] == board[6])
        return 1;

    if (board[7] == board[8] && board[8] == board[9])
        return 1;

    // Columns
    if (board[1] == board[4] && board[4] == board[7])
        return 1;

    if (board[2] == board[5] && board[5] == board[8])
        return 1;

    if (board[3] == board[6] && board[6] == board[9])
        return 1;

    // Diagonals
    if (board[1] == board[5] && board[5] == board[9])
        return 1;

    if (board[3] == board[5] && board[5] == board[7])
        return 1;

    // Draw condition
    if (board[1] != '1' && board[2] != '2' &&
        board[3] != '3' && board[4] != '4' &&
        board[5] != '5' && board[6] != '6' &&
        board[7] != '7' && board[8] != '8' &&
        board[9] != '9')
        return 0;

    // Continue game
    return -1;
}

int main()
{
    char choice;

    do
    {
        char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

        int player = 1;
        int position;
        int gameStatus = -1;

        char mark;

        cout << "\n========== TIC TAC TOE ==========\n";

        while (gameStatus == -1)
        {
            displayBoard(board);

            player = (player % 2 == 0) ? 2 : 1;

            cout << "\nPlayer " << player << ", enter a position (1-9): ";
            cin >> position;

            mark = (player == 1) ? 'X' : 'O';

            // Check valid move
            if (position >= 1 && position <= 9 && board[position] == char(position + '0'))
            {
                board[position] = mark;
            }
            else
            {
                cout << "\nInvalid Move! Try Again.\n";
                player--;
            }

            gameStatus = checkWin(board);

            player++;
        }

        displayBoard(board);

        if (gameStatus == 1)
        {
            cout << "\n🎉 Player " << --player << " Wins!\n";
        }
        else
        {
            cout << "\n🤝 Game Draw!\n";
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "\nThank You for Playing Tic Tac Toe!\n";

    return 0;
}
