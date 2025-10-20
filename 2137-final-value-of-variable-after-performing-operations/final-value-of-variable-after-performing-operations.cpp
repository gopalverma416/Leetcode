class Solution {
public:
    int finalValueAfterOperations(vector<string>& ope) {
        int n=ope.size();
        int x=0;
        
        for(int i=0;i<n;i++){
            string cuu=ope[i];
            if(cuu=="X++"){
                x++;
            }else if(cuu=="X--"){
                x--;
            }else if(cuu=="--X"){
                x--;
            }else{
                x++;
            }
        }
        return x;
    }
};