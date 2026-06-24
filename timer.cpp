#include <iostream>
#include <ctime>
#include "timer.hpp"

void Timer::startTimer(){
    time(&startTime);
}

void Timer::endTimer(){
    if(startTime == 0){
        std::cout << "error: タイマーをスタートさせてから終了させてください" << std::endl;
        exit(1);
    }

    time(&endTime);

    std::cout << "計算時間: " << difftime(endTime, startTime) << "秒" << std::endl;
}