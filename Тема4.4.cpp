#include <iostream>
using namespace std;

class GameObject {
public:
    GameObject() {
        cout << "GameObject constructor" << endl;
    }

    void info() const {
        cout << "Shared base class GameObject" << endl;
    }

    ~GameObject() {
        cout << "GameObject destructor" << endl;
    }
};

class Drawable : virtual public GameObject {
public:
    Drawable() {
        cout << "Drawable constructor" << endl;
    }

    ~Drawable() {
        cout << "Drawable destructor" << endl;
    }
};

class Movable : virtual public GameObject {
public:
    Movable() {
        cout << "Movable constructor" << endl;
    }

    ~Movable() {
        cout << "Movable destructor" << endl;
    }
};

class Tile : public Drawable, public Movable {
public:
    Tile() {
        cout << "Tile constructor" << endl;
    }

    void show() {
        info();
        cout << "Tile uses one shared GameObject base" << endl;
    }

    ~Tile() {
        cout << "Tile destructor" << endl;
    }
};

int main() {
    Tile t;
    t.show();

    return 0;
}
