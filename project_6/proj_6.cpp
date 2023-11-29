#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <stdlib.h> 
#include <time.h> 
#include <sstream>
using namespace std;

//������ ��� �������������� ��������


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    string input;
    int n;
    
    while (true) {
        cout << "������� ������ �������: ";
        getline(cin, input);
        istringstream iss(input);
        if (iss >> n) {
            // �������� ������� ������ �������� ��������
            char remaining;
            if (iss >> remaining) {
                cout << "������! ������� ������ �������� ��������." << endl;
            }else if (n < 1) {
            cout << "������! ������� �� ������� � ������������� �������� ��������." << endl;
            } else {
                break; // ���� ���������, ������� �� �����
            }
        } 
        else {
            cout << "������! ������� �������� ��������." << endl;
        }
    }
    
    //int *arr = new int[n];
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    // ��������� �������
    srand(time(0));
    // ���������� ������� ���������� ������� �� 1 �� n
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 1 + rand() % n;
        }
    }
    cout << "����: " << endl;
    // ����� ���������� �������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    
    for (int i = 0; i < n; i++) 
    {
        int p = 1;
        while (p < ((n/2)+1)) 
        {
            for (int k = 0; k < n - 2*p; k++) 
            {
                arr[i][n-1-k]^=arr[i][n-2-k]^=arr[i][n-1-k]^=arr[i][n-2-k];
            }
                p++;
        }
    }
    cout << "����������: " << endl;
    // ����� �������������� �������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    // ������� �������
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    system("pause");
    return 0;
}
