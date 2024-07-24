class Solution {
public:
   bool solve(vector<int>& nums, vector<int>& vis, int k, int start, int curr, int target) {
     if (k == 0) return true; // If all subsets are successfully found
     if (curr > target) return false; // If the current sum exceeds the target
     if (curr == target) return solve(nums, vis, k - 1, 0, 0, target); // Start finding the next subset

     for (int i = start; i < nums.size(); i++) {
        if (vis[i]) continue; // Skip if the element is already used
        
        vis[i] = 1; // Mark the element as used
        if (solve(nums, vis, k, i + 1, curr + nums[i], target)) return true; // Recursively try to find the solution
        vis[i] = 0; // Backtrack: unmark the element
     }

     return false; // If no valid subset found, return false
   }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (auto i : nums) sum += i;
        
        if (sum % k != 0) return false; // If the total sum is not divisible by k, return false
        if (n < k) return false; // If there are fewer elements than k, return false
        
        vector<int> vis(n, 0); // Initialize visited array
        int target = sum / k; // Each subset should sum to this target
        
        // Sort the nums array in descending order to try larger elements first
        sort(nums.begin(), nums.end(), greater<int>());
        
        // If the largest element is greater than the target, it's impossible to partition
        if (nums[0] > target) return false;
        
        return solve(nums, vis, k, 0, 0, target); // Start the recursive process
    }
};
