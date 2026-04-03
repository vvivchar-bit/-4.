#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor" << endl;
    }

    void publicMethod() const {
        cout << "Base public method" << endl;
    }

protected:
    void protectedMethod() const {
        cout << "Base protected method" << endl;
    }

public:
    ~Base() {
        cout << "Base destructor" << endl;
    }
};

class ProtectedDerived : protected Base {
public:
    ProtectedDerived() {
        cout << "ProtectedDerived constructor" << endl;
    }

    void test() {
        publicMethod();
        protectedMethod();
    }

    ~ProtectedDerived() {
        cout << "ProtectedDerived destructor" << endl;
    }
};

class PrivateDerived : private Base {
public:
    PrivateDerived() {
        cout << "PrivateDerived constructor" << endl;
    }

    void test() {
        publicMethod();
        protectedMethod();
    }

    ~PrivateDerived() {
        cout << "PrivateDerived destructor" << endl;
    }
};

int main() {
    cout << "Protected inheritance:" << endl;
    ProtectedDerived pd;
    pd.test();

    cout << endl;

    cout << "Private inheritance:" << endl;
    PrivateDerived prd;
    prd.test();

    return 0;
}
