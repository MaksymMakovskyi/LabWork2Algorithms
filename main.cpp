#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 80

void ShakerSort(int mass[], int size)
{
    int left = 0, right = size - 1; // ��� � ����� ��� ������, �� ���������
    int flag = 1;  // ��������� �������� ���������
    // ��������� �����, ���� ��� ���� �� ��������� � ������
    // � ���� � ����� ����� ����������
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)  //�������� ���� �������
        {
            if (mass[i] > mass[i + 1]) // ���� ��������� ������� ����� �����������,
            {             // ������ �� ������
                double t = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = t;
                flag = 1;      // ���������� � ����� ���� ����
            }
        }
        right--; // ������ ����� ���� �� ��������� �������
        for (int i = right; i > left; i--)  //�������� ������ �� ���
        {
            if (mass[i - 1] > mass[i]) // ���� ��������� ������� ����� �����������,
            {            // ������ �� ������
                double t = mass[i];
                mass[i] = mass[i - 1];
                mass[i - 1] = t;
                flag = 1;    // ���������� � ����� ���� ����
            }
        }
        left++; // ������ ��� ���� �� ��������� �������
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
    cout << "����i������� �����: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    unsigned int start_time = clock(); // ���������� ���
    ShakerSort(arr, size);
    unsigned int end_time = clock(); // ������� ���
    unsigned int search_time = end_time - start_time; // ������� ���
    cout << "�i����������� �����: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n��� ���������� ������, �� ���������� � " << size << " �������i� ���������: " << search_time << " �i�i������";
    cout << endl;
    return 0;
}