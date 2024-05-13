#include <iostream>
using namespace std;

struct CELL{
int index;
CELL *Previous;
CELL *Next;
};

void add_Tail( CELL *p, int );
void add_List( CELL *, int, int );
void del_List( CELL *, int );
void make_Header( CELL *, int );
void show_List( CELL * );
void delete_all( CELL * );
int main( void )
{
const int DNUM = 5;
CELL *header = new CELL;
make_Header( header, 0 );
cout << ">> Now making a new list" << endl;

for( int i = 1; i < DNUM; ++i ){
    add_Tail( header, i );
}

show_List( header );
cout << ">> Add a cell #10 next to the #3 cell" << endl;
add_List( header, 10, 3 );
show_List( header );

#ifdef ADDTEST
cout << ">> Add a cell #11 as the first cell" << endl;
add_List( header, 11, 0 );
show_List( header );
cout << ">> Add a cell #12 next to the #5 cell" << endl;
add_List( header, 12, 5 );
show_List( header );
cout << ">> Add a cell #20 to the tail of the list" << endl;
add_Tail( header, 20 );
show_List( header );
#endif

#ifdef DELTEST
cout << ">> Delete the cell of which index is 2" << endl;
del_List( header, 2 );
show_List( header );
cout << ">> Delete the cell of which index is 5" << endl;
del_List( header, 5 );
show_List( header );
#endif

delete_all( header );

#ifdef REMOVE
show_List( header );
#endif

return 0;
}

void add_Tail( CELL *p, int index )
{
    CELL *newcell = new CELL;
    while( p->Next != NULL ){
        p = p->Next;
    }
    newcell->index = index;
    newcell->Previous = p;
    newcell->Next = p->Next;
    p->Next = newcell;
}

void add_List( CELL *p, int index, int target )
{
    CELL *newcell = new CELL;
    while( p->Next != NULL && p->index != target ){
        p = p->Next;
    }
    if( p->Next == NULL ){
        cout << "<< Not added: There is no target in the list!!" << endl;
    } else {
        cout << "<< Cell added" << endl;
        newcell->index = index;
        newcell->Previous = p;
        newcell->Next = p->Next;
        (p->Next)->Previous = newcell;
        p->Next = newcell;
    }
}

void del_List( CELL *p, int target )
{
    while( p->Next != NULL && p->index != target ){
        p = p->Next;
    }
    if( p->Next == NULL ){
        cout << "<< Not deleted: There is no target in the list!!" << endl;
    } else {
        (p->Previous)->Next = p->Next;
        (p->Next)->Previous = p->Previous;
    }
}
void make_Header( CELL *p, int index )
{
    p->index = index;
    p->Previous = NULL;
    p->Next = NULL;
} 
void show_List( CELL *p ){
    cout << "---------------------------" << endl;
    cout << "Current List: " << endl;
    while( p->Next != NULL ){
        p = p->Next;
        cout << "---------------------------" << endl;
        cout << " Index: " << p->index << endl;
        cout << " Address: " << p << endl;
        cout << " Previous cell: " << p->Previous << endl;
        cout << " Next cell: " << p->Next << endl;
        }
    cout << "---------------------------" << endl;
}
void delete_all( CELL *p )
{
    if( p->Next != NULL ){
        delete_all( p->Next );
        delete p;
    } else {
        delete p;
    }
} 