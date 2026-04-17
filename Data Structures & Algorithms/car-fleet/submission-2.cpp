class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> carInfo;
        stack<double> fleetTimes;
        
        for(int i = 0; i<position.size(); i++)
        {
            int pos = position[i];
            int sp = speed[i];
            carInfo.push_back({pos,sp});
        }

        std::sort(carInfo.begin(),carInfo.end(), [](const auto& a, const auto& b){
            return a.first>b.first;
        });

        double t = (target-carInfo[0].first)/((double)carInfo[0].second);
        fleetTimes.push(t);

        for(int i = 1; i<position.size(); i++)
        {
            double time = (target-carInfo[i].first)/((double)carInfo[i].second);
            if(!fleetTimes.empty() && time>fleetTimes.top())
            {
                fleetTimes.push(time);
            }
        }

        return fleetTimes.size();
    }
};