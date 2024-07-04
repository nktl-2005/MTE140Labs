#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// isSafe function (bool) to see if the position is safe to place a queen
bool isSafe(int row, int col, int n, vector<int>& queen) {
    for (int i =0; i < rows; i++) { 
        /*
        running a for loop for as many rows
        checks to see if the position (row, col) is unsafe 
        */
        int placedcol = queen[i]; //storing position (index) of placed queen

        //checking if there are any conflicts
        if (placecol == col || abs(i - row) == abs(placedcol - col)) {
            return false
        }
        else { //there are no conflicts
            return true
        }

    }

// Solution (bool?) returns if the solution is possible and solves it

bool solution(int n) {
    stack<pair<int,int>> stk; //declaring a stack to store pair of ints (row, col)
    vector<int> queen(n, -1); //delcaring vector for col position of queens, starting at -1 (before the board)
    int row =0; col=0; //initialzing row and col to be 0


    while (true) {
        /*
        By using an infinite loop, will run until solution is found, or not and will break out
        runs loop for as many cols as there is, places a queen in a position by checking if that
        position is safe using isSafe and then changing input values to search for a new position
        */

       while (col < n) {
        /*
        running col for as large as the chess board is
        */
            if (isSafe{row, col, n, queen}) { // only runs if the position (row,col) is safe to place a queen
                stk.push(make_pair(row,col)); //using stack to place the queen
                queen[row] = col; // keeping tracking of the queen
                row++; //updating row value
                col = 0; //starting next iterration from first col
                placed = true;
                break;
            }
            col++;
       } 

        // queen was placed at least once, checking if this is actually a solution to see if a queen
        // was placed in every row
       if (placed) {
            if (row == n) {
                return true;
            }
       }
        else { //using backtracking to try to move queens to find a new solution
            if (stk.empty()) {
                return false; // there is no solution
            }

            pair<int,int> top = stk.top(); //changing the position of the last placed queen by backtracking
            int prevrow = top.first; //declaring row position of last placed queen
            int prevcol = top.second; //declaring col position of last palced queen

            stk.pop(); //removing the last placed queen
            queen[prevrow] = -1; //resetting this value to no queen
            row = prevrow; // backtracking to previous row
            col = prevcol + 1 // moving to the next col
        }

    }

}

// PrintSol function (void) to print the solution using Solution function

main() {}