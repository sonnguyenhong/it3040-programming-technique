/*
    Viết chương trình yêu cầu nhập giá trị cho 3 biến số nguyên x, y, z kiểu int. 
    Sau đó sử dụng duy nhất một con trỏ để cộng giá trị của mỗi biến thêm 100.
*/
#include <stdio.h>
int main()
{
    int x, y, z;
    int *ptr;
    scanf("%d %d %d", &x, &y, &z);
    printf("Nguyen Hong Son - 20194156\n");
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);

    /*****************
    # YOUR CODE HERE #
    *****************/
    ptr = &x;
    *ptr += 100;
    ptr = &y;
    *ptr += 100;
    ptr = &z;
    *ptr += 100;
    
    printf("Once again, here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
    return 0;
}    
