#include<bits/stdc++.h>
using namespace std;

int n;
int *a;

// allocate mem
void allocateMem(int **a, int n) {
    *a = new int[n];
}

void input() {
    cin>>n;
    allocateMem(&a, n);
    for(int i = 0 ; i < n ; i++) {
        cin>>a[i];
    }
}

void freeMem(int *a) {
    delete[] a;
}

// Print array a from index start to index end
void printSubarray(int *a, int start, int end) {
    for(int i = start ; i <= end ; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main() {
	printf("Nguyen Hong Son - 20194156\n");
    input();
    for(int i = 0 ; i < n ; i++) {
        for(int j = i ; j < n ; j++) {
            printSubarray(a, i, j);
        }
    }
    freeMem(a);
}
