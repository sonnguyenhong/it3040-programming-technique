#include<bits/stdc++.h>
using namespace std;

int n;
int **a1, **a2, **res;

void allocateMem(int ***a, int n) {
    *a = new int*[n];
    for(int i = 0 ; i < n ; i++) {
        (*a)[i] = new int[n];
    }
}

void input() {
    cin>>n;
    allocateMem(&a1, n);
    allocateMem(&a2, n);
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin>>a1[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin>>a2[i][j];
        }
    }
}

void freeMem(int **a, int n) {
    for(int i = 0 ; i < n ; i++) {
        delete[] a[i];
    }
    delete[] a;
}

int** sumMt(int **a1, int **a2, int n) {
    int **res;
    allocateMem(&res, n);
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            res[i][j] = a1[i][j] + a2[i][j];
        }
    }
    return res;
}

int** mulMt(int **a1, int **a2, int n) {
    int **res;
    allocateMem(&res, n);
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            res[i][j] = 0;
            for(int k = 0 ; k < n ; k++) {
                res[i][j] += (a1[i][k] * a2[k][j]);
            }
        }
    }
    return res;
}

void printArr(int **a, int n) {
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    } 
}

int main() {
	printf("Nguyen Hong Son - 20194156\n");
    input();
    res = sumMt(a1, a2, n);
    //cout<<"Tong 2 ma tran la: "<<endl;
    printArr(res, n);
    freeMem(res, n);
    res = mulMt(a1, a2, n);
    //cout<<"Tich 2 ma tran la: "<<endl;
    printArr(res, n);
    freeMem(res, n);

    freeMem(a1, n);
    freeMem(a2, n);
}
