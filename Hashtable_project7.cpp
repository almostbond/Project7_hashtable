// Hashtable_project7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

Hash_table::Hash_table() {
    
    for (int i = 0; i < table_size; i++) {
        hashtable[i] = new cubby;
        hashtable[i]->name = "empty";
        hashtable[i]->age = 0;
        hashtable[i]->next = NULL;
    }
}

Hash_testing::Hash_testing() {}

// complexity O(constant)
int Hash_table::hash(string value) {
    int key;
    int hash = 0;
    
    
    hash = (int)value[0];
    key = hash % table_size;
    

    return key;
}

// complexity O(constant)
void Hash_table::fill_simple(string name, int age) {

    int cubby_index = hash(name);


    hashtable[cubby_index]->age = age;
    hashtable[cubby_index]->name = name;

}

// complexity O(n)
void Hash_table::fill_chain(string name, int age) {

    int cubby_index = hash(name);

    if (hashtable[cubby_index]->name == "empty") {

        hashtable[cubby_index]->age = age;
        hashtable[cubby_index]->name = name;

    }
    else {
        cubby* ptr = hashtable[cubby_index];
        cubby* morestuff = new cubby;
        morestuff->name = name;
        morestuff->age = age;
        morestuff->next = NULL;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = morestuff;

    }
    
}

// complexity O(n)
bool Hash_table::simple_contains(string name) {

    int cubby_index = hash(name);
    if (hashtable[cubby_index]->name == name) {
        cout << "name: " << name << " found in hash table." << endl;
        return true;

    }
    else {
        cout << "name: " << name << " not found in hash table." << endl;
        return false;
    }
    
}
// complexity O(n) 
bool Hash_table::contains(string name) {
    int cubby_index = hash(name);
    cubby* ptr = hashtable[cubby_index];

    while (ptr->name != name && ptr->name != "empty" && ptr->next != NULL) {

        ptr = ptr->next;
    }

    if (ptr->name == name) {
        cout << "Hash table contains " << name << endl;
        return true;
    }
    else {
        cout << "Hash table does not contain " << name << endl;
        return false;
    }
}

// should only return values between 0 and 9.
void Hash_testing::test_hash() {
    cout << hash("a") << endl;//7
    cout << hash("b") << endl;//8
    cout << hash("c") << endl;//9
    cout << hash("d") << endl;//0
    cout << hash("e") << endl;//1
    cout << hash("f") << endl;//2
    cout << hash("g") << endl;//3
    cout << hash("h") << endl;//4 and so on
    cout << hash("i") << endl;
    cout << hash("j") << endl;
    cout << hash("k") << endl;
    cout << hash("l") << endl;
    cout << hash("m") << endl;
    cout << hash("n") << endl;
    cout << hash("o") << endl;
    cout << hash("p") << endl;
    cout << hash("q") << endl;
    cout << hash("r") << endl;
    cout << hash("s") << endl;
    cout << hash("t") << endl;
    cout << hash("u") << endl;
    cout << hash("v") << endl;
    cout << hash("w") << endl;
    cout << hash("x") << endl;
    cout << hash("y") << endl;
    cout << hash("z") << endl;

}

//tests filling buckets a handful of values are replaced.
void Hash_testing::test_simfill() {

    fill_simple("rosco", 3);
    fill_simple("max", 4);
    fill_simple("henry", 5);
    fill_simple("zoey", 14);
    fill_simple("gus", 8);
    fill_simple("hank", 6);// will override the bucket henry is in.
    fill_simple("penny", 5);
    fill_simple("boon", 2);
    fill_simple("titan", 7);


}
void Hash_testing::test_fill() {

    fill_chain("rosco", 3);
    fill_chain("max", 4);
    fill_chain("henry", 5);
    fill_chain("zoey", 14);
    fill_chain("gus", 8);
    fill_chain("hank", 6);
    fill_chain("penny", 5);
    fill_chain("boon", 2);
    fill_chain("titan", 7);

}



//tests the two possible cases either the name is contained in the table or it is not.
void Hash_testing::test_simcontains() {

    test_simfill();
    simple_contains("max");
    simple_contains("amy");

}
void Hash_testing::test_contains() {
    test_fill();
    contains("gus");
    contains("james");
   

}





int main()
{
    Hash_table hashbrowns;
    Hash_testing test;
    
    //test.test_hash();
    //test.test_simfill();
    //test.test_fill();
    //test.test_contains();
    //test.test_simcontains();
    cout << "Program exited successfully.\n";
}

