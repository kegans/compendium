/**
  * app_entry.cpp
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
#include "app_entry.h"

//initializes app_entry data members
app_entry::app_entry()
{
    name = NULL; //name of app
    keywords = NULL; //list of keywords
    descrip = NULL; //description for each app
    rating = 0; //rating for each app
    categories = 0; //number of keywords
}

//destroys all allocated memory
app_entry::~app_entry()
{
    if(name) //delete allocated memory for name
        delete[]name;
    if(descrip) //delete allocated memory for description
        delete[]descrip;
    
    if(keywords) //delete allocated memory for keywords
    {
        for(int i = 0; i < categories; ++i)
        {
            delete [] keywords[i]; //delete each keyword
        }
    
        delete [] keywords; //delete the entire array of pointers
    }
    
    //set everything to NULL to avoid segmentation faults
    name = NULL; 
    descrip = NULL;
    keywords = NULL;
    rating = 0;
}

//creates a new entry based on temp values from the client program
int app_entry::create(char * new_name, char ** new_keywords, char * new_descrip, int new_rating, int new_cat_num)
{
    if(!new_name || !new_descrip || !new_rating) return 0; //if values are NULL, return failure

    if(name) //if name is already pointing to something
    {
        delete [] name; //delete name and set to NULL
        name = NULL;
    }
    name = new char[strlen(new_name)+1]; //create new name char
    strcpy(name, new_name); //copy information into name

    /*if(keywords) // if keywords is already pointing to something
    {
        for(int i = 0; keywords[i] != NULL; ++i) // for each element, delete the data
        {
            delete [] keywords[i];
        }
        
        delete [] keywords; // delete the entire array of pointers
    }*/
    
    categories = new_cat_num; //set the member variable to the number of elements

    keywords = new char*[categories]; //create a new array of pointers 
    for(int j = 0; j < categories; ++j) //for every element in the array
    {
        keywords[j] = new char[strlen(new_keywords[j])+1]; //create a new char
        strcpy(keywords[j], new_keywords[j]); //copy the data over
    }
    if(descrip) //if descrip is already pointing to something
    {
        delete [] descrip; //delete descrip and set it to NULL
        descrip = NULL;
    }
    descrip = new char[strlen(new_descrip)+1]; //create a new char
    strcpy(descrip, new_descrip); //copy the data over

    rating = new_rating; //set the member variable to the new temp value

    return 1;
}
//copies a data into a struct as well as temp data members for a node in a LLL of structs
int app_entry::copy(const app_entry & new_entry, char **& temp_keywords, int &temp_categories)
{
    //if either of the variables are NULL, return failure
    if(!new_entry.name || !new_entry.keywords || !new_entry.descrip || !new_entry.rating) return 0;

    if(name) //if name is already pointing to something
    {
        delete [] name; //delete name and set it to NULL
        name = NULL;
    }

    /*if(keywords) //if keywords is already pointing to something
    {
        for(int i = 0; keywords[i] != NULL; ++i) // for every element in the array
        {

            delete [] keywords[i]; // delete each item being pointed to
        }
        
        delete [] keywords; // delete the entire array
        keywords = NULL; // set the array pointer to NULL
    }*/

    if(descrip) //if descrip is already pointing to something
    {
        delete [] descrip; //delete descrip and set it to NULL
        descrip = NULL;
    }

    name = new char[strlen(new_entry.name)+1]; //create a new char 
    strcpy(name, new_entry.name); //copy the data over
   
    keywords = new char*[new_entry.categories]; //create a new array of pointers
    for(int j = 0; j < new_entry.categories; ++j) //for every element in the array
    {
        keywords[j] = new char[strlen(new_entry.keywords[j])+1]; //create a new char
        strcpy(keywords[j], new_entry.keywords[j]); //copy the data over
    }

    temp_keywords = new char*[new_entry.categories];
    for(int l = 0; l < new_entry.categories; ++l)
    {
        temp_keywords[l] = new char[strlen(keywords[l])+1];
        strcpy(temp_keywords[l], keywords[l]);
    }

    descrip = new char[strlen(new_entry.descrip)+1]; //create a new char
    strcpy(descrip, new_entry.descrip); //copy the data over

    rating = new_entry.rating; //set the member variable to the temp valu
    categories = new_entry.categories;
    temp_categories = new_entry.categories;
    return 1;   
}

//return whether the current entry's keyword is alphabetically less
//than or greater than a new keyword
int app_entry::compare(const char * keyword, char * key)
{
    //compares each element sequentially
    return strcmp(keyword, key);
}

//returns whether a matching app has been found
int app_entry::retrieve(char * keyword_to_find, char * key)
{
    if(!keyword_to_find || !key) //returns failure if chars are NULL
        return 0;

    //returns success if a match occurs and failure otherwise    
    if(strcmp(key, keyword_to_find) == 0)
    {
        return 1;
    }
    else
        return 0;
}

//display a single app in the list
int app_entry::display(void)const
{
    //if any of the data members are NULL, return failure
    if(!name || !descrip || !rating)
        return 0;

    cout << "******************************************" << endl;
    cout << "APP name:\t" << name << '\n'; //output the name variable
    
    cout << "Categories:\t";
    for(int i = 0; i < categories; ++i) //for every element in keywords list
    {
        cout << keywords[i] << " "; //output each keyword being pointed to
    }

    cout << '\n' << "Description:\t" << descrip << '\n' //output the description
         << "Rating:\t\t" << rating << '\n' << '\n'; //output the rating
    
    return 1;
}
