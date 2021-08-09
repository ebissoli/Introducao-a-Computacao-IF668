#include "serial.h"
#include "mbed.h"

serial::serial(PinName p1, PinName p2, int *p) : Serial(p1,p2)
{
    pdata = p;
    Serial::baud(9600);
    Serial::attach(this, &serial::getdata, Serial::RxIrq);
}

void serial::baud(int speed)
{
    Serial::baud(speed);
}

void serial::putdata(int data)
{
    Serial::putc(data);
}

void serial::getdata()
{
    if(Serial::readable())
        *pdata = Serial::getc();
}