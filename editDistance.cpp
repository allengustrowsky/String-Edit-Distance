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

        int matrix[(int)str_from.length() + 1][(int)str_to.length() + 1];

        // initialize first row
        // thanks w3schools for showing how to get array length below
        for (int i = 0; i < (int)(sizeof(matrix[0]) / sizeof(int)); i++) {
            matrix[0][i] = i;
        }
        // initialize first column
        for (int i = 1; i < (int)(sizeof(matrix) / sizeof(matrix[0])); i++) {
            matrix[i][0] = i;
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