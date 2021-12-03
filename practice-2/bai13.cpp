#include<bits/stdc++.h>
using namespace std;

typedef struct bigNum {
    char sign;
    char num[101];
} bigNum;

int convertToNum(char c) {
    return c - '0';
}

void display(bigNum num) {
    fflush(stdin);
    cout<<num.sign<<num.num<<endl;
}

// convert a char array to stack of int
stack<int> stringToStack(char *c) {
    stack<int> st;

    int lenC = strlen(c);
    for(int i = 0 ; i < lenC ; i++) {
        st.push(convertToNum(c[i]));        
    }
    return st;
}

stack<int> multi(char *c1, char *c2) {
    int *res;
    stack<int> resStack;
    stack<int> c1Stack = stringToStack(c1);
    stack<int> c2Stack = stringToStack(c2);
    
    int c1Len = strlen(c1);
    int c2Len = strlen(c2);
    res = new int[c1Len + c2Len];

    for(int i = 0 ; i < c1Len + c2Len ; i++) {
        res[i] = 0;
    }

    for(int i = c1Len - 1 ; i >= 0 ; i--) {
        for(int j = c2Len - 1 ; j >= 0 ; j--) {
            res[i+j+1] += (c1[i] - '0') * (c2[j] - '0');
        }
    }

    int resLen = c1Len + c2Len;
    for(int i = resLen-1 ; i >= 0 ; i--) {
        int tmp = res[i];
        res[i] = tmp % 10;
        res[i-1] += tmp / 10;
    }

    int index = 0;
    while(res[index] == 0) {
        index++;
    }
    for(int i = resLen - 1 ; i >= index ; i--) {
        resStack.push(res[i]);
    }

    return resStack;
}



// Tru 2 chuoi duong
stack<int> sub (char *c1, char *c2) {
    stack<int> resStack;
    stack<int> c1Stack = stringToStack(c1);
    stack<int> c2Stack = stringToStack(c2);
    int carry = 0;

    while(!c1Stack.empty() && !c2Stack.empty()) {

        if(c1Stack.top() > c2Stack.top()) {
            int tmp = c1Stack.top() - c2Stack.top() - carry;
            resStack.push(tmp);
            c1Stack.pop();
            c2Stack.pop();
            carry = 0;
        } else if (c1Stack.top() == c2Stack.top()) {
            if(carry == 0 && c1Stack.size() > 1) {
                resStack.push(0);
                c1Stack.pop();
                c2Stack.pop();
            } else if(carry > 0) {
                resStack.push(9);
                carry = 1;
                c1Stack.pop();
                c2Stack.pop();
            }
        } else {
            int tmp = 10 + c1Stack.top() - c2Stack.top() - carry;
            resStack.push(tmp);
            carry = 1;
            c1Stack.pop();
            c2Stack.pop();
        }
    
    }
    while(!c1Stack.empty()) {
        if(c1Stack.top() < carry) {
            int tmp = 10 + c1Stack.top() - carry;
            resStack.push(tmp);
            c1Stack.pop();
            carry = 1;
        } else {
            int tmp = c1Stack.top() - carry;
            if(tmp == 0 && c1Stack.size() == 1) {
                c1Stack.pop();
                carry = 0;
            } else {
                resStack.push(tmp);
                c1Stack.pop();
                carry = 0;
            }
        }
    }

    return resStack;
}

// Cong 2 chuoi duong
stack<int> add(char *c1, char *c2) {
    stack<int> resStack;
    stack<int> c1Stack = stringToStack(c1);
    stack<int> c2Stack = stringToStack(c2);
    
    int carry = 0;

    while(!c1Stack.empty() && !c2Stack.empty()) {
        int t = c1Stack.top() + c2Stack.top() + carry;
        carry = t / 10;
        resStack.push(t % 10);
        c1Stack.pop();
        c2Stack.pop();
    }
    while(!c1Stack.empty()) {
        int t = c1Stack.top() + carry;
        carry = t / 10;
        resStack.push(t % 10);
        c1Stack.pop();
    }

    while(!c2Stack.empty()) {
        int t = c2Stack.top() + carry;
        carry = t / 10;
        resStack.push(t % 10);
        c2Stack.pop();
    }

    if(carry > 0) {
        resStack.push(carry);
    }

    return resStack;
}

// return 1 if num1 > num2, 0 if num1 == num2, -1 if num1 < num2
int compareAbs(bigNum num1, bigNum num2) {
    stack<int> num1Stack = stringToStack(num1.num);
    stack<int> num2Stack = stringToStack(num2.num);
    if(num1Stack.size() > num2Stack.size()) return 1;
    if(num1Stack.size() < num2Stack.size()) return -1;
    else {
        while(!num1Stack.empty() && !num2Stack.empty()) {
            if(num1Stack.top() > num2Stack.top())   return 1;
            if(num1Stack.top() < num2Stack.top())   return -1;
            else {
                num1Stack.pop();
                num2Stack.pop();
            }
        }
        return 0;
    }
}

