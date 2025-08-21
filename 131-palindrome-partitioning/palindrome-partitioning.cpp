class Solution {
    private:
    bool isPalindrome(string& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;   
        }
        left++;
        right--;
    }
    return true;  
}

    void solve(int i,string s,vector<string>& temp,vector<vector<string>>& result){
       int n=s.size();
       if(i==n){
        result.push_back(temp);
       }
        for(int j=i;j<n;j++){
            int len=j-i+1;
            string sub=s.substr(i,len);
          if(isPalindrome(sub)){
            temp.push_back(sub);
            solve(j+1,s,temp,result);
            temp.pop_back();
          }
        }
    
    }
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>result;
        vector<string>temp;
        solve(0,s,temp,result);
      return result;
    }
};