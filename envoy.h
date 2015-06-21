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
  * manage RPG Characters by implementing functions to 
  * recursively insert, retrieve, display, remove all 
  * matches by location, and remove all items.
  *
  * envoy.h module: includes an instance of a table
  * ADT for a binary search tree and instances of a
  * Character class object both used to call each ADT's
  * functions. The functions intercept the client program 
  * and the table ADT which call the public table and 
  * app_entry functions. 
  *
  */

#include "bst.h" // bst ADT header file
#include "character.h" // character class header file

// encapsulates all member functions and private data members
// utilized by the managing envoy program
class envoy
{
    public:
            envoy(void); // initializes data members
            ~envoy(void); // deletes dynamic memory

            //passes in temporary values from the client program to the BST create and insert functions 
            int create(char * a_name, char ** a_skills, char * a_arcana, int a_level, int a_skill_num);
            int display_all(); //calls the BST display_all() function
            int retrieve(char * a_skill); //
            int remove(char * a_skill); //

    private:
            table app_list; //creates an instance of the table class
            Character to_add, an_entry; //creates instances of the app_entry class

}; bool again(); //returns client's decision to continue entering apps 
