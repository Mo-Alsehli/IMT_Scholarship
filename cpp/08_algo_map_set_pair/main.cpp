#include <iostream>
#include <vector>
#include "car_parking_project.cpp"


int main() {
    init_spots();

    enter_parking("ABC123", 00, 8, "REGULAR");
    enter_parking("ABC124", 1, 5, "REGULAR");
    enter_parking("ABC125", 1, 8, "REGULAR");
    enter_parking("ABC126", 2, 9, "VIP");
    enter_parking("ABC127", 2, 19, "VIP");
    enter_parking("ABC128", 3, 25, "REGULAR");
    enter_parking("ABC129", 12, 10, "REGULAR");
    enter_parking("ABC130", 13, 10, "REGULAR");
    enter_parking("ABC131", 14, 11, "REGULAR");
    enter_parking("ABC132", 15, 15, "DISABLED");
    
    
    exit_parking("ABC123", 02, 12);
    
    enter_parking("ABC123", 16, 8, "REGULAR");

    exit_parking("ABC123", 18, 0);
    exit_parking("ABC124", 19, 0);
    exit_parking("ABC125", 20, 0);
    exit_parking("ABC127", 21, 0);

    show_spots();

    find_car("ABC123");
    find_car("ABC132");

    show_parking_cars();

    show_car_history("ABC123");

    show_daily_report();


}