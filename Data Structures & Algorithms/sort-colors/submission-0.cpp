class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto& i:m){
            cout << "MAPKey: " << i.first << ", MapValue: " << i.second << endl;    
        }
        
        int k = 0;
        for(int n=0;n<3;n++){
            for(int i=0;i<m[n];i++){
                nums[k++] = n;
            }
        }
    }
};