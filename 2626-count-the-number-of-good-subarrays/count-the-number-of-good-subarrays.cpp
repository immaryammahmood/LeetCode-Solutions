class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long prev_count = 0, res = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            // Add new pairs formed by nums[right]
            prev_count += freq[nums[right]];
            freq[nums[right]]++;

            // Shrink window until we have fewer than k pairs
            while (prev_count >= k) {
                res += nums.size() - right; // Count subarrays starting from left
                prev_count -= freq[nums[left]] - 1;
                freq[nums[left]]--;
                left++;
            }
        }
        
        return res;
    }
};