#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int strCompare(char *s1,char *s2,int i){
    if(i>strlen(s1) && i>strlen(s2)){
        return 0;
    }

    if(i>strlen(s1)){
        return -1;
    }
    if(i>strlen(s2)){
        return 1;
    }

    if( (s1[i] | 32) < (s2[i] | 32) ){
        return -1;
    }
    else if(s1[i]>s2[i] || ((s1[i] | 32) > (s2[i] | 32))){
        return 1;
    }
    return strCompare(s1,s2,i+1);
}

int main(){
    int n1;
    printf("Enter the size of first string\n");
    scanf("%d",&n1);
    char s1[n1];
    printf("Enter the string\n");
    scanf("%s",&s1);
    int n2;
    printf("Enter the size of second string\n");
    scanf("%d",&n2);
    char s2[n2];
    printf("Enter the string\n");
    scanf("%s",&s2);

    int ans=strCompare(s1,s2,0);
    printf("%d",ans);
    return 0;
}