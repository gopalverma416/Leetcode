class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n=fruits.size();
        int left=0;
        unordered_map<int,int>mp;
        int right=1;
        int score=1;
        int maxi=1;
        int aam=fruits[0];
        mp[aam]++;
        while(right<n){
            int val=fruits[right];
            score++;
            mp[val]++;
            while(mp.size()>2){
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }
                left++;
                score--;
            }
            maxi=max(maxi,score);
            right++;
        }
        return maxi;
    }
};