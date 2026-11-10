#define QUEUE_H

template <class T>
class Node {
	T val;
public:
	Node* next = nullptr;
	Node(T val_) :val(val_) {};
	void insert<T>(T val_) {
		if (next == nullptr) {
			next = new Node<T>(val_);
		}
		else {
			Node* tmp = new Node(val_);
			tmp->next = next;
			next = tmp;
		}
	}
	Node* get_next() {
		return next;
	}
	T get_val() const {
		return val;
	}
	~Node() {
		delete next;
	}
};
template<class T>
class Queue {

	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
	size_t queue_size;
public:
	Queue() : queue_size(0) {};
	void push(T val) {
		if (first == nullptr) {
			first = new Node(val);
		}
		else if (last == nullptr) { first->insert<T>(val); last = first->get_next(); }
		else last->insert<T>(val);
	}
	T top() const {
		if (first != nullptr) return first->get_val();
		else throw "queue is empty";
	}
	void pop() {
		Node<T>* tmp = first->get_next();
		delete first;
		first = tmp;
	}
	~Queue() {
		delete first, last;
	}
};