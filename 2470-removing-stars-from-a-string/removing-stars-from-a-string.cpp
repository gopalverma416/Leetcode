class Solution {
public:
    string removeStars(string s) {
        vector<char>res;
        int n=s.size();
        for(int i=0;i<n;i++){
         char ch=s[i];
           if(ch=='*'){
            res.pop_back();
           }else{
            
            
            res.push_back(ch);
           }
          
        }
        string result="";
        for(int i=0;i<res.size();i++){
            char ch=res[i];
            result+=ch;
        }
        return result;
    }
};