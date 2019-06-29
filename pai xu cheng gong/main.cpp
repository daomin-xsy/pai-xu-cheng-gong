#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>     //sort排序
using namespace std;
struct Stu
{
    char index[20];
    char college[20];
    char name[20];
    int score[7];
};
bool cmp(  ){      //比较平均分大小
    return ;
}
int main()
{
    ifstream out("/Users/s20181105303/Desktop/选手信息.txt");
    int number,i,j;
    out>>number;
    Stu s[number];
    for(i=0;i<number;i++){
        out>>s[i].index>>s[i].college>>s[i].name;
    }
    
    ifstream out1("/Users/s20181105303/Desktop/裁判信息.txt");
    for(i=0;i<number;i++){
        for(j=0;j<7;j++){
            out1>>s[i].score[j];
        }
    }
    for(i=0;i<number;i++){
        int max=0;
        for(j=0;j<7;j++){
            if(s[i].score[j]>max){
                max=s[i].score[j];
            }
        }
        for(j=0;j<7;j++){
            if(s[i].score[j]==max){
                s[i].score[j]=0;
            }
        }
    }
    for(i=0;i<number;i++)
    {
        int min;
        for(j=0;j<7;j++){
            if(s[i].score[j]!=0){
                min=s[i].score[j];
            }
        }
        for(j=0;j<7;j++)
        {
            if(s[i].score[j]<min&&s[i].score[j]!=0){
                min=s[i].score[j];
            }
        }
        for(j=0;j<7;j++)
        {
            if(s[i].score[j]==min)
            {
                s[i].score[j]=0;
            }
        }
    }
    sort(s,s+number,cmp);     //结构体数组首地址，末地址，自定义函数 比较结构体大小
    ofstream in("/Users/s20181105303/Desktop/最终得分.txt");
    if(in.is_open())
    {
        for(int i=0;i<number;i++)
        {
            in<<s[i].index<<" "<<s[i].college<<" "<<s[i].name<<endl;
        }
        out.close();
        
    }
    return 0;
}

