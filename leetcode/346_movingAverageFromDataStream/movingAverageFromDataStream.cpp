class MovingAverage {
public:
    int window;
    int sum;
    queue<int> q;
    MovingAverage(int size) {
        window = size;
        sum = 0;
    }

    double next(int val) {
        if (q.size() == window) {
            sum -= q.front();
            q.pop();
        }

        q.push(val);
        sum += val;

        return sum / (double)q.size();
    }
};
