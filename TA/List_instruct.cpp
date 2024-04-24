#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;
typedef struct{
    char name[10];
    int id;
    double average;
    int next;
} 
    st_result;
    const int TERMIN = INT_MAX;
    const int start_n=6;
    void make_list( st_result *, st_result *, int );
    void print_list( st_result *, int );
    void add_list(st_result *,st_result *,int);
int main( void ){
    st_result st_dat[]= {
    { "HD", 0, 0.0, 0 },
    { "AA", 1001, 60.5, 0 },
    { "BB", 1025, 53.2, 0 },
    { "CC", 1012, 82.3, 0 },
    { "DD", 1003, 73.8, 0 },
    { "EE", 1033, 93.2, 0 }};
    st_result new_dat[]= {
    { "AB", 1032, 79.1, 0 }};
    int st_num = sizeof(st_dat)/sizeof(st_dat[0]);
    st_result st_list[st_num+1];
    make_list( st_dat, st_list, st_num );
    add_list(st_list, new_dat, st_num);
    print_list( st_list, st_num );
    return 0;
}

void make_list( st_result *dat, st_result *list, int num )
{
    for( int i = 0; i < num; ++i ){
    list[i] = dat[i];
    if(i==num-1){
        list[i].next=TERMIN;
    }else{
    list[i].next = i+1;
        }
    }
}

void print_list( st_result *list, int num )
{
    cout << "----------------------------------" << endl;
    cout << "Linear-List: " << endl;
    cout << " Name ID Ave. Next " << endl;
    cout << "----------------------------------" << endl;
    for( int i=1; i<=num; ++i )
    cout << i << " " << list[i].name << " "
    << setw(4) << right << list[i].id << " "
    << setw(4) << fixed << setprecision(1) << list[i].average << " "
    << setw(10) << left << list[i].next << endl;
    cout << "----------------------------------" << endl;
} 
void add_list(st_result *list,st_result *new_dat,int num){
    list[num]=new_dat[0];
    list[num].next=list[start_n].next;
    list[start_n].next=num;
}