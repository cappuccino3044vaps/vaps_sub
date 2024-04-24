#include <iostream>
#include <vector>
#include <cstdlib>
#include <sys/time.h>
#include <unistd.h>
using namespace std;
int main(void)
{
    const int R_MAX = 100;
    const int DAT_NUM = 200;
    const int SLEEP_TIME = 1000000;
    vector<int> dat;
    timeval tv;
    int start, end;
    srand((unsigned)time(NULL));

    for( int i = 0; i < DAT_NUM; ++i ){
        dat.push_back( rand() % R_MAX );
        cout << dat[i] << " ";
    }
    cout << endl;

    gettimeofday(&tv,NULL);
    start = 1000000*tv.tv_sec+tv.tv_usec;
    usleep( SLEEP_TIME );
    gettimeofday(&tv,NULL);
    end = 1000000*tv.tv_sec+tv.tv_usec;
    cout << "Run Time: " << end-start << "[us]" << endl;
    return 0;
}