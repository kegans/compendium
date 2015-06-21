/**
  * main.cpp
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
  * main.cpp module: serves as the client interface of
  * the program by including and creating an instance
  * of the managing class/file and calling functions
  * managed by this class (envoy). Also creates temporary
  * variables to hold input from the client and passes 
  * them into the envoy.h functions.
  *
  */

#include "envoy.h" //includes the managing file
using namespace std;

int main()
{
    envoy a_list; //an instance of envoy class 

    //initialize temporary variables
    char name[100]; //for an app's name
    char temp[100]; //for a single keyword
    char ** skills; //for an array of skills
    char arcana[300]; //for an app's arcanation
    int level; //for a numerical app level
    int skills_num; //for the number of skills/categories
    
    do
    { 
        do
        {
            //gets the name of the app
            cout <<"Please enter the character's name: ";
            cin.get(name, 100); cin.ignore(100, '\n');

            //gets the number of categories then get each category
            cout <<"How many skills would you like to enter" << '\n'<< "(between 1 and 5): ";
            cin >> skills_num; cin.ignore(100, '\n');
	    skills = new char * [skills_num];
            for(int k = 0; k < skills_num; ++k)
            {
                cout <<"Please enter a skill: ";
                cin.get(temp, 35);
                cin.ignore(100, '\n');
	        skills[k] = new char[strlen(temp)+1];
                strcpy(skills[k], temp);
            }

            //gets the arcana
            cout <<"Arcana: ";
            cin.get(arcana, 300); cin.ignore(100, '\n');
            //gets the level
            cout <<"Level (between 1 and 10): ";
            cin >> level; cin.ignore(100,'\n');

            //creates and inserts an entry into the BST 
            if(!a_list.create(name, skills, arcana, level, skills_num))
                cout << "Could not insert entry." << endl;

        }while(again()); //get app info while client wants to continue  

        //display the bst through inorder traversal
        cout <<"\nThese are the contents of the compendium";
        cout <<"\nin sorted order:\n\n";
        if(!a_list.display_all())
            cout <<"Could not display the compendium." << endl;

        //retrieve and display entries by keyword
        cout <<"Which characters would you like to display ? ";
        cout <<"\n- provide the skill: ";
        cin.get(temp, 100); cin.ignore(100,'\n');

        if(!a_list.retrieve(temp))
            cout << "Could not display entries." << endl;

        //retrieve and delete entries based on keyword
        cout <<"Which characters whould you like to delete ? ";
        cout <<"\n- provide the skills: ";
        cin.get(temp, 100); cin.ignore(100, '\n');

        if(!a_list.remove(temp))
            cout << "Could not display entries." << endl;

        //display the BST through inorder traversal
        cout <<"\nThese are the contents of the compendium";
        cout <<"\nin sorted order:\n\n";
        if(!a_list.display_all())
            cout <<"Could not display the APP list." << endl;

        if(skills) //delete allocated memory for skills
        {
            for(int i = 0; i < skills_num; ++i)
            {
                delete [] skills[i]; // delete each keyword
            }
    
            delete [] skills; // delete the entire array of pointers
        }

    }while(again()); //continue entire program while client wants to continue 
  
    return 0;
}
