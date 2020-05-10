#include<stdio.h>
#include<string.h>
int main()
{
    int a1[1000]={0},a2[1000]={0};
    char b1[100]={'0'},b2[100]={'0'};
	int ll1,ll2;
	int i,j;
    scanf("%s%s",b1,b2);
    ll1=strlen(b1);
    ll2=strlen(b2);
    for(i=1,j=ll1; j>0; --j) {
        a1[i]=b1[j]-'0';
        i++;
    }
    for(i=1,j=ll2; j > 0; --j){
        a2[j]=b2[i]-'0';
        i++;
    }
    for(i=1; i<=(ll2>ll1?ll2:ll1); i++)
    {
        a1[i]+=a2[i];
        if(a1[i]>9){
            a1[i+1]+=1;
            a1[i]-=10;
        }
    }
    for(j=i - 1; j >0; j--)
        printf("%d",a1[j]);
    return 0;
}
