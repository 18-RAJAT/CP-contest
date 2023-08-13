class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        function<bool(vector<vector<int>>&,int,vector<int>,vector<int>&)>cycle=[&](vector<vector<int>>&graph,int course,vector<int>visited,vector<int>&noCycle)->bool
        {
            if(visited[course]==true)
            {
                return true;
            }
            if(noCycle[course]==true)
            {
                return false;
            }
            visited[course]=true;
            for(auto&it:graph[course])
            {
                bool notValid=cycle(graph,it,visited,noCycle);
                if(notValid)
                {
                    return true;
                }
            }
            noCycle[course]=true;
            return false;
        };
        vector<vector<int>>graph(numCourses);
        for(auto&it:prerequisites)
        {
            /*
                0->1
                1->0
            */
            graph[it[0]].push_back(it[1]);
        }
        vector<int>visited(numCourses,0);
        vector<int>noCycle(numCourses,0);
        for(int i=0;i<numCourses;++i)
        {
            bool notValid=cycle(graph,i,visited,noCycle);
            if(notValid)
            {
                return false;
            }
        }
        return true;
    }
};