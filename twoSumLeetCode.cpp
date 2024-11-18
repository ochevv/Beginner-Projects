/*
    Problem:
Given an array of integers, find the two numbers whose product (multiplication) is equal to a given target. Return their indices.

Example Input:

nums = [1, 2, 3, 6], target = 6
Example Output:

[1, 2]
Explanation: 2 * 3 == 6, so we return the indices [1, 2].

Hint: You can modify the solution for Two Sum slightly to solve this! You’ll check for multiplication instead of addition.

*/

#include <iostream> 
#include <iomanip> 
#include <vector>
#include <unordered_map>

using namespace std; 

vector<int> twoProd(vector<int>& nums, int target) 
{
    unordered_map <int, int > numMap; //  Hash map To store the key values 

    for(int i = 0; i < nums.size(); ++i) // Start at the index 0 and keep going until you find a complement 
    {
        int complement = target / nums[i]; // complement = the number we are looking for to complete the sum 
                                          // target divided by first number we find that can possibly equal the target (nums[i]), 
                                          //then we get the complement that we need to look for.
        
        // Check if complement is already in the map
        if(numMap.find(complement) != numMap.end())
        {
            // if found return the two indices 
            return {numMap[complement], i}; // the two indices are i which was the nums[i] and the complement which was found by numMap.find(complement)

        }
        // Otherwise store the current number with it's index
        numMap[nums[i]] = i; // 
    } 
        // if no two numbers add up to the target return an empty vector
        return {};
}

int main() 
{
    vector<int> nums = {1, 2, 3, 6};
    int target = 6; 

    vector <int> result = twoProd(nums, target);
    cout << "Indices: [" << result[1] << ", " << "]" << endl;
    return 0;
}