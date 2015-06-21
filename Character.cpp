/**
  * character.cpp
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
  * Character.cpp module: initializes private member
  * variables through the constructor, deletes dynamic
  * memory through the destructor, and implementation
  * for member functions that create a new character, 
  * copy a character, retrieve a character based on skill, 
  * and display a character.
  *
  */

#include "character.h"

//initializes Character data members
Character::Character()
{
    name = NULL; //name of a character
    skills = NULL; //list of skills
    arcana = NULL; //arcana a character belongs to
    level = 0; //level for a character
    num_skills = 0; //number of skills
}

//destroys all allocated memory
Character::~Character()
{
    if(name) //delete allocated memory for name
        delete[]name;
    if(arcana) //delete allocated memory for arcana
        delete[]arcana;
    
    if(skills) //delete allocated memory for skills
    {
        for(int i = 0; i < num_skills; ++i)
        {
            delete [] skills[i]; //delete each skill
        }
    
        delete [] skills; //delete the entire array of pointers
    }
    
    //set everything to NULL to avoid segmentation faults
    name = NULL; 
    arcana = NULL;
    skills = NULL;
    level = 0;
}

//creates a new character based on temp values from the client program
int Character::create(char * new_name, char ** new_skills, char * new_arcana, int new_level, int new_skills_num)
{
    if(!new_name || !new_arcana || !new_level) return 0; //if values are NULL, return failure

    if(name) //if name is already pointing to something
    {
        delete [] name; //delete name and set to NULL
        name = NULL;
    }
    name = new char[strlen(new_name)+1]; //create new name char
    strcpy(name, new_name); //copy information into name

    /*if(skills) // if skills is already pointing to something
    {
        for(int i = 0; skills[i] != NULL; ++i) // for each element, delete the data
        {
            delete [] skills[i];
        }
        
        delete [] skills; // delete the entire array of pointers
    }*/
    
    num_skills = new_skills_num; //set the member variable to the number of elements

    skills = new char*[num_skills]; //create a new array of pointers 
    for(int j = 0; j < num_skills; ++j) //for every element in the array
    {
        skills[j] = new char[strlen(new_skills[j])+1]; //create a new char
        strcpy(skills[j], new_skills[j]); //copy the data over
    }
    if(arcana) //if arcana is already pointing to something
    {
        delete [] arcana; //delete arcana and set it to NULL
        arcana = NULL;
    }
    arcana = new char[strlen(new_arcana)+1]; //create a new char
    strcpy(arcana, new_arcana); //copy the data over

    level = new_level; //set the member variable to the new temp value

    return 1;
}
//copies a data into a struct as well as temp data members for a node in a LLL of structs
int Character::copy(const Character & new_character, char **& temp_skills, int &temp_num_skills)
{
    //if either of the variables are NULL, return failure
    if(!new_character.name || !new_character.skills || !new_character.arcana || !new_character.level) return 0;

    if(name) //if name is already pointing to something
    {
        delete [] name; //delete name and set it to NULL
        name = NULL;
    }

    /*if(skills) //if skills is already pointing to something
    {
        for(int i = 0; skills[i] != NULL; ++i) // for every element in the array
        {

            delete [] skills[i]; // delete each item being pointed to
        }
        
        delete [] skills; // delete the entire array
        skills = NULL; // set the array pointer to NULL
    }*/

    if(arcana) //if arcana is already pointing to something
    {
        delete [] arcana; //delete arcana and set it to NULL
        arcana = NULL;
    }

    name = new char[strlen(new_character.name)+1]; //create a new char 
    strcpy(name, new_character.name); //copy the data over
   
    skills = new char*[new_character.num_skills]; //create a new array of pointers
    for(int j = 0; j < new_character.num_skills; ++j) //for every element in the array
    {
        skills[j] = new char[strlen(new_character.skills[j])+1]; //create a new char
        strcpy(skills[j], new_character.skills[j]); //copy the data over
    }

    temp_skills = new char*[new_character.num_skills];
    for(int l = 0; l < new_character.num_skills; ++l)
    {
        temp_skills[l] = new char[strlen(skills[l])+1];
        strcpy(temp_skills[l], skills[l]);
    }

    arcana = new char[strlen(new_character.arcana)+1]; //create a new char
    strcpy(arcana, new_character.arcana); //copy the data over

    level = new_character.level; //set the member variable to the temp value
    num_skills = new_character.num_skills;
    temp_num_skills = new_character.num_skills;
    return 1;   
}

//return whether the current character's skill is alphabetically less
//than or greater than a new skill
int Character::compare(const char * skill, char * key)
{
    //compares each element sequentially
    return strcmp(skill, key);
}

//returns whether a matching character has been found
int Character::retrieve(char * skill_to_find, char * key)
{
    if(!skill_to_find || !key) //returns failure if chars are NULL
        return 0;

    //returns success if a match occurs and failure otherwise    
    if(strcmp(key, skill_to_find) == 0)
    {
        return 1;
    }
    else
        return 0;
}

//display a single character in the list
int Character::display(void)const
{
    //if any of the data members are NULL, return failure
    if(!name || !arcana || !level)
        return 0;

    cout << "******************************************" << endl;
    cout << "Character name:\t" << name << '\n'; //output the name variable
    
    cout << "Skills:\t";
    for(int i = 0; i < num_skills; ++i) //for every element in skills list
    {
        cout << skills[i] << " "; //output each skill being pointed to
    }

    cout << '\n' << "Arcana:\t" << arcana << '\n' //output the arcana
         << "Level:\t\t" << level << '\n' << '\n'; //output the level
    
    return 1;
}
