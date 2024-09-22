int rearrangeStudents(vector<int>& A,vector<int>& B)
{
    map<int,int>mp1,mp2;
    for(auto& a:A)mp1[a]++;
    for(auto& b:B)mp2[b]++;

    if(mp1!=mp2) return -1;
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    int ans=0;
    for(int i=0;i<A.size();++i)
    {
        if(A[i]!=B[i])
        {
            ans+=min(A[i],B[i]);
        }
    }
    return ans;
}