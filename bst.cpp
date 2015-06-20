/**
  * table.cpp
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
  * table.cpp module: contains the implementation for 
  * the table ADT for the constructor,destructor, inserting, 
  * retrieving(based on keyword), removing(based on keyword), 
  * displaying (based on keyword), and displaying all items 
  * in the tree
  *
  */

#include "bst.h"

// constructor to initialize private data members
table::table()
{
    root = NULL; // sets root of BST to NULL
    head = tail = NULL; // sets head of LLL to NULL
}

// destructor to deallocate dynamic memory
table::~table()
{
    // call private function to deallocate memory
    // and catches success/failure for testing
    int status = remove_all(root);
}

//removal function to delete all nodes in the BST
int table::remove_all(bst_node *& root)
{
    if(!root) return 0; // if the tree is empty, return failure

    remove_all(root -> left); // recursively traverse the left nodes
    remove_all(root -> right); // recursively traverse the right nodes

    delete root; // delete the current node root is pointing to
    root = NULL; // set the node to NULL to avoid memory leaks

    return 1; // return success*/

}

// wrapper function to call the private insert functions
int table::insert(app_entry & a_new_entry)
{
    //copies an entry into a private LLL of app entries
    if(!insert_LLL(head, tail, a_new_entry))
        return 0;
    //inserts a node into the BST for every keyword in the current entry
    for(int i = 0; i < tail -> bst_categories; ++i)
    {
        //inserts a node into the BST for the current keyword being evaluated
        if(!insert_BST(root, tail -> entry, tail -> bst_keywords[i]))
            return 0;
    }
    
    return 1;
}

//copies an entry into a private LLL of app entries
int table::insert_LLL(l_node *& head, l_node *& tail, app_entry & a_new_entry)
{
    char ** temp_keywords = NULL;
    int temp_categories = 0;

    l_node * temp = new l_node; //creates a new node with a temp pointer

    if(!head) //if the LLL is empty
    {
        head = temp; //sets head to the new node
        tail = temp; //sets tail to the new node
    }
    else //if the LLL is not empty
    {
        tail -> next = temp; //set tail's next pointer to the new node
        tail = tail -> next; //set tail to the new node
    }
        
    tail -> entry.copy(a_new_entry, temp_keywords, temp_categories); //copy the entry's data into the new node
    tail -> bst_categories = temp_categories; //copy the entry's category/keyword number into the node
    tail -> bst_keywords = new char *[temp_categories]; //create a keyword array in the new node
    for (int m = 0; m < temp_categories; ++m) //for each element in the array
    {
        tail -> bst_keywords[m] = new char[strlen(temp_keywords[m])+1]; //create a new char array
        strcpy(tail -> bst_keywords[m], temp_keywords[m]); //copy the keyword into the node's array of keywords
    }

    tail -> next = NULL; //set the end of the LLL to NULL
  
    return 1; //return success
}

//inserts an entry into the BST table sorted by keyword
int table::insert_BST(bst_node *& root, app_entry & a_new_entry, char * keyword)
{
    if(!root) //if there are no more nodes to traverse
    {
        root = new bst_node; //create a new node
        root -> key = new char[strlen(keyword)+1]; //create a new char for the key 
        strcpy(root -> key, keyword); //copy the keyword into the key char
        root -> entry = &a_new_entry; //point entry to the app entry
        root -> left = root -> right = NULL; //set the children to NULL

        return 1; //return success
    }
    else if((root -> entry -> compare(keyword, root -> key)) < 0) //if the keyword is less than the current root's key
        insert_BST(root -> left, a_new_entry, keyword); //insert it into the left side of the BST
    else //if the keyword is greater than the current root's key
        insert_BST(root -> right, a_new_entry, keyword); //insert it into the right side of the BST

    //figure out how to return 0 ?
}

//wrapper function to call function that displays all nodes in the BST
int table::display_all()
{
    return display_all(root); //returns the value of the private display_all() function
}

