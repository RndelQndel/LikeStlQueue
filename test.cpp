#include <iostream>
#include "Queue_Stl.h"

int main()
{
	Queue_Stl<int> q;
	for(int i = 1; i <= 10; i++){
		std::cout << i << " ";
		if(	!q.Push(i) )
			break;
	}
	std::cout << std::endl;
	for(int i = 0; i < 10; i++){
		int temp = 0;
		if( !q.Pop( temp ) )
			break;
		std::cout << temp << " ";
	}
	std::cout << std::endl;
	return 0;
}
