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
  * manage mobile apps by implementing functions to 
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
    char ** keywords; //for an array of keywords
    char descrip[300]; //for an app's description
    int rating; //for a numerical app rating
    int cat_num; //for the number of keywords/categories
    
    do
    { 
        do
        {
            //gets the name of the app
            cout <<"Please enter the APP name: ";
            cin.get(name, 100); cin.ignore(100, '\n');

            //gets the number of categories then get each category
            cout <<"How many keyword/categories would you like to enter" << '\n'<< "(between 1 and 5): ";
            cin >> cat_num; cin.ignore(100, '\n');
	    keywords = new char * [cat_num];
            for(int k = 0; k < cat_num; ++k)
            {
                cout <<"Please enter a category: ";
                cin.get(temp, 35);
                cin.ignore(100, '\n');
	        keywords[k] = new char[strlen(temp)+1];
                strcpy(keywords[k], temp);
            }

            //gets the description
            cout <<"Description: ";
            cin.get(descrip, 300); cin.ignore(100, '\n');
            //gets the rating
            cout <<"Rating (between 1 and 10): ";
            cin >> rating; cin.ignore(100,'\n');

            //creates and inserts an entry into the BST 
            if(!a_list.create(name, keywords, descrip, rating, cat_num))
                cout << "Could not insert entry." << endl;

        }while(again()); //get app info while client wants to continue  

        //display the bst through inorder traversal
        cout <<"\nThese are the contents of the APP BST";
        cout <<"\nin sorted order:\n\n";
        if(!a_list.display_all())
            cout <<"Could not display the APP list." << endl;

        //retrieve and display entries by keyword
        cout <<"Which entries would you like to display ? ";
        cout <<"\n- provide the keyword/category: ";
        cin.get(temp, 100); cin.ignore(100,'\n');

        if(!a_list.retrieve(temp))
            cout << "Could not display entries." << endl;

        //retrieve and delete entries based on keyword
        cout <<"Which entries whould you like to delete ? ";
        cout <<"\n- provide the keyword/category: ";
        cin.get(temp, 100); cin.ignore(100, '\n');

        if(!a_list.remove(temp))
            cout << "Could not display entries." << endl;

        //display the BST through inorder traversal
        cout <<"\nThese are the contents of the APP BST";
        cout <<"\nin sorted order:\n\n";
        if(!a_list.display_all())
            cout <<"Could not display the APP list." << endl;

        if(keywords) //delete allocated memory for keywords
        {
            for(int i = 0; i < cat_num; ++i)
            {
                delete [] keywords[i]; // delete each keyword
            }
    
            delete [] keywords; // delete the entire array of pointers
        }

    }while(again()); //continue entire program while client wants to continue 
  
    return 0;
}
