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

        //insert in between node
        //step 8: Locate position for insertion
        Node *currrent = START;
        while (currrent->next != NULL && currrent->next->noMhs < nim)
        {
            currrent = currrent->next;
        }

        if (currrent->next != NULL && nim == currrent->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        //step 9: Insert between current and current->next
        newNode->next = currrent->next;  //step 9a: newNode.next = current.next
        newNode->prev = currrent;        //step 9b: newNode.prev = current

        //insert last node
        if (currrent->next != NULL)
            newNode->next->prev = newNode; //step 9c: current.next.prev = newNode
        
        currrent->next = newNode; //step 9d: current.next = newNode
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        Node *currrent = START;
        
        //Step 1: Traverse the list to find the node
        while (currrent != NULL && currrent->noMhs != rollNo)
            currrent = currrent->next;

        if (currrent == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        //step 2: if node is at the beginning
        if (currrent == START)
        {
            START = currrent->next; //step 2a: START = START.next
            if (START != NULL)
                START->prev = NULL; //step 2b: START.prev = NULL
        }
        else
        {
            //step 3: Link previous node to next of current
            currrent->prev->next = currrent->next;

            //step 4: If current is not the last node
            if (currrent->next != NULL)
                currrent->next->prev = currrent->prev;
        }

        //step 5: Delete the node
        delete currrent;
        cout << "Record with roll number " << rollNo << "delete" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }
        //step 1: Mark first node as currentNode
        Node *curentNode = START;
        //STEP 2: Repeat until currentNode = NULL
        cout << "\nRecords in ascending order of roll number are:\n";
        int i = 0;
        while (curentNode != NULL)
        {
            cout << i + 1 << " . " << curentNode->noMhs << " " << endl;
            //step 3: Move to next node
            curentNode = curentNode->next;
            i++;
        }


        void revtraverse()
        {
            if (START == NULL)
            {
                cout << "\nList is empty" << endl;
                return;
            }

            //step 1: move to last node
            Node *curentNode = START;
            int i = 0;
            while (curentNode->next != NULL)
            {
                curentNode = curentNode->next;
                i++;
            }

            //step 2: traverse backward
            cout << "\nRecord in descending order roll number are:\n";
            while (curentNode != NULL)
            {
                cout << i + 1 << ". " << curentNode->noMhs << " " << endl;

                //step 3: move to previous node
                curentNode = curentNode->prev;
                i--;
            }
        }

        void searchData()
        {
            if (START == NULL)
            {
                cout << "\nList is empty" << endl;
                return;
            }

            int rollNo;
            cout << "\nEnter the roll number to search: ";
            cin >> rollNo;

            Node *current = START;

            //step 1: traverse to find matching roll number
            while (current != NULL && current->noMhs != rollNo)
                current = current->next;

            //step 2: output resilt
            if (current == NULL)
            {
                cout << "Record not found\n";
            }
            else 
            {
                cout << "Record found\n";
                cout << "Roll Number: " << current->noMhs << endl;
            }
        }
    }
};
int main()
{
    DoubleLinkedList list;
    char choice;

    do
    {

        cout << "\nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Delete Record\n";
        cout << "3. View Ascending\n";
        cout << "4. view Descending\n";
        cout << "5. Search Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case '1':
                list.addNode();
                break;
            case '2':
                list.hapus();
                break;
            case '3':
                list.traverse();
                break;
            case '4':
                list.revtraverse();
                break;
            case '5':
                list.searchData();
                break;
            case '6':
                return 0;
            default:
                cout << "Invalid option\n";
        }
        cout << "\nPress enter to continue...";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");
    }while (choice != '6');
}