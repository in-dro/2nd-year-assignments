#include<iostream>
template<typename T>


struct  Growingstack
{
  int size;
  int top;
  T *arr;


void inflate();

int isEmpty();

void intialize(int &n)
{
  arr=new T[n];
  size=n;
  top=-1;
}

void display()
{

  for(int i=top;i>=0;i--)

  {
      std::cout<<arr[i]<<" "<<std::endl;
  }
}
void push(T &x)
{

  if(top!=size-1)
  {
      top++;
      arr[top]=x;

  }

  else
  {
      std::cout<<"Stack is full ";
  }
}
T pop()
{
  T data;
  if(top==-1)
  std::cout<<"stack is empty";
  else
  {

    data=arr[top];
    top--;
  }
  return data;
}


int getMaxSize()
{
  return size;
}

int currentsize()
{
  return top;
}

void inflate(int &n)
{

  std::cout<<" The new size is n\n";

  T *p= new T[n];

  for(int i=0;i<size;i++)
  {
     p[i]=arr[i];
  }


  delete &arr;
  arr=p;
  size=n;
}

int isEmpty(Growingstack <T>&s)
{
  if(top==0)
  return 1;
  else
  return 0;
}
};


int main()
{
  Growingstack<int>s1,s2,s3;

  std::cout<<"Enter the intial size of stack1 , stack2 , stack3\n";
  int n1,n2,n3;
  std::cin>>n1>>n2>>n3;
  s1.intialize(n1);
  s2.intialize(n2);
  s3.intialize(n3);
  for(int j=0;j<n1;j++)
  {

      int x;
      std::cout<<"Enter the element to be pushed in s1"<<std::endl;
      std::cin>>x;
      s1.push(x);
  }
   for(int j=0;j<n2;j++)
  {

      int x;
      std::cout<<"Enter the element to be pushed in s2"<<std::endl;
      std::cin>>x;
      s2.push(x);
  }
  std::cout<<"s1 contains"<<std::endl;
  s1.display();
  std::cout<<"s2 contains"<<std::endl;
  s2.display();
  int x;
  std::cout<<"Enter the new size"<<std::endl;
  std::cin>>x;
  s1.inflate(x);
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
          s1.push(p);
      }
      else{
        break;
      }

  }
  s1.display();



  int i=0;
  while((!s1.isEmpty(s1))&&(!s2.isEmpty(s2)))
  {
   int num;
   if(i%2==0&&(!s1.isEmpty(s1)))
   {
    num=s1.pop();
    s3.push(num);
   }
   if(i%2==1&&(!s2.isEmpty(s2)))
   {
    num=s2.pop();
    s3.push(num);
   }
   i++;
  }

  while(!s1.isEmpty(s1))
  {
    int num;
    num=s1.pop();
    s3.push(num);
  }

  while(!s2.isEmpty(s2))
  {
    int num;
    num=s2.pop();
    s3.push(num);
  }


  std::cout<<"Stack3 contains\n";
  s3.display();
  Growingstack<float> s4,s5,s6;


  std::cout<<"Enter the intial size of stack4, stack5 , stack6\n";
  int n4,n5,n6;
  std::cin>>n4>>n5>>n6;
  s4.intialize(n4);
  s5.intialize(n5);
  s6.intialize(n6);
  for(int j=0;j<n4;j++)
  {

      float x;
      std::cout<<"Enter the element to be pushed in s4"<<std::endl;
      std::cin>>x;
      s4.push(x);
  }
   for(int j=0;j<n5;j++)
  {

      float x;
      std::cout<<"Enter the element to be pushed in s5"<<std::endl;
      std::cin>>x;
      s5.push(x);
  }
  std::cout<<"s4 contains"<<std::endl;
  s4.display();
  std::cout<<"s5 contains"<<std::endl;
  s5.display();
  int l;
  std::cout<<"Enter the new size"<<std::endl;
  std::cin>>l;
  s4.inflate(l);
  std::cout<<"New stack s4 will be"<<std::endl;
  for(int j=n4;j<l;j++)
  {

      int m;
      float p;
      std::cout<<" If want to enter the element to be pushed in s4 enter 5"<<std::endl;
      std::cin>>m;
      if(m==5)
      {
          std::cout<<"Enter element to be pushed in s4"<<std::endl;
          std::cin>>p;
          s4.push(p);
      }
      else{
        break;
      }

  }
  s4.display();



  i=0;
  while((!s4.isEmpty(s4))&&(!s5.isEmpty(s5)))
  {
   float num;
   if(i%2==0&&(!s4.isEmpty(s4)))
   {
    num=s1.pop();
    s6.push(num);
   }
   if(i%2==1&&(!s5.isEmpty(s5)))
   {
    num=s5.pop();
    s6.push(num);
   }
   i++;
  }

  while(!s4.isEmpty(s4))
  {
    float num;
    num=s4.pop();
    s6.push(num);
  }

  while(!s5.isEmpty(s5))
  {
    float num;
    num=s5.pop();
    s6.push(num);
  }


  std::cout<<"Stack6 contains\n";
  s6.display();

  return 0;
}