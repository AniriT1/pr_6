#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <stdlib.h> 
#include <time.h> 
#include <sstream>
using namespace std;

//Задача для упорядочивания столбцов


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    string input;
    int n;
    
    while (true) {
        cout << "Введите размер массива: ";
        getline(cin, input);
        istringstream iss(input);
        if (iss >> n) {
            // Проверка наличия только числовых символов
            char remaining;
            if (iss >> remaining) {
                cout << "Ошибка! Введите только числовое значение." << endl;
            }else if (n < 1) {
            cout << "Ошибка! Введите не нулевое и положительное числовое значение." << endl;
            } else {
                break; // Ввод корректен, выходим из цикла
            }
        } 
        else {
            cout << "Ошибка! Введите числовое значение." << endl;
        }
    }
    
    //int *arr = new int[n];
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    // Обнуление рандома
    srand(time(0));
    // Заполнение массива рандомными числами от 1 до n
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 1 + rand() % n;
        }
    }
    cout << "было: " << endl;
    // Вывод рандомного массива
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
    cout << "получилось: " << endl;
    // Вывод упорядоченного массива
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    // Очистка массива
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    system("pause");
    return 0;
}
