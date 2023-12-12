#pragma once
#include <iostream>
#include <random>


using namespace std;

namespace fun {

	template < typename T>

	class Node {
		Node* _next;
		Node* _prev;
		T* _val;

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

		~Node() {
			delete _val;
		}

		Node* get_next() const {
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

		void set_val(T* val) {
			_val = val;
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
			Node<T>* node = list._head;
			this->push_tail(new Node<T>(*node));
			node = node->get_next();
			while (node != nullptr) {
				Node<T>* node2 = new Node<T>(*node);
				this->push_tail(node2);
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

		~LinkedList() {
			Node<T>* node;
			while (_head != nullptr) {
				node = _head->_next;
				delete _head;
				_head = node;
			}

			Node<T>* get_tail() const {
				return _tail;
			}


			Node<T>* get_head() const {
				return _head;
			}
		}

		void push_tail(Node<T>* tail) {
			if (_tail == nullptr) {
				_head = tail;
				_tail = tail;
				tail->set_next(nullptr);
				tail->set_prev(nullptr);
			}
			else {
				_tail->set_next(tail);
				tail->set_next(nullptr);
				tail->set_prev(_tail);
				_tail = tail;
			}
		}
	};
}