#include <iostream>

/*
** Trafic Light
*** Timer cycling.
*** red 30 sec
*** green 60 sec
*** yellow 10 sec
*/

class CTimer {
    public:
    CTimer(): counter(0) {};

    void start_timer(int period){
        for(int i = 0; i < period; i++){
            counter++;
        }
    }

    int get_counter() const {
        return counter;
    }

    private:
    int counter;
};


class CTrafficLight {
    public:
        void traffic_light_start() {
            timer.start_timer(30000000);
            state = "RED";
            std::cout << "[" << state << "]" << std::endl;

            timer.start_timer(60000000);
            state = "GREEN";
            std::cout << "[" << state << "]" << std::endl;

            timer.start_timer(10000000);
            state = "YELLOW";
            std::cout << "[" << state << "]" << std::endl;
        }


    private:
        std::string state;
        int time;
        CTimer timer;
};