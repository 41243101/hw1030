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

    // ��l�Ʒs�}�C�������� 0
    for (int i = 0; i < new_size; i++)
    {
        new_arr[i] = 0;//0 0 0 0 0 0
    }

    //arr[0]~arr[3]�ƻs�°}�C�����e��s�}�C
    copy(arr, arr + size, new_arr);//1 2 3 0 0 0

    // Increase every elements by size.�s�}�C���C�Ӥ����W�[ new_size ���� 
    for (int i = 0; i < new_size; i++) new_arr[i] += new_size;// 1+6 2+6 3+6 0+6 0+6 0+6

    delete[] arr;//�^���°}�C���O����
    arr = new_arr;//��s���СA���V�s�}�C
    size = new_size;  // ��s�e�q
}

int main() {
    int size = 3;
    int* arr = new int[size];

    cout << "��l�}�C: ";
    // Inserting elements.���J����
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    };
    print_arr(arr, size);  // Print initial array.�C�L��l�}�C���e 1 2 3

    cout << "�s�}�C: ";
    change_size(arr, size);
    print_arr(arr, size);  // Size has changed, print the new array. �}�C�j�p���ܡA�L�X�ثe(�s)�}�C�����e 7 8 9 6 6 6
    
    delete[] arr;  // ����̲װ}�C���O����
    return 0;
}