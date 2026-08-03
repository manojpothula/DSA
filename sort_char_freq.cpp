class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mpp;
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
        }
        string ans;
        vector<pair<char,int>> v;
        for(auto it:mpp)
        {
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),[](auto &a,auto &b)
        {
            return a.second > b.second;
        });
        for(auto it:v)
        {
           
           while(it.second > 0)
           {
            ans+=it.first;
            it.second--;
           }
           
        }
        return ans;
    }
};