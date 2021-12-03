/*
Bài tập 1: Truyền tham trị
Viết hàm tính độ dài cạnh huyền của tam giác theo độ hai cạnh góc vuông.
*/


#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) {
    /*****************
    # YOUR CODE HERE #
    *****************/

   return sqrt(pow(x, 2) + pow(y, 2));
}

int main(){
    float x, y;
    scanf("%f%f", &x, &y);
    
    float z = get_hypotenuse(x, y);
    printf("z = %.2f\n", z);
    
    return 0;
}