#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//
//  Class       :   QueueX
//  Description :   Generic implementation of queue
//  Author      :   Kartik Ganesh Jare
//
///////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////// 
// 
// Structure Name : Queuenode 
// Description    : Structure represents node of queue 
// Author         : Kartik Ganesh Jare 
// Date           : 08/8/25
// 
///////////////////////////////////////////////////////////////////////

template <class T>
struct Queuenode
{
    T data;
    struct Queuenode<T> *next;
};

/////////////////////////////////////////////////////////////////////// 
// 
// Class Name  : QueueX 
// Description : Generic implementation of queue 
// Author      : Kartik Ganesh Jare
// Date        : 08/8/25
// 
///////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////// 
// 
// Function Name : QueueX 
// Description   : Constructor, initializes empty queue 
// Author        : Kartik Ganesh Jare 
// Date          : 08/8/25
// Prototype     : QueueX<T>::QueueX() 
// Input         : None 
// Output        : None 
// 
///////////////////////////////////////////////////////////////////////

template <class T>
QueueX<T> :: QueueX()
{
    first = NULL;
    iCount = 0;
}

/////////////////////////////////////////////////////////////////////// 
// 
// Function Name : Enqueue 
// Description   : Insert element at last position in queue 
// Author        : Kartik Ganesh Jare 
// Date          : 08/8/25
// Prototype     : void QueueX<T>::Enqueue(T no)
// Input         : T no - element to insert 
// Output        : None 
// 
///////////////////////////////////////////////////////////////////////

template <class T>
void QueueX<T> :: Enqueue(
                           T no
                         ) // InsertLast
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

/////////////////////////////////////////////////////////////////////// 
// 
// Function Name : Dequeue 
// Description   : Delete element from first position of queue 
// Author        : Kartik Ganesh Jare 
// Date          : 08/8/25
// Prototype     : T QueueX<T>::Dequeue() 
// Input         : None 
// Output        : Returns deleted element 
// 
///////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////// 
// 
// Function Name : Display 
// Description   : Display all elements of queue 
// Author        : Kartik Ganesh Jare 
// Date          : 08/8/25
// Prototype     : void QueueX<T>::Display() 
// Input         : None 
// Output        : Prints elements of queue 
// 
///////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////// 
// 
// Function Name : Count 
// Description   : Returns number of elements in queue 
// Author        : Kartik Ganesh Jare 
// Date          : 08/8/25
// Prototype     : int QueueX<T>::Count() 
// Input         : None 
// Output        : Returns element count 
// 
///////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////// 
// 
// Structure Name : Stacknode 
// Description    : Structure represents node of stack 
// Author         : Kartik Ganesh Jare 
// Date           : 08/8/25
// 
///////////////////////////////////////////////////////////////////////

template<class T>
struct Stacknode
{
    T data;
    struct Stacknode<T> *next;
};

/////////////////////////////////////////////////////////////////////// 
// 
// Class Name  : StackX 
// Description : Generic implementation of stack 
// Author      : Kartik Ganesh Jare 
// Date        : 08/8/25
// 
///////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////// 
// 
// Function Name : StackX 
// Description   : Constructor, initializes empty stack 
// Author        : Kartik Ganesh Jare 
// Date          : 08/8/25
// Prototype     : StackX<T>::StackX() 
// Input         : None // Output : None 
// 
///////////////////////////////////////////////////////////////////////

template<class T>
StackX<T> :: StackX()
{
    first = NULL;
    iCount = 0;
}

/////////////////////////////////////////////////////////////////////// 
// 
// Function Name : Push 
// Description   : Insert element at top of stack (InsertFirst) 
// Author        : Kartik Ganesh Jare 
// Date          : 08/8/25
// Prototype     : void StackX<T>::Push(T no) 
// Input         : T no - element to push 
// Output        : None 
// 
///////////////////////////////////////////////////////////////////////

template<class T>
void StackX<T> :: Push( 
                        T no
                      ) // InsertFirst
{
    struct Stacknode<T> * newn = NULL;

    newn = new Stacknode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}

