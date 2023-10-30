#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class UndergroundSystem
{
public:
    unordered_map<int, pair<string, int>> checkInData;
    unordered_map<string, pair<int, int>> avgTime;

    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        checkInData[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        auto checkInInfo = checkInData[id];

        string travelName = checkInInfo.first + ":" + stationName;
        int time = t - checkInData[id].second;

        if (avgTime.find(travelName) == avgTime.end())
        {
            avgTime[travelName] = {time, 1};
        }
        else
        {
            avgTime[travelName].first += time;
            avgTime[travelName].second++;
        }
    }

    double getAverageTime(string startStation, string endStation)
    {
        string dist = startStation + ":" + endStation;
        // total_time / trips
        double total_time = avgTime[dist].first;
        double trips = avgTime[dist].second;
        double ans = total_time / trips;
        return ans;
    }
};

int main()
{
    int key;
    UndergroundSystem *obj = new UndergroundSystem();
    obj->checkIn(45, "Leyton", 3);
    obj->checkIn(32, "Paradise", 8);
    obj->checkIn(27, "Paradise", 10);
    obj->checkOut(45, "Waterloo", 15);
    obj->checkOut(27, "Waterloo", 20);
    obj->checkOut(32, "Cambridge", 22);
    obj->getAverageTime("Paradise", "Cambridge");
    obj->checkIn(10, "Leyton", 24);
    obj->getAverageTime("Leyton", "Waterloo");
    obj->checkOut(10, "Waterloo", 38);
    obj->getAverageTime("Leyton", "Waterloo");
    return 0;
}