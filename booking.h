#ifndef BOOKING_H
#define BOOKING_H
#include "guest.h"
#include "normalroom.h"
#include <string>
using namespace std;


class booking
{
    private:
        room *reservationsBooked;
        int size;
        int guests;

    public:
        booking(int _size);
        booking(const booking& obj);
        booking & operator = (const booking& RHS);
        ~booking();
        int getSize() const;
        int getGuests() const;
        bool addBooking(const room &B);
        //void printBookings(const room&B);
        //bool deleteBooking(normalRoom &B);
        
};
        
#endif