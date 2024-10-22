#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void get_next(char b[],int *next){
    next[1]=0;
    int i=1,j=0;
    while (i<b[0])
    {
        if(j==0||b[i]==b[j]){
            i++;j++;
            if(b[i]!=b[j]){
                next[i]=j;
            }
            else next[i]=next[j];
        }
        else j=next[j];
    }
}

int KMP(char a[],char b[]){
    int i=1,j=1,p,q;
    int len1=strlen(a),len2=strlen(b);
    int *next=(int *)malloc(sizeof(int)*(len2+1));
    get_next(b,next);
    while(i<a[0]&&j<b[0]){
        if(a[i]==b[j]||j==0){
            i++;j++;
        }
        else{
            j=next[j];
        }
    }
    if(j>b[0]) return i-b[0];
    else return 0;
} 


int main(){
    char a[10]={9,'a','b','c','b','a','b','a','c','a'};
    char b[4]={3,'b','a','c'};
    printf("%d",KMP(a,b));
    return 0;
}
