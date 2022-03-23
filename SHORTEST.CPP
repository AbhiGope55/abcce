#include<iostream.h>
#include<conio.h>
void main()
{
 clrscr();
 int Sr,Dest;
 int minIndex,minValue;
 int M[6][6]={0,3,0,1,1,0,
	      0,0,4,0,0,0,
	      0,0,0,0,0,2,
	      0,0,6,0,4,0,
	      0,0,5,0,0,2,
	      0,0,0,0,0,0};
 cout<<"\nEnter Source And Destination:";
 cout<<"\nA=0,B=1,C=2,D=3,E=4,F=5\n";
 cin>>Sr>>Dest;
 int cost=0;
 int i;
 for(i=0; i<Dest; i=minIndex)
 {
   minIndex=6;
   minValue=999;
   for(int j=0; j<6; j++)
   {
    if(M[i][j]<=minValue && M[i][j]!=0)
     {
       minValue=M[i][j];
       minIndex=j;
     }
   }
   cost+=minValue;
 }
 if(i==Dest)
  cout<<"Cost:"<<cost;
 else
  cout<<"No Path";
 getch();
}