bigNum operator + (bigNum num1, bigNum num2) {
    bigNum res;
    stack<int> resStack;
    stack<int> num1Stack = stringToStack(num1.num);
    stack<int> num2Stack = stringToStack(num2.num);
    int num1Len = num1Stack.size();
    int num2Len = num2Stack.size();

    if(num1.sign == num2.sign) {
        res.sign = num1.sign;   
        resStack = add(num1.num, num2.num);
        
        int index = 0;
        for(int i = 0 ; i < 101 ; i++) {
            res.num[i] = '\0';
        }
        while(!resStack.empty()) {
            res.num[index] = resStack.top() + '0';
            resStack.pop();
            index++;
        }
    }
    else {
        // Neu abs(num1) > abs(num2)
        if(compareAbs(num1, num2) == 1) {
            res.sign = num1.sign;
            /*
                CODE HERE
            */
            resStack = sub(num1.num, num2.num);
            int index = 0;
            while(!resStack.empty()) {
                res.num[index] = resStack.top() + '0';
                resStack.pop();
                index++;
            }

            // DONEEEE
        } else if(compareAbs(num1, num2) == 0) {
            res.sign = '1';
            res.num[0] = '0';
            return res;
        } else {
            /*
                CODE HERE
            */
            res.sign = num2.sign;
            resStack = sub(num2.num, num1.num);
            int index = 0;
            for(int i = 0 ; i < 101 ; i++) {
                res.num[i] = '\0';
            }
            while(!resStack.empty()) {
                res.num[index] = resStack.top() + '0';
                resStack.pop();
                index++;
            }
            // DONEEE
        }
    }
    return res;
}

bigNum operator - (bigNum num1, bigNum num2) {
    bigNum res;
    stack<int> resStack;
    stack<int> num1Stack = stringToStack(num1.num);
    stack<int> num2Stack = stringToStack(num2.num);
    int carry = 0;
    
    if(num1.sign == num2.sign) {
        // Neu abs(num1) > abs(num2)
        if(compareAbs(num1, num2) == 1) {
            res.sign = num1.sign;
            resStack = sub(num1.num, num2.num);
        }
        // Neu abs(num1) == abs(num2)
        else if(compareAbs(num1, num2) == 0) {
            res.sign = '1';
            res.num[0] = '0';
            return res;
        }
        // Neu abs(num1) < abs(num2)
        else {
            if(num1.sign == '0')    res.sign = '1';
            else res.sign = '0';
            resStack = sub(num2.num, num1.num);
        }
    } else {
        
        res.sign = num1.sign;
        resStack = add(num1.num, num2.num);
        
    }

    int index = 0;
    for(int i = 0 ; i < 101 ; i++) {
        res.num[i] = '\0';
    }
    while(!resStack.empty()) {
        res.num[index] = resStack.top() + '0';
        resStack.pop();
        index++;
    }
    return res;
}   

bigNum operator * (bigNum b1, bigNum b2) {
    bigNum res;
    if(b1.sign == b2.sign) {
        res.sign = '1';
    } else res.sign = '0';

    stack<int> resStack = multi(b1.num, b2.num);

    for(int i = 0 ; i < 101 ; i++) {
        res.num[i] = '\0';
    }

    int index = 0;
    while(!resStack.empty()) {
        res.num[index] = resStack.top() + '0';
        resStack.pop();
        index++;
    }
    return res;
}


// Nhan mot so tu nhien 0 < a < 10  voi b1
bigNum operator * (int param, bigNum b1) {
    bigNum res;
    res.sign = b1.sign;

    stack<int> resStack;
    stack<int> b1Stack = stringToStack(b1.num);

    int b1Len = strlen(b1.num);
    int resLen = b1Len + 1;
    int *resArray = new int[resLen];
    for(int i = 0 ; i < resLen ; i++) {
        resArray[i] = 0;
    }

    for(int i = b1Len - 1 ; i >= 0 ; i--) {
        resArray[i + 1] += param * (b1.num[i] - '0');
    }

    for(int i = resLen - 1 ; i >= 0 ; i--) {
        int tmp = resArray[i];
        resArray[i] = tmp % 10;
        resArray[i-1] += tmp / 10;
    }

    int index = 0;
    while(resArray[index] == 0) {
        index++;
    }

    for(int i = resLen - 1 ; i >= index ; i--) {
        resStack.push(resArray[i]);
    }

    for(int i = 0 ; i < 101 ; i++) {
        res.num[i] = '\0';
    }

    index = 0; 
    while(!resStack.empty()) {
        res.num[index] = resStack.top() + '0';
        resStack.pop();
        index++;
    }
    return res;
}

int main() {
    bigNum b1, b2;
    cin>>b1.sign;
    gets(b1.num);
    cin>>b2.sign;
    gets(b2.num);
    
    display(b1 * b2 - 3 * b1 + 4 * b2);
}