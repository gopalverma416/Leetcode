class Solution {
    private:
    bool compare(string& a,string& b){
        vector<int>arr(26,0);
        for(int i=0;i<a.size();i++){
            int idx=a[i]-'a';
            arr[idx]++;
        }
        for(int i=0;i<b.size();i++){
            int idx=b[i]-'a';
            arr[idx]--;
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0){
                return false;
            }
        }
        return true;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string>result;
        result.push_back(words[0]);
        for(int i=1;i<n;i++){
            bool temp=compare(words[i],result.back());
            if(temp==false){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};