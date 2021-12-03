/*
    Viết hàm trả về con trỏ trỏ tới giá trị lớn nhất của một mảng các số double. Nếu mảng rỗng hãy trả về NULL.
*/

#include<bits/stdc++.h>
using namespace std;

double* maximum(double* a, int size){
    double *max;
    max = a;

    if (a==NULL) return NULL;

    /*****************
    # YOUR CODE HERE #
    *****************/
    for(int i = 0 ; i < size ; i++) {
        if(*max < *(a + i)) {
            max = (a + i);
        }
    }
    
    return max;
}

int main() {
	printf("Nguyen Hong Son - 20194156\n");
    double a[7] = {1.1, 1.0, 2.1, 2.2, 2.7, 3.0, 0.5};
    printf("Array: ");
	for(int i = 0 ; i < 7 ; i++) {
    	printf("%.2f ", a[i]);
	}
    printf("\nGia tri lon nhat la:  %.4f", *maximum(a, 7));
    return 0;
}
