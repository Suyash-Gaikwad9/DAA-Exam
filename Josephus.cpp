// Josephus Problem 
#include<iostream> 
#include<queue> 
using namespace std; 
struct Node{ 
int data; 
struct Node *next; 
}; 
int josRecursion(int n,int k) { 
if(n==1){ 
return 0; 
} 
return (josRecursion(n-1,k)+k)%n; } 
void josArr(int n,int k){ 
queue<int> qe; 
for(int i=1;i<=n;i++){ 
qe.push(i); 
} 
while(qe.size()!=1){ 
int round=0; 
while(round<k-1){ 
int player=qe.front(); 
qe.pop(); 
qe.push(player); 
round++; 
} 
qe.pop(); 
} 
cout<<"Winner is : "<<qe.front()<<endl; }
void josLinked(int n,int k){ 
struct Node *head=NULL,*p=NULL,*q=NULL,*temp=NULL; for(int i=0;i<n;i++){ 
struct Node *newnode=new Node(); 
newnode->data=i+1; 
newnode->next=NULL; 
if(head==NULL){ 
head=newnode; 
p=newnode; 
p->next=head; 
}else{ 
p->next=newnode; 
p=newnode; 
p->next=head; 
} 
} 
p=head; 
int size=n; 
while(size!=1){ 
int round=1; 
while(round<k-1){ 
p=p->next; 
round++; 
} 
temp=p->next; 
p->next=temp->next; 
p=p->next; 
temp->next=NULL; 
free(temp); 
size--; 
} 
cout<<"Winner is : "<<q->data<<endl; 
} 
int main(){ 
int n,k,ch; 
cout<<"Enter the number of Players: "<<endl; cin>>n; 
cout<<"Enter the value of k: "<<endl; 
cin>>k; 
cout<<"1. Using Array"<<endl; 
cout<<"2. Using LinkedList"<<endl; 
cout<<"3. Using Recursion"<<endl;
cout<<"Enter Your Choice: "<<endl; 
cin>>ch; 
switch(ch){ 
case 1: josArr(n,k); 
break; 
case 2: josLinked(n,k); 
break; 
case 3: cout<<"Winner is : "<<josRecursion(n,k)+1; break; 
default: cout<<"Enter Valid number"<<endl; 
} 
return 0; 
}
