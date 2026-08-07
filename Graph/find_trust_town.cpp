class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int>mpp;
        for(auto t:trust)
        {
            mpp[t[1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(mpp[i]==n-1)
            {
                bool found=false;
                for(auto it:trust)
                {
                    if(it[0]==i)
                    {
                        found=true;
                        break;
                    }
                }
                if(!found)
                   return i;
            }
        }
        return -1;
    }
};