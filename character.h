/**
  * character.h
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
  * Character.h module: contains #include files for 
  * csstdlib, cstring, cctype, and iostream, as well as 
  * definition for a CHARACTER. Also holds prototypes for
  * a constructor,destructor, public member functions for 
  * creating a new character, copying a character, 
  * retrieving a character based on skill, and displaying 
  * a character and private member variables for a character's
  * name, skills, arcana, level, and number of skills entered.
  *
  */

#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

#ifndef CHARACTER
#define CHARACTER
class Character //contains character member function prototypes and data members
{
    public:
            Character(void); //initializes data members
            ~Character(void); //destroys dynamic memory
	    int create(char * new_name, char ** new_skills, char * new_arcana, int new_level, int new_skills_num); //creates an entry from temp values
            int copy(const Character & new_character, char ** & temp_skills, int & temp_num_skills); //copies a character from a temp struct
            int compare(const char * skill, char * key); //returns whether a new character's keyword is less than the current character's keyword
            int retrieve(char * skill_to_find, char * key); //finds matching character by skill

            int display(void) const; //displays a character

    private: 
            char * name; //name of the character
            char ** skills; //list of skills
            char * arcana; //arcana character belongs to
            int level; //rating for the app
            int num_skills; //number of skills entered
};
#endif

