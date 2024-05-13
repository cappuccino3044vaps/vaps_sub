
#include<iostream>
#include<string>
using namespace std;
struct CELL{
int index;
CELL *next;
};
void add_list( CELL *, int );
void print_list( CELL * );
int main( void )
{
    const int DAT_NUM = 10;
    CELL *header = new CELL;
    header->next = NULL; /* header->next は (*header).next に同じ */
    header->index = 0;
    /* header 以降にデータを追加 */
    for( int i = 0; i < DAT_NUM; ++i ) {
        add_list( header, i );
    }
    print_list( header->next );
    return 0;
}
void add_list( CELL *p, int n )
{
    CELL *newcell = new CELL;
    while( p->next != NULL ){
    p = p->next;
    }
    newcell->next = p->next;
    p->next = newcell;
    newcell->index = n;
}
void print_list( CELL *p )
{
    cout << "-----------------------------" << endl;
    cout << " Linear-List: " << endl;
    cout << " No. Pointer Linked to" << endl;
    cout << "-----------------------------" << endl;
    while( p != NULL ){
    cout << " " << p->index << " " << p << " " << p->next << endl;
    p = p->next; /* 次のセルにポインタを移動 */
    }
    cout << "-----------------------------" << endl;    
} 