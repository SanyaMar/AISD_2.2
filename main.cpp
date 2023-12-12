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
}