/////////////////////////////////////////////////////////////////////// 
// 
// Function Name : Pop 
// Description   : Remove element from top of stack (DeleteFirst) 
// Author        : Kartik Ganesh Jare 
// Date          : 08/8/25
// Prototype     : T StackX<T>::Pop() 
// Input         : None 
// Output        : Returns deleted element 
// 
///////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////// 
// 
// Function Name : Display 
// Description   : Display all elements of stack 
// Author        : Kartik Ganesh Jare 
// Date          : 08/8/25
// Prototype     : void StackX<T>::Display() 
// Input         : None 
// Output        : Prints elements of stack 
// 
///////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////// 
// 
// Function Name : Count 
// Description   : Returns number of elements in stack 
// Author        : Kartik Ganesh Jare 
// Date          : 08/8/25
// Prototype     : int StackX<T>::Count() 
// Input         : None 
// Output        : Returns element count
// 
///////////////////////////////////////////////////////////////////////

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
void SinglyCLL<T>::InsertFirst( 
                                T no
                              )
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
void SinglyCLL<T>::InsertLast(
                               T no
                             )
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
void SinglyCLL<T>::DeleteAtPos(
                                int pos
                              )
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
void SinglyCLL<T>::InsertAtPos(
                                T no, 
                                int pos
                              )
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
void DoublyCLL<T> :: InsertFirst(
                                  T no
                                )
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
void DoublyCLL<T> :: InsertLast( 
                                 T no
                               )
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
void DoublyCLL<T> :: InsertAtPos( 
                                 T no,
                                 int pos
                                )
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
void DoublyCLL<T> :: DeleteAtPos(
                                  int pos
                                )
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
void SinglyLLL<T> ::InsertFirst(
                                T no
                               )
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
void SinglyLLL<T> :: InsertLast( 
                                 T no
                                )
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
void SinglyLLL<T> :: InsertAtPos(
                                 T no,
                                 int pos
                                )
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
void SinglyLLL<T> :: DeleteAtPos( 
                                 int pos
                                )
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
void DoublyLL<T> :: InsertFirst( 
                                 T no
                               )
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
void DoublyLL<T> :: InsertLast( 
                                T no
                              )
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
void DoublyLL<T> :: InsertAtPos( 
                                 T no,
                                 int pos
                                )
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
void DoublyLL<T> :: DeleteAtPos( 
                                int pos
                               )
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
//  Class :         Sorting generic
//  Description :   Generic implementation of sorting algorithms
//  Author :        Kartik Ganesh Jare
//
///////////////////////////////////////////////////////////////////////

template<class T>
class SortingX    // Increasing
{
    public:
        int *Arr;
        int iSize;
        bool Sorted;
    public:
        SortingX(T);
        ~SortingX();
        void Accept();
        void Display();
        void BubbleSort();
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();        
};

///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : SortingX 
// Description   : Constructor to allocate memory for array dynamically and initialize values 
// Author        : Kartik Ganesh Jare 
// Date          : 08/7/25 
// Prototype     : SortingX<T>::SortingX(T no) 
// Input         : Integer no (Size of array) 
// Output        : Allocates memory for Arr and initializes Sorted flag 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
SortingX<T>::SortingX( 
                       T no
                     )
{
    iSize = no;
    Arr = new int[iSize];
    Sorted = true;
}

////////////////////////////////////////////////////////////////////////////
//
// Function Name  : ~SortingX 
// Description    : Destructor to deallocate memory 
// Author         : Kartik Ganesh Jare 
// Date           : 08/7/25 
// Prototype      : SortingX<T>::~SortingX() 
// Input          : None
// Output         : Deallocates array
//
//////////////////////////////////////////////////////////////////////////

template<class T>
SortingX<T>::~SortingX()
{
    delete []Arr;
}

////////////////////////////////////////////////////////////////////////////
//
// Function Name : Accept 
// Description   : Accepts elements from user and updates Sorted flag 
// Author        : Kartik Ganesh Jare 
// Date          : 08/7/25 
// Prototype     : void SortingX<T>::Accept() 
// Input         : Reads iSize elements from user 
// Output        : Stores elements in Arr[]
//
///////////////////////////////////////////////////////////////////////

