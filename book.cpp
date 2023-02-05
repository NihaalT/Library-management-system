/*
    Book.cpp
    Author: M00738443
    Created: 15/03/2021
*/
#include "book.h"
#include <sstream>

Book::Book(int id, char title, char author, 
                int quantity, int ISBN);
{
    this->ISBN=ISBN;
}

Book::Book(){
    ISBN="";
}

Book::~Book(){
    std::cout<<"de constructor: Book\n";
}

int Book::get_ISBN(){
    return this->ISBN;
}

void Book::set_ISBN(int ISBN){
    this->ISBN=ISBN;
}


void Book::add_book(){
    int ISBN, quantity;
    char title, author;
    
    std::cout<<"Book title: ";
    std::cin>> title;
    std::cout<<"Quantity: ";
    std::cin>> quantity;
    std::cout<<"Author: "
    std::cin>> author;
    //***********************
    std::cout<<"ISBN: ";
    std::cin>>ISBN;

    
    
}

Book books;
std::fstream File;
void save_book(){
    File.open("book", std::ios::out|std::ios::app);
    books.add_book();
    File.write<<title<<"\t"<<author<<"\t"<<ISBN<<"\t"<<quantity<<"\n";
    File.close();
    std::cout<<"\nBook: "<<title<< " saved successfully!\n\n";

}