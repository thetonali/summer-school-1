# include <bits/stdc++.h>
using namespace std;

deque<char> dq; // 开双端队列，从后方插入和弹出模拟栈，从前方弹出用于正向输出
string num;
int k;

int main() {
    cin >> num >> k;
    for (char c : num) {
        // 保持栈内元素单调性，使元素单调不降
        while (dq.size()) {
            if (!k) break;
            if (dq.back() > c) {
                dq.pop_back();
                k--;
            }
            else break;
        }
        dq.push_back(c);
    }
    // 若使序列转化为单调序列不足以用尽 k 次删除，从末端开始删除
    while (k--) dq.pop_back();
    // 输出，忽略前导零、判断全零
    bool preZero = true;
    while (dq.size()) {
        if (preZero) {
            if (dq.front() != '0') preZero = false;
        }
        if (!preZero) putchar(dq.front());
        dq.pop_front();
    }
    if (preZero) putchar(48);
    return 0;
}