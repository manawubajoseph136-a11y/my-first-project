// vent
/*
 * example_multiplication_table.cpp
 * 
 * Problem: Display a multiplication table (1 to 9) using nested for loops.
 * Uses iomanip to align columns.
 */

#include <iostream>
#include <iomanip>   // for setw()
using namespace std;

int main() {
    // Print the column headers
    cout << "    ";
    for (int col = 1; col <= 9; col++) {
        cout << setw(3) << col << " ";
    }
    cout << endl;

    // Print a separator line
    cout << "   -----------------------------------------" << endl;

    // Outer loop for rows
    for (int row = 1; row <= 9; row++) {
        cout << setw(2) << row << " | ";   // Row label

        // Inner loop for columns
        for (int col = 1; col <= 9; col++) {
            cout << setw(3) << (row * col) << " ";
        }
        cout << endl;
    }

    return 0;
}