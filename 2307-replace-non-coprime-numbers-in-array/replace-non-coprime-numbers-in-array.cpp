class Solution {
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    int lcm(int a, int b) { 
        long long g = __gcd(a, b);
        long long res = (1LL * a / g) * b;
        return (int)res;
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>st;
       for(auto& a:nums){
        st.push_back(a);
        while(st.size()>1){
            int first=st.back(); st.pop_back();
            int second=st.back(); st.pop_back();
            int g=gcd(first,second);
            if(g>1){
                st.push_back(lcm(first,second));
            }else{
                st.push_back(second);
                st.push_back(first);
                break;
            }

        }
       }
       return st;
    }
};
