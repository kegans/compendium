/**
  * envoy.h
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
  * envoy.h module: includes an instance of a table
  * ADT for a binary search tree and instances of an
  * app_entry class object both used to call each ADT's
  * functions. The functions intercept the client program 
  * and the table ADT which call the public table and 
  * app_entry functions. 
  *
  */

#include "bst.h"
#include "app_entry.h"

class envoy
{
    public:
            envoy(void); // initializes data members
            ~envoy(void); // deletes dynamic memory

            //passes in temporary values from the client program to the BST create and insert functions 
            int create(char * a_name, char ** a_keywords, char * a_descrip, int a_rating, int a_cat_num);
            int display_all(); //calls the BST display_all() function
            int retrieve(char * a_keyword); //
            int remove(char * a_keyword); //

    private:
            table app_list; //creates an instance of the table class
            app_entry to_add, an_entry; //creates instances of the app_entry class

}; bool again(); //returns client's decision to continue entering apps 
