#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

void create(int* arr, int SIZE, int MIN, int MAX, int i)
{
    if (i < SIZE)
    {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
        create(arr, SIZE, MIN, MAX, ++i);
    }
}

void print(int* arr, int SIZE, int i)
{
    if (i < SIZE)
    {
        cout << arr[i] << ' ';
        print(arr, SIZE, ++i);
    }
}

int calculateSumOfSquaresRecursive(int arr[], int SIZE, int index = 0) {
    if (index == SIZE) {
        return 0; 
    }
    else {
        int square = arr[index] * arr[index];
        return square + calculateSumOfSquaresRecursive(arr, SIZE, index + 1);
    }
}



void sort(int* arr, const int SIZE, int i)
{
    int min = arr[i];
    int imin = i;
    for (int j = i + 1; j < SIZE; j++)
        if (min < arr[j])
        {
            min = arr[j];
            imin = j;
        }
    arr[imin] = arr[i];
    arr[i] = min;

    if (i < SIZE - 2)
        sort(arr, SIZE, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double MIN, MAX;
    int SIZE;

    cout << "¬вед≥ть розм≥р масиву (SIZE): "; cin >> SIZE;
    cout << "¬вед≥ть д≥апазон елемент≥в масиву (MIN): "; cin >> MIN;
    cout << "¬вед≥ть д≥апазон елемент≥в масиву (MAX): "; cin >> MAX;
    cout << endl;

    int* arr = new int[SIZE];

    create(arr, SIZE, MIN, MAX, 0);

    print(arr, SIZE, 0);
    cout << endl;
    cout << "—ума квадрат≥в = " << calculateSumOfSquaresRecursive(arr, SIZE, 0) << endl;
    sort(arr, SIZE, 0);
    print(arr, SIZE, 0);

    delete[] arr;

    return 0;
}