#include <iostream>

template <class T>
class List {
protected:
	T data;
	List* next;
	int elements;
public:
	List() : next(nullptr), data(0), elements(0) {};
	List(T data) : data(data), next(nullptr), elements(1) {};

	int GetElements() {
		return elements;
	}

	void add(T value) {
		if (!elements) {
			data = value;
			elements += 1;
			return;
		}
		List* node = this;
		while (node->next != nullptr) {
			node = node->next;
		}
		node->next = new List<T>(value);
		elements += 1;
	}

	T get_back() {
		if (!elements) return NULL;
		List* node = this;
		List* parent = nullptr;
		while (node->next != nullptr) {
			parent = node;
			node = node->next;
		}
		return node->data;
	}

	void pop_front() {
		List<T>* node = this;
		List<T>* parent = nullptr;
		while (node->next != nullptr) {
			node->data = node->next->data;
			parent = node;
			node = node->next;
		}
		if (parent != nullptr) {
			parent->next = nullptr;
		}
		elements -= 1;
		delete node;
	}

	void pop_back() {
		if (!elements) return;
		List* node = this;
		List * parent = nullptr;
		while (node->next != nullptr) {
			parent = node;
			node = node->next;
		}
		if (parent != nullptr) { 
			parent->next = nullptr;
		}
		delete node;
		elements -= 1;

	}
	
	void print() {
		if (!elements) {
			std::cout << "Stack is Empty!" << std::endl;
			return;
		}
		T value = data;
		List* node = this;
		for (int i = 0; i < elements; i++) {
			std::cout << value << " ";
			node = node->next;
			if (node == nullptr) {
				std::cout << "\n";
				return;
			}
			value = node->data;
		}
		std::cout << "\n";
	}

	~List() {
		if (next != nullptr) {
			delete next;
		}
	}
};

template <class T>
class Stack : public List<T> {
private:
	static int count;
public:
	Stack() : List<T>::List() {};
	Stack(T data) : List<T>(data) { count++; }
	void push(T data){
		List<T>::add(data);
		count++;
	};
	T getTop() {
		if (!this->elements) throw std::exception("Stack is EMPTY!");
		return List<T>::get_back();
	};
	T pop() {
		if (!this->elements) throw std::exception("Stack is EMPTY!");
		T result = this->get_back();
		this->pop_back();
		count--;
		return result;
	}
	static int getCount() {
		return count;
	}
};

template <class T>
class Queue : public List<T> {
public:
	Queue() : List<T>::List() {};
	Queue(T data) : List<T>(data) {}

	void enqueue(T data) {
		List<T>::add(data);
	};
	T dequeue() {
		if (!this->elements) throw std::exception("Stack is EMPTY!");
		T result = this->data;
		this->pop_front();
		return result;
	}
	T getFirst() {
		if (!this->elements) throw std::exception("Stack is EMPTY!");
		return this->data;
	};
};

template <class T>
int Stack<T>::count = 0;

int main() {
	std::cout << "> Stack" << std::endl;
	Stack<float> stack(5);
	stack.push(6);
	stack.push(1);
	stack.push(3);
	stack.push(5);
	stack.push(0);
	std::cout << "stack pop: " << stack.pop() << std::endl;
	std::cout << "stack pop: " << stack.pop() << std::endl;
	stack.print();

	std::cout << "Top: " << stack.getTop() << std::endl;
	std::cout << "Elements: " << stack.GetElements() << std::endl;
	std::cout << "\n> Queue" << std::endl;
	Queue<float> queue(5);
	queue.enqueue(6);
	queue.enqueue(1);
	queue.enqueue(3);
	queue.enqueue(5);
	queue.enqueue(0);
	std::cout << "queue dequeue: " << queue.dequeue() << std::endl;
	std::cout << "queue dequeue: " << queue.dequeue() << std::endl;
	queue.print();

	std::cout << "First: " << queue.getFirst() << std::endl;
	std::cout << "Elements: " << queue.GetElements() << std::endl;
	return 0;
}