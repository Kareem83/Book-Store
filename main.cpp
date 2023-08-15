#include <iostream>
#include <limits>
#include <string>
using namespace std;

class linkedqueue {
 private:
  	struct node {
		string customername;
		string bookname;
		node* next;
	};

	node* front, * back;
	int size;

 public:

	linkedqueue() :front(NULL), back(NULL), size(0)
	{
	}

	bool is_empty()
	{
		return (back == NULL);
	}

	void push(string new_item,string nbook)
	{
		node* new_ptr = new node;
		new_ptr->customername = new_item;
		new_ptr->bookname = nbook;
		new_ptr->next = NULL;

		if (is_empty())
		{
			front = back = new_ptr;
		}
		else
		{
			back->next = new_ptr;
			back = new_ptr;
		}
		size++;
	}

	void get_size()
	{
		cout << size << endl;
	}

	void display()
	{
		if (is_empty())
		{
			cout << "queue is empty " << endl;
		}
		else
		{
			node* print = front;

			cout << "Buyers Data :" << endl;
			while (print != NULL)
			{
				cout << "customer name :(" << print->customername << ") -> book name :(" << print->bookname << ")" << endl;
				print = print->next;
			}
		}
	}
};

class Linkedlist {

 private:
	struct node {
		string item;  //book name 
		int num;   //copies numbers
		node* next;
	};

	node* head;
	node* tail;
	int size;

 public:
	Linkedlist() {
		head = tail = NULL;
		size = 0;
	}

	bool isempty()
	{
		return size == 0;
	}

	int print_size()
	{
		return size;
	}

    void insertfirst(string newitem, int n) 
	{
         node* newnode = new node;
         newnode->item = newitem;
         newnode->num = n;	
         newnode->next = NULL;
         if(newnode->num != 0){
         if (size == 0)
           {
              head = tail = newnode;
            }
	  
         else
           {
             node* search = head;
             while (search != NULL)
                    {
                      if (newitem == search->item)
                        {
                             search->num += n;
                             delete newnode; // Since the item already exists, we don't need the newly created node
                             return;
                        }
                      search = search->next;
                    }
             newnode->next = head;
             head = newnode;
            }
         size++;
         }
         else
        {
	       cout<<"(Sorry  wrong number we have to go back)\n ";
	       return;
        }
    }


    void addnew(string newbook, int n)
	{
     node* newnode = new node;
     newnode->item = newbook;
     newnode->num = n;	
     newnode->next = NULL;
    
     bool again =false;
     while (!again){
        cout << "-->BOOK NAME then numbers of COPIES"<<endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, newbook);
		
		cin >> n;
        newnode->item = newbook;
        newnode->num = n;	
     if(newnode->num > 0)
	 {
        if (size == 0)
        {
          head = tail = newnode;
        }
        else
       {
         node* search = head;
         while (search != NULL)
            {
               if (newbook == search->item)
                {
                  search->num += n;
		   		  cout << "****************** Copies increased Successfully *****************\n" << endl;
                  delete newnode; // Since the item already exists, we don't need the newly created node
                  return;
                }
               search = search->next;
            }
         newnode->next = head;
         head = newnode;
        }
        size++;
	    cout << "****************** Book is Added Successfully *****************\n" << endl;
        again=true;
      }
     else
       {
	     cout<<"(Try Again Number Of Copies Must Be More Than (0))\n\n ";
	     again = false;
        }
     }
    }
	void popitem(string popitem)
	{
	 if (isempty())
		   {
			 cout << "list is empty in pop item " << endl;
		    }

	 node* current, * prv;

	 if (head->item == popitem)
		   {  
			 current = head;
			 head = head->next;
			 free(current);
			 size--;
			 if (size == 0)
			 {
				tail = NULL;
				delete tail;
			  }
		    }
	 else
		   {
			 current = head->next;
			 prv = head;

			 while (current != NULL)
			    {
				 if (current->item == popitem)
					 break;

				 prv = current;
				 current = current->next;
			    }
		 	 if (current == NULL)
			  {
				cout << "not found " << endl;
			   }
			 else
			   {
			  	 prv->next = current->next;
				 if (tail == current)
				  {
					tail = prv;
				   }
				 free(current);
				 size--;
			    }
		    }
    }	
    void search_node(string nitem)
    {
      node* current = head;
    
      while (current != NULL)
      {
        if (current->item == nitem)
       {
            if (current->num == 0)
            {
                cout << "The book is not available\n";
                popitem(current->item);
                break;
            }
            
            cout << endl << "The book is available, and we have (" << current->num << ") copies of this book" << endl;
            cout << "***************** The book is sold successfully ****************" << endl;
            current->num--;
            break;
        }
        current = current->next;
       }
    
      if (current == NULL)
      {
         cout << "(The book was not found)\n" << endl;
        
         while (true)
        {
            cout << "If you want to search another book, press (1). To return, press (2): ";
            int temp;
            cin >> temp;
            
            if (temp == 1)
            {
                cout << "Enter Book Name: ";
                string tempStr;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, tempStr);
                search_node(tempStr);
                break;
            }
            else if (temp == 2)
            {
                return;
            }
            else
            {
                cout << "Invalid input. Please try again." << endl;
            }
        }
       }
    }

	void display()
	{
		node* print = head;
		cout<<"Available Books:"<<endl;
		while (print != NULL)
		{
			cout <<"book name: ("<< print->item << ")\t\t\tcopies:("<<print->num<<")"<<endl;
			print = print->next;
		}
		cout << endl;
	}

};

