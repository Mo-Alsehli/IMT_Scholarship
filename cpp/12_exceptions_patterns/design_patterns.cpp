#include<iostream>

/*
* Design Patterns
** Behavioral State Machine
** Behavioral Observer
** Creational Factory
** Creational Singleton

** State Machine Pattern
*** This pattern consists of a set of states.
*** We can describe the state by behaviour or variables.
*** The relationship between states is called Transitions.
*** The condition that causes the transition is called Guard Condition or Event.
*** There are Entry and Exit actions that can happen at the time of entry and exit.
*** We have to define the Start(Initial) State for the system.
*/ 

class CATMState {
    public:
        virtual void on_triggered(CATMContext& context) = 0;
    
    private:
        std::string state;
};


class CATMContext {
    public:
    void set_state(CATMState state) {
        m_current_state = state;
    }


    private:
        CATMState m_current_state;
};

class CIdleState {
    public:
        void on_triggered() {
            
        }

    private:
        std::string state = "IDLE";
};