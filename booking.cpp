#include <iostream>
#include "booking.h"
#include "deluxeroom.h"
#include "suiteroom.h"

using namespace std;

booking::booking(int _size)
{
    size = _size;
    guests = 0;
    reservationsBooked = new  normalroom [size];
}
booking::booking(const booking& obj)
{
    size = obj.size;
    guests = obj.guests;
    reservationsBooked = new normalroom[size];
    for(int i =0;i < guests;i++)
    {
        reservationsBooked[i] = obj.reservationsBooked[i];
    }
}
booking & booking::operator = (const booking& RHS)
{
    if(this != &RHS)
    {
        size = RHS.size;
        guests = RHS.guests;
        if(reservationsBooked != nullptr)
        {
            delete[] reservationsBooked;
            reservationsBooked = nullptr;
        }
            reservationsBooked = new normalroom [size];
        for(int i =0;i < guests;i++)
        {
            reservationsBooked[i] = RHS.reservationsBooked[i];
        }
    }
    return *this;
}
booking::~booking()
{
    if(reservationsBooked != nullptr)
    {
        delete [] reservationsBooked;
        reservationsBooked = nullptr;
    }
}
int booking::getSize() const
{
    return size;
}
int booking::getGuests() const
{
    return guests;
}
bool booking::addBooking(const room &B) 
{
    if(guests = size)
    {
        return false;
    }
    if(guests < size)
    {
        if(B.getType() == "Normal-room")
        {
            reservationsBooked[guests] = B;
            guests++;
            return true;
        }
        if(B.getType() == "Deluxe-room")
        {
            reservationsBooked[guests] =  B;
            guests++;
            return true;
        }        
        else
        {
            reservationsBooked[guests] =  B;
            guests++;
            return true;
        }
    }
}
/*void booking::printBookings(const room&B)
  {
    for(int i =0; i < guests;i++)
    {
        cout << reservationsBooked[i].getRoomNum() << endl;
    }
  }*/
