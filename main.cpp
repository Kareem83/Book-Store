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

	void insertfirst(string newitem,int n) {
		node* newnode = new node;
		newnode->item = newitem;
		newnode->num = n;

		if (size == 0)
		{
			head = tail = newnode;
			newnode->next = NULL;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
		size++;
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
		node* current = new node;
		current = head;
		
		while (current != NULL)
		{
			if (current->item == nitem)
			{
				if (current->num == 0)
				{
					cout << "the book not available\n";
					popitem(current->item);
					goto jump;
				}
				cout <<endl<< "the book is available and we have (" << current->num << ") copies of this book"<<endl;
				
				current->num--;
				break;
			}
			current = current->next;
		} 
		
		if (current == NULL)
		{
			cout << "not found the book" << endl;

			jump:
			cout << "if you want to search an another book press 1 " << endl;
			int temp;
			cin >> temp;
			cout<<"Enter Book Name:";
			string tempStr;
			if (temp == 1)
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, tempStr);
				search_node(tempStr);
			}
			else
			{
				return;
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
void enter_book_name() {
	string bookname;
	int nums, nbooks;

	cout << "!!!you have ("; 
	cout<<l.print_size()<< ") books in your book store"<<endl;

	cout << "->please enter the (numbers) of books that you need to enter in your book store " << endl;
	cin >> nbooks;

	for (int i = 0; i < nbooks; i++)
	{
		cout << "-->book name then numbers of copies"<<endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, bookname);

		cin >> nums;
		l.insertfirst(bookname, nums);
	}
}

linkedqueue q;
void buy_book() {
	string namebuyer,bookname;
	int nn;
	l.display();

	cout << "->please enter customer name :";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, namebuyer);
	again:
	cout << "-->how much books you need :";
	cin >> nn;
	if(nn>0)
	{
	for (int i = 0; i < nn; i++)
	{
		cout << "-->please enter the book name :";

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, bookname); 
		//cin >> bookname;  
		l.search_node(bookname);
		q.push(namebuyer, bookname);
		cout << endl;
	}
	}
	else{
	  cout<<"\n(invalid number try again) "<<endl;
	  goto again;
	  }
}

int main() {
	l.insertfirst("rich dad & poor dad", 5);
	l.insertfirst("automic habits", 5);
	l.insertfirst("the art of not given a *", 5);
	l.insertfirst("pistachio fury", 5);
	l.insertfirst("the five am club", 5);
	l.insertfirst("the secret", 3);
	l.insertfirst("tyt", 10);
	l.insertfirst("gg", 1);

	cout << "                                                  MAIN MENU\n\n";
	cout << "1. DISPLAY BOOKS\n";
	cout << "2. ADD NEW BOOKS\n";
	cout << "3. DELETE A BOOK \n"; 
	cout << "4. BUY A BOOK\n";
	cout << "5. DISPLAY BUYER DATA(name , bookname)\n";
	cout << "6. EXIT\n\n";
    //int choice;
    //cin>>choice;
	while (1) {
		string n;
		cout << "please enter your choice :";
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
			cout << "****************** Book is Added Successfully *****************" << endl;
			break;
		case 3:
		    l.display();
			cout << "->please enter the book name you want to delete :"<<endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, n);
			l.popitem(n);
			cout << "***************** Book is Deleted Successfully ***************** " << endl;
			break;
		case 4:
			buy_book();
			cout << "***************** The book is sold successfully **************** \n" << endl;
			break;
		case 5:
			q.display();
			break;
		case 6:
		//	cout << "****************** thanks sir :)  ********************" << endl;
			goto bay;
			break;
		default:
			cout << "\n(invalied choice)" << endl;
		}
	}

       bay:
			cout << "****************** thanks sir :)  ********************" << endl;



}
