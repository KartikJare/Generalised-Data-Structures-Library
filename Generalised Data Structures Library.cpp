#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//
//  Class :         QueueX
//  Description :   Generic implementation of queue
//  Author :        Kartik Ganesh Jare
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct Queuenode
{
    T data;
    struct Queuenode<T> *next;
};

template <class T>
class QueueX
{
    private:
        struct Queuenode<T> *first;
        int iCount;

    public:
        QueueX();
        void Enqueue(T);
        T Dequeue();
        void Display();
        int Count();
};

template <class T>
QueueX<T> :: QueueX()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void QueueX<T> :: Enqueue(T no) // InsertLast
{
    struct Queuenode<T> *temp = NULL;
    struct Queuenode<T> * newn = NULL;

    newn = new Queuenode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }

    iCount++;
}

template <class T>
T QueueX<T> :: Dequeue()         // DeleteFirst
{
    struct Queuenode<T> *temp = NULL;
    T value;

    if(first == NULL)
    {
        cout<<"Unable to remove as queue is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;

        first = first -> next;
        delete temp;

        iCount--;

        return value;
    }
}

template <class T>
void QueueX<T> :: Display()
{
    struct Queuenode<T> *temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int QueueX<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         StackX
//  Description :   Generic implementation of stack
//  Author :        Kartik Ganesh Jare
//
///////////////////////////////////////////////////////////////////////

template<class T>
struct Stacknode
{
    T data;
    struct Stacknode<T> *next;
};

template<class T>
class StackX
{
    private:
        struct Stacknode<T> *first;
        int iCount;

    public:
        StackX();
        void Push(T);
        T Pop();
        void Display();
        int Count();
};

template<class T>
StackX<T> :: StackX()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void StackX<T> :: Push(T no) // InsertFirst
{
    struct Stacknode<T> * newn = NULL;

    newn = new Stacknode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}

template<class T>
T StackX<T> :: Pop()         // DeleteFirst
{
    struct Stacknode<T> *temp = NULL;
    T value;

    if(first == NULL)
    {
        cout<<"Unable to pop as stack is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;

        first = first -> next;
        delete temp;

        iCount--;

        return value;
    }
}

template<class T>
void StackX<T> :: Display()
{
    struct Stacknode<T> *temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int StackX<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyCLL
//  Description :   Generic implementation of singly circular linked list
//  Author :        Kartik Ganesh Jare
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> *next;
};

template <class T>
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;

        last->next = first;
    }

    iCount++;
}

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;
    }

    iCount++;
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;

        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    struct SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        delete last;
        last = temp;

        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    struct SinglyCLLnode<T> * temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != last ->next);
    
    cout<<"\n";
}

template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        iCount--;
    }
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyCLL
//  Description :   Generic implementation of doubly cirular Linked List
//  Author :        Kartik Ganesh Jare
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *next;
    struct DoublyCLLnode<T> *prev;
};

template <class T>
class DoublyCLL
{
    private:
        struct DoublyCLLnode<T> * first;
        struct DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

template <class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Inside Constructor\n";
    
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)   // LL is empty
    {
        first = newn;
        last = newn;
    }   
    else    // LL contains atleast one node
    {
        newn->next = first;
        first->prev = newn;

        first = newn;
    } 

    last->next = first;
    first->prev = last;

    iCount++;
}

template <class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)   // LL is empty
    {
        first = newn;
        last = newn;
    }   
    else    // LL contains atleast one node
    {
        last->next = newn;
        newn->prev = last;

        last = newn;
    } 

    last->next = first;
    first->prev = last;
    
    iCount++;
}

template <class T>
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T> * temp = NULL;
    cout<<"Elements of the LinkedList are : \n";

    temp = first;

    if(first == NULL && last == NULL)
    {
        cout<<"LinkedList is empty\n";
        return;
    }

    do
    {
        cout<<"| "<< temp->data <<" | <=> ";
        temp = temp->next;   
    } while (temp != first);
    cout<<"\n";
}

