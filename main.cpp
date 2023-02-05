/*
    main.cpp
    Author: M00738443
    Created: 11/03/2021
*/
#include <iostream>
#include <ostream>
#include <fstream>
#include <string.h>
//#include "book.h"
/*
struct BOOK{
    char title;
    char author;
    int ISBN; 
    int qty;
};
struct BOOK book;

class book{
    friend ostream&
}
int main(){

    int option, n, count_n, qty;
    char title, author, data;
    std::string empty="";
    std::string ISBN="";

    std::ifstream f("Books");
    std::string line;

    for(int i=0; std::getline(f,line); ++i){
        count_n++;
    }

    while(option!=0){
        system("cls");
        std::cout<<"-----------        MAIN MENU       ----------" <<std::endl<<std::endl;
        std::cout<<"1. Add books"<<std::endl;
        std::cout<<"2. Delete books"<<std::endl;
        std::cout<<"3. Search book"<<std::endl;
        std::cout<<"4. View book list"<<std::endl;
        std::cout<<"5. Edit book record"<<std::endl;
        std::cout<<"6. Exit"<<std::endl;
        std::cin>>option;
        switch(option){
            case 1:
                //std::cout<<"adding a book"<<std::endl;
                //save_book();
                std::cout<<"how many books do you want to add? "<<std::endl;
                std::cin>>n;
                count_n=count_n+n;
                for(int i=0; i < n;i++){
                    std::ofstream outfile;
                    outfile.open("Books", std::ios::app);

                    std::cout<<"Title: ";
                    std::cin>>data;
                    outfile<<data<<"\t";

                    std::cout<<"Author: ";
                    std::cin>>data;
                    outfile<<data<<"\t";

                    std::cout<<"ISBN: ";
                    std::cin>>ISBN;
                    outfile<<ISBN<<"\t";

                    std::cout<<"Quantity: ";
                    std::cin>>empty;
                    outfile<<title<<"\t"<<author<<"\t"<<ISBN<<"\t"<<qty<<std::endl;
                }
                break;
            case 2:
                std::cout<<"deleting a book"<<std::endl;
                break;
            case 3:
                std::cout<<"Displaying book"<<std::endl;
                break;
            case 4:
                std::cout<<"Book list"<<std::endl;
                break;
            case 5:
                std::cout<<"Editing"<<std::endl;
                break;
            default:
                std::cout<<"Invalid"<<std::endl;
            
        }
    }
}
void addbook(){
    system("cls");
    std::fstream fp= fopen("books", std::ios::in);
    std::string line;
*/
class Book{
    public:
        int ISBN, quantity;
        char author[150], title[150];

        void add_book(){
            std::cout<<"Please enter the title of the book: "; 
            std::cin>>title;
            std::cout<<"Please enter the name of the author: ";
            std::cin>>author;
            std::cout<<"Please enter the quantity of the books: "; 
            std::cin>>quantity;
            std::cout<<"Please enter the Book ISBN: "; 
            std::cin>>ISBN;
        }

        void display_book(){
            std::cout<<"Title: "<<title<<std::endl;
            std::cout<<"Author: "<<author<<std::endl;
            std::cout<<"ISBN: "<<ISBN<<std::endl;
            std::cout<<"Quantity: "<<quantity<<std::endl;
        }
        
};

//binary tree
struct node {
    Book B;
    node *left;
    node *right;
};

class btree{
    public:
        btree();

        void insert(Book B, node *leaf);
        void insert(Book B);
        node *search(int ISBN, node* leaf);
        node *root;
        //void save(Book B, node *leaf);
        //void saveList(Book B, node *leaf, FILE *list);
};
btree::btree(){root=NULL;}

void btree::insert(Book B,node *leaf){
    if(B.ISBN<leaf->B.ISBN){
        if(leaf->left!=NULL){
            insert(B, leaf->left);
        }else{
            leaf->left= new node; 
            leaf->B= B;
            leaf->left->left= NULL;
            leaf->left->right= NULL; 
        }
    }
    if (B.ISBN>=leaf->B.ISBN) {
        if (leaf->right!=NULL)
            insert(B,leaf->right);
        else {
            leaf->right= new node;
            leaf->B=B;
            leaf->right->left=NULL;
            leaf->right->left=NULL;
            
        }
    }
}
node *btree::search(int ISBN, node *leaf)
{
    if(ISBN==leaf->B.ISBN) 
        return leaf;
    if(ISBN<leaf->B.ISBN) 
        return search(ISBN, leaf->left);
    else 
        return search(ISBN, leaf->right);
}
void btree::insert(class Book B) {
    if(root!=NULL) insert(B, root);
    else { root=new node;
        root->B=B;
        root->left=NULL;
        root->right=NULL;
    }
   // save(node* root);
}
/*
void btree::save(Book B,node *leaf){
    FILE *bookList;
    bookList=fopen("bookList","wb");
    saveList(leaf, bookList);
    fclose(bookList);
    return;
}

void saveList(Book B, node *leaf, FILE *bookList){
    if(leaf->node* left){
        saveList(leaf->node* left,bookList);
    }
    std::ofstream bookList;
    bookList.open("bookList", std::ios::out||std::ios::app);
    fwrite(leaf, sizeof(B), 1, bookList);
    bookList<<leaf->B.title<<"\t"<<leaf->B.author<<"\t"
        <<leaf->B.ISBN<<"\t"<<leaf->B.quantity<<"\n";
    std::cout<<"Storing data in database \n",leaf->B.title);
    if(leaf->node* right){
        saveList(leaf->node* right,bookList);
    }
    bookList.close();
}*/

//main function
int main(){
    int option;
    Book books[5000];
    btree booktree;
    std::ifstream FILE;
    FILE.open("bookList");
   //if(!FILE){
    //    std::cout<<"The file does not exist"<<std::endl;
    //};


    while(option!=6){
        std::cout<<"-----------        MAIN MENU       ----------"<<std::endl
            <<std::endl;
        std::cout<<"1. Add books"<<std::endl;
        std::cout<<"2. Delete books"<<std::endl;
        std::cout<<"3. Search book"<<std::endl;
        std::cout<<"4. View book list"<<std::endl;
        std::cout<<"5. Edit book record"<<std::endl;
        std::cout<<"6. Exit"<<std::endl;
        std::cin>>option;
        switch(option){
            case 1:{
                int n;
                std::cout<<"How many books do you want to add?";
                std::cin>>n;
                for(int i=0; i<n; i++){
                    books[i].add_book();
                    booktree.insert(books[i]);
                    std::cout<<std::endl;
                }
            }
                break;
            case 2:{
                std::cout<<"deleting";
            }break;
            case 3:{
                std::cout<<"searching";
            }break;
            case 4:{
                int ISBN ;
                std::cout<<"Enter the isbn of the book: "; 
                std::cin>>ISBN;
                node *bnode= booktree.search(ISBN, booktree.root);
            }break;
            case 5:{
                std::cout<<"editing";
            }break;
            default:{
                std::cout<<"Invalid command. Please try again."<<std::endl;
            
            }
        }
    }
}