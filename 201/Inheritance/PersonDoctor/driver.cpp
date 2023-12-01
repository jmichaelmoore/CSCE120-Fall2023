#include <string>

struct Person {
   std::string name;
   int weight;
};

struct Doctor : public Person {
   std::string specialty;
};

int main() {
   Person* p = new Person;
   p->name = "George";
   p->weight = 187;
   Doctor* d = new Doctor;
   d->name = "Sam";
   d->weight = 165;
   d->specialty = "surgeon";
   Person* w;
   w = d;
}
