//
// Created by ajh07 on 2021-05-31.
//

#include <iostream>
#include <vector>

using namespace std;

double getAverage(const vector<double>& nums) {
    double sum = 0;
    for(int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }

    return sum/nums.size();
}
vector<double> f(){
    vector<double> tmp;
    tmp.push_back(3);
    return tmp;
}

int main() {
    vector<double> nums;
    double num;
    int n = 0;

    double d = f()[n];

    cout << d << endl;
    cout << "please input nums : ";
    while(cin >> num)
        nums.push_back(num);

    cout << "nums average : " << getAverage(nums) << endl;

    return 0;
}