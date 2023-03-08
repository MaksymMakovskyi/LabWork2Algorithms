#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 80000

void BubbleSort(int arr[]) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    BubbleSort(arr);
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