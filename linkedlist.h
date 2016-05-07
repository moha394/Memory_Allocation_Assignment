#include  <iostream>
#include <string>
#include <math.h>
#include  <algorithm>
using namespace std ;

class Node
{
private:
	int _address;
	int _size ;
	int Process_number ;
	int _Prosize;
	Node *next ;
	int no_of_Process;
	
	
public:
	Node()
	{
		_address=0;
		no_of_Process=0;
		Process_number=0;
		_size =0 ;
		_Prosize=0;
		next =nullptr;
	}

	Node(int d ,int c , int l , int k,int n)
	{
		_address=d;
		Process_number=l;
		_size=c;
		_Prosize=k;
		no_of_Process=n;
		next =nullptr;

	}
	
	void set_address(int d){_address =d ;}
	int get_address(){return _address ;}
	void set_Processnumber(int l){Process_number =l ;}
	int get_Processnumber(){return Process_number ;}
	void set_size(int c){_size=c;}
	int get_size(){return _size ;}
	void set_prosize(int k){_Prosize=k;}
	int get_prosize(){return _Prosize;}
	void set_next(Node *ptr){next=ptr;}
	Node* get_next(){return next;}

	friend class Hole;


};

class Hole
{
private:
	Node*head ;
	int holesno;
	int  k ;
	int Process[30];
	int processno;
	int count ;
public:
	Hole()
	{
		head=nullptr;
		holesno=0;
		k=0;
		Process[30];
		processno = 0 ;
		count = 0;
	}

	void setnoofprocess(int m){processno = m ;}
	int getnoofprocess(){ return processno;}
	bool isEmpty()
	{
		if(head==nullptr)
		return true;
		return false ;
	}
	
	bool filled(int size)
	{
		if (size <=0)
			return true;
		return false;
	}
	
	bool sizable(int size , int Pro_size)
	{
		if(size>=Pro_size)return true;
		return false;
	}
	
	void add_End(int address , int size , int pro_size , int Process_number , int noofpro)
	{
		if(isEmpty())
			add_Front( address , size , pro_size , Process_number,noofpro);

		else 
		{	
			Node *tmp = head ;
			while (tmp->next!=nullptr)
			{
				tmp=tmp->next;
			}
			Node *nw =new Node	( address , size ,  pro_size,Process_number,noofpro);
			tmp->next=nw ;
		}
	}
	
	void add_Front(int address , int size , int pro_size , int Process_number , int noofpro )
	{
		Node* nw = new Node ( address ,  size ,  pro_size,Process_number,noofpro );
		nw->set_next(head);
		head=nw ;
	}
	
	void create_hole()
	{
		int holes;
		cout << "Enter The Number of the Holes " << endl ;
		cin >> holes;
		holesno=holes;
		int address , size , pro_size=0  , Process_number = 0 ,noofpro=0;
		for(int i=0 ; i<holes ; i++)
		{
			cout << "Enter The Address" << endl ;
			cin >> address ;
			cout << "Enter The size" << endl ;
			cin >> size ;
			add_End(address,size,pro_size , Process_number,noofpro);
				
		}


	}
	
	void first_fit()
	{
		
		int Process_number , Process_size , x , y;
		cout << "Enter The Process Number" << endl ;
		cin >> Process_number ; 
		cout << "Enter The Size of Process" << endl ;
		cin >> Process_size;
		Node* temp = head ;
		
		for(int i=0 ; i<holesno  ; i++)
		{
			
			if( temp!=nullptr)
			{
				if(sizable(temp->get_size(),Process_size)==true )
				{
				x=temp->get_address();
				x=Process_size + x + 1 ;
				temp->set_address(x);
				
				y=temp->get_size();
				y=y-Process_size;
				temp->set_size(y);
			 
				temp->set_Processnumber(Process_number);
				temp->set_prosize(Process_size);
				i=holesno-1;
			
				Process[count]=temp->get_Processnumber();
				count++;	
				}		
			
				else if (sizable(temp->get_size(),Process_size)==false)
				{
					temp=temp->next ;
				}	
			}
		
			if(temp==nullptr){cout << "Sorry No available Memory Space";}
			
		}
		

	}
	
