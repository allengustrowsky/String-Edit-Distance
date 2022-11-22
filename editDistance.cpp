#include <string>
#include <iostream>

using namespace std;

int main()
{

    // read strings from input
    string str_from;
    string str_to;
    std::getline(std::cin, str_from);
    while (str_from != "")
    {
        // have to fetch input strings at different times
        std::getline(std::cin, str_to);

        // fetch array dimensions
        int numRows = (int)str_from.length();
        int numCols = (int)str_to.length();

        int matrix[(numRows + 1)][(numCols + 1)];

        // initialize first row
        for (int i = 0; i < (numCols + 1); i++)
        {
            matrix[0][i] = i;
        }
        // initialize first column
        for (int i = 1; i < (numRows + 1); i++)
        {
            matrix[i][0] = i;
        }

        // calculate values in array
        for (int i = 1; i < (numRows + 1); i++) {
            // for each letter, compare to letters in column
            for (int j = 1; j < (numCols + 1); j++) {
                // compare letters
                if (str_from[i-1] == str_to[j-1]) {
                    // if letters match, use value of previous diagonal
                    matrix[i][j] = matrix[i-1][j-1];
                } else {
                    // TODO: fill in with unequal operation
                    matrix[i][j] = -1;
                }
            }
        }

        // DELETE ME, loops thru all array indices
        for (int i = 0; i < ((int)str_from.length() + 1); i++)
        {
            for (int j = 0; j < ((int)str_to.length() + 1); j++)
            {
                // matrix[i][j] = -1;
                // std::cout << "matrix [" << i << "][" << j <<"]: " << matrix[i][j] << "  |  ";
                std::cout << matrix[i][j] << "  ";
            }
            std::cout << endl;
        }

        // fetch first string for loop
        std::getline(std::cin, str_from);
    }
    std::cout << "str_from: " << str_from << "; str_to: " << str_to << endl;
}

// remove initialization of array indices to -1
// CURRENT: working on getneighbors() errors
// questions: handle upper/lowercase the same?