class Solution {
    private:
    void build(int i,int n,vector<int>& result){
        if(i>n){
        return;
        }
        result.push_back(i);
        for(int j=0;j<=9;j++){
            int current=i*10+j;
            if(current>n){
                break;
            }
            build(current,n,result);
        }

    }
    
public:
    vector<int> lexicalOrder(int n) {
        vector<int>result;
     for(int i=1;i<=9;i++){
        if(i>n){
            break;
        }
       build(i,n,result);
     }
     return result;
    }
};