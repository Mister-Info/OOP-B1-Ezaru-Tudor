#include<bits/stdc++.h>

using namespace std;
char sen[256],*p,a[256][256],sep[]=" ";
int k;
int main()
{
   scanf("%[^\n]s", sen);
    p=strtok(sen,sep);
    while(p){

        strcpy(a[++k],p);
        p=strtok(NULL,sep);
    }

    for(int i=1;i<k;++i)
        for(int j=i+1;j<=k;++j){
        if(strlen(a[i])<strlen(a[j]))
        {
            swap(a[i],a[j]);
        }
        else if(strlen(a[i])==strlen(a[j]))
        {
            if(strcmp(a[i],a[j])<=0)
            {
                swap(a[i],a[j]);
            }
        }
    }

    for(int i=1;i<=k;++i)
    {
        printf("%s \n",a[i]);
    }
       return 0;
}
