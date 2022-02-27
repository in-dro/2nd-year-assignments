#include<iostream>
using namespace std;

template<typename T>
void swap(T *a,T *b)
{
	T s;
	s=*a;
	*a=*b;
	*b=s;
}


int main()
{
	int a=12,b=2;
	float a1=12.2,b1=22.3;

	swap(&a,&b);
	swap(&a1,&b1);
	cout << "after swaping of integers" <<endl;
	cout<<"a="<<a <<" b="<<b;
	cout<<endl<<"a="<<a1 << " b="<<b1;
}
