#include <iostream>
#include "error_handling.cpp"
#include "traffic_light.cpp"



int main(){
    // check_file_exist("no.txt");

    CTrafficLight tf;

    while(1){
        tf.traffic_light_start();
    }

    return 0;
}