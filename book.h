#ifndef BOOK_H
#define BOOK_H

/*
    Book.h
    Author: M00738443
    Created: 14/03/2021
*/

#include <fstream>

class Book{
    private:
        int ISBN;
    
    public: 
        Book( char title, char author, 
                int quantity, int ISBN);

        Book();
        ~Book();
        int get_ISBN();
        void set_ISBN(int ISBN);
        void add_book();
};
void save_book();

#endif