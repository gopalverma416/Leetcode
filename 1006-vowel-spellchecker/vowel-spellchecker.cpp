class Solution {
private:
   
    string to_lower(string s) {  
        for (char &c : s) c = tolower(c);
        return s;
    }

   
    string devowel(string s) {   
        for (char &c : s) {
            if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') c = '*';
        }
        return s;
    }

  
    void noMatch(vector<string>& nums, unordered_map<string, string>& ram) {
        for (int i = 0; i < nums.size(); i++) {
            string ans = nums[i];
            string low = to_lower(ans);      
            string res = devowel(low);       
            if (!ram.count(res))           
                ram[res] = ans;
        }
    }

    // \U0001f539 For case-insensitive preprocessing
    void fillCaseInsensitive(vector<string>& nums,
                             unordered_map<string, string>& ram) {
        for (int i = 0; i < nums.size(); i++) {
            string ans = to_lower(nums[i]);  
            if (!ram.count(ans))            
                ram[ans] = nums[i];
        }
    }

public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        
        unordered_map<string, string> exact;  
        for (string &w : wordlist) {
            exact[w] = w;                    
        }

       
        unordered_map<string, string> inst;
        fillCaseInsensitive(wordlist, inst); 

      
        unordered_map<string, string> nomatch;
        noMatch(wordlist, nomatch);         

        vector<string> result;

       
        for (string q : queries) {
            if (exact.count(q)) {
                result.push_back(exact[q]);   // exact match
            } 
            else {
                string low = to_lower(q);
                if (inst.count(low)) {
                    result.push_back(inst[low]); 
                } 
                else {
                    string dev = devowel(low);
                    if (nomatch.count(dev)) {
                        result.push_back(nomatch[dev]); 
                    } else {
                        result.push_back("");        
                    }
                }
            }
        }
        return result;
    }
};
