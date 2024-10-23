// Lab_7_2_2.cpp
// <прізвище, ім’я автора>
// Лабораторна робота № 7.2.2)
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 0

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo) {
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateMatrix(int** a, const int K, const int N, const int Low, const int High, int rowNo) {
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < K - 1)
        CreateMatrix(a, K, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo) {
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintMatrix(int** a, const int K, const int N, int rowNo) {
    PrintRow(a, rowNo, N, 0);
    if (rowNo < K - 1)
        PrintMatrix(a, K, N, rowNo + 1);
}

void SwapMinMaxInOddRows(int** a, int K, int N, int rowIndex) {
    if (rowIndex < K) {
       
        if (rowIndex % 2 == 1) {
            int minIndex = 0;
            int maxIndex = 0;

            for (int j = 1; j < N; j++) {
                if (a[rowIndex][j] < a[rowIndex][minIndex]) {
                    minIndex = j;
                }
                if (a[rowIndex][j] > a[rowIndex][maxIndex]) {
                    maxIndex = j;
                }
            }
            swap(a[rowIndex][minIndex], a[rowIndex][maxIndex]);
        }
        SwapMinMaxInOddRows(a, K, N, rowIndex + 1);
    }
}

int main() {
    srand((unsigned)time(NULL));
    int K, N;
    cout << "k = "; cin >> K; 
    cout << "n = "; cin >> N; 
    cout << endl;

    int** a = new int* [K];
    for (int i = 0; i < K; i++)
        a[i] = new int[N];

    int Low = 1, High = 100;
    CreateMatrix(a, K, N, Low, High, 0);
    PrintMatrix(a, K, N, 0);
    SwapMinMaxInOddRows(a, K, N, 0); 
    cout << "Modified:\n";
    PrintMatrix(a, K, N, 0);

    for (int i = 0; i < K; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
