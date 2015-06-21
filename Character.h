/**
  * app_entry.h
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
  * app_entry.h module: contains #includes for the 
  * cstring, cctype, and iostream libraries as well as
  * the APP definition for a class for an app entry. 
  * The app_entry class contains member function 
  * prototypes for a constructor, destructor, creating
  * a new entry, copying an entry, retrieving an entry 
  * based on keyword, and displaying an entry.
  *
  */

#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

#ifndef APP
#define APP
class app_entry //contains app member function prototypes and data members
{
    public:
            app_entry(void); //initializes data members
            ~app_entry(void); //destroys dynamic memory
	    int create(char * new_name, char ** new_keywords, char * new_descrip, int new_rating, int new_cat_num); //creates an entry from temp values
            int copy(const app_entry & new_entry, char ** & temp_keywords, int & temp_categories); //copies an entry from a temp struct
            int compare(const char * keyword, char * key); //returns whether a new entry's keyword is less than the current entry's keyword
            int retrieve(char * keyword_to_find, char * key); //finds a matching entry

            int display(void) const; //displays an entry

    private: 
            char * name; //name of the app
            char ** keywords; //list of category keywords
            char * descrip; //description of the app
            int rating; //rating for the app
            int categories; //number of categories entered
};
#endif

