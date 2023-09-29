/*
*Hare-Tortoise
*
*
*Detect cycles in a path. Returns the beginning node of the cycle
*
*Requires: nums (value represent next node in the path)
*Effect(s): find beginning of the cycle, if there is any
* 
*O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int hare_tortoise(vector<int>& nums) {
    int tortoise = nums[0]; 
    int hare = nums[nums[0]];
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    }
    tortoise = 0;
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }
    return hare; 
}