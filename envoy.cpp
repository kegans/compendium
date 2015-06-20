/**
  * envoy.cpp
  *
  * Character-Lexicon
  * 6.20.2015
  *
  * Kegan Sanchez
  * kegan.sanchez@gmail.com
  * 
  * Character-Lexicon: Creates a binary search tree ADT to 
  * manage mobile apps by implementing functions to 
  * recursively insert, retrieve, display, remove all 
  * matches by location, and remove all items.
  *
  * envoy.cpp module: implements the envoy.h member 
  * functions which call functions from the app_entry
  * and table ADTs.
  *
  */

#include "envoy.h"

envoy::envoy(){}

envoy::~envoy(){}

// calls the app_entry function to create an entry with data sized just right
int envoy::create(char * a_name, char ** a_keywords, char * a_descrip, int a_rating, int a_cat_num)
{
    if(!to_add.create(a_name, a_keywords, a_descrip, a_rating, a_cat_num))
        return 0;
    
    if(!app_list.insert(to_add))
        return 0;

    return 1;
}

//calls the bst.cpp function that displays all apps in the BST in order
int envoy::display_all()
{
    return app_list.display_all(); // returns the success/failure of the BST function
}

// returns client's decision to continue entering apps
bool again()
{

    char response; //variable for client's response

    //asks client if they want to enter again
    cout << "Would you like to enter again ? (Y/N): ";
    cin >> response; //retrieves client's response
    cin.ignore(100, '\n');

    response = toupper(response); //converts response to uppercase 

    if('Y' == response) //returns true if client enters yes/Y
        return true;

    return false; //otherwise, returns false

}

//calls the BST wrapper function to retrieve and
//display an entry based on keyword
int envoy::retrieve(char * a_keyword)
{
    //returns success/failure of the BST retrieval function
    return app_list.retrieve(a_keyword, an_entry);
}

//calls the BST wrapper funcion to remove
//an entry based on keyword
int envoy::remove(char * a_keyword)
{
    //returns success/failure of the BST removal function
    return app_list.remove(a_keyword);
} 
