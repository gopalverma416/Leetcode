class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distx=abs(x-z);
        int disty=abs(y-z);
        if(distx<disty){
            return 1;
        }else if(distx==disty){
            return 0;
        }else{
            return 2;
        }
    }
};