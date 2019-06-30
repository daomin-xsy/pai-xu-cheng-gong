
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>      //sort
using namespace std;
struct Student
{
    char index[30];
    char college[30];
    char name[30];
    int score[7];
    char rename[20];
    double average;
};
bool cmp( Student & a, Student &b ){      //比较平均分大小
    return a.average>b.average;
}
int main()
{
    ifstream out("/Users/s20181105303/Desktop/选手信息.txt");
    int number,head,end;
    double sum=0;
    out>>number;
    Student student[number];
    Student  refereename[7];
    for(head=0;head<number;head++)
    {
        out>>student[head].index>>student[head].college>>student[head].name;
    }
    ifstream out1("/Users/s20181105303/Desktop/裁判信息.txt");
    for(head=0;head<7;head++){
        out1>>refereename[head].rename;
        for(end=0;end<number;end++){
            out1>>student[end].score[head];
        }
    }
    
    
    for(head=0;head<number;head++)
    {
        int max=0;
        for(end=0;end<7;end++)
        {
            if(student[head].score[end]>max)
            {
                max=student[head].score[end];
            }
        }
        for(end=0;end<7;end++)
        {
            if(student[head].score[end]==max)
            {
                student[head].score[end]=0;
            }
        }
    }
    for(head=0;head<number;head++)
    {
        int min;
        for(end=0;end<7;end++)
        {
            if(student[head].score[end]!=0)
            {
                min=student[head].score[end];
            }
        }
        for(end=0;end<7;end++)
        {
            if(student[head].score[end]<min&&student[head].score[end]!=0)
            {
                min=student[head].score[end];
            }
        }
        for(end=0;end<7;end++)
        {
            if(student[head].score[end]==min)
            {
                student[head].score[end]=0;
            }
        }
    }
    for(head=0;head<number;head++)
    {
        sum=0;
        for(end=0;end<7;end++)
        {
            sum=sum+student[head].score[end];
        }
        student[head].average=sum/5;
    }
    sort(student,student+number,cmp);   //结构体数组首地址，末地址，自定义函数 比较结构体大小
    ofstream in("/Users/s20181105303/Desktop/最后得fen.txt");
    if(in.is_open())
    {
        for(head=0;head<number;head++)
        {
            in<<student[head].index<<" "<<student[head].college<<" "<<student[head].name<<" "<<student[head].average<<endl;
        }
        out.close();
    }
    return 0;
}