	void best_fit()
	{
		int Process_size ,d=0  , x , y , Process_number ,count1=-1; 
		cout << "Enter The Process size " << endl ;
		cin >> Process_size;
		cout << "Enter The Process no." <<endl ;
		cin >> Process_number;
		Node*temp = head ;
		Node *min =head ;
		while(temp!=nullptr)
			{
				
				count1++;
			if (sizable(temp->get_size(),Process_size)==true && temp->get_size() <= min->get_size()&& min->get_size()>Process_size)
			{
				d=count1;
				min=temp;
			}
			if(min->get_size()<Process_size)
			{
				min=min->next ;
			}
				temp=temp->next ;	
			}

		
		temp=head ; 
		
			for(int i =0 ; i<d ; i++)
			{
				temp=temp->next;		
			}
		
				x=temp->get_address();
				x=Process_size + x + 1 ;
				temp->set_address(x);
				
				y=temp->get_size();
				y=y-Process_size;
				temp->set_size(y);
			 
				temp->set_Processnumber(Process_number);
				temp->set_prosize(Process_size);
				Process[count]=temp->get_Processnumber();
				count++;	
				
		

	}

	void worst_fit()
	{
		int Process_size ,d=0  , x , y , Process_number ,count1=-1; 
		cout << "Enter The Process size " << endl ;
		cin >> Process_size;
		cout << "Enter The Process no." <<endl ;
		cin >> Process_number;
		Node*temp = head ;
		Node *max =head ;
		while(temp!=nullptr)
			{
				count1++;

			if (sizable(temp->get_size(),Process_size)==true && temp->get_size() > max->get_size())
			{
				d=count1;
				max=temp;
			}
				temp=temp->next ;	
			}

		
		temp=head ; 
		
			for(int i =0 ; i<d ; i++)
			{
				temp=temp->next;		
			}
		
				x=temp->get_address();
				x=Process_size + x + 1 ;
				temp->set_address(x);
				
				y=temp->get_size();
				y=y-Process_size;
				temp->set_size(y);
			 
				temp->set_Processnumber(Process_number);
				temp->set_prosize(Process_size);
				Process[count]=temp->get_Processnumber();
				count++;
	}
	
	void Deallocate()
	{
		Node*temp =head ; 
		int y  , x , z,count=1 ;
		cout << "Enter the Process you want to Deallocate it " << endl ;
		cin >> y ; 
		while(temp!=nullptr)
		{ 
			if(temp->get_Processnumber()==y)
			{
				cout << "The Deallocated Process is  : " << temp->get_Processnumber() << endl ;
				cout << "The Size of the Process is  : " << temp->get_prosize() << endl ;
				cout << "The Process was allocated in Hole : " << count  << endl ;
				x=temp->get_address()-temp->get_prosize()-1;
				cout << "The Address of the hole is : " << x  << endl ;
				z=temp->get_size()+temp->get_prosize();
				cout << "The Size of the Hole is : " << z  << endl ;
				
			}
			temp=temp->next ;
			count++;
		}

		
	}
	
	void Display()
	{
		int i =1 ;

	Node*temp =head ;
	while(temp != nullptr)
		{
			cout << endl ;
			cout << "The Hole No. :" << i <<endl ;
			cout << endl ;
			cout <<  "The Address of The Hole : " << temp->get_address()<< endl ;
			cout << "The Size of The Hole : " << temp->get_size() << endl ;
			cout<< "The Current Process is " << temp->get_Processnumber() << endl ;
			i++;
			temp=temp->next;
		}
			
	}

	void printprocess()
	{
			cout << "The Memory Now has Processes :" << endl;
			for(int j =0 ; j <getnoofprocess() ; j++)
			{
				cout << "P : " <<  Process[j] << endl ;
			
			}
	}
	~Hole()
	{
		Node* temp;
		while (head != nullptr)
		{
        temp = head;
        head = head -> next;
        delete temp;
		}
	}


};
	
	