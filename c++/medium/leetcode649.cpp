#include <vector>
#include <iostream>
#include <queue>
using namespace std;

string predictPartyVictory(string senate)
{
    queue<int> qd, qr;

    for (int i = 0; i < senate.size(); i++)
    {
        if (senate[i] == 'R')
            qr.push(i);
        else
            qd.push(i);
    }
    while (!qd.empty() && !qr.empty())
    {
        int qd_index = qd.front();
        int qr_index = qr.front();
        qd.pop();
        qr.pop();

        if (qd_index < qr_index)
            qd.push(qd_index + senate.size());
        else
            qr.push(qr_index + senate.size());
    }
    return (!qd.empty()) ? "Dire" : "Radiant";
}

int main()
{
    string senate = "RDD";
    predictPartyVictory(senate);
    return 0;
}
// rrddr
// 1. rrd
// 2. rr => r

// qd = 2 3
// qr = 0 1 4
