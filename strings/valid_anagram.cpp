class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
          return false;
        map<char,int>mpp;
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
        }
        int flag=1;
        for(int i=0;i<t.size();i++)
        {   mpp[t[i]]--;
            if(mpp[t[i]] < 0)
              return false;
        }
        return true;
    }
};