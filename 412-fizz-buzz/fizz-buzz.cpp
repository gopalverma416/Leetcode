class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>res;
        for(int i=1;i<=n;i++){
            int val=i;
            if(val%3==0 && val%5==0){
               res.push_back("FizzBuzz");
            }else if(val%3==0){
                res.push_back("Fizz");
            }else if(val%5==0){
                res.push_back("Buzz");
            }else{
                string st=to_string(i);
                res.push_back(st);
            }
        }
        return res;
    }
};