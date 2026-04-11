class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
        
        std::sort(cars.begin(), cars.end(), [](const pair<int, double>& a, const pair<int, double>& b){
            return a.first > b.first;
        });

        stack<double> times;

        if (n == 0) return 0;

        times.push(cars[0].second);

        for(int i = 1; i < n; i++)
        {
            double t = cars[i].second;

            if(t <= times.top())
                continue;
            else
                times.push(t);
        }

        int ans = times.size();

        return ans;
    }
};