template <class T>
int DoublyCLL<T> :: Count()
{
    return iCount;  
}

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(first == NULL && last == NULL)   // LL is empty
    {
        return;
    }
    else if(first == last)  // LL contains 1 node
    {
        delete first;
    
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than 1 nodes
    {
        first = first -> next;
        delete first->prev;     // delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(first == NULL && last == NULL)   // LL is empty
    {
        return;
    }
    else if(first == last)  // LL contains 1 node
    {
        delete last;
    
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than 1 nodes
    {
        last = last -> prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

template <class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    struct DoublyCLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct DoublyCLLnode<T>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyLL
//  Description :   Generic implementation of singly linear Linked List
//  Author :        Kartik Ganesh Jare
//
///////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//
// Structure Name :   SinglyLLLnode
// Description    :   Represents a single node in the Singly Linear Linked List
//
////////////////////////////////////////////////////////////////////

template <class T>
struct SinglyLLLnode
{
    T data;
    struct SinglyLLLnode<T> *next;
};

////////////////////////////////////////////////////////////////////
//
// Class Name    :   SinglyLLL
// Description   :   Provides functionalities to perform various operations on
//                   Singly Linear Linked List such as insertion, deletion, display and count
//
////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLLL
{
    private:
        struct SinglyLLLnode<T> *first;    
        int iCount;                        

    public:

        ////////////////////////////////////////////////////////////////////
        //
        // Function Name :   SinglyLLL
        // Description   :   Constructor to initialize the linked list
        // Author        :   Kartik Ganesh Jare
        // Date          :   08/07/25
        // Prototype     :   SinglyLLL()
        // Input         :   None
        // Output        :   None
        //
        ////////////////////////////////////////////////////////////////////
        SinglyLLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

////////////////////////////////////////////////////////////////////
//
// Function Name :   SinglyLLL
// Description   :   Constructor definition - Initializes list as empty
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   SinglyLLL()
// Input         :   None
// Output        :   None
//
////////////////////////////////////////////////////////////////////

template <class T>
SinglyLLL<T> ::SinglyLLL()
{
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertFirst
// Description   :   Inserts new node at first position
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   void InsertFirst(T no)
// Input         :   Generic data (no)
// Output        :   None
//
////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> ::InsertFirst(T no)
{
    struct SinglyLLLnode<T> *newn = new struct SinglyLLLnode<T>;

    newn->data = no;
    newn->next = first;
    first = newn;

    iCount++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertLast
// Description   :   Inserts new node at last position
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   void InsertLast(T no)
// Input         :   Generic data (no)
// Output        :   None
//
////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    struct SinglyLLLnode<T> *newn = new struct SinglyLLLnode<T>;
    struct SinglyLLLnode<T> *temp = first;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteFirst
// Description   :   Deletes first node from the list
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   void DeleteFirst()
// Input         :   None
// Output        :   None
//
////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }

    struct SinglyLLLnode<T> *temp = first;

    first = first->next;
    delete(temp);

    iCount--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteLast
// Description   :   Deletes last node from the list
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   void DeleteLast()
// Input         :   None
// Output        :   None
//
////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete(first);
        first = NULL;
    }
    else
    {
        struct SinglyLLLnode <T>*temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   Display
// Description   :   Displays all elements of the list
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   void Display()
// Input         :   None
// Output        :   None
//
////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: Display()
{
    struct SinglyLLLnode<T> *temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   Count
// Description   :   Returns number of nodes in the list
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   int Count()
// Input         :   None
// Output        :   Integer (count)
//
////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T> :: Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertAtPos
// Description   :   Inserts node at specific position
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   void InsertAtPos(T no, int pos)
// Input         :   Generic data (no), Integer (pos)
// Output        :   None
//
////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertAtPos(T no,int pos)
{
    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct SinglyLLLnode<T> * newn = new struct SinglyLLLnode<T>;
        struct SinglyLLLnode<T> * temp = first;

        newn->data=no;
        newn->next=NULL;

        for(int iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteAtPos
// Description   :   Deletes node at specific position
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   void DeleteAtPos(int pos)
// Input         :   Integer (pos)
// Output        :   None
//
////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct SinglyLLLnode<T> * temp = first;
        struct SinglyLLLnode<T> * target = NULL;

        for(int iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete(target);
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyLL
//  Description :   Generic implementation of doubly linear Linked List
//  Author :        Kartik Ganesh Jare
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct DoublyLLnode
{
    T data;
    struct DoublyLLnode<T> *next;
    struct DoublyLLnode<T> *prev;
};

template <class T>
class DoublyLL
{
    private:
        struct DoublyLLnode<T> * first;   // Pointer to first node
        int iCount;                       // Node count

    public:

        ////////////////////////////////////////////////////////////////////
        //
        // Function Name :   DoublyLL
        // Description   :   Constructor to initialize linked list
        // Author        :   Kartik Ganesh Jare
        // Date          :   08/07/25
        // Prototype     :   DoublyLL()
        // Input         :   None
        // Output        :   None
        //
        ////////////////////////////////////////////////////////////////////
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

////////////////////////////////////////////////////////////////////
//
// Function Name :   DoublyLL
// Description   :   Initializes first pointer and node count
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   DoublyLL()
// Input         :   None
// Output        :   None
//
////////////////////////////////////////////////////////////////////

template <class T>
DoublyLL<T> :: DoublyLL()
{
    first = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertFirst
// Description   :   Inserts a new node at the beginning of the list
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   void InsertFirst(T no)
// Input         :   T no
// Output        :   None
//
////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct DoublyLLnode<T> * newn = new struct DoublyLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL) // If list is empty
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertLast
// Description   :   Inserts a new node at the end of the list
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   void InsertLast(T no)
// Input         :   T no
// Output        :   None
//
////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct DoublyLLnode<T> * newn = new struct DoublyLLnode<T>;
    struct DoublyLLnode<T> * temp = first;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL) // If list is empty
    {
        first = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteFirst
// Description   :   Deletes the first node of the list
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   void DeleteFirst()
// Input         :   None
// Output        :   None
//
////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    struct DoublyLLnode <T>* temp = NULL;

    if(first == NULL) // Empty list
    {
        return;
    }
    else if(first->next == NULL) // Only one node
    {
        delete(first);
        first = NULL;
    }
    else
    {
        temp = first;
        first = first->next;
        delete(temp);
        if(first != NULL)
        {
            first->prev = NULL;
        }
    }

    if(iCount > 0)
        iCount--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteLast
// Description   :   Deletes the last node of the list
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   void DeleteLast()
// Input         :   None
// Output        :   None
//
////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    struct DoublyLLnode<T> * temp = first;

    if(first == NULL) // Empty list
    {
        return;
    }
    else if(first->next == NULL) // Only one node
    {
        delete(first);
        first = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete(temp->next);
        temp->next = NULL;
    }

    if(iCount > 0)
        iCount--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   Display
// Description   :   Displays all elements from the list
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   void Display()
// Input         :   None
// Output        :   None (prints elements)
//
////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: Display()
{
    struct DoublyLLnode<T> * temp = first;

    cout<<"NULL <=> ";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   Count
// Description   :   Returns number of nodes present in the list
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   int Count()
// Input         :   None
// Output        :   int (count of nodes)
//
////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertAtPos
// Description   :   Inserts a new node at a specific position
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   void InsertAtPos(T no, int pos)
// Input         :   T no, int pos
// Output        :   None
//
////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: InsertAtPos(T no,int pos)
{
    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct DoublyLLnode<T> * newn = new struct DoublyLLnode<T>;
        struct DoublyLLnode<T> * temp = first;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteAtPos
// Description   :   Deletes a node from a specific position
// Author        :   Kartik Ganesh Jare
// Date          :   08/07/25
// Prototype     :   void DeleteAtPos(int pos)
// Input         :   int pos
// Output        :   None
//
////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct DoublyLLnode<T> * temp = first;
        struct DoublyLLnode<T> * target = NULL;

        for(int iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete(target);

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         BST (program571.c) -> .cpp -> generic
//  Description :   Generic implementation of Binary Search Tree
//  Author :        Kartik Ganesh Jare
//
///////////////////////////////////////////////////////////////////////

// Add code

///////////////////////////////////////////////////////////////////////
//
//  Class :         Sorting (program595.cpp) -> generic
//  Description :   Generic implementation of sorting algorithms
//  Author :        Kartik Ganesh Jare
//
///////////////////////////////////////////////////////////////////////

// Add code

///////////////////////////////////////////////////////////////////////
//
//  Class :         Searching (program587.cpp) -> generic
//  Description :   Generic implementation of searching algorithms
//  Author :        Kartik Ganesh Jare
//
///////////////////////////////////////////////////////////////////////

// Add code

///////////////////////////////////////////////////////////////////////
// Assignment no 34,35,36 functions -> C++ -> Generic
// Write all functions logic in all types of Linked List
///////////////////////////////////////////////////////////////////////

int main()
{
    
    return 0;
}