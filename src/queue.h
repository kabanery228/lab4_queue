#define QUEUE_H
#include <vector>
template<class T>
class TForwardList {
	template <class T>
	struct Node{
		T val;
		Node<T>* next;
	};
	Node<T>* first;
	Node<T>* last;
	size_t sz = 0;
public:
	TForwardList():sz(0),first(nullptr),last(nullptr){}
	TForwardList(const std::vector<T>& v) {
		Node<T>* newElem = new Node<T>{ v[v.size() - 1],nullptr };
		sz++;
		first = last = newElem;
		for (int i = v.size() - 2;i >= 0;--i) {
			newElem = new Node<T>{ v[i],first };
			first = newElem;
			sz++;
		}
	}
	TForwardList(const TForwardList<T>& other):sz(other.sz) {
		//if (sz) clear();
		Node<T>* newElem = new Node<T>{ other.first->val,other.first->next };
		first = last = newElem;
		while (newElem != nullptr) {
			auto* tmp = new Node<T>{ newElem->val, newElem->next }
			last->next = tmp;
			last = tmp;
			newElem = newElem->next;
		}

	}
	TForwardList<T>& operator=(const TForwardList<T>& other) {
		if (*this != other) 
			*this = TForwardList(other);
		return *this;
	}
	T getFirst() {
		return first->val;;
	}
	
	T getLast() {
		return last->val;
	}
	
	void clear() {
		if (sz > 0) {
			Node<T>* nextElem = first;
			Node<T>* delElem;
			while (nextElem != nullptr) {
				delElem = nextElem;
				nextElem = nextElem->next;
				delete delElem;
			}
		}
		sz = 0;
	}
	~TForwardList() {
		clear();
	}
	void pushBack(const T& val) {
		if (last != nullptr) {
			last->next = new Node<T>{ val, nullptr };
			last = last->next;
		}
		else { last = new Node<T>{ val, nullptr };first = last; };
		sz++;
	}
	void pushFront(const T& val) {
		first = new Node<T>{ val,first };
		if (!sz) last = first;
		sz++;

	}
	void eraseFront() {
		auto* tmp = first->next;
		delete first;
		first = tmp;
		sz--;
		if (sz == 1) first = last;
	}
	void eraseBack() {
		auto* tmp = first;
		delete last;
		while (tmp->next != nullptr) tmp = tmp->next;
		last = tmp;
		if (sz == 1) first = last;
	}
};

//template <class T>
//class Queue{
//	TForwardList<T> queue;
//	size_t sz;
//public:
//	Queue() {
//		TForwardList()
//	};
//};