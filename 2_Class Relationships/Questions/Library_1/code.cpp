/*
Problem: Library Management System (Beginner Version)
Goal
Design a basic Library Management System that allows:

Adding books
Registering members
Borrowing and returning books

Requirements
1. Book
Each book has:
bookId (unique)
title
author
isAvailable (boolean — whether book is currently borrowed or not)

2. Member
Each member has:
memberId (unique)
name
List of books currently borrowed

3. Library
Should be able to:
Add a new book
Register a new member
Borrow a book (if available)
Return a book

4. Constraints
A member can borrow at most 3 books at a time.
A book that’s already borrowed cannot be borrowed again until it’s returned.

*/
#include<bits/stdc++.h>
using namespace std;
class Book{
    private: 
    int bookId; 
    string title; 
    string author; 
    bool isAvailable; 

    public:
    bool checkAvailable(){
        return this->isAvailable;
    }
    void markBorrowed(){
        this->isAvailable = false; 
    }
    void markUnborrowed(){
        this->isAvailable = true; 
    }
    int getBookId(){
        return this->bookId; 
    }
};
class Member{
    private:
    int memberId; 
    string name; 
    vector<Book*>borrowedBooks; 

    public: 
    void addBook(Book* book){
        borrowedBooks.emplace_back(book);
    }
    void removeBook(Book* book){
        auto idx = find(borrowedBooks.begin(),borrowedBooks.end(),book);
        borrowedBooks.erase(idx); 
    }
    bool exceedsCount(){
        return borrowedBooks.size()>3; 
    }
    int getMemberId(){
        return this->memberId; 
    }
    string getName(){
        return this->name; 
    }
};
class Library{
    private: 
    vector<Book*>books; 
    vector<Member*>members; 

    public: 
    void addBook(Book* book){
        this->books.emplace_back(book); 
    }
    void addMember(Member*member){
        this->members.emplace_back(member); 
    }
    bool existsBook(Book *book){
        for (auto &it:books){
            if (it->getBookId()==book->getBookId()){
                return true;
            }
        }
        return false; 
    }
    bool existsMember(Member* member){
        for (auto &it:members){
            if (it->getMemberId()==member->getMemberId()){
                return true;
            }
        }
        return false; 
    }
    void borrowBook(Member *member, Book* book){
        if (!existsMember(member)){
            cout << "No such member exists" << endl; 
            return ; 
        }
        if (!existsBook(book)){
            cout << "No such book exists" << endl; 
            return ;
        }
      
        if (!member->exceedsCount()){
            if (book->checkAvailable()){
                member->addBook(book);
                book->markBorrowed(); 
            }
            else{
                cout << "Already borrowed" << endl; 
            }
        }
        else{
            cout << "The member: " << member->getName() << "cannot borrow more than 3 books" << endl; 
        }            
    }
    void returnBook(Member *member, Book* book){
        member->removeBook(book); 
        book->markUnborrowed();                  
    }
};
int main(){
    
    return 0;
}