#include  <iostream>
#include  "linkedlist.h"

using namespace std;

int main()
{
	Hole h  ;
	int i ,y , no_of_Processes;
	cout << "Choose Which Algorithm Do you Want " << endl ;
	cout << "1) First Fit" << endl ;
	cout << "2) Best  Fit" << endl ;
	cout << "3) worst Fit" << endl ;
	cin >> i ;
	cout << "Enter the Number of Processes" << endl ;
	cin >> no_of_Processes;
	h.setnoofprocess(no_of_Processes);
	switch(i)
	{
	case 1:
	h.create_hole();
	for(int j=0 ; j<no_of_Processes ; j++)
	{
	h.first_fit();
	h.Display();
	
	}
	h.printprocess();
	
	cout<<"Do you Want to Deallocate ??" << endl ;
	cout << "1)yes or 2)No " << endl ;
	cin >> y ;
	if(y==1){h.Deallocate();}
	break ;

	case 2:
	h.create_hole();
	for(int j=0 ; j<no_of_Processes ; j++)
	{
	h.best_fit();
	h.Display();	
	}
	h.printprocess();
	cout<<"Do you Want to Deallocate ??" << endl ;
	cout << "1)yes or 2)No " << endl ;
	cin >> y ;
	if(y==1){h.Deallocate();}
	break ;

	case 3:
	h.create_hole();
	for(int j=0 ; j<no_of_Processes ; j++)
	{
	h.worst_fit();
	h.Display();	
	}
	h.printprocess();
	cout<<"Do you Want to Deallocate ??" << endl ;
	cout << "1)yes or 2)No " << endl ;
	cin >> y ;
	if(y==1){h.Deallocate();}
	break ;
	}
	system("pause");	
	return 0 ;
}