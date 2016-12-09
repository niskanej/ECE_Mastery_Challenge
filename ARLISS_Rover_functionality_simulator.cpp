//
//  ARLISS_Rover_functionality_simulator.cpp
//  
//
//  Created by Jon W. Niskanen on 12/3/16.
//
//The following program was primarily created to demonstrate the C++ level 2 Mastery Challenge.  The
//requirments for the challenge are listed below:
//Level: 2
//Write one or more programs that contain the following features:
//~Use of libraries-
//~Principles of Object Oriented Programming (OOP)-
//~Encapsulation-
//~Abstraction-
//~Inheritance-
//~Polymorphism-
//~Function overloading-
//~Class descriptions containing
//  >Constructor-
//  >Destructor-
//  >overloaded constructor-
//  >overloaded assignment operator-

#include <iostream>//use of a libraries
#include <cmath>
#include <stdlib.h>

using namespace std;

class data_frame{
    float time_of_measurement;
    float temperature;
    
    public:
    void set_time(float time);
    void set_temperature(float temp);
    int get_time();
    int get_temperature();
    int x_coordinate;
    int y_coordinate;
    
    data_frame();
    ~data_frame(){};//destructor
};


class InFlight_data_frame: public data_frame{
    private:
    int altitude;
    public:
    int get_altitude();
    void set_altitude(int alt);
    InFlight_data_frame();
    InFlight_data_frame(float time);//overloaded contructor
    ~InFlight_data_frame(){cout<<"deleting flight frame..."<<endl;};
    
    
};
class land_data_frame: public data_frame{//inheritance example
    
    
    
public:
    
    int get_x_coordinate();
    int get_y_coordinate();
    void set_x_coordinate(int x);
    void set_y_coordinate(int y);
    
    void operator = (InFlight_data_frame &frame){//operator overload
        
        set_temperature(frame.get_temperature());
        set_time(frame.get_time());
    }

    
};

//Constructor
data_frame::data_frame(){
    set_time(0);
}

InFlight_data_frame::InFlight_data_frame(float t){
    set_time(t);
}


//setters
void data_frame::set_time(float time){time_of_measurement=time;}
void data_frame::set_temperature(float temp){temperature=temp;}
void land_data_frame::set_x_coordinate(int x){x_coordinate=x;}
void land_data_frame::set_y_coordinate(int y){y_coordinate=y;}
void InFlight_data_frame::set_altitude(int alt){altitude=alt;}

//getters
int data_frame::get_time(){return time_of_measurement;}
int data_frame::get_temperature(){return temperature;}
int land_data_frame::get_x_coordinate(){return x_coordinate;}
int land_data_frame::get_y_coordinate(){return y_coordinate;}
int InFlight_data_frame::get_altitude(){return altitude;}

void transmit_data_frame(InFlight_data_frame *frame_to_send);
void collect_data(data_frame *frame_to_send);
void transmit_data_frame(data_frame *frame_to_send);
void pause();
int main(){
    InFlight_data_frame airframe = InFlight_data_frame(200);
    InFlight_data_frame *aframe;
    aframe =&airframe;
    for(int i=0; i<=10;i++){
        collect_data(aframe);
        transmit_data_frame(aframe);
        pause();
    }
    cout<<"system land"<<endl;
    land_data_frame frame;
    frame = airframe;//makes use of operator overload to transfer time air data to land frames
    airframe.~InFlight_data_frame();
    int inf_loop=1;
    data_frame *pframe;
    pframe = &frame;//polymorphism data_frame pointer pointing to land_data class instance
    while(inf_loop==1){
    collect_data(pframe);
    transmit_data_frame(pframe);
        pause();
    }
    return 0;
}
void collect_data(data_frame *frame_to_send){
    float t = rand()%110+60;
    frame_to_send->set_temperature(t);
    t=frame_to_send->get_time()+1;
    frame_to_send->set_time(t);
}
void transmit_data_frame(data_frame *frame_to_send){
    cout<<"Surface Temp: "<<frame_to_send->get_temperature()<<endl;
    cout<<"t = "<<frame_to_send->get_time()<<endl;
}
void transmit_data_frame(InFlight_data_frame *frame_to_send){
    cout<<"air Temp: "<<frame_to_send->get_temperature()<<endl;
    cout<<"t = "<<frame_to_send->get_time()<<endl;
}
void pause(){
    int i,j,k,wait;
    for(i=0;i<=1000;i++){
        for(j=0;j<=1000;j++){
            for(k=0;k<=100;k++){
                wait=wait+1;
            }
        }
    }

}
