#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
    private:
    Node *START;

    public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        string nm;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        //step 1: Allocate memory for new node
        Node *newNode = new Node();

        //step 2: Assign value to the data fields
        newNode->noMhs = nim;

        //step 3: Insert at beginning if list is empty or nim is smallest
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            //step 4: newNode.next = START
            newNode->next = START;

            //step 5: START.prev = newNode (if START exists)
            if (START != NULL)
                START->prev = newNode;

            //step 6: newNode.prev = NULL
            newNode->prev = NULL;

            //step 7: START = newNode
            START = newNode;
            return;
        }

        
    }
}