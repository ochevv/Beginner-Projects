/*
    Problem:
You are given a sorted array of integers nums and a target integer target. Find the indices of the two numbers in the array that add up to the given target. 
Return the indices as a 1-based array (not 0-based). 
You can assume that exactly one valid solution exists, and the same element cannot be used twice.

Example:

Input:
nums = [2, 3, 4, 7]
target = 9

Output:
[2, 3]
Explanation:
The numbers 3 (index 2) and 4 (index 3) add up to 9. Since this is a 1-based indexing problem, the output is [2, 3].

Hint:
Since the array is sorted, think about how you can use two pointers or binary search to solve this efficiently.

Your Task:
Write the function to solve the problem.
Implement the main() function to test it with the example input.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; 

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> numMap; // To store the values 

    for(int i = 0; i < nums.size(); ++i) // Find number that can equal to 9
    {
        int complement = target - nums[i]; // Find the complement 
                                          // Complent = number needed to complete the sum

        // Check is complement is already in the map 
        if(numMap.find(complement) != numMap.end())
        {
            // Return both indices 
            return{numMap[complement], i};
        }

        // Store current number and it's index in the map
    }
     return{};
}

int main() 
{
    vector<int> nums = {2, 3, 4, 7};
    int target = 9;
    
    vector<int> result = twoSum(nums, target);

    // Check if a valid result was found before accessing the indices 
    if(!result.empty())
    {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } 
    else 
    {
        cout << "No two numbers add up to the target." << endl;
    }

    return 0;
 }
