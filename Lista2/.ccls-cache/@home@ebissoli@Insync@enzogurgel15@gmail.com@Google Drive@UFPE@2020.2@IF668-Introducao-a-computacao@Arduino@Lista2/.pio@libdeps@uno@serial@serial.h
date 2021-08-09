#ifndef MBED_SERIAL_H
#define MBED_SERIAL_H
 
#include "mbed.h"
 
class serial : public Serial
{
    public:
        serial(PinName p1, PinName p2, int *p) : Serial(p1,p2);
        void baud(int speed);
        void putdata(int data);
        void getdata();
      
    private:  
        int *pdata;
};
 
#endif