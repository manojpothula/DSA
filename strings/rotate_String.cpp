class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
          return false;
       string a=s+s;
       return a.find(goal)!=string::npos;
    }
};