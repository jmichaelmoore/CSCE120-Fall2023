#include <iostream>
#include <vector>

using std::cout, std::endl, std::string;

struct Animal {
    std::string type;
    virtual void speak() = 0; //{ cout << "hello" << endl; }
    Animal(string type);
    Animal();
    virtual ~Animal() {}
};

Animal::Animal(string type) : type(type) {
    cout << "Animal constructor " << type << endl;
}

Animal::Animal() : type() {
    cout << "Animal default constructor" << endl;
}

struct Octopus : public Animal {
    Octopus();
    void speak() override {
        cout << "squirt" << endl;
    }
};

Octopus::Octopus() : Animal("octopus") {
    cout << "Octopus default constructor" << endl;
}

struct Dragon : public Animal {
    Dragon();
    void speak() override { cout << "roar!" << endl; }
};

Dragon::Dragon() : Animal("dragon") {
    cout << "Dragon default constructor" << endl;
}

int main() {
    std::vector<Animal*> animals;

    //Animal* a = new Animal("tiger");
    //animals.push_back(a);

    Octopus* o = new Octopus();
    animals.push_back(o);

    Dragon* d = new Dragon();
    animals.push_back(d);

    for (size_t i=0; i<animals.size(); ++i) {
        cout << animals.at(i)->type << " says ";
        animals.at(i)->speak();
    }

    for (size_t i=0; i<animals.size(); ++i) {
        delete animals.at(i);
    }
}