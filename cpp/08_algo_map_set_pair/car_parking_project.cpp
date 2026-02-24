#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

const double RATE_REGULAR = 5.0;
const double RATE_VIP = 10.0;
const double RATE_DISABLED = 0.0;
const int TOTAL_SPOTS = 20;
const double MIN_CHARGE = 5.0;

struct SParkingSession {
    std::string plate;
    int spot_number;
    int entry_hour;
    int entry_min;
    std::string spot_type;
};

struct SReceipt {
    std::string plate;
    int spot_number;
    std::string entry_time;
    std::string exit_time;
    double duration;
    double total_cost;
};

std::map<std::string, SParkingSession> active_sessions;
std::map<std::string, std::vector<SReceipt>> history;
std::map<int, bool> spots;
std::map<int, std::string> spot_type;
std::map<int, int> hourly_traffic;
double total_revenue;

// helper for printing receipt
void print_receipt(const SReceipt r){
    std::cout << "<=========== RECEIPT FOR PLATE " << r.plate << "=============>" <<std::endl;
    std::cout << "             Entry Time: " << r.entry_time << std::endl;
    std::cout << "             Exit Time: " << r.exit_time << std::endl;
    std::cout << "             duration: " << r.duration << std::endl;
    std::cout << "             total_cost: " << r.total_cost<< std::endl;
    std::cout << std::endl;
}

// helper for printing session
void print_session(const SParkingSession s){
    std::cout << "<=========== SESSION FOR PLATE " << s.plate << "=============>" <<std::endl;
    std::cout << "             Entry Hour: " << s.entry_hour << std::endl;
    std::cout << "             SPOT NO: " << s.spot_number << std::endl;
    std::cout << "             SPOT Type: " << s.spot_type << std::endl;
    std::cout << std::endl;
}

std::string format_time(int hour, int minute) {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << hour << ":" << std::setfill('0') << std::setw(2) << minute;

    return ss.str();
}

double get_rate(std::string spot_type) {
    if (spot_type == "VIP") {
        return RATE_VIP;
    } else if (spot_type == "DISABLED") {
        return RATE_DISABLED;
    } else {
        return RATE_REGULAR;
    }
}

void init_spots() {
    for (int i = 1; i <= 15; i++) {
        spot_type.insert({i, "REGULAR"});
        spots.insert({i, true});
    }

    for (int i = 16; i <= 18; i++) {
        spot_type.insert({i, "VIP"});
        spots.insert({i, true});
    }

    for (int i = 19; i <= 20; i++) {
        spot_type.insert({i, "DISABLED"});
        spots.insert({i, true});
    }
}

bool enter_parking(std::string plate, int hour, int minute, std::string prefered_type = "REGULAR") {
    // ensure that care isn't already parking.
    if (active_sessions.count(plate)) {
        std::cout << "[WARNING] " << plate << "Already Parking" << std::endl;
        return false;
    }

    // find an available place with the prefered_type.
    // if prefered_type doesn't
    int available_spot = -1;
    for (auto spot : spot_type) {
        if (spot.second == prefered_type) {
            available_spot = spot.first;

            if(spots[available_spot] == true)
                break;
        }
    }

    if (available_spot == -1) {
        return false;
    } else {
        spots[available_spot] = false;
    }

    SParkingSession session;

    session.plate = plate;
    session.spot_number = available_spot;
    session.spot_type = prefered_type;
    session.entry_hour = hour;
    session.entry_min = minute;

    active_sessions[plate] = session;
    hourly_traffic[hour]++;

    std::cout << "[IN] " << plate << "-> spot " << available_spot << " " << prefered_type << " @ " << format_time(hour, minute)
              << std::endl;

    return true;
}

