#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int m = num1.size();
        int n = num2.size();
        vector<char> result(m + n, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1];
                result[i + j + 1] = product % 10;
                result[i + j] += product / 10;
            }
        }
        string resultStr;
        for (int digit : result) {
            if (!(resultStr.empty() && digit == 0))
                resultStr.push_back(digit + '0');
        }
        return resultStr;
    }
};

class Solution2 {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; 0 <= i; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; 0 <= j; --j) {
                int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            sum[i] += carry;
        }
        size_t startpos = sum.find_first_not_of('0');
        if (startpos != string::npos) {
            return sum.substr(startpos);
        }
        return "0";
    }
};

int main() {
    auto result =  Solution{}.multiply("123", "21");
    cout << result << endl;
}
