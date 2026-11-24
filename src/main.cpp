#include "queue.h"
#include <iostream>
int main() {
	TForwardList<int> ls;
	ls.pushBack(10);
	std::cout << ls.getFirst()<<std::endl;
	ls.pushFront(20);
	std::cout << ls.getFirst() << std::endl;
	ls.eraseFront();
	std::cout << ls.getFirst() << std::endl;
	ls.pushBack(100);
	ls.eraseBack();
	std::cout << ls.getFirst() << std::endl;
}