bool exit_parking(std::string plate, int exit_hour, int exit_min) {
    // ensure car is already parking
    if (!active_sessions.count(plate)) {
        std::cout << "Car with plate: " << plate << " Isn't parking" << std::endl;
        return false;
    }

    // retrieve session info
    SParkingSession& session = active_sessions[plate];

    // calculate cost
    // calculate duration in minutes
    int entryTotal = session.entry_hour * 60 + session.entry_min;
    int exitTotal = exit_hour * 60 + exit_min;
    int durationMin = exitTotal - entryTotal;

    // handle overnight parking
    if (durationMin < 0) durationMin += 24 * 60;

    double durationHours = durationMin / 60.0;

    // calculate cost
    double rate = get_rate(session.spot_type);
    double cost = durationHours * rate;

    // apply minimum charge (except for disabled spots)
    if (session.spot_type != "DISABLED") cost = std::max(cost, MIN_CHARGE);

    // round to nearest 0.5 EGP
    cost = std::round(cost * 2) / 2.0;

    SReceipt receipt;
 
    receipt.plate = plate;
    receipt.spot_number = session.spot_number;
    receipt.entry_time = format_time(session.entry_hour, session.entry_min);
    receipt.exit_time = format_time(exit_hour, exit_min);
    receipt.duration = durationHours;
    receipt.total_cost = cost;

    history[plate].push_back(receipt);
    total_revenue += cost;
    spots[session.spot_number] = true;
    active_sessions.erase(plate);

    std::cout << "Car Exited Successfully" << std::endl;
    std::cout << "[RECEIPT] " << plate << "\n"

              << std::string(35, '-') << "\n"

              << "  Spot     : " << receipt.spot_number

              << " (" << session.spot_type << ")\n"

              << "  Entry    : " << receipt.entry_time << "\n"

              << "  Exit     : " << receipt.exit_time << "\n"

              << "  Duration : " << std::fixed << std::setprecision(1)

              << durationHours << " hrs\n"

              << "  Rate     : " << rate << " EGP/hr\n"

              << "  Total    : " << cost << " EGP\n"

              << std::string(35, '-') << "\n\n";


    return true;
}


void show_spots(){
    std::cout << std::string(100, '-') << std::endl;
    std::cout << " SHOW SPOTS " << std::endl;
    std::cout << std::string(100, '-') << std::endl;
    
    for(auto spot: spots)
    {
        int spot_num = spot.first;
        bool is_available = spot.second;
        std::string status = is_available ? "Free" : "Busy";
        std::cout << " SPOT" << std::setw(2) << spot_num << "[ " << std::setw(8) << 
        spot_type[spot_num] << "[" << status << "]" << std::endl;
    }
    
    std::cout << "<================ OCCUPIED SPOTS ===================>" << std::endl;
    for(auto session: active_sessions){
        std::cout << "SPOT [" << session.second.spot_number << "] TYPE [" << session.second.spot_type << 
        "] PLATE [" << session.second.plate << "]" << std::endl; 
    }
    
}


void find_car(std::string plate){
    if(!active_sessions.count(plate) && !history.count(plate)){
        std::cout << "Couldn't find car with plate " << plate << std::endl;
    }

    std::cout << std::string(100, '-') << std::endl;
    std::cout << "FIND CAR" << std::endl;
    std::cout << std::string(100, '-') << std::endl;

    if(active_sessions.count(plate)){
        SParkingSession& session = active_sessions[plate];

        std::cout << "CAR Found IN Parking :) " << std::endl;
        std::cout << "Plate: " << plate << " | " << "Entry hour: " << 
        session.entry_hour << " | " << "Spot Number: " << session.spot_number << std::endl << std::endl;

        return;
    }

    if(history.count(plate)){
        std::cout << "<============ FOUND PLATE " << plate << " HISTORY ============>" << std::endl;
        for(auto receipt: history[plate]){
            print_receipt(receipt);
        }
    }

    std::cout << std::endl;
}


void show_parking_cars(){

    std::cout << std::string(100, '-') << std::endl;
    std::cout << "SHOW PARKING CARS" << std::endl;
    std::cout << std::string(100, '-') << std::endl;

    for(auto session: active_sessions){
        print_session(session.second);
    }

    std::cout << std::endl;
}


void show_car_history(std::string plate){
    if(!history.count(plate)){
        std::cout << "There is no HISTORY for plate: " << plate << std::endl;
        return;
    }


    std::cout << std::string(100, '-') << std::endl;
    std::cout << "CAR HISTORY" << std::endl;
    std::cout << std::string(100, '-') << std::endl;

    std::cout << std::string(20, '=') << " Car with Plate: " << plate <<  " HISTORY " << std::string(20, '=') << std::endl;
    for(auto receipt: history[plate]){
        print_receipt(receipt);
    }

    std::cout << std::endl;
}


void show_daily_report(){
    std::cout << std::string(100, '-') << std::endl;
    std::cout << " DAILY REPORT " << std::endl;
    std::cout << std::string(100, '-') << std::endl;
    
    
    std::cout << std::string(50, '=') << std::endl;
    std::cout << "Cars Inside Parking" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    for(auto session: active_sessions){
        print_session(session.second);
    }
    
    std::cout << std::string(50, '=') << std::endl;
    std::cout << " Cars Exited Parking " << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    for(auto pair: history){
        for(auto receipt: history[pair.first]){
            print_receipt(receipt);
        }
    }

    std::cout << std::endl;
}