Linkedlist l;
void enter_book_name() 
{
	string bookkname;
	int nums, nbooks;
	cout << "!!!you have ("; 
	cout<<l.print_size()<< ") books in your book store"<<endl;
	cout << "->please enter the (numbers) of books that you need to enter in your book store " << endl;
	cin >> nbooks;
	for (int i = 0; i < nbooks; i++)
	{
		
		l.addnew(bookkname, nums);

		
    }
}
linkedqueue q;
void buy_book() {
    string customerName, bookName;
    int numBooks;
    l.display();
    cout << "->Please Enter CUSTOMER NAME: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, customerName);

    bool again = false;
    while (!again)
	{
	
     cout << "-->How Many Books Do You Need: ";
     cin >> numBooks;
	
     if (numBooks > 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < numBooks; i++) {
            cout << "-->Please Enter The BOOK NAME: ";
            getline(cin, bookName);
            l.search_node(bookName);
            q.push(customerName, bookName);
            cout << endl;
        }
		again = true;
     } 
	 else {
        cout << "\n(Invalid Number, Please Try Again) " << endl; 
     }
	}
}

void menu()
{

	cout << "                                                  MAIN MENU\n\n";
	cout << "1. DISPLAY BOOKS\n";
	cout << "2. ADD NEW BOOKS\n";
	cout << "3. DELETE A BOOK \n"; 
	cout << "4. BUY A BOOK\n";
	cout << "5. DISPLAY BUYER DATA(name , bookname)\n";
	cout << "6. EXIT\n\n";

}

void Avbooks()
{
 l.insertfirst("fiverules", 5);
 l.insertfirst("habits", 5);
 l.insertfirst("art", 5);
 l.insertfirst("fury", 5);
 l.insertfirst("club", 5);
 l.insertfirst("thesecret", 3);
 l.insertfirst("tyt", 10);
 l.insertfirst("ggg", 1);
}
void logic(){
 bool exitLoop = false;
 while (!exitLoop) 
  {
     string n;
     cout << "Please enter your choice: ";
     int choice;
     cin >> choice;
     cout << endl;

     switch (choice)
	  {
         case 1:
            l.display();
            break;
         case 2:
            enter_book_name();
            // cout << "****************** Book is Added Successfully *****************" << endl;
            break;
         case 3:
            l.display();
            cout << "-> Please enter the book name you want to delete: \n" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, n);
            l.popitem(n);
            cout << "***************** Book is Deleted Successfully ***************** " << endl;
            break;
         case 4:
            buy_book();
            cout << "\n*****************  thank you  **************** \n" << endl;
            break;
         case 5:
            q.display();
            break;
         case 6:
            cout << "****************** THANKS SIR :)  ********************" << endl;
            exitLoop = true;
            break;
         default:
            cout << "\n(Invalid Choice)" << endl;
        }
    }

}
int main()
{

 Avbooks();
 menu();
 logic();

}
