/**
  * table.h
  *
  * Character-Lexicon
  * 6.20.2015
  * CS163
  *
  * Kegan Sanchez
  * kegan.sanchez@gmail.com
  *
  * Character-Lexicon: Creates a binary search tree ADT to
  * manage characters by implementing functions to
  * recursively insert, retrieve, display, remove all
  * matches by location, and remove all items.
  *
  * table.h module: contains the struct node prototype
  * which has an app entry as data and node pointers
  * to the left and right nodes. It also has the member
  * function prototypes for the table ADT for the
  * constructor,destructor, inserting, retrieving(based
  * on keyword), removing(based on keyword), displaying
  * (based on keyword), and displaying all items in the
  * tree.
  *
  */

#include "app_entry.h"

struct bst_node //framework for a BST node
{
    app_entry * entry; //pointer to an app entry
    char * key; //holds keyword node is sorted by
    bst_node * left; //pointer to the left child
    bst_node * right; //pointer to the right child
};

struct l_node //framework for a LLL node
{
    app_entry entry; //instance of an app entry
    char ** bst_keywords; //array of keywords
    int bst_categories; //number or categories
    l_node * next; //pointer to the next node
};

class table
{
    public:
            table(); //constructor to initialize private data
            ~table(); //destructor to deallocate memory

            //public wrapper functions to call private member functions
            int insert(app_entry & a_new_entry); //returns private insert function
            int retrieve(char * a_keyword, app_entry & an_entry); //returns private retrieve function
            int remove(char * a_keyword); //returns private remove function
            int display(); //returns private display function
            int display_all(); //returns private display_all function

    private:
            bst_node * root; //pointer to the root of the BST
            l_node * head; //pointer to the head of a LLL of entries
            l_node * tail; //pointer to the tail of a LLL of entries

            //private member functions
            int insert_LLL(l_node *& head, l_node *& tail, app_entry & a_new_entry); //copies an entry into a private LLL of app entries
            int insert_BST(bst_node *& root, app_entry & a_new_entry, char * keyword); //inserts a node into the BST
            int retrieve(char * a_keyword, app_entry & an_entry, bst_node * root); //retrieves and displays entry based on keyword
            int remove(char * a_keyword, bst_node *& root); //removes an entry based on keyword
            int display_all(bst_node * root); //diplays all items in the BST
            int remove_all(bst_node *& root); //removes all nodes in the BST
};
