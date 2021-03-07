#pragma once
#include <string>
using namespace std;


class Hash_table {

private:
	static const int table_size = 10;

	struct cubby {
		string name;
		int age;
		cubby* next;

	};
	cubby* hashtable[table_size];

public:
	Hash_table();
	int hash(string value);
	void fill_simple(string name, int age);
	void fill_chain(string name, int age);
	bool simple_contains(string name);
	bool contains(string name);
};



class Hash_testing: public Hash_table {

public:
	Hash_testing();
	void test_hash();
	void test_fill();
	void test_contains();

	void test_simfill();
	void test_simcontains();

};