
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void ypac(int* mass1, int len, int* cc);

int main()
{
    cout << "Введите длину массива(n>1000): \n"; 
    int n;
    cin >> n; 
    if (n < 1000) {
        cout << "Длина массива меньше 1000 :( ";
        return 0;
    }
    int* mass = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        mass[i] = rand() % 17 + 0;
    }
    int temp;
    // отсортировка 
    for (int i = 0; i < n - 1; i++) {
        for (int j=0;j<n-i-1;j++){
            if (mass[j] > mass[j + 1]) {
                temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = temp;
            }
        }
    }

    cout << "Исходный массив чисел: \n";
    for (int i = 0; i < n; i++) {
        cout << mass[i] << " "; 
    }
    cout << endl;
    // ПУНКТ А
    //массив счетчик
    int count[18];
    ypac(mass, n, count);
    int tcount = 0;
    cout << "-------------------------------------------------------------------------------------------\n";
    cout << "Упакованный массив чисел: \n";
    // вывод чисел которые есть в массиве
    for (int i = 0; i < 18; i++) {
        if (count[i] > 0) {
            cout << "Число - " << i << " | " << "Попадается количество раз: " << count[i] << endl;;
            tcount += count[i];
        }
    }
    delete[] mass;
    return 0;
}

void ypac(int* mass1, int len, int* cc) {
    for (int i = 0; i < 18; i++) {
        cc[i] = 0;
    }
    for (int i = 0; i < len; i++) {
        int val = mass1[i];
        cc[val]++;
    }
}