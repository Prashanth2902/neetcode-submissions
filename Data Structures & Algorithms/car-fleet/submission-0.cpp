class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i=0;i<speed.size();i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        stack<double> stk;
        for(auto car: cars) {
            double time = (double) (target - car.first)/car.second;
            if(stk.empty() || time > stk.top()) {
                stk.push(time);
            }
        }
        return stk.size();
    }
};