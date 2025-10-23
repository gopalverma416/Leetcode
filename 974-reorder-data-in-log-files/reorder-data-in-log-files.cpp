class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter;
        vector<string> digits;
        int n = logs.size();
        for (int i = 0; i < n; i++) {
            string st = logs[i];
            int pos = st.find(' ');
            if (isalpha(st[pos + 1])) {
                letter.push_back(st);
            } else {
                digits.push_back(st);
            }
        }
        sort(letter.begin(),letter.end(),[](string& a,string& b){
            int idx1=a.find(' ');
            int idx2=b.find(' ');
            string identi1=a.substr(0,idx1);
            string identi2=b.substr(0,idx2);
            string cont1=a.substr(idx1+1);
            string cont2=b.substr(idx2+1);
            if(cont1==cont2){
                return identi1<identi2;
            }else{
                return cont1<cont2;
            }
        });
        letter.insert(letter.end(),digits.begin(),digits.end());
        return letter;
    }
};