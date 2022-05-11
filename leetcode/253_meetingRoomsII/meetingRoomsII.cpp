class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
      if (intervals.size() == 1) {
          return 1;
      }
      int rooms = 1;
      sort(intervals.begin(), intervals.end());
      priority_queue<int, vector<int>, greater<int>> pq;
      for(int i = 0; i < intervals.size(); i++) {
          //while the queue is not empty and the
          //top value(lowest interval time) is less than the new start time
          //pop the queue since the rooms are open again.
          while(!pq.empty() && pq.top() <= intervals[i][0]) pq.pop();
            //now add the new end time to the priority_queue
            pq.push(intervals[i][1]);
            //find out if the max number of rooms taken(queue size)
            //is bigger than the previous and update rooms if so
            rooms = max(rooms, (int)pq.size());
      }
        return rooms;
    }
};