//displays all nodes in the BST with inorder traversal
int table::display_all(bst_node * root)
{
    if(root) //if the BST is not empty
    {
        display_all(root -> left); //traverse the left subtree
        
        root -> entry -> display(); //display an entry at the root
        cout << "Keyword: " << root -> key << '\n' << '\n'; //display the entry keyword

        display_all(root -> right); //traverse the right subtree

        return 1; //return success
    }
    else
        return 0; //return failure
}

//wrapper function for retrieving entries based on keyword
int table::retrieve(char * a_keyword, app_entry & an_entry)
{
    //returns the success/failure of the private retrieve function
    return retrieve(a_keyword, an_entry, root);
}

//retrieves entries based on keyword and calls app_entry display for each match
int table::retrieve(char * a_keyword, app_entry & an_entry, bst_node * root)
{
    if(root) //if the BST is not empty
    {
	//recursively traverse the left subtree
        retrieve(a_keyword, an_entry, root -> left);

        //if the current entry's keyword matches the sought after keyword
        if(root -> entry -> retrieve(a_keyword, root -> key))
            //call the display function with the current entry
            root -> entry -> display();
    
        //recursively traverse the right subtree
        retrieve(a_keyword, an_entry, root -> right);
        
        return 1; //return success
    }
    else
        return 0; //if the BST is empty, return failure
}

//wrapper function for removing entries based on keyword
int table::remove(char * a_keyword)
{
    //returns the success/failure of the private remove function
    return remove(a_keyword, root);
}

//removes entries based on keyword
int table::remove(char * a_keyword, bst_node *& root)
{
    if(root)
    {
        //recursively traverse the left subtree
        remove(a_keyword, root -> left);    

        //if the current entry's keyword matches the sought after keyword
        if(root -> entry -> retrieve(a_keyword, root -> key))
        {
            //if the matching node has no children
            if(!root -> left && !root -> right)
            {
                delete root; //delete the node root is pointing to
                root = NULL; //set the node root is pointing to to NULL
            }
            //if the matching node has two children
            else if(root -> left && root -> right)
            {
                bst_node * current = root -> right; //point current to root's right child
                bst_node * previous = root; //point previous to root

                //loop while current has a left child (find the inorder successor)
                while(current -> left)
                {
                    previous = current; //point previous to current
                    current = current -> left; //point current to it's own left child
                }
                //if current has no left children
                if(previous -> right == current)
                {
                    root -> right = NULL; //disconnect root's right subtree
		    current -> left = root -> left; //point current's left pointer to root's left subtree
            
                    root -> left == NULL; //disconnect root's left subtree

                    delete root; //delete what root is pointing to
                    root = current; //point root to current
                }
                else //if current has progressed to the leftmost node
                {
                    previous -> left = current -> right; //point previous's left pointer to current's right subtree
                    current -> left = root -> left; //point current's left pointer to root's left subtree
                    current -> right = root -> right; //point current's right pointer to root's right subtree
                    
                    root -> right = NULL; //disconnect root's right subtree
                    root -> left = NULL; //disconnect root's left subtree
 
                    delete root; //delete the memory root is pointing to
                    root = current; //point root to the node current is pointing to
                }
 
            }
            //if the matching node has one child
            else if(root -> right || root -> left)
            {
                //if the matching node has a right child
                if(root -> right)
                {
                    bst_node * temp = root; //hold the place with temp 
                    root = root -> right; //point root to the child
                
                    delete temp; //delete the temp node
                    temp = NULL; //set the temp node's pointer to NULL
                }
                //if the matching node has a left child
                else if(root -> left)
                {
                
                    bst_node * temp = root; //hold the place with temp
                    root = root -> left; //point the root to the child
                
                    delete temp; //delete the temp node
                    temp = NULL; //set the temp node's pointer to NULL
                }
           }
        }
      
        //recursively traverse the right subtree
        remove(a_keyword, root -> right);
      
        return 1; 
    }
    else
        return 0; //if the BST is empty, return failure
}
