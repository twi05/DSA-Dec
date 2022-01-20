#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<int>> &board)
{

    int n = board.size(), m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
// bool safe(vector<vector<int>> &board, int r,int  c){

// }
void ratInMaze(vector<vector<int>> &board, int r, int c, vector<vector<int>> &solution, int steps)
{
    int n = board.size(), m = board[0].size();
    if (r == n - 1 && c == m - 1)
    {
        solution[r][c] = 1;
        display(solution);
        cout << endl
             << endl;
        return;
    }  

    if (r < n - 1 && board[r + 1][c] == true)
    {
        board[r][c] == false;
        solution[r][c] = 1;
        ratInMaze(board, r + 1, c, solution, steps + 1);
    }
    if (c < m - 1 && board[r][c + 1] == true)
    {
        board[r][c] == false;
        solution[r][c] =1;
        ratInMaze(board, r, c + 1, solution, steps + 1);
    }

    board[r][c] = true;
    solution[r][c] = 0;


}
int main()
{
    int n = 6, m = 6;

    vector<vector<int>> board{{1, 0, 0, 0},
                              {1, 1, 0, 1},
                              {0, 1, 0, 0},
                              {1, 1, 1, 1}};
    vector<vector<int>> solution(n, vector<int>(m, 0));

    ratInMaze(board, 0, 0, solution, 1);

    return 0;
}