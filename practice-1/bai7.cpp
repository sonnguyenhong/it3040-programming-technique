/*
    Viết chương trình nhập vào một mảng các số nguyên với số lượng các phần tử nhập từ bàn phím. 
    Sau đó sắp xếp mảng theo thứ tự tăng dần. Hiển thị danh sách mảng trước và sau khi sắp xếp.
    Yêu cầu chỉ sử dụng con trỏ để truy cập mảng, không truy cập theo index mảng.
*/

#include <stdio.h>
#include <stdlib.h>

int *a;
int n, tmp;

int main(){
	printf("Nguyen Hong Son - 20194156\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    //#Allocate memory
    a = (int*) malloc(n * sizeof(int));
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    for(int i = 0; i < n; i++)
        scanf("%d", a + i); 
    
    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    //#Sort array
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    for(int i = 0 ; i < n-1 ; i++) {
        for(int j = i+1 ; j < n ; j++) {
            if(*(a+i) > *(a+j)) {
                tmp = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = tmp;
            }
        }
    }
    
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    delete [] a;
    return 0;
}
