/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System
 */

// @lc code=start
class UndergroundSystem
{
public:
   unordered_map<int, pair<string, int>> checkInMap;
    unordered_map<string, pair<int, int>> checkOutMap;
    UndergroundSystem()
    {
        
    }

    void checkIn(int id, string stationName, int t)
    {
        checkInMap[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        auto chIn = checkInMap[id];
        checkInMap.erase(id);
        string route = chIn.first + " " + stationName;
        checkOutMap[route].first += t - chIn.second;
        checkOutMap[route].second++;
    }

    double getAverageTime(string startStation, string endStation)
    {
        string route = startStation + " " + endStation;
        auto chOut = checkOutMap[route];
        return (double)chOut.first / chOut.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end
