class ParkingSystem {
public:
    vector<int> ref;
    vector<int> take;

    ParkingSystem(int big, int medium, int small) {
        ref.push_back(0);   
        ref.push_back(big);
        ref.push_back(medium);
        ref.push_back(small);
        take.resize(4, 0);
    }
    
    bool addCar(int carType) {
        int maxi = ref[carType];
        int have = take[carType];
        
        if (have >= maxi) return false;
        
        take[carType]++;
        return true;    
    }
};
