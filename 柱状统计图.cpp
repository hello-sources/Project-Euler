#include<bits/stdc++.h>
using namespace std;
int main()
{
//	string num0,num1,num2,num3;
//	getline(cin,num0);//Ä¬ÈÏ\nÎª×Ö·û´®·Ö¸ô·û 
//	getline(cin,num1);
//	getline(cin,num2);
//	getline(cin,num3);
	//cout<<num0<<endl<<num1<<endl<<num2;
//	for(int i=0;i<num0.length();i++)
//	{
//		char temp=num0.at(i);
//		cout<<temp;
//	 } 
  
  string num0,num1,num2,num3;
  getline(cin,num0);
   getline(cin,num1);
    getline(cin,num2);
     getline(cin,num3);
     int a[100]={0};
     for(int i=0;i<num0.length();i++)
     {
     	char temp=num0.at(i);
     	if(temp-'A'>=0)
     	{
     		a[temp-'A']++;
		 }
	 }
	 for(int i=0;i<num1.length();i++)
     {
     	char temp=num1.at(i);
     	if(temp-'A'>=0)
     	{
     		a[temp-'A']++;
		 }
	 }
	 for(int i=0;i<num2.length();i++)
     {
     	char temp=num2.at(i);
     	if(temp-'A'>=0)
     	{
     		a[temp-'A']++;
		 }
	 }
	 for(int i=0;i<num3.length();i++)
     {
     	char temp=num3.at(i);
     	if(temp-'A'>=0)
     	{
     		a[temp-'A']++;
		 }
	 }
    
	 int max=-1;
	 for(int i=0;i<26;i++)
	 {
	 	if(max<a[i])
	 	{
	 		max=a[i];
		 }
	 }
	 int count=1;
	 int res=max;
	for(int i=0;i<max;i++)
	{
		
	for(int j=0;j<26;j++)
	{
			count=1;
		if(res-a[j]>0)
		{
			cout<<" ";
		}
		else{
			cout<<"*";
		}
		if(count)
		{
			cout<<" ";
		}
		count--;
	}
	res--;
	cout<<endl;
		
	}
	for(char i='A';i<='Z';i++)
	{
		if(i!='Z')
		{
				cout<<i<<" ";
		}
	  else{
	  	cout<<i;
	  }
	}
 } 
