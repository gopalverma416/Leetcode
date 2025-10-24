class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
    vector<long long> result;
    if(finalSum % 2 != 0) return result; // cannot split odd sum

    long long currentEven = 2;
    while(finalSum > 0) {
        if(finalSum - currentEven >= 0) {
            result.push_back(currentEven);
            finalSum -= currentEven;
            currentEven += 2;
        } else {
            // last number to complete the sum
            result.back() += finalSum; // add remaining to last number
            break;
        }
    }
    return result;
}

};