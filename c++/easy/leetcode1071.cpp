#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 == str2 + str1){ //先判斷兩個string是否唯有重複
            return str1.substr(0,__gcd(str1.length(), str2.length())); // 判斷兩個字串長度最大供因數，並且擷取出字串
        }
        return "";
    }


int main()
{
    string str1 = "ABCABC";
    string str2 = "ABC";
    gcdOfStrings(str1, str2);
    return 0;
}
