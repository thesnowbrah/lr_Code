#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


struct Spisok {
	char el;
	Spisok* next;
	Spisok* prev;
};
struct Point {
	Spisok* h, * c, *l;
	int len;
};

void Fill2(Point* P) {
	cout<< "Please enter string of list elements.\n";
	(*P).len = 0;
	Spisok* Temp;
	string str;
	char c;
	(*P).h = new Spisok;
	(*P).l = (*P).h;
	(*P).h->next = new Spisok;
	(*P).h->next->prev = (*P).h;
	(*P).h->prev = new Spisok;
	(*P).h->prev->next = (*P).h;
	(*P).c = (*P).h;
	int i = 0;
	cin >> str;
	
	for (int i = 0; i < str.length();i++) {
		
		
			if ((*P).len != 0) {
				(*P).c->next->prev = (*P).c;
				(*P).c = (*P).c->next;
			}
			(*P).c->el = str[i];
			(*P).c->next = new Spisok;
			(*P).len++;
		

	}
	(*P).l = (*P).c;
	(*P).l->next = NULL;
}
void Output(Point *P) {
	(*P).c = (*P).h;
	for (int i = 0; i < (*P).len; i++) {
		cout << (*P).c->el << ", ";
		(*P).c = (*P).c->next;
	}
	cout << '\n';
}

