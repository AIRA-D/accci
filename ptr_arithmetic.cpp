// Массив int[10], взять указатель (тип можно варировать) на первый элемент
// и с помощью арифметики указателей вывести 4 элемент массива.

#include <iostream>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* ptr = &arr[0] + 3;

    std::cout << "4th element of the array: " << *ptr << std::endl;

    return 0;
}
