#include "main.cpp"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;
using namespace fun;

TEST(Tests1, LinkedList_1) {
	LinkedList<int> list1;
	list1.push_tail(1);
	list1.push_tail(2);
	list1.push_tail(3);
	list1.push_head(2);
	cout << list1 << "\n";
	list1.pop_tail();
	cout << list1 << "\n";
	list1.pop_head();
	cout << list1 << "\n";
	cout << list1[0]<<"\n";
	list1.delete_node(2);
	cout << list1 << "\n";

	EXPECT_TRUE(true);
}
TEST(Tests2, Sum) {
	LinkedList<int> list1;
	LinkedList<int> list2;
	list1.push_tail(1);
	
	list2.push_tail(9);
	list2.push_tail(9);
	
	LinkedList<int> list_sum = sum_list(&list1, &list2);
	cout << list_sum;
	EXPECT_TRUE(true);
}

TEST(Tests3, Sum1) {
	LinkedList<int> list1;
	LinkedList<int> list2;
	list1.push_tail(3);
	list1.push_tail(4);

	list2.push_tail(8);
	list2.push_tail(9);

	LinkedList<int> list_sum = sum_list(&list1, &list2);
	cout << list_sum;
	EXPECT_TRUE(true);
}

TEST(Tests4, mullis) {
	LinkedList<int> list1;
	list1.push_tail(8);
	list1.push_tail(9);
	list1.push_tail(4);
	LinkedList<int> list2;
	list2.push_tail(4);
	list2.push_tail(5);
	cout << list2 << "\n";
	cout << list1 << "\n";
	LinkedList<int> list_mul = mul_list(&list1, &list2);
	cout << list_mul;
	EXPECT_TRUE(true);
}

TEST(Tests5, mullis2) {
	LinkedList<int> list1;
	list1.push_tail(8);
	list1.push_tail(9);
	LinkedList<int> list2;
	list2.push_tail(4);
	list2.push_tail(5);
	cout << list2 << "\n";
	cout << list1 << "\n";
	LinkedList<int> list_mul = mul_list(&list1, &list2);
	cout << list_mul;
	EXPECT_TRUE(true);
}