template<class T>
void SortingX<T>::Accept()
{
    cout<<"Enter "<<iSize<< " elements : \n";

    int i = 0;                 // 11 
    
    for(i = 0;i < iSize;i++) 
    {
        cout<<"Enter the element no : "<<i+1<<"\n";
        cin>>Arr[i];

        if(i > 0 && Sorted == true)   // IMP
        {
            if(Arr[i] < Arr[i-1])
            {
                Sorted = false;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display 
// Description   : Displays elements of array 
// Author        : Kartik Ganesh Jare Date : 08/7/25 
// Prototype     : void SortingX<T>::Display() 
// Input         : None 
// Output        : Prints elements of Arr[]
//
///////////////////////////////////////////////////////////////////////

template<class T>
void SortingX<T>::Display()
{
    cout<<"Elements of the array are : \n";

    int i = 0;
    
    for(i = 0;i < iSize;i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////
//
// Function Name : BubbleSort 
// Description   : Implements Bubble Sort (Basic version) 
// Author        : Kartik Ganesh Jare 
// Date          : 08/7/25 
// Prototype     : void SortingX<T>::BubbleSort() 
// Input         : None 
// Output        : Sorts the array in ascending order */
//
///////////////////////////////////////////////////////////////////////

template<class T>
void SortingX<T>::BubbleSort()
{
    int i = 0,j = 0,temp = 0;

    if(Sorted == true)
    {
        return;
    }
    
    for(i = 0; i < iSize;i++)     //Outer loop
    {
        for(j = 0;j < iSize - 1;j++)  //Inner loop
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }

        cout<<"Data after pass : "<<i+1<<"\n";

        Display();
    }
}

////////////////////////////////////////////////////////////////////////////
//
// Function Name : BubbleSortEfficient 
// Description   : Implements Bubble Sort (Efficient version with early stopping) 
// Author        : Kartik Ganesh Jare 
// Date          : 08/7/25 
// Prototype     : void SortingX<T>::BubbleSortEfficient() 
// Input         : None 
// Output        : Sorts the array in ascending order more efficiently
//
///////////////////////////////////////////////////////////////////////

template<class T>
void SortingX<T>::BubbleSortEfficient()
{
    int i = 0,j = 0,temp = 0;
    bool bFalg = true;

    if(Sorted == true)
    {
        return;
    }
    
    for(i = 0;(i < iSize && bFalg == true);i++)     //Outer loop
    {
        bFalg = false;

        for(j = 0;(j < iSize - 1 - i);j++)  //Inner loop
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;

                bFalg = true;
            }
        }
        cout<<"Data after pass : "<<i+1<<"\n";

        Display();
    }
}

////////////////////////////////////////////////////////////////////////////
//
// Function Name : SelectionSort 
// Description   : Implements Selection Sort 
// Author        : Kartik Ganesh Jare 
// Date          : 08/7/25 
// Prototype     : void SortingX<T>::SelectionSort() 
// Input         : None 
// Output        : Sorts the array in ascending order
//
///////////////////////////////////////////////////////////////////////

template<class T>
void SortingX<T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0,temp = 0;

    for(i = 0 ; i < iSize -1;i++)
    {
        min_index = i;

        for(j = i + 1;j< iSize;j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }

        if(i != min_index)
        {   
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }    
    }
}

////////////////////////////////////////////////////////////////////////////
//
// Function Name  : InsertionSort 
// Description    : Implements Insertion Sort 
// Author         : Kartik Ganesh Jare 
// Date           : 08/7/25 
// Prototype      : void SortingX<T>::InsertionSort() 
// Input          : None 
// Output         : Sorts the array in ascending order
//
///////////////////////////////////////////////////////////////////////

template<class T>
void SortingX<T>::InsertionSort()
{
    int i = 0, j = 0,selected = 0;

    for(i = 1; i < iSize;i++)
    {
        for(j = i - 1,selected = Arr[i];(j >= 0) && (Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         Searching generic
//  Description :   Generic implementation of searching algorithms
//  Author :        Kartik Ganesh Jare
//
///////////////////////////////////////////////////////////////////////

template<class T>
class SearchingX    // Increasing
{
    public:
        int *Arr;
        int iSize;
        bool Sorted;
    
    public:
        SearchingX(T);                   
        ~SearchingX();                   
        void Accept();                   
        void Display();                  
        bool LinearSearch(T);            
        bool BiDirectionalSearch(T);     
        bool BinaryserachInc(T);         
        bool BinaryserachDec(T);         
        bool BinaryserachEfficientInc(T);
        bool BinaryserachEfficientDec(T);
        bool CheckSortedDec();           
        bool CheckSortedInc();           
};

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : SearchingX
// Description   : Constructor to allocate memory for array dynamically and initialize values
// Author        : Kartik Ganesh Jare
// Date          : 30/9/25
// Prototype     : SearchingX<T>::SearchingX(T no)
// Input         : Integer no (Size of array)
// Output        : Allocates memory for Arr and initializes Sorted flag
//
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
SearchingX<T>::SearchingX(
                          T no
                         )
{
    iSize = no;
    Arr = new int[iSize];
    Sorted = true;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name  : ~SearchingX
// Description    : Destructor to deallocate memory
// Author         : Kartik Ganesh Jare
// Date           : 30/9/25
// Prototype      : SearchingX<T>::~SearchingX()
// Input          : None
// Output         : Deallocates dynamic array
//
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
SearchingX<T>::~SearchingX()
{
    delete []Arr;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Accept
// Description   : Accepts elements from user and updates Sorted flag
// Author        : Kartik Ganesh Jare
// Date          : 30/9/25
// Prototype     : void SearchingX<T>::Accept()
// Input         : Reads iSize elements from user
// Output        : Stores elements in Arr[]
//
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SearchingX<T>::Accept()
{
    cout<<"Enter "<<iSize<< " elements : \n";

    int i = 0;                 // Loop counter
    
    for(i = 0;i < iSize;i++) 
    {
        cout<<"Enter the element no : "<<i+1<<"\n";
        cin>>Arr[i];

        if(i > 0 && Sorted == true)   // Check if array remains sorted
        {
            if(Arr[i] < Arr[i-1])
            {
                Sorted = false;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays elements of array
// Author        : Kartik Ganesh Jare
// Date          : 30/9/25
// Prototype     : void SearchingX<T>::Display()
// Input         : None
// Output        : Prints elements of Arr[]
//
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SearchingX<T>::Display()
{
    cout<<"Elements of the array are : \n";

    int i = 0;
    
    for(i = 0;i < iSize;i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : LinearSearch
// Description   : Performs linear search; if array is sorted, uses efficient binary search
// Author        : Kartik Ganesh Jare
// Date          : 30/9/25
// Prototype     : bool SearchingX<T>::LinearSearch(T no)
// Input         : Value to search in Arr[]
// Output        : Returns true if found, false otherwise
//
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool SearchingX<T>::LinearSearch(
                                 T no
                                )    //N
{
    int i = 0;
    bool bFlag = false;

    if(Sorted == true)
    {
        cout<<"Data is sorted";

        return BinaryserachEfficientInc(no);
    }

    for(i = 1;i < iSize;i++)
    {
        if(Arr[i] == no)
        {
            bFlag = true;
            break;
        }    
    }

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : BiDirectionalSearch
// Description   : Searches for value from both ends of array simultaneously
// Author        : Kartik Ganesh Jare
// Date          : 30/9/25
// Prototype     : bool SearchingX<T>::BiDirectionalSearch(T no)
// Input         : Value to search in Arr[]
// Output        : Returns true if found, false otherwise
//
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool SearchingX<T>::BiDirectionalSearch(
                                        T no
                                       )     // N/2
{
    int iStrat = 0;
    int iEnd = 0;

    bool bFlag = false;

    for(iStrat = 1,iEnd = iSize - 1;iStrat <= iEnd;iStrat++,iEnd--)
    {
        if(Arr[iStrat] == no || Arr[iEnd] == no)
        {
            bFlag = true;
            break;
        } 
    }

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : BinaryserachInc
// Description   : Performs binary search on increasing sorted array
// Author        : Kartik Ganesh Jare
// Date          : 30/9/25
// Prototype     : bool SearchingX<T>::BinaryserachInc(T no)
// Input         : Value to search in Arr[]
// Output        : Returns true if found, false otherwise
//
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool SearchingX<T>::BinaryserachInc( 
                                    T no
                                   )
{
    int iStart = 0,iEnd = 0,iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == no)
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid]) // First half (left window)
        {
            iEnd = iMid -1;                
        }
        else if(no > Arr[iMid]) // second half (right window)
        {
            iStart = iMid + 1;
        }
    } // End of while 
    
    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : BinaryserachDec
// Description   : Performs binary search on decreasing sorted array
// Author        : Kartik Ganesh Jare
// Date          : 30/9/25
// Prototype     : bool SearchingX<T>::BinaryserachDec(T no)
// Input         : Value to search in Arr[]
// Output        : Returns true if found, false otherwise
//
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool SearchingX<T>::BinaryserachDec( 
                                    T no
                                   )
{
    int iStart = 0,iEnd = 0,iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == no)
        {
            bFlag = true;
            break;
        }
        else if(no > Arr[iMid]) // First half (left window)
        {
            iEnd = iMid -1;                
        }
        else if(no < Arr[iMid]) // second half (right window)
        {
            iStart = iMid + 1;
        }
    } // End of while 
    
    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : BinaryserachEfficientInc
// Description   : Efficient binary search on increasing sorted array; uses linear search if unsorted
// Author        : Kartik Ganesh Jare
// Date          : 30/9/25
// Prototype     : bool SearchingX<T>::BinaryserachEfficientInc(T no)
// Input         : Value to search in Arr[]
// Output        : Returns true if found, false otherwise
//
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool SearchingX<T>::BinaryserachEfficientInc(
                                             T no
                                            )
{
    int iStart = 0,iEnd = 0,iMid = 0;
    bool bFlag = false;

    if(Sorted == false) // New
    {
        cout<<"Data is not sorted\n";

        return LinearSearch(no); // Important
    }

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == no) || (Arr[iStart] == 0) || (Arr[iEnd] == 0)) //Change
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid]) // First half (left window)
        {
            iEnd = iMid -1;                
        }
        else if(no > Arr[iMid]) // second half (right window)
        {
            iStart = iMid + 1;
        }
    } // End of while 
    
    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : BinaryserachEfficientDec
// Description   : Efficient binary search on decreasing sorted array
// Author        : Kartik Ganesh Jare
// Date          : 30/9/25
// Prototype     : bool SearchingX<T>::BinaryserachEfficientDec(T no)
// Input         : Value to search in Arr[]
// Output        : Returns true if found, false otherwise
//
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool SearchingX<T>::BinaryserachEfficientDec( 
                                              T no
                                            )
{
    int iStart = 0,iEnd = 0,iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == no) || (Arr[iStart] == 0) || (Arr[iEnd] == 0)) //Change
        {
            bFlag = true;
            break;
        }
        else if(no > Arr[iMid]) // First half (left window)
        {
            iEnd = iMid -1;                
        }
        else if(no < Arr[iMid]) // second half (right window)
        {
            iStart = iMid + 1;
        }
    } // End of while 
    
    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : CheckSortedInc
// Description   : Checks if array is sorted in increasing order
// Author        : Kartik Ganesh Jare
// Date          : 30/9/25
// Prototype     : bool SearchingX<T>::CheckSortedInc()
// Input         : None
// Output        : Returns true if array is increasing, false otherwise
//
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool SearchingX<T>::CheckSortedInc()
{
    bool bFalg = true;
    int i = 0;

    for(i = 0; i < iSize - 1;i++)
    {
        if(Arr[i] > Arr[i+1]) // change 
        {
            bFalg = false;
            break;
        }
    }

    return bFalg;
}

///////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : CheckSortedDec
// Description   : Checks if array is sorted in decreasing order
// Author        : Kartik Ganesh Jare
// Date          : 30/9/25
// Prototype     : bool SearchingX<T>::CheckSortedDec()
// Input         : None
// Output        : Returns true if array is decreasing, false otherwise
//
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool SearchingX<T>::CheckSortedDec()
{
    bool bFalg = true;
    int i = 0;

    for(i = 0; i < iSize - 1;i++)
    {
        if(Arr[i] < Arr[i+1]) // change 
        {
            bFalg = false;
            break;
        }
    }

    return bFalg;
}

///////////////////////////////////////////////////////////////////////
// Assignment no 34,35,36 functions -> C++ -> Generic
// Write all functions logic in all types of Linked List
///////////////////////////////////////////////////////////////////////

int main()
{
    
    return 0;
}