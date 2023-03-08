#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 80000

void InsertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    setlocale(LC_ALL, "Ukr");
    srand(time(NULL));
    int size;
    cout << "����i�� ����i� ������: ";
    cin >> size;
    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % (20 * 8);
    }
    /*cout << "����i������� �����: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }*/
    cout << endl;
    unsigned int start_time = clock(); // ���������� ���
    InsertionSort(arr, N);
    unsigned int end_time = clock(); // ������� ���
    unsigned int search_time = end_time - start_time; // ������� ���
    /*cout << "�i����������� �����: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }*/
    cout << "\n��� ���������� ������, �� ���������� � " << size << " �������i� ���������: " << search_time << " �i�i������";
    cout << endl;
    return 0;
}