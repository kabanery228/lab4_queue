#include "queue.h"
#include <iostream>
int main() {
	Queue<int> q;
	q.push(10);
	q.push(5);
	q.pop();
	std::cout << q.top();
}