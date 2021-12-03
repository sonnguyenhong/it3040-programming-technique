/*
    Viết hàm countEven(int*, int) nhận một mảng số nguyên và kích thước của mảng, trả về số lượng số chẵn trong mảng.
*/

#include<bits/stdc++.h>
using namespace std;

int counteven(int* arr, int size){
    int count = 0;
    
    /*****************
    # YOUR CODE HERE #
    *****************/

    for(int i = 0 ; i < size ; i++) {
        if(*(arr+i) % 2 == 0) {
            count++;
        }
    }
    
    return count;    
}

int main() {
	printf("Nguyen Hong Son - 20194156\n");
    int a[7] = {1, 2, 3, 4 ,5 ,6 , 7};
    printf("Array: ");
    for(int i = 0 ; i < 7 ; i++) {
    	cout<<a[i]<<" ";
	}
	cout<<endl;
    cout<<counteven(a, 7);
}
