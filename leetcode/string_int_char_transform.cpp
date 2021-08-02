#include<iostream>
#include<windows.h>
#include<string>

using namespace std;

namespace wangsf{
    int i = 1;
}

int main(){
    //int 转 string
    int i=78;
    string s = to_string(i);

    //string -> int
    string s2 = "123";
    int i = atoi(s2.data());

    //string -> char*p
    string s = "abc";
    char*p = (char*)s.data();

    //char*p, char[]p -> string
    char*p1 = "456";
    string s3 = p1;

    //char* -> char p[]
    char* p2 = "tyu";
    char p3[88];
    strcpy(p3, p2);
    
    system("pause");
    return 0;
}