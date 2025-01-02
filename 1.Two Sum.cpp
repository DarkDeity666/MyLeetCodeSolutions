#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndexMap; // Maps numbers to their indices

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if the complement exists in the map
            if (numIndexMap.find(complement) != numIndexMap.end()) {
                return {numIndexMap[complement], i}; // Return the indices
            }
            
            // Add the current number and its index to the map
            numIndexMap[nums[i]] = i;
        }

        // Return an empty vector if no solution is found (not expected as per constraints)
        return {};
    }
};
