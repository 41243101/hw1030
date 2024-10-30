#include <iostream>
using namespace std;

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << '\n';
}

void change_size(int*& arr, int &size) 
{
    int new_size = size * 2;//3*2=6
    int* new_arr = new int[new_size];

    // 初始化新陣列的元素為 0
    for (int i = 0; i < new_size; i++)
    {
        new_arr[i] = 0;//0 0 0 0 0 0
    }

    //arr[0]~arr[3]複製舊陣列的內容到新陣列
    copy(arr, arr + size, new_arr);//1 2 3 0 0 0

    // Increase every elements by size.新陣列的每個元素增加 new_size 的值 
    for (int i = 0; i < new_size; i++) new_arr[i] += new_size;// 1+6 2+6 3+6 0+6 0+6 0+6

    delete[] arr;//回收舊陣列的記憶體
    arr = new_arr;//更新指標，指向新陣列
    size = new_size;  // 更新容量
}

int main() {
    int size = 3;
    int* arr = new int[size];

    cout << "初始陣列: ";
    // Inserting elements.插入元素
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    };
    print_arr(arr, size);  // Print initial array.列印初始陣列內容 1 2 3

    cout << "新陣列: ";
    change_size(arr, size);
    print_arr(arr, size);  // Size has changed, print the new array. 陣列大小改變，印出目前(新)陣列的內容 7 8 9 6 6 6
    
    delete[] arr;  // 釋放最終陣列的記憶體
    return 0;
}