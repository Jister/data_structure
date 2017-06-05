#include "link_list.h"
#include <iostream>

using namespace std;

int main()
{
	SimpleLinkList<int> a;
	for(int i = 0; i < 10; i++)
	{
		a.Insert(i+1,i);
	}
	cout << "size: " << a.Length() << endl;
	return 0;  
}