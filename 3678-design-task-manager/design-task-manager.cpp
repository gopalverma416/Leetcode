class TaskManager {
public:
    unordered_map<int, int> taskRating;
    unordered_map<int, int> taskUserId;
    priority_queue<pair<int, int>> pq;

    TaskManager(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            int use = tasks[i][0];
            int tas = tasks[i][1];
            int prio = tasks[i][2];
            taskRating[tas] = prio;
            taskUserId[tas] = use;
            pq.push({prio, tas});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskRating[taskId] = priority;
        taskUserId[taskId] = userId;
        pq.push({priority, taskId});
    }

    void edit(int taskId, int newPriority) { 
        taskRating[taskId] = newPriority; 
        pq.push({newPriority, taskId});  // push new pair
    }

    void rmv(int taskId) { 
        taskRating[taskId] = INT_MIN; 
    }

    int execTop() {
        while(!pq.empty()){
            auto [priority,taskId]=pq.top();
            pq.pop();
            if(taskRating[taskId]==priority){
                taskRating[taskId]=INT_MIN;
                return taskUserId[taskId];
            }
        }
        return -1;
    }
};
