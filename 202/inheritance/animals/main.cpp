#include <iostream>
#include <vector>

using std::cout, std::endl, std::string;

struct Animal {
    string type;
    Animal(string type);
    Animal();
    virtual ~Animal() {}
    virtual void speak() = 0; // { cout << "hello" << endl; }
};

Animal::Animal() : type("missing") {
    cout << "Animal default constructor" << endl;
}

Animal::Animal(string type) : type(type) {
    cout << "Animal constructor " << type << endl;
}

struct Pig : public Animal {
    Pig();
    void speak() override;
};

void Pig::speak() { cout << "oink" << endl; }

Pig::Pig() : Animal("pig") {
    cout << "Pig constructor" << endl;
}

struct Cow : public Animal {
    Cow();
    void speak() { cout << "moo" << endl; }
};

Cow::Cow() : Animal("cow") {
    cout << "cow constructor" << endl;
}

int main () {
    std::vector<Animal*> animals;
    //Animal* a = new Animal("generic");
    //animals.push_back(a);

    Pig* p = new Pig();
    animals.push_back(p);

    Cow* c = new Cow();
    animals.push_back(c);

    for (size_t i=0; i<animals.size(); ++i) {
        cout << animals.at(i)->type << " says ";
        animals.at(i)->speak();
    }

    for (size_t i=0; i<animals.size(); ++i) {
        delete animals.at(i);
    }
}