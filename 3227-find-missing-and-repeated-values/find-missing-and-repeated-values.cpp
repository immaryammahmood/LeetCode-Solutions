class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    int totalNumbers = n * n;
    vector<int> count(totalNumbers + 1, 0);
    for(const auto& row : grid){
        for(int num : row){
            count[num]++;
        }
    }  
    int repeated = -1, missing = -1;
    for(int i = 0; i <= totalNumbers; i++){
        if(count[i] == 2) repeated = i;
        if(count[i] == 0) missing = i;
    } 
    return {repeated, missing}; 
    }
};