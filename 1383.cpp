class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<pair<int, int>> engineers;
        for (int i = 0; i < n; ++i)
        {
            engineers.push_back({efficiency[i], speed[i]});
        }
        sort(engineers.rbegin(), engineers.rend());

        long long totalSpeed = 0, maxPerformance = 0;
        multiset<int> speeds;

        for (auto &[e, s] : engineers)
        {
            if (speeds.size() == k)
            {
                totalSpeed -= *speeds.begin();
                speeds.erase(speeds.begin());
            }
            speeds.insert(s);
            totalSpeed += s;
            maxPerformance = max(maxPerformance, totalSpeed * e);
        }

        return maxPerformance % (int)(1e9 + 7);
    }
};