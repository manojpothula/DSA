class Solution {
public:
    string reverseWords(string s) {
        vector<string>ans;
        string a="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ' && a=="")
               continue;
          if(s[i]==' ')
          {
             ans.push_back(a);
            a="";
          }
          else
          {
               a+=s[i];
          }
        }
        if(a!="")
          ans.push_back(a);
        reverse(ans.begin(),ans.end());
        string c;
        for(int i=0;i<ans.size();i++)
        {
            c+=ans[i]+" ";
        }
        c.pop_back();
        return c;
    }
};