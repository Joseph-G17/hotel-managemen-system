#ifndef GUEST_H
#define GUEST_H
#include <string>

using namespace std;

class guest
{
    private:
        string name;
        string phoneNum;
        string bookingDate;
        string roomType;
        string special;


    public:
        guest()
        {
            name = "";
            phoneNum = "";
            bookingDate = "";
            roomType = "";
            special = "";
        }
        guest(const string  _name, const string _phoneNum, const string _bookingDate, const string _roomType, const string _special)
        {
            name = _name;
            phoneNum = _phoneNum;
            bookingDate = _bookingDate;
            roomType = _roomType;
            special = _special;
        }
        string getName() {return name;}
        string getPhoneNum() {return phoneNum;}
        string getBookingDate() {return bookingDate;}
        string getRoomType() {return roomType;}
        string getSpecial() {return special;}
        void setName(string _name) {name = _name;}
        void setPhoneNum(string _phoneNum) {phoneNum = _phoneNum;}
        void setBookingDate(string _bookingDate) {bookingDate = _bookingDate;}
        void setRoomType(string _roomType) {roomType = _roomType;}
        void setSpecial(string _special) {special = _special;}
};  

#endif