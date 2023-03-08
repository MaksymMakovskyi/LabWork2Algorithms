#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 80

void ShakerSort(int mass[], int size)
{
    int left = 0, right = size - 1; // ліва і права межі масива, що сортується
    int flag = 1;  // прапорець наявності переміщень
    // Виконання циклу, доки ліва межа не закриється з правою
    // і доки в масиві наявні переміщення
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)  //рухаємось зліва направо
        {
            if (mass[i] > mass[i + 1]) // якщо наступний елемент менше теперішнього,
            {             // міняємо їх місцями
                double t = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = t;
                flag = 1;      // переміщення в цьому циклі були
            }
        }
        right--; // зміщуємо праву межу на попередній елемент
        for (int i = right; i > left; i--)  //рухаємось справа не ліво
        {
            if (mass[i - 1] > mass[i]) // якщо попередній елемент більше теперішнього,
            {            // міняємо їх місцями
                double t = mass[i];
                mass[i] = mass[i - 1];
                mass[i - 1] = t;
                flag = 1;    // переміщення в цьому циклі були
            }
        }
        left++; // зміщуємо ліву межу на наступний елемент
    }
}

int main()
{
    setlocale(LC_ALL, "Ukr");
    srand(time(NULL));
    int size;
    cout << "Введiть розмiр масиву: ";
    cin >> size;
    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % (20 * 8);
    }
    cout << "Оригiнальний масив: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    unsigned int start_time = clock(); // початковий час
    ShakerSort(arr, size);
    unsigned int end_time = clock(); // кінцевий час
    unsigned int search_time = end_time - start_time; // шуканий час
    cout << "Вiдсортований масив: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nЧас сортування масиву, що складається з " << size << " елементiв становить: " << search_time << " мiлiсекунд";
    cout << endl;
    return 0;
}