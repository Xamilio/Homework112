#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;


void shuffleArray(int arr[], int size) 
{
    for (int i = size - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}

int findPosition(int arr[], int size, int num) 
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num) return i;
    }
    return -1;
}

void sortDescending(int arr[], int start, int end)
{
    for (int i = start; i < end; i++) 
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (arr[i] < arr[j]) 
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void sortAscending(int arr[], int start, int end)
{
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++) 
        {
            if (arr[i] > arr[j]) 
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}


int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));
    const int SIZE = 20;
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) 
    {
        arr[i] = i + 1;
    }
    shuffleArray(arr, SIZE);
    cout << "Перемешанный массив: ";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int randomNum = rand() % 20 + 1;
    cout << "Случайное число: " << randomNum << endl;
    int pos = findPosition(arr, SIZE, randomNum);
    cout << "Позиция числа " << randomNum << " в массиве: " << pos << endl;
    if (pos > 0)
    {
        sortDescending(arr, 0, pos - 1);
    }
    if (pos < SIZE - 1)
    {
        sortAscending(arr, pos + 1, SIZE - 1);
    }
    cout << "Результат: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}