class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(char t: tasks) {
            count[t - 'A']++;
        }

        sort(count.begin(), count.end());
        int maxf = count[25];
        int idleSlots = (maxf - 1) * n;

        for(int i=24;i>=0;i--) {
            idleSlots -= min(maxf - 1, count[i]);
        }

        return max(0, idleSlots) + tasks.size();
    }
};
