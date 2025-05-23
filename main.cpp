#include<stdio.h>
#include <cstdio>
using namespace std;

// 動物クラス（抽象クラス）
class Animal {
public:
    virtual void sound() const = 0; // 純粋仮想関数
};

// 犬クラス（Animal を継承）
class Dog : public Animal {
public:
    void sound() const override {
        printf("イヌ鳴き声：ワン\n");
    }
};

// 猫クラス（Animal を継承）
class Cat : public Animal {
public:
    void sound() const override {
        printf("ネコ鳴き声：ニャー\n");
    }
};

int main() {
    Animal* animal1 = new Dog(); // 犬のインスタンス
    Animal* animal2 = new Cat(); // 猫のインスタンス

    animal1->sound(); // ポリモーフィズムにより Dog の sound() が呼ばれる
    animal2->sound(); // 同上、Cat の sound()

    delete animal1;
    delete animal2;

    return 0;
}
