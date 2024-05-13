#include<iostream>
#include<string>
using namespace std;
struct CELL{
int num;
string name;
};
int main( void )
    {
    CELL data[] = {{1,"AA"}, {2,"BB"}, {3,"CC"}};
    CELL *pdata;
    int dnum = sizeof(data) / sizeof(data[0]);
    cout << "---------------------" << endl;
    cout << "Operation by Array" << endl;
    for( int i = 0; i < dnum; ++i ) {
        cout << "No:" << data[i].num << ", Name: "
        << data[i].name << endl;
}
pdata = data;
cout << "---------------------" << endl;
cout << "Operation by Pointer" << endl;
for( int i = 0; i < dnum; ++i ) {
    cout << "No:" << pdata->num << ", Name: "
    << pdata->name << endl;
/* p->next は (*p).next に同じ */
++pdata;
}
cout << "---------------------" << endl;
    pdata = data+1;
cout << "---------------------" << endl;
cout << "No:" << pdata->num << ", Name: "
    << pdata->name << endl;
cout << "---------------------" << endl;
return 0;
} 