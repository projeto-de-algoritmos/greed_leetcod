class Solution
{
public:
    string largestMultipleOfThree(vector<int> &digits)
    {
        vector<int> rem[3];
        int sum = 0;
        for (int digit : digits)
        {
            rem[digit % 3].push_back(digit);
            sum += digit;
        }
        for (vector<int> &r : rem)
            sort(r.begin(), r.end(), greater<int>());

        if (sum % 3 == 1)
        {
            if (!rem[1].empty())
                rem[1].pop_back();
            else if (rem[2].size() >= 2)
            {
                rem[2].pop_back();
                rem[2].pop_back();
            }
            else
                return "";
        }
        else if (sum % 3 == 2)
        {
            if (!rem[2].empty())
                rem[2].pop_back();
            else if (rem[1].size() >= 2)
            {
                rem[1].pop_back();
                rem[1].pop_back();
            }
            else
                return "";
        }

        string res = "";
        for (vector<int> &r : rem)
            for (int digit : r)
                res += to_string(digit);
        sort(res.begin(), res.end(), greater<char>());

        return res[0] == '0' ? "0" : res;
    }
};