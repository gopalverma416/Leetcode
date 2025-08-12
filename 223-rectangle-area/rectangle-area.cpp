class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {
        int mini_x = max(ax1, bx1);
        int maxi_x = min(ax2, bx2);
        int mini_y = max(ay1, by1);
        int maxi_y = min(ay2, by2);

       
        int overlap_w = max(0, maxi_x - mini_x);
        int overlap_h = max(0, maxi_y - mini_y);
        int total_overlap = overlap_w * overlap_h;

        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);

        return area1 + area2 - total_overlap;
    }
};
