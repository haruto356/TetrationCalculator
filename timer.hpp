#include <ctime>
class Timer{
    private:
    time_t startTime = 0, endTime;

    public:
    void startTimer();
    void endTimer();
};