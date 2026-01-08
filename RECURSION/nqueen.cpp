class Solution {
public:
void solve(int col,vector<string> & board,vector<vector<string>>&ans,vector<int>&left,vector<int>& upper,vector<int>&lower,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(left[row]==0 && lower[row+col]==0&&upper[n-1+col-row]==0){
            board[row][col]='Q';
            left[row]=1;
            lower[row+col]=1;
            upper[n-1+col-row]=1;
            solve(col+1,board,ans,left,upper,lower,n);
            board[row][col]='.';
            left[row]=0;
            lower[row+col]=0;
            upper[n-1+col-row]=0;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
vector<vector<string>> ans;
vector<string> board(n);
string s(n,'.');
for(int i=0;i<n;i++){
    board[i]=s;
}
vector<int> left(n,0),upper(2*n-1,0),lower(2*n-1,0);
solve(0,board,ans,left,upper,lower,n);
return ans;
}
};
N-Queens Problem - Complete Notes
Problem Statement
Place N queens on an N×N chessboard such that no two queens attack each other. Queens can attack horizontally, vertically, and diagonally.
Key Insight
Instead of checking all positions for conflicts every time, we use three arrays to track which rows and diagonals are already occupied:

left[] - tracks occupied rows
upper[] - tracks occupied upper diagonals (/)
lower[] - tracks occupied lower diagonals ()

Code Breakdown
1. Main Function: solveNQueens(int n)
cppvector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;           // Store all solutions
    vector<string> board(n);              // Current board state
    string s(n,'.');                      // Create row template "....."
    
    // Initialize board with dots
    for(int i=0;i<n;i++){
        board[i]=s;                       // Each row = "....."
    }
    
    // Attack tracking arrays
    vector<int> left(n,0);                // Row occupancy
    vector<int> upper(2*n-1,0);           // Upper diagonal occupancy
    vector<int> lower(2*n-1,0);           // Lower diagonal occupancy
    
    solve(0,board,ans,left,upper,lower,n);
    return ans;
}
Purpose: Initialize the board and tracking arrays, then start backtracking from column 0.
2. Backtracking Function: solve()
cppvoid solve(int col, vector<string>& board, vector<vector<string>>&ans,
           vector<int>&left, vector<int>& upper, vector<int>&lower, int n)
Parameters:

col - current column we're trying to place a queen in
board - current state of the chessboard
ans - stores all valid solutions
left, upper, lower - attack tracking arrays
n - board size

3. Base Case
cppif(col == n){
    ans.push_back(board);    // Found complete solution
    return;
}
When we've successfully placed queens in all columns (0 to n-1), we've found a valid solution.
4. Try Each Row in Current Column
cppfor(int row = 0; row < n; row++){
    // Check if position (row, col) is safe
    if(left[row]==0 && lower[row+col]==0 && upper[n-1+col-row]==0){
        // Place queen and mark attacks
        // Recurse to next column  
        // Remove queen and unmark attacks (backtrack)
    }
}
Attack Tracking System
Row Attacks: left[row]

left[i] = 1 means row i has a queen
Simple: if placing at (row, col), mark left[row] = 1

Diagonal Attacks
Lower Diagonal \ : lower[row + col]
Positions on same lower diagonal have same (row + col) value:

(0,0): 0+0=0    (0,1): 0+1=1    (0,2): 0+2=2
(1,0): 1+0=1    (1,1): 1+1=2    (1,2): 1+2=3
(2,0): 2+0=2    (2,1): 2+1=3    (2,2): 2+2=4

Diagonal 0: (0,0)
Diagonal 1: (0,1), (1,0) 
Diagonal 2: (0,2), (1,1), (2,0)

Range: 0 to (2n-2), so array size = 2n-1

Upper Diagonal / : upper[n-1+col-row]
Positions on same upper diagonal have same (col-row) value:

(0,0): 0-0=0    (0,1): 1-0=1    (0,2): 2-0=2
(1,0): 0-1=-1   (1,1): 1-1=0    (1,2): 2-1=1
(2,0): 0-2=-2   (2,1): 1-2=-1   (2,2): 2-2=0

Since col-row can be negative, we add (n-1) to make it positive:
Index = (n-1) + (col-row)

Range: -(n-1) to +(n-1), so after adding (n-1): 0 to (2n-2)
Array size = 2n-1

Step-by-Step Execution
Place Queen
cppboard[row][col] = 'Q';           // Place queen on board
left[row] = 1;                   // Mark row as occupied
lower[row+col] = 1;              // Mark lower diagonal as occupied  
upper[n-1+col-row] = 1;          // Mark upper diagonal as occupied
Recurse
cppsolve(col+1, board, ans, left, upper, lower, n);
Try to place a queen in the next column.
Backtrack
cppboard[row][col] = '.';           // Remove queen
left[row] = 0;                   // Unmark row
lower[row+col] = 0;              // Unmark lower diagonal
upper[n-1+col-row] = 0;          // Unmark upper diagonal
If the recursive call doesn't lead to a solution, undo the changes and try the next row.
Bug Fix
Original code had a typo: uapper[n-1+col-row]=0; should be upper[n-1+col-row]=0;
Time Complexity

O(N!) - In the first column we have N choices, second column we have at most (N-1) choices, etc.
In practice, it's much better due to early pruning from the constraint checking.

Space Complexity

O(N²) for the board representation
O(N) for the recursion stack depth

Example Walkthrough (N=4)
Initial State:
Board:    left: [0,0,0,0]    lower: [0,0,0,0,0,0,0]    upper: [0,0,0,0,0,0,0]
. . . .
. . . .  
. . . .
. . . .
Try (0,0): ✓ Safe
Board:    left: [1,0,0,0]    lower: [1,0,0,0,0,0,0]    upper: [0,0,0,1,0,0,0]
Q . . .
. . . .
. . . .  
. . . .
Try (0,1), (1,1), (2,1): ✗ All blocked by queen at (0,0)
Try (3,1): ✓ Safe, and so on...
Key Points for Notes

Backtracking: Try all possibilities, undo when stuck
Optimization: Use arrays to track attacks instead of checking entire board
Diagonal formulas:

Lower diagonal: row + col
Upper diagonal: col - row (add n-1 for positive indexing)


Column-by-column: Place one queen per column, try all rows
Base case: When all columns filled, solution found
The genius of this approach is that instead of checking "Is there a queen that can attack position (row, col)?", we simply check three array indices. This reduces the time complexity of each placement check from O(N) to O(1).
Common Mistakes to Avoid:

Index bounds: Make sure diagonal arrays have size 2*n-1
Upper diagonal formula: Remember to add n-1 to handle negative indices
Backtracking: Always undo ALL changes when backtracking
Typos: Like uapper instead of upper in your original code

The algorithm systematically tries every possible position while using the constraint arrays to quickly eliminate invalid placements, making it much more efficient than a brute force approach.RetryClaude does not have the ability to run the code it generates yet.Claude can make mistakes. Please double-check responses. Sonnet 4