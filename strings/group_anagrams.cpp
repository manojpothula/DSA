class Solution {
public:
       bool anagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
       }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        vector<bool>visited(strs.size(),false);
        for(int i=0;i<strs.size();i++)
        {
            if(visited[i])
              continue;
            vector<string>level;
            level.push_back(strs[i]);
            visited[i]=true;
            for(int j=i+1;j<strs.size();j++)
            {
              if(!visited[j]&& anagram(strs[i],strs[j]))
              {
                level.push_back(strs[j]);
                visited[j]=true;
              }
            }
            ans.push_back(level);
        }
        return ans;
    }
};