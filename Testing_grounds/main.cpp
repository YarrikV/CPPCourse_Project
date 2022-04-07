#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdlib.h>

std::vector<int*> test() {
    std::vector<int*> features;
    int * p = new int(3);
    features.push_back(p);

    std::string bla;
    bla = "BLA BLA";
    printf("%s\n",bla.c_str());
    return features;
}

float randomFloat() {
    // returns random nr between 0 and 1
    float r;
    r = (float)std::rand() / RAND_MAX;
    std::vector<int> test;
    test.clear();
    test.push_back(3);

    return r;
}

//struct type_A {
//    std::string name;
//};

//struct type_AA : type_A {
//    int a;
//};

//struct type_AB : type_A {
//    int b;
//};

//class A {
//public:
//    type_A type;
//};

//class AA : public A {
//public:
//    type_AA type;
//};

//class AB : public A {
//public:
//    type_AB type;
//};

int main()
{
    // test 1
//    for (auto i=0; i<20; i++) {
//        std::cout << randomFloat() << std::endl;
//    }
//    return 0;

    // test 2
//    type_AA aa; aa.name = "aa"; aa.a = 3;
//    type_AB ab; ab.name="ab"; ab.b=5;

//    AA AA;
//    AA.type = aa;


}
