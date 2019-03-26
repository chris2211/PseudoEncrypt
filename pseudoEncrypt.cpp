#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <set>
#include <vector>

int pseudoEncrypt (int val) {
    int l1 = (val >> 16) & 0xffff;
    int r1 = val & 0xffff;
    int l2,r2;
    int i;
    
    for (i = 0;i < 3;i++) {
        l2 = r1;
        r2 = l1 ^ (int)round((((1366*r1 + 150889) % 714025) / 714025.0) * 32767);
        l1 = l2;
        r1 = r2;
    }
    
    return ((r1 << 16) + l1);
}


int pseudoEncrypt8 (int val) {
    int l1 = (val >> 13) & 8191;
    int r1 = val & 8191;
    int l2,r2;
    int i;
    
    for (i = 0;i < 3;i++) {
        l2 = r1;
        r2 = l1 ^ (int)round((((1366*r1 + 150889) % 714025) / 714025.0) * 8191);
        l1 = l2;
        r1 = r2;
    }
    
    return ((r1 << 13) + l1);
}


//将8位的值存入nums
void boundPseudoEncrypt8 (std::vector<int>& nums,int min, int max) {
    int result;
    for (int i = min;i < max;i++) {
        result = pseudoEncrypt8(i);
        if (result >= 10000000 && result <= 99999999) {
            nums.push_back(result);
        }
    }
}

bool testPseudoEncryptDuplicate(std::vector<int>& nums) {
    return nums.size() > std::set<int>(nums.begin(),nums.end()).size();
}

int testPseudoEncryptRange() {
    int result = 0;
    for (int i = INT_MIN;i < INT_MAX;i++) {
        if (pseudoEncrypt(pseudoEncrypt(i)) != i) {
            std::cout << "not self inverse" << std::endl;
            std::cout << i << std::endl;
        }
        
        result++;
    }
    
    return result;
}

int main()
{
    //std::cout << testPseudoEncrypt() << std::endl;
    //for (int i = -10;i < 10;i++) {
    //     std::cout <<  pseudoEncrypt8(i) << std::endl;
    // }
    
    //for (int i = -10;i < 10;i++) {
    //     std::cout <<  pseudoEncrypt(i) << std::endl;
    // }
    
    std::vector<int> a;
    boundPseudoEncrypt8(a,10,30);
    
    for (unsigned i = 0;i < a.size();i++) {
        std::cout <<  a[i] << std::endl;
    }
    return 0;
    
}





