int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    if(timeSeries.empty() || duration <= 0){
        return 0;
    }
    int times = duration;
    for(int i = timeSeries.size() - 1; i>=1; i--) {
        if(timeSeries[i]-duration >= timeSeries[i-1]) {
            times += duration;
        } else {
            times += timeSeries[i] - timeSeries[i-1];
        }
    }
    return times;
}