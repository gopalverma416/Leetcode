class FoodRatings {
public:
   using P=pair<int,string>;
    unordered_map<string,string>ftoc;
    unordered_map<string,int>ftor;
    unordered_map<string,set<P>>mp;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
      
        int n=foods.size();
        for(int i=0;i<n;i++){
            string food=foods[i];
            string cuisine=cuisines[i];
            ftoc[food]=cuisines[i];
        }
        for(int i=0;i<n;i++){
            string food=foods[i];
            int val=ratings[i];
            ftor[food]=val;
        }
        for(int i=0;i<n;i++){
            string food=foods[i];
            string cuisine=ftoc[food];
            int rating=ratings[i];
            mp[cuisine].insert({-rating,food});
        }

    }
    
    void changeRating(string food, int newRating) {
       string cuisine=ftoc[food];
       int oldrating=ftor[food];
       mp[cuisine].erase({-oldrating,food});
       mp[cuisine].insert({-newRating,food});
       ftor[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return mp[cuisine].begin()->second;
    }
};
