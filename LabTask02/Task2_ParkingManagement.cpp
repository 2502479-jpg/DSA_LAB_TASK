#include <iostream>
using namespace std;

int main()
{
    const int ROWS = 4;
    const int COLS = 5;

    int parking[ROWS][COLS] = {
        {1, 0, 1, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1}
    };

    // Display parking layout
    cout << "Parking Layout (1 = Occupied, 0 = Empty):" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            cout << parking[i][j] << "\t";
        cout << endl;
    }

    // Count occupied and empty spaces
    int occupied = 0, empty = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (parking[i][j] == 1)
                occupied++;
            else
                empty++;

    cout << "\nTotal Occupied Spaces: " << occupied << endl;
    cout << "Total Empty Spaces: " << empty << endl;

    // Ask user for a specific space
    int row, col;
    cout << "\nEnter row (0-" << ROWS - 1 << ") and column (0-" << COLS - 1 << "): ";
    cin >> row >> col;

    if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
        if (parking[row][col] == 1)
            cout << "Space [" << row << "][" << col << "] is Occupied." << endl;
        else
            cout << "Space [" << row << "][" << col << "] is Available." << endl;
    }
    else
    {
        cout << "Invalid row or column." << endl;
    }

    cout << "\nTotal Parking Capacity: " << ROWS * COLS << endl;
    cout << "Current Occupancy: " << occupied << endl;

    return 0;
}
