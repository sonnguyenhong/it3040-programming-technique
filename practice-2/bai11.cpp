/*
Bài tập 11: Tính tích hai đa thức
Cho 2 đa thức A(x) và B(x) tương ứng có bậc  N  và  M . Hãy tính ma trận tích C(x) = A(x) * B(x) có bậc  N+M−1 .

Input: Gồm 2 dòng biểu diễn các đa thức A(x) và B(x), mỗi dòng

Số đầu tiên  N  là bậc của đa thức;
N+1  số nguyên tiếp theo, số thứ i là hệ số của  xi−1 .
Output: Một số nguyên duy nhất là XOR của các hệ số của đa thức C(x).
*/

#include <bits/stdc++.h>

using namespace std;

typedef struct dathuc {
    int n;
    int *a;
}dathuc;

dathuc operator * (dathuc x, dathuc y) {
    dathuc c;
    int bac_x = x.n;
    int bac_y = y.n;
    c.n = bac_x + bac_y;
    c.a = new int[c.n + 1];
    for(int i = 0 ; i <= c.n ; i++) {
        c.a[i] = 0;
        for(int j = 0 ; j <= bac_x ; j++) {
            if(((c.n - i) - (x.n - j)) <= y.n && ((c.n - i) - (x.n - j)) >= 0) {
                c.a[i] += x.a[j] * y.a[y.n - (c.n - i) + (x.n - j)];
            }
        }
    }
    return c;
}

int main() {
    dathuc x, y;
    cin>>x.n;
    x.a = new int[x.n + 1];
    for(int i = 0 ; i <= x.n ; i++) {
        cin>>x.a[i];
    }

    cin>>y.n;
    y.a = new int[y.n + 1];
    for(int i = 0 ; i <= y.n ; i++) {
        cin>>y.a[i];
    }

    dathuc c = x * y;
    //cout<<c.n<<endl;
    int res = 0; // anything XOR with 0 remain unchange
    for(int i = 0 ; i <= c.n ; i++) {
        res = res ^ c.a[i];
    }
    cout<<res;
}