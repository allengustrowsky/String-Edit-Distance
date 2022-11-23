#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// edit characters
string insertChar = "+";
string deleteChar = "-";
string replaceChar = "/";
string keepChar = "^";

int main()
{
    // read strings from input
    string strFrom;
    string strTo;
    string editStr = "";
    int numEdits = 0;
    int diagBack, left, top;
    std::getline(std::cin, strFrom);

    // main loop
    while (strFrom != "") {
        // have to fetch input strings at different times
        std::getline(std::cin, strTo);

        // fetch array dimensions
        int numRows = (int)strFrom.length() + 1;
        int numCols = (int)strTo.length() + 1;

        int matrix[numRows][numCols];

        // initialize first row
        for (int i = 0; i < numCols; i++) {
            matrix[0][i] = i;
        }
        // initialize first column
        for (int i = 1; i < (numRows); i++) {
            matrix[i][0] = i;
        }

        // calculate values in matrix
        for (int i = 1; i < (numRows); i++) {
            // for each letter, compare to letters in column
            for (int j = 1; j < (numCols); j++) {
                // compare letters
                if (strFrom[i-1] == strTo[j-1]) {
                    // if letters match, use value of previous diagonal
                    matrix[i][j] = matrix[i-1][j-1];
                } else {
                    // if they don't match, choose smallest of neighbors + 1
                    diagBack = matrix[i-1][j-1];
                    left = matrix[i][j-1];
                    top = matrix[i-1][j];
                    
                    matrix[i][j] = min(diagBack, min(left, top)) + 1;
                }
            }
        }

        // backtrace to calculate edits        
        // index back by one to match index of last element
        int row = numRows - 1;
        int col = numCols - 1;
        while ((row > 0) && (col > 0)) {
            // if match, go diagonal back
            if (strFrom[row-1] == strTo[col-1]) {
                editStr = keepChar + editStr;
                row--, col--;
            } else { 
                // otherwise determine smallest of 3 sidevals and 
                // needed edit type
                diagBack = matrix[row-1][col-1];
                left = matrix[row][col-1];
                top = matrix[row-1][col];
                int smallest = min(diagBack, min(left, top));
                if (diagBack == smallest) { // replace
                    editStr = replaceChar + strTo[col-1] + editStr;
                    row--, col--; 
                }
                else if (left == smallest) { // insert
                    editStr = insertChar + strTo[col-1] + editStr;
                    col--; 
                }
                else { // delete
                    editStr = deleteChar + editStr;
                    row--; 
                }
                numEdits++;
            }
        }

        // print final results
        std::cout << numEdits << ":  " << editStr << endl;

        editStr = "";
        numEdits = 0;
        // fetch first string for loop condition
        std::getline(std::cin, strFrom);
    }
}
