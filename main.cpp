#pragma once
#include <iostream>
#include <random>


using namespace std;

namespace fun {

	template < typename T>

	class Node {
	private:
		Node* _next;
		Node* _prev;
		T* _val;
	public:
		Node() {
			_next = nullptr;
			_prev = nullptr;
			_val = nullptr;
		}

		Node(T value) {
			_next = nullptr;
			_prev = nullptr;
			_val = new T(value);
		}

		Node(Node* cur1, Node* cur2, T value) {
			_next = cur1;
			_prev = cur2;
			_val = new T(value);
		}

		Node(Node<T>& node) {
			_next = node._next;
			_prev = node._prev;
			_val = new T(node._val);
		}

		~Node() = default;

		Node* get_next() {
			return _next;
		}

		Node* get_prev() const {
			return _prev;
		}

		T* get_val() const {
			return _val;
		}

		void set_next(Node* next) {
			_next = next;
		}

		void set_prev(Node* prev) {
			_prev = prev;
		}

		void set_val(T val) {
			_val = new T(val);
		}

		friend ostream& operator<< (ostream& out, Node<T>& node) {
			out << *(node.get_val()) << " ";
			return out;
		}

		void operator = (const Node<T> node) {
			_next = node._next;
			_prev = node._prev;
			_val = node._val;
		}

		friend bool operator == (Node<T> node1, Node<T> node2) {
			if (*(node1.get_val()) == *(node2.get_val())) {
				return false;
			}
			else {
				return true;
			}
		}

		friend bool operator!= (Node<T> node1, Node<T> node2) {
			return !(node1 == node2);
		}

	};


	template < typename T>

	class LinkedList {
	private:
		Node<T>* _head;
		Node<T>* _tail;
	public:
		LinkedList() : _head(nullptr), _tail(nullptr) {}

		LinkedList(const LinkedList& list) {
			_head = nullptr;
			_tail = nullptr;
			Node<T>* node = list.get_head();
			while (node != nullptr) {
				push_tail(*(node->get_val()));
				node = node->get_next();
			}
		}

		LinkedList(int size, T min, T max) {
			_head = nullptr;
			_tail = nullptr;
			for (int i = 0; i < size; i++) {
				this->push_tail(new Node<T>(random(min, max)));
			}
		}

		T random(T min, T max) {
			std::random_device random_device;
			std::mt19937 generator(random_device());
			std::uniform_int_distribution<> distribution(min, max);
			T x = distribution(generator);
			return x;
		}

		

		Node<T>* get_tail() const {
			return _tail;
		}

		Node<T>* get_head() const {
			return _head;
		}

		

		void push_head(T value) {
			Node<T>* start = new Node<T>(value);
			if (_head == nullptr) {
				_head = start;
				_tail = start;
				start->set_next(nullptr);
				start->set_prev(nullptr);
			}
			else {
				start->set_prev(nullptr);
				start->set_next(_head);
				_head->set_prev(start);
				_head = start;
			}
		}

		void push_head(LinkedList<T>* start) {
			start->_tail->set_next(_head);
			_head->set_prev(start->_tail);
			_head = start->_head;
		}

		void push_tail(T value) {
			Node<T>* end= new Node<T>(value);
			if (_tail == nullptr) {
				_head = end;
				_tail = end;
				end->set_next(nullptr);
				end->set_prev(nullptr);
			}
			else {
				_tail->set_next(end);
				end->set_next(nullptr);
				end->set_prev(_tail);
				_tail = end;
			}
		}

		void push_tail(LinkedList<T>* list) {
			_tail->set_next(list->_head);
			list->_head->set_prev(_tail);
			_tail = list->_tail;
		}

		void push_head(const LinkedList& other) {
			Node<T>* cur = other.tail;
			while (cur != nullptr) {
				push_head(cur->data);
				cur = cur->prev;
			}
		}


		void pop_head() {
			Node<T>* temp(_head);
			_head->get_next()->set_prev(nullptr);
			_head = _head->get_next();
			delete temp->get_val();
		}

		void pop_tail() {
			Node<T>* temp(_tail);
			_tail->get_prev()->set_next(nullptr);
			_tail = _tail->get_prev();
			delete temp->get_val();
		}

		void delete_node(T val) {
			Node<T>* temp = _head;
			while (temp != nullptr) {
				if (*(temp->get_val()) == val) {
					if (temp == _head) {
						this->pop_head();
					}
					else if (temp == _tail) {
						 this->pop_tail(); 
					}
					else{
						temp->get_prev()->set_next(temp->get_next());
						temp->get_next()->set_prev(temp->get_prev());
						
					}

				}
				temp = temp->get_next();
			}
		}

		friend ostream& operator<< (ostream& out, LinkedList<T>& list) {
			Node<T>* temp = list._head;
			while (temp != nullptr) {
				out << *temp;
				temp = temp->get_next();
			}
			return out;
		}

		T operator[](int index) {
			Node<T>* start = _head;
			if (index > this->size() || index < 0) {
				throw runtime_error("Index is out of range");
			}
			if (start != nullptr && index == 0) {
				return *(_head->get_val());
			}
			for (int i = 0; i < index; i++) {
				start = start->get_next();
			}
			return *(start->get_val());
		}



		~LinkedList() = default;

		int size() const {
			int count = 0;
			Node<T>* current = _head;

			while (current != nullptr) {
				++count;
				current = current->get_next();
			}

			return count;
		}
	};
	template <typename T>
	LinkedList<int> sum_list(LinkedList<T>* list_1 , LinkedList<T>* list_2) {
		LinkedList<int> temp;
		int over_f = 0;
		Node<int>* right = list_2->get_tail();
		Node<int>* left = list_1->get_tail();
		while (right != nullptr && left != nullptr) {
			int r = *(right->get_val());
			int l = *(left->get_val());
			if (r + l + over_f > 9) {
				temp.push_head((r + l + over_f) % 10);
				over_f = (r + l + over_f) / 10;
			}
			else {
				temp.push_head(r + l + over_f);
				over_f = 0;
			}
			right = right->get_prev();
			left = left->get_prev();
		}
		while (right != nullptr) {
			int r = *(right->get_val());
			if (r + over_f > 9) {
				temp.push_head((r + over_f) % 10);
				over_f = 1;
			}
			else {
				temp.push_head(r + over_f);
				over_f = 0;
			}
			right = right->get_prev();
		}
		while (left != nullptr) {
			int l = *(left->get_val());
			if (l + over_f > 9) {
				temp.push_head((l + over_f) % 10);
				over_f = 1;
			}
			else {
				temp.push_head(l + over_f);
				over_f = 0;
			}
			left  = left->get_prev();
		}
		if (over_f == 1) {
			temp.push_head(1);
		}
		return temp;
	}

	template <typename T>
	LinkedList<int> mul_list(LinkedList<T>* list1, LinkedList<T>* list2) {

	LinkedList<int> result;
	result.push_head(0);

	Node<int>* right = list2->get_tail();
	int count = 0;
	while (right != nullptr) {
		int r = *(right->get_val());
		LinkedList<int> temp;
		int over_f = 0;
        Node<int>*left = list1->get_tail();
		while (left != nullptr) {
			int l = *(left->get_val());
			temp.push_head((l * r + over_f) % 10);
			over_f = (l * r + over_f) / 10;
			left = left->get_prev();
		}
		if (over_f != 0) {
			temp.push_head(over_f);
		}
		for (int i = 0; i < count; i++) {
			temp.push_tail(0);
		}
		cout << temp << "\n";
		
		result = sum_list(&result, &temp);

        count++;
		right = right->get_prev();
	}
	
	return result;
    }
}