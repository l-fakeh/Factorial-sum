#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

const int MAX_DIGITS = 1000;  // 预留的最大位数

void multiply(int result[], int &result_size, int num) {
    int carry = 0;  // 进位
    
    for (int i = 0; i < result_size; i++) {
        int prod = result[i] * num + carry;  // 逐位乘以 num 并加上进位
        result[i] = prod % 10;  // 当前位
        carry = prod / 10;  // 更新进位
    }

    // 处理进位
    while (carry) {
        result[result_size] = carry % 10;
        carry /= 10;
        result_size++;  // 增加结果的位数
    }
}
void add(int arr[], int ans[], int &arr_size, int ans_size) {
    int carry = 0;  // 进位
    
    int max_size = max(arr_size, ans_size);  // 使用较大数组的大小
    for (int i = 0; i < max_size || carry != 0; i++) {
        if (i < ans_size) {
            arr[i] += ans[i];
        }
        
        arr[i] += carry;
        carry = arr[i] / 10;
        arr[i] %= 10;

        if (i >= arr_size) {
            arr_size++;
        }
    }
}
void factorial(int n) {
    int result[MAX_DIGITS];  // 存储大数的每一位
    int arr[MAX_DIGITS];
    fill(arr, arr + MAX_DIGITS, 0);
    int ans[MAX_DIGITS];
    arr[0] = 0;
    int arr_size = 1;
    // 依次将每个数乘到当前的结果中
    for (int i = 1; i <= n; i++) {
        fill(result, result + MAX_DIGITS, 0);
        result[0] = 1;
        int result_size = 1;
        for (int j = 2; j <= i; j++) {
            multiply(result, result_size, j);
        }
        copy(result, result + result_size, ans);
        add(arr, ans, arr_size,result_size);
    }

    
    for (int i = arr_size - 1; i >= 0; i--) {
        cout << arr[i];
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;

    factorial(n);  // 计算并输出 n 的阶乘和
    return 0;
}