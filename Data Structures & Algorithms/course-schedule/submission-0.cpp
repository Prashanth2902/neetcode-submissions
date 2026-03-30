class Solution {
public:

    bool dfs(int crs, unordered_map<int, vector<int>>& preMap, unordered_set<int>& visit) {
        if(visit.count(crs)) return false;
        if(preMap[crs].empty()) {
            return true;
        }
        visit.insert(crs);
        for(int x:preMap[crs]) {
            if(!dfs(x, preMap, visit)) return false;
        }
        visit.erase(crs);
        preMap[crs].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preMap;
        unordered_set<int> visit;
        for(int i=0;i<numCourses;i++) {
            preMap[i] = {};
        }
        for(auto& prereq: prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }
        for(int c=0;c<numCourses;c++) {
            if(!dfs(c, preMap, visit)) return false;
        }
        return true;
    }
};