void AddToStart(Point* P) {
	char NewEl;
	cout << "\nEnter new element: ";
	cin >> NewEl;
	if ((*P).len == 0) {
		(*P).h = new Spisok;
		(*P).l = (*P).h;
		(*P).h->next = new Spisok;
		(*P).h->next->prev = (*P).h;
		(*P).h->prev = new Spisok;
		(*P).h->prev->next = (*P).h;
		(*P).h->el = NewEl;
		(*P).len++;
	}
	else {
		(*P).h->prev = new Spisok;
		(*P).h->prev->el = NewEl;
		(*P).h->prev->next = (*P).h;
		(*P).h = (*P).h->prev;
		(*P).h->prev = new Spisok;
		(*P).h->prev->next = (*P).h;
		(*P).len++;
	}
	
}
void AddToEnd(Point* P) {
	char NewEl;
	cout << "\nEnter new element: ";
	cin >> NewEl;
	if((*P).len==0){
		(*P).h = new Spisok;
		(*P).l = (*P).h;
		(*P).h->next = new Spisok;
		(*P).h->next->prev = (*P).h;
		(*P).h->prev = new Spisok;
		(*P).h->prev->next = (*P).h;
		(*P).h->el = NewEl;
		(*P).len++;
	}
	else {
		(*P).l->next = new Spisok;
		(*P).l->next->el = NewEl;
		(*P).l->next->prev = (*P).l;
		(*P).l = (*P).l->next;
		(*P).len++;
	}
}
void AddByInd(Point* P) {
	int num; char NewEl;
	cout << "\nPlease enter index from 0 to " << (*P).len - 1 << ": ";
	cin >> num;
	if (num<0 || num>(*P).len - 1) { cout << "\nNo element with such index.\n"; }
	else {
		cout << "Enter new element: ";
		cin >> NewEl; 
		(*P).c = (*P).h;
		for (int i = 0; i < num; i++) {
			(*P).c = (*P).c->next;
		}
		if(num==0){
			(*P).h->prev = new Spisok;
			(*P).h->prev->el = NewEl;
			(*P).h->prev->next = (*P).h;
			(*P).h = (*P).h->prev;
		}
		else {
			(*P).c->prev->next = new Spisok;
			(*P).c->prev->next->el = NewEl;
			(*P).c->prev->next->prev = (*P).c->prev;
			(*P).c->prev = (*P).c->prev->next;
			(*P).c->prev->next = (*P).c;
		}
		(*P).len++;
	}

}
void DeleteAll(Point* P) {
	(*P).c = (*P).h;
	while ((*P).l != (*P).h) {
		(*P).l = (*P).l->prev;
		delete[](*P).l->next;
		(*P).len--;
	}
	delete[](*P).h;

	(*P).len--;
}
void DeleteFirst(Point* P) {
	if ((*P).len == 1) {
		DeleteAll(P);
	}
	else {
		(*P).h = (*P).h->next;
		delete[](*P).h->prev;
		(*P).len--;
	}
}
void DeleteLast(Point* P) {
	if((*P).len==1){
		DeleteAll(P);
	}
	else {
	(*P).l = (*P).l->prev;
	delete[](*P).l->next;
	(*P).len--;
	}
}
void DeleteByInd(Point* P) {
	int num;
	cout << "\nPlease enter index from 0 to " << (*P).len - 1 << ": ";
	cin >> num;
	if (num<0 || num>(*P).len - 1) { cout << "\nNo element with such index.\n"; }
	else {
		(*P).c = (*P).h;
		for (int i = 0; i < num; i++) {
			(*P).c = (*P).c->next;
		}
		if (num == 0) {
			DeleteFirst(P);
		}
		else if(num==(*P).len-1) {
			DeleteLast(P);
		}
		else {
			(*P).c->prev->next = (*P).c->next;
			(*P).c->next->prev = (*P).c->prev;
			delete[](*P).c;
		}
		(*P).len--;
	}
}
void ElemByInd(Point* P) {
	int num;
	cout << "\nPlease enter index from 0 to " << (*P).len - 1 << ": ";
	cin >> num;
	if (num<0 || num>(*P).len - 1) { cout << "\nNo element with such index.\n"; }
	else {
		(*P).c = (*P).h;
		for (int i = 0; i < num; i++) {
			(*P).c = (*P).c->next;
		}
		cout << "Element under " << num << " index: "<< (*P).c->el<<"\n";

	}
}
void SwitchWithInput(Point* P) {
	int num; char c;
	cout << "\nEnter index: ";
	cin >> num;
	if (num<0 || num>(*P).len - 1) { cout << "\nNo element with such index.\n"; }
	else {
		cout << "\nEnter new element: ";
		cin >> c;
		(*P).c = (*P).h;
		for (int i = 0; i < num; i++) {
			(*P).c = (*P).c->next;
		}
		(*P).c->el = c;

	}
}
void SwitchOrder(Point* P) {
	int num1, num2;
	char tmpchar, tmp;
	for (int i = 0; i < (*P).len / 2; i++) {
		num1 = i;
		num2 = (*P).len - i - 1;
		(*P).c = (*P).h;
		for (int i = 0; i < num1; i++) {
			(*P).c = (*P).c->next;
		}
		tmp = (*P).c->el;
		(*P).c = (*P).h;
		for (int i = 0; i < num2; i++) {
			(*P).c = (*P).c->next;
		}
		tmpchar = (*P).c->el;
		(*P).c->el = tmp;
		tmp = tmpchar;
		(*P).c = (*P).h;
		for (int i = 0; i < num1; i++) {
			(*P).c = (*P).c->next;
		}
		(*P).c->el = tmp;
	}
}
void SwitchByIndex(Point* P) {
	int num1, num2;
	char tmpchar, tmp;
	cout << "\nPlease enter index from 0 to " << (*P).len - 1 << ": ";
	cin >> num1;
	if (num1<0 || num1>(*P).len - 1) { cout << "\nNo element with such index.\n"; }
	else {
		cout << "\nPlease enter index from 0 to " << (*P).len - 1 << ": ";
		cin >> num2;
		if (num2<0 || num2>(*P).len - 1) { cout << "\nNo element with such index.\n"; }
		else if(num1!=num2) {
			(*P).c = (*P).h;
			for (int i = 0; i < num1; i++) {
				(*P).c = (*P).c->next;
			}
			tmp = (*P).c->el;
			(*P).c = (*P).h;
			for (int i = 0; i < num2; i++) {
				(*P).c = (*P).c->next;
			}
			tmpchar = (*P).c->el;
			(*P).c->el = tmp;
			tmp = tmpchar;
			(*P).c = (*P).h;
			for (int i = 0; i < num1; i++) {
				(*P).c = (*P).c->next;
			}
			(*P).c->el = tmp;
		}

	}
}
void AddListToStart(Point* P, Point* Pb) {
	if ((*P).len == 0) {
		(*P).h = new Spisok;
		(*P).l = (*P).h;
		(*Pb).c = (*Pb).h; (*P).c = (*P).h;
		for (int i = 0; i < (*Pb).len; i++, (*P).len++) {
			if (i != 0)(*P).c = (*P).c->next;
			(*P).c->el = (*Pb).c->el;
			(*P).c->next = new Spisok;
			(*P).c->next->prev = (*P).c;
			(*Pb).c = (*Pb).c->next;
		}
		(*P).l = (*P).c;
	}
	else {
		(*Pb).c = (*Pb).l;
		for (int i = 0; i < (*Pb).len; i++, (*P).len++) {
			(*P).h->prev = new Spisok;
			(*P).h->prev->next = (*P).h;
			(*P).h = (*P).h->prev;
			(*P).h->el = (*Pb).c->el;
			(*Pb).c = (*Pb).c->prev;
		}
		(*P).h->prev = new Spisok;
		
	}
}
void AddListToEnd(Point* P, Point* Pb) {
	if (P->len == 0)AddListToStart(P, Pb);
	else {
		(*Pb).c = (*Pb).h;
		for (int i = 0; i < (*Pb).len; i++, (*P).len++) {
			(*P).l->next = new Spisok;
			(*P).l->next->prev = (*P).l;
			(*P).l = (*P).l->next;
			(*P).l->el = (*Pb).c->el;
			(*Pb).c = (*Pb).c->next;
		}
		(*P).l->next = new Spisok;
	}
}
void AddListByInd(Point* P, Point* Pb) {
	int num;
	Spisok *temp;
	cout << "\nPlease enter index from 0 to "<< (*P).len-1<<  ": ";
	cin >> num;
	if (num<0 || num>(*P).len-1) {
		cout << "\nWrong input.\n";
	}
	else if (num == 0) { AddListToStart(P, Pb); }
	else {
		(*P).c = (*P).h; (*Pb).c = (*Pb).h;
		for (int i = 0; i < num-1; i++) {
			(*P).c = (*P).c->next;
		}
		temp = (*P).c->next;
		(*Pb).c = (*Pb).h;
		for (int i = 0; i < (*Pb).len; i++) {
			(*P).c->next = new Spisok;
			(*P).c->next->prev = (*P).c;
			(*P).c = (*P).c->next;
			(*P).c->el = (*Pb).c->el;
			(*Pb).c = (*Pb).c->next;
		}
		(*P).c->next = temp;
		(*P).c->next->prev = (*P).c;
		(*P).len += (*Pb).len;
	}
}
void CheckIfListInList(Point* P, Point* Pb) {
	int k = 0; bool IsIn=0;
	(*P).c = (*P).h; (*Pb).c = (*Pb).h;
	for (int i = 0; i < (*P).len;i++, (*P).c=(*P).c->next) {
		if ((*P).c->el == (*Pb).c->el) {
			
			k++;
			if (k != (*Pb).len)(*Pb).c = (*Pb).c->next;
			else { cout << "\nSecondary list is in Primary list.\n"; IsIn = 1; }
		}
		else if (k != 0) {
			(*Pb).c = (*Pb).h; k = 0;
		}

	}
	if (IsIn == 0)cout << "\nSecondary list is not in Primary list.\n";
}
void FindFirstList2InList1(Point* P, Point* Pb) {
	int  tmp, k = 0; bool IsIn = 0; 
	(*P).c = (*P).h; (*Pb).c = (*Pb).h;
	for (int i = 0; i < (*P).len; i++, (*P).c = (*P).c->next) {
		if ((*P).c->el == (*Pb).c->el) {
			if (k == 0) { tmp = i; }
			k++;
			if (k != (*Pb).len)(*Pb).c = (*Pb).c->next;
			else {
				if ((*Pb).len > 1) { cout << "\nFirst Secondary list in Primary list is from index number " << tmp << " to " << i << ".\n"; IsIn = 1; break; }
				else{ cout << "\nFirst Secondary list in Primary list is in index number " <<  i << ".\n"; IsIn = 1; break; }
			}
		}
		else if (k != 0) {
			(*Pb).c = (*Pb).h; k = 0;
		}

	}
	if (IsIn == 0)cout << "\nSecondary list is not in Primary list.\n";
}
void FindLastList2InList1(Point* P, Point* Pb) {
	int  tmp1,tmp2, k = 0; bool IsIn = 0;
	(*P).c = (*P).h; (*Pb).c = (*Pb).h;
	for (int i = 0; i < (*P).len; i++, (*P).c = (*P).c->next) {
		if ((*P).c->el == (*Pb).c->el) {
			if (k == 0) { tmp1 = i; }
			k++;
			if (k != (*Pb).len)(*Pb).c = (*Pb).c->next;
			else {
				if ((*Pb).len > 1) { tmp2 = i; IsIn = 1;  }
				else { tmp1 = i; IsIn = 1; }
			}
		}
		else if (k != 0) {
			(*Pb).c = (*Pb).h; k = 0;
		}

	}
	if (IsIn == 0)cout << "\nSecondary list is not in Primary list.\n";
	else {
		if ((*Pb).len > 1) { cout << "\nFirst Secondary list in Primary list is from index number " << tmp1 << " to " << tmp2 << ".\n"; IsIn = 1;  }
		else { cout << "\nFirst Secondary list in Primary list is in index number " << tmp1 << ".\n"; IsIn = 1;  }
	}
}



