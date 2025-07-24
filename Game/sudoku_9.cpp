#include <iostream>
#include <vector>
using namespace std;

bool valid(vector<vector<char>> &board, char f, int r, int c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[r][i] == f)
            return false;
        if (board[i][c] == f)
            return false;

        if (board[3 * (r / 3) + (i / 3)][3 * (c / 3) + i % 3] == f)
        {
            return false;
        }
    }
    return true;
}
bool find(vector<vector<char>> &board)
{
    for (int p = 0; p < board.size(); p++)
    {

        for (int q = 0; q < board[p].size(); q++)
        {
            //  cout<<"Af";
            if (board[p][q] == '.')
            {
                for (char f = '1'; f <= '9'; f++)
                {
                    if (valid(board, f, p, q))
                    {
                        board[p][q] = f;
                        if (find(board))
                        {
                            return 1;
                        }
                        else
                        {
                            board[p][q] = '.';
                        }
                    }
                }
                return 0;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>> &board)
{

    find(board);
    // return board;
}
void printBoard(const vector<vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
            cout << cell << ' ';
        cout << '\n';
    }
}
int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);
    printBoard(board);
    return 0;
}