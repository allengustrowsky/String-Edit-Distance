#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// edit characters
string insertChar = "+";
string deleteChar = "-";
string replaceChar = "/";
string keepChar = "^";


void test() {
    // string a, b, c = "a", "b", "c";
    // std::cout << "a: " << a << "; b: " << b << "; c: " << c;
//     string a = "#";
//     string b = "$";
//     string d = a + b;
//     std::cout << d << endl;
}

int main()
{
    // test();
    // read strings from input
    string str_from;
    string str_to;
    string editStr = "";
    int *neighbors = nullptr;
    int num_edits = 0;
    int diag_back, left, top;
    // string deleteChar = "^";
    std::getline(std::cin, str_from);
    while (str_from != "")
    {
        // have to fetch input strings at different times
        std::getline(std::cin, str_to);

        // fetch array dimensions
        int numRows = (int)str_from.length() + 1;
        int numCols = (int)str_to.length() + 1;
        std::cout << "numRows: " << numRows << "; numCols: " << numCols << endl;

        int matrix[numRows][numCols];

        // initialize first row
        for (int i = 0; i < numCols; i++)
        {
            matrix[0][i] = i;
        }
        // initialize first column
        for (int i = 1; i < (numRows); i++)
        {
            matrix[i][0] = i;
        }

        // calculate values in array
        for (int i = 1; i < (numRows); i++) {
            // for each letter, compare to letters in column
            for (int j = 1; j < (numCols); j++) {
                // compare letters
                if (str_from[i-1] == str_to[j-1]) {
                    // if letters match, use value of previous diagonal
                    matrix[i][j] = matrix[i-1][j-1];
                } else {
                    // if they don't match, choose smallest of neighbors + 1
                    diag_back = matrix[i-1][j-1];
                    left = matrix[i][j-1];
                    top = matrix[i-1][j];
                    
                    // neighbors = new int[3] {
                    //     matrix[i-1][j-1], // back diagonal
                    //     matrix[i][j-1], // left
                    //     matrix[i-1][j], // above
                    // };
                
                    // delete neighbors;
                    matrix[i][j] = min(diag_back, min(left, top)) + 1;
                    // std::cout << "[" << i << "][" << j << "]  ";
                }
            }
            // std::cout << endl;
        }

        // DELETE ME, loops thru all array indices
        bool f = true;
        bool f2 = true;
        for (int i = 0; i < numRows; i++)
        {
            // pritn first row
            if (f) {
                std::cout << "     ";
                for (char i : str_to) {
                    std::cout << i << "  ";
                }
                std::cout << endl;
                f = false;
            }

            // print first letter in each row
            if (i > 0) {
                std::cout << str_from[i-1] << " ";
            } else {
                std::cout << "  ";
            }
            
            for (int j = 0; j < numCols; j++)
            {
                // matrix[i][j] = -1;
                // std::cout << "matrix [" << i << "][" << j <<"]: " << matrix[i][j] << "  |  ";
                std::cout << matrix[i][j];
                if (matrix[i][j] < 10) {
                    std::cout << "  ";
                } else {
                    std::cout << " ";
                }
            }
            
            std::cout << endl;
        }

        // backtrace to calculate edits
        bool keepGoing = true;
        
        // index back by one to match index of last element
        int row = numRows - 1;
        int col = numCols - 1;
        std::cout << "numRows: " << numRows << " row: " << row << endl;
        std::cout << "numCols: " << numCols << " col: " << col << endl;
        while ((row > 0) && (col > 0)) {
            // if match, go diagonal back
            if (str_from[row-1] == str_to[col-1]) {
                editStr = keepChar + editStr;
                std::cout << keepChar << " curr: " << matrix[row][col] << "[" << row << "][" << col << "]" << endl;
                row--, col--;
            } else { 
                // otherwise determine smallest of 3 sidevals and 
                // needed edit type
                diag_back = matrix[row-1][col-1];
                left = matrix[row][col-1];
                top = matrix[row-1][col];
                int smallest = min(diag_back, min(left, top));
                if (diag_back == smallest) {
                    editStr = replaceChar + str_to[col-1] + editStr;
                    std::cout << replaceChar << " " << smallest << " diag" << "; curr: " << matrix[row][col] << "[" << row << "][" << col << "]" << endl; 
                    row--, col--; 
                } // replace
                else if (left == smallest) { 
                    editStr = insertChar + str_to[col-1] + editStr;
                    std::cout << insertChar << " " << smallest << " left" << "; curr: " << matrix[row][col] << "[" << row << "][" << col << "]" << endl;
                    col--; 
                } // insert
                else { 
                    editStr = deleteChar + editStr;
                    std::cout << deleteChar << " " << smallest << " top" << "; curr: " << matrix[row][col] << "[" << row << "][" << col << "]" << endl;
                    row--; 
                } // delete
                // std::cout << "s: " << smallest << endl;
                num_edits++;
            }


                // increment edit count

        }

        // print final results
        std::cout << num_edits << ":  " << editStr << endl;

        editStr = "";
        num_edits = 0;
        // fetch first string for loop
        std::getline(std::cin, str_from);
    }
}

// remove initialization of array indices to -1
// CURRENT: reverse-traversal, make edit string
// replce numRows with numRows + 1 so don't have to manually add to it every time 1.
    // will have to adjust row-2 and col-2 to row-1 and col-1 in backtracing block
// put should-be global vars outside of main()?
// change snake case to camel case
// questions: handle upper/lowercase the same?