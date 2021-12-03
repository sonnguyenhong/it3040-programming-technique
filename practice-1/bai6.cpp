/*
    Viết hàm đảo ngược một mảng các số nguyên theo hai cách: dùng chỉ số và dùng con trỏ.
    Ví dụ mảng đầu vào là [9, -1, 4, 5, 7] thì kết quả là [7, 5, 4, -1, 9].
*/

#include<bits/stdc++.h>
using namespace std;

void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp;
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    while(l < r) {
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++;
        r--;
    }
}

void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;
    
    /*****************
    # YOUR CODE HERE #
    *****************/
   while(l < r) {
       tmp = *(arr + l);
       *(arr + l) = *(arr + r);
       *(arr + r) = tmp;
       l++;
       r--;
   }
}

int main() {
    int a[5] = {9, -1, 4, 5, 7};
    printf("Nguyen Hong Son - 20194156\n");
    ptr_reversearray(a, 5);
    for(int i = 0 ; i < 5 ; i++) {
        printf("%d ", a[i]);
    }
}
