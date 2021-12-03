/*
Bài tập 12: Map Sort
Hôm nay, cô giáo giao cho An một câu hỏi hóc búa. Cô cho một danh sách với mỗi phần tử có dạng <key, value> 
    và yêu cầu An sắp xếp danh sách đó giảm dần theo giá trị value. 
    Nếu 2 phần tử có value giống nhau thì sắp xếp giảm dần theo key.

Hãy viết một chương trình sử dụng hàm nặc danh để giúp An làm bài tập.

Input: Danh sách đầu vào. Mỗi dòng ghi một cặp giá trị key, value cách nhau bởi dấu cách (|key|  ≤109 , |value|  ≤109 ).

Output: In danh sách đã được sắp xếp theo yêu cầu. Mỗi dòng ghi một cặp giá trị key, value cách nhau bởi dấu cách.
*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> vec;

void display() {
    int sz = vec.size();
    for(int i = 0 ; i < sz ; i++) {
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
}

int main() {
    int x, y;
    while(cin>>x && cin>>y) {
        vec.push_back(make_pair(x, y));
    }

    // compareF return 1 if x > y, 0 if x == y and -1 if x < y
    auto compareF = [] (pair<int, int> x, pair<int, int> y) {
        if(x.second > y.second) {
            return true;
        } else if (x.second < y.second) {
            return false;
        } else {
            return x.first > y.first;
        }
    };
    
    sort(vec.begin(), vec.end(), compareF);

    display();
}