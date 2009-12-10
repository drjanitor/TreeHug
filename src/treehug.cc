#include <iostream>
#include <list>
#include <string>
#include <boost/shared_ptr.hpp>

using std::cout;
using std::endl;
using std::string;
using std::list;
using boost::shared_ptr;

namespace treehug {

struct Role {};
struct UStarRole : Role {};
struct ExistentialRole : Role {};
struct StarRole : ExistentialRole {
    string name;
    bool inv;
    StarRole(string name, bool inv=false) 
        : name(name), inv(inv) { }
};
struct BaseRole : ExistentialRole {
    string name;
    bool inv;
    BaseRole(string name, bool inv=false)
        : name(name), inv(inv) { }
};

struct State {};
struct Concept : State {};
struct AndConcept : Concept {
    list<shared_ptr<Concept>> subs;
};
struct OrConcept : Concept {
    list<shared_ptr<Concept>> subs;
};
struct ExConcept : Concept {
    shared_ptr<ExistentialRole> role;
    shared_ptr<Concept> sub;
    ExConcept(ExistentialRole *role, Concept *sub)
        : role(role), sub(sub) { }
};
struct AllConcept : Concept {
    shared_ptr<Role> role;
    shared_ptr<Concept> sub;
    AllConcept(Role *role, Concept *sub)
        : role(role), sub(sub) { }
};
struct BaseConcept : Concept {
    string name;
    bool neg;
    BaseConcept(string name, bool neg=false)
        : name(name), neg(neg) { }
};

} // namespace treehug

using namespace treehug;

int main (int argc, char const **argv)
{
    Concept *c = new BaseConcept("C1");
}
