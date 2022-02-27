#include<iostream>


struct  Growingstack
{
  int size;
  int top;
  int *arr;
};

void inflate(Growingstack &);

int isEmpty(const Growingstack &);

void intialize(Growingstack &s,int n)
{
  s.arr=new int[n];
  s.size=n;
  s.top=-1;
}

void display(const Growingstack &s)
{

  for(int i=s.top;i>=0;i--)

  {
      std::cout<<s.arr[i]<<" "<<std::endl;
  }
}
void push(Growingstack &s,int &x)
{

  if(s.top!=s.size-1)
  {
      s.top++;
      s.arr[s.top]=x;

  }

  else
  {
      std::cout<<"Stack is full ";
  }
}
int pop(Growingstack &s)
{
  int data;
  if(s.top==-1)
  std::cout<<"stack is empty";
  else
  {

    data=s.arr[s.top];
    s.top--;
  }
  return data;
}


inline int getMaxSize(const Growingstack &s)
{
  return s.size;
}

inline int currentsize(const Growingstack &s)
{
  return s.top;
}

void inflate(Growingstack &s,int &n)
{
  std::cout<<" The new size is n\n";

  int *p= new int[n];

  for(int i=0;i<s.size;i++)
  {
     p[i]=s.arr[i];
  }


  delete &s.arr;
  s.arr=p;
  s.size=n;
}

inline int isEmpty(const Growingstack &s)
{
  if(s.top==0)
  return 1;
  else
  return 0;
}


int main()
{
  Growingstack s1,s2,s3;

  std::cout<<"Enter the intial size of stack1 , stack2 , stack3\n";
  int n1,n2,n3;
  std::cin>>n1>>n2>>n3;
  intialize(s1,n1);
  intialize(s2,n2);
  intialize(s3,n3);
  for(int j=0;j<n1;j++)
  {

      int x;
      std::cout<<"Enter the element to be pushed in s1"<<std::endl;
      std::cin>>x;
      push(s1,x);
  }
   for(int j=0;j<n2;j++)
  {

      int x;
      std::cout<<"Enter the element to be pushed in s2"<<std::endl;
      std::cin>>x;
      push(s2,x);
  }
  std::cout<<"s1 contains"<<std::endl;
  display(s1);
  std::cout<<"s2 contains"<<std::endl;
  display(s2);
  int x;
  std::cout<<"Enter the new size"<<std::endl;
  std::cin>>x;
  inflate(s1,x);
  std::cout<<"New stack s1 will be"<<std::endl;
  for(int j=n1;j<x;j++)
  {

      int m,p;
      std::cout<<" If want to enter the element to be pushed in s1 enter 1"<<std::endl;
      std::cin>>m;
      if(m==1)
      {
          std::cout<<"Enter element to be pushed in s1"<<std::endl;
          std::cin>>p;
          push(s1,p);
      }
      else{
        break;
      }

  }
  display(s1);



  int i=0;
  while((!isEmpty(s1))&&(!isEmpty(s2)))
  {
   int num;
   if(i%2==0&&(!isEmpty(s1)))
   {
    num=pop(s1);
    push(s3,num);
   }
   if(i%2==1&&(!isEmpty(s2)))
   {
    num=pop(s2);
    push(s3,num);
   }
   i++;
  }

  while(!isEmpty(s1))
  {
    int num;
    num=pop(s1);
    push(s3,num);
  }

  while(!isEmpty(s2))
  {
    int num;
    num=pop(s2);
    push(s3,num);
  }


  std::cout<<"Stack3 contains\n";
  display(s3);

  return 0;
}