#include <iostream>
#include "guest.h"
#include "room.h"
#include "normalroom.h"
#include "booking.h"
#include "booking.cpp"
#include <fstream>

using namespace std;

int main()
{
    
    //member variables
    int choice;
    string guestName;
    string guestPhoneNumber;
    string guestDates;
    string guestRoomType;
    string guestRequests;
    int guestRoom;
    double guestPrice;

    //file variables
    ofstream fileOut;
    ifstream fileIn;
    string guestTxt;

    //complex variables
    guest guestInfo;
    normalroom roomInfo1;
    suiteroom roomInfo3;
    deluxeroom roomInfo2;
    booking guestBook(44);
    do
    {
    //menu loaded up
    cout << "Welcome to the Hotel Mangement System" << endl;
    cout << "1. Check-in Guest" << endl;
    cout << "2. Check-out Guest" << endl;
    cout << "3. View Guest Booking Info" << endl;
    cout << "4. Exit" << endl;
    cout << "Option: ";
    cin >> choice;
    switch(choice)
    {
        case 1: 
            cout << "Insert Guest Info:" << endl << endl << "Guest Name: ";
            //enter guest information
            cin.ignore();
            getline(cin, guestName);
            guestInfo.setName(guestName);
            cout << "Guest Phone Number: ";
            cin >> guestPhoneNumber;
            guestInfo.setPhoneNum(guestPhoneNumber);
            cout << "Guest Booking Dates: ";
            cin.ignore();
            getline(cin, guestDates);
            guestInfo.setBookingDate(guestDates);
            cout << "Guest Room Type: (N, D, S) ";
            getline(cin, guestRoomType);
            guestInfo.setRoomType(guestRoomType);
            cout << "Guest Request: ";
            
            getline(cin, guestRequests);
            cout << endl;
            guestInfo.setSpecial(guestRequests);
            
            cout << "Choose a room that is availaible: " << endl;

            if(guestInfo.getRoomType() == "N") //normalroom info
            {
                roomInfo1.printAvailableRooms();
                cin >> guestRoom;
                roomInfo1.setRoomNum(guestRoom);
                roomInfo1.setPrice(320.19);
                roomInfo1.setRoomAvailability(guestRoom);
                guestBook.addBooking(roomInfo1); //use inheritance/polymorphism for function parameter
                
            }
            else if(guestInfo.getRoomType() == "D")//deluxeroom info
            {
                roomInfo2.printAvailableRooms();
                cin >> guestRoom;
                roomInfo2.setRoomNum(guestRoom);
                roomInfo2.setPrice(320.29);
                roomInfo2.setRoomAvailability(guestRoom);
                roomInfo2.setGuestPool('Y');
                guestBook.addBooking(roomInfo2);//use inheritance/polymorphism for function parameter
            }
            else if(guestInfo.getRoomType() == "S")//suiteroom info
            {
                roomInfo3.printAvailableRooms();
                cin >> guestRoom;
                roomInfo3.setRoomNum(guestRoom);
                roomInfo3.setPrice(520.39);
                roomInfo3.setRoomAvailability(guestRoom);
                roomInfo3.setGuestPool('Y');
                roomInfo3.setGuestService('Y');
                guestBook.addBooking(roomInfo3);//use inheritance/polymorphism for function parameter
            }
            cout << "Saving changes... " << endl << endl;
            //save info into its own file
            fileOut.open(guestInfo.getName());
            fileOut << "Guest Name: " << guestInfo.getName() << endl << "Guest Phone Number " << guestInfo.getPhoneNum() << endl << "Guest Booking Dates: " << guestInfo.getBookingDate() << endl << "Guest Requests: " << guestInfo.getSpecial() << endl;
            if(guestInfo.getRoomType() == "N")
            {
                fileOut << "Guest Room Number: " << to_string(roomInfo1.getRoomNum()) << endl << "Guest Price Payment: " << to_string(roomInfo1.getPrice()) << endl << "Roomtype: Normal room";
            }
            else if(guestInfo.getRoomType() == "D")
            {
                fileOut << "Guest Room Number: " << to_string(roomInfo2.getRoomNum()) << endl << "Guest Price Payment: " << to_string(roomInfo2.getPrice()) << endl << "Room type: Deluxe room" << endl << "Pool Access: " << roomInfo2.getGuestPool() << endl;
            }
            else if(guestInfo.getRoomType() == "S")
            {
                fileOut << "Guest Room Number: " << to_string(roomInfo3.getRoomNum()) << endl << "Guest Price Payment: " << to_string(roomInfo3.getPrice()) << endl << "Room type: Suite room" << endl << "Pool access: " << roomInfo3.getGuestPool() << endl << "Requires room service: " << roomInfo3.getGuestService() << endl;
            }
            fileOut.close();

            break;
        case 2:
            cout << "Which guest would like to check out?" << endl; 
            cin.ignore();
            getline(cin, guestName);
            guestInfo.setName(guestName);
            cout << "Have a nice day!" << endl << endl;
            //manually delete file from system
            //wanted it to print booking info dynamic array of roomNumbers being used
            break;
        case 3:
            cout << endl << "Enter guest file (First and Last): " << endl;
            cin.ignore();
            getline(cin, guestTxt); //get file of person info
            fileIn.open(guestTxt);
            while(getline(fileIn, guestTxt)) //print out info
            {
                cout << guestTxt << endl;
            }
            fileIn.close();
            cout << endl;
            break;
        case 4:
            cout << "You have exited"; //exit out of menu
            break;
    }
    }
    while(choice <= 3);

    return 0;
}