void Menu(Point *P, Point *Pb) {
	char c; bool exit = 0;
	for (;;) {
		cout << "\nPlease choose function:\n1. Add element\n2. Delete element\n3. Check\n4. Add list\n5. Find list\n6. Switch\n0. Exit\n";
		cin >> c;
		switch (c) {
		case '1':
			cout << "\nPlease choose how to add:\n1. Add to start\n2. Add to end\n3. Add by index\n";
			cin >> c;
			switch (c) {
			case '1':
				AddToStart(P);
				cout << "\nPrimary list: ";
				Output(P);
				break;
			case '2':
				AddToEnd(P);
				cout << "\nPrimary list: ";
				Output(P);
				break;
			case '3':
				if (P->len == 0)cout << "\nNo elements in list, no index available\n";
				else {
					AddByInd(P);
					cout << "\nPrimary list: ";
					Output(P);
				}
				break;
			default: cout << "\nIncorrect input.\n"; break;
			}
			break;
		case '2':
			if (P->len == 0)cout << "\nNo elements in list, can't delete.\n";
			else {
				cout << "\nPlease choose how to delete:\n1. Delete first element\n2. Delete last element\n3. Delete by index\n4. Delete whole list\n";
				cin >> c;
				switch (c) {
				case '1':
					DeleteFirst(P);
					cout << "\nPrimary list: ";
					Output(P);
					break;
				case '2':
					DeleteLast(P);
					cout << "\nPrimary list: ";
					Output(P);
					break;
				case '3':
					DeleteByInd(P);
					cout << "\nPrimary list: ";
					Output(P);
					break;
				case '4':
					DeleteAll(P);
					cout << "\nPrimary list: ";
					Output(P);
					break;
				default: cout << "\nIncorrect input.\n"; break;
				}
			}
			break;
		case '3':
			cout << "\nPrimary list: ";
			Output(P);
			cout << "\nPlease choose what to check:\n1. Check element by index\n2. Check list length\n3. Check if empty\n";
			cin >> c;
			switch (c) {
			case '1':
				if (P->len == 0)cout << "\nNo elements in list, no index available\n";
				else {
					ElemByInd(P);
				}
				break;
			case '2':
				cout << "List length is " << (*P).len<<"\n";
				break;
			case '3':
				if ((*P).len == 0) {
					cout << "List is empty.\n";
				}
				else cout << "List is not empty.\n";
				break;


			default: cout << "\nIncorrect input.\n"; break;
			}
			break;
		case '4':
			cout << "\nPrimary list: ";
			Output(P);
			cout << "\nPlease choose how to add list:\n1. Add to start\n2. Add to end\n3. Add by index\n";
			cin >> c;
			switch (c) {
			case '1':
				cout << "\nPlease fill secondary list:\n";
				Fill2(Pb);
				AddListToStart(P, Pb);
				DeleteAll(Pb);
				Output(P);
				break;
			case '2':
				cout << "\nPlease fill secondary list:\n";
				Fill2(Pb);
				AddListToEnd(P, Pb);
				DeleteAll(Pb);
				Output(P);
				break;
			case '3':
				if (P->len == 0)cout << "\nNo elements in list, no index available\n";
				else {
					cout << "\nPlease fill secondary list:\n";
					Fill2(Pb);
					AddListByInd(P, Pb);
					DeleteAll(Pb);
					Output(P);
				}
				break;

			default: cout << "\nIncorrect input.\n"; break;
			}
			break;
		case '5':
			cout << "\nPrimary list: ";
			Output(P);
			cout << "\nPlease choose what to find:\n1. If list 2 is in list 1\n2. Index of first found list 2 in list 1\n3. Index of last found list 2 in list 1\n";
			cin >> c;
			switch (c) {
			case '1':
				cout << "\nPlease fill secondary list: \n";
				Fill2(Pb);
				CheckIfListInList(P, Pb);
				DeleteAll(Pb);
				break;
			case '2':
				cout << "\nPlease fill secondary list: \n";
				Fill2(Pb);
				FindFirstList2InList1(P, Pb);
				DeleteAll(Pb);
				break;
			case '3':
				cout << "\nPlease fill secondary list: \n";
				Fill2(Pb);
				FindLastList2InList1(P, Pb);
				DeleteAll(Pb);
				break;
			default:

				break;

			}
			break;
		case '6':
			cout << "\nPlease choose what to switch:\n1. Element by index from input\n2. Switch list order\n3. Switch elements by index\n";
			cin >> c;
			switch (c) {
			case '1':
				if (P->len == 0)cout << "\nNo elements in list, no index available\n";
				else {
					SwitchWithInput(P);
					cout << "\nPrimary list: ";
					Output(P);
				}
				break;
			case '2':
				SwitchOrder(P);
				cout << "\nPrimary list: ";
				Output(P);
				break;
			case '3':
				if (P->len == 0)cout << "\nNo elements in list, no index available\n";
				else {
					SwitchByIndex(P);
					cout << "\nPrimary list: ";
					Output(P);
				}
				break;

			default: cout << "\nIncorrect input.\n"; break;
			}


			break;
		case '0': 
			exit = 1; cout << "\nExitting, bye!\n";
			break;

		default:  cout << "\nIncorrect input.\n"; break;
		}
		if (exit == 1)break;
	}
}

int main() {
	Point P1, P2;
	P1.h=new Spisok;
	P1.h->next = NULL;
	P1.c = P1.h;
	P1.h->prev = NULL;
	P2.h = new Spisok;
	P2.h->next = NULL;
	P2.c = P1.h;
	P2.h->prev = NULL;
	cout << "Hello! \n";
	cout << "Please fill primary list:\n";
	Fill2(&P1);
	cout << "\nCurrent list:\n";
	Output(&P1);
	Menu(&P1, &P2);
	
}