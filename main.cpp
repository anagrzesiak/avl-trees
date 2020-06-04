#include"header.h"
#include<ctime>
#include<iostream>

using namespace std;


//void random(AVL* c)
//{
//	for (int i = 0; i < 10; i++)
//	{
//		c->Insert(rand() % 50);
//	}
//}


int main() {

	srand(time(NULL));

	AVL* ana = new AVL;
	//random(ana);
	ana->Insert(1);
	ana->Insert(2);
	ana->Insert(3);
	ana->Insert(8);
	ana->Insert(9);
	ana->Insert(5);
	ana->Insert(17);
	ana->Insert(12);
	ana->Insert(18);
	ana->Insert(14);
	ana->Insert(10);
	ana->Insert(20);
	ana->Insert(19);
	ana->Print2D();
	cout << endl;
	cout << "nowe" << endl;
	cout << endl;
	ana->Show();
	//ana->Remove(7);
	ana->Show();
	ana->Print2D();

	system("PAUSE");
	return 0;

}