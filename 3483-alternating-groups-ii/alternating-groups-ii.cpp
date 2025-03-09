class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int count = 0;
        int left = 0;
        
        for (int right = 0; right < n + k - 1; ++right) {
            if (right > 0 && colors[right % n] == colors[(right - 1) % n]) {
                left = right;  
            }
            
            if (right - left + 1 >= k) {
                count++;  
            }
        }
        
        return count;
    }
};