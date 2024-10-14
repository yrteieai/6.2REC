#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void PrintAsRow(int* a, const int size, int i)
{
    cout << a[i];
    if (i < size - 1) {
        cout << ", ";
        PrintAsRow(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

int SumOddIndices(int* a, const int size, int i)
{
    if (i < size)
        return a[i] + SumOddIndices(a, size, i + 2);
    else
        return 0;
}

bool ModifyArray(int* a, const int size, int i)
{
    bool isModified = false;
    if (i < size) {
        if (a[i] % 2 != 0) { 
            a[i] = 0;
            isModified = true;
        }
        return ModifyArray(a, size, i + 1) || isModified;
    }
    return isModified;
}

int main()
{
    srand((unsigned)time(NULL));
    const int n = 5;
    int a[n];
    int Low = -10;
    int High = 10;

    Create(a, n, Low, High, 0);

    cout << "Initial array: ";
    PrintAsRow(a, n, 0);

    int sumOdd = SumOddIndices(a, n, 1); 
    cout << "The sum of elements with odd indices: " << sumOdd << endl;

    if (ModifyArray(a, n, 0)) {
        cout << "Modified array: ";
        PrintAsRow(a, n, 0);
    }

    return 0;
}
