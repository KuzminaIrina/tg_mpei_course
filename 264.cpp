https://leetcode.com/problems/ugly-number-ii/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>v(n,0);
        v[0]=1;
        int i2=0,i3=0,i5=0;
        int m2=2,m3=3,m5=5;
        for(int i=1;i<n;i++)
        {
            int next=min(m2,min(m3,m5));
            v[i]=next;
            if(next==m2)
            {
                i2=i2+1;
                m2=v[i2]*2;
            }
            if(next==m3)
            {
                i3=i3+1;
                m3=v[i3]*3;
            }
            if(next==m5)
            {
                i5=i5+1;
                m5=v[i5]*5;
            }
        }
        return v[n-1];
    }
};
