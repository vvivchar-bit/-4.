#include <iostream>
using namespace std;

class PuzzleObject {
public:
    virtual void draw() const = 0;

    virtual ~PuzzleObject() {
        cout << "PuzzleObject destructor" << endl;
    }
};

class NumberTile : public PuzzleObject {
private:
    int value;

public:
    NumberTile(int value) : value(value) {
        cout << "NumberTile constructor" << endl;
    }

    void draw() const override {
        cout << "Drawing number tile: " << value << endl;
    }

    void showValue() const {
        cout << "Tile value = " << value << endl;
    }

    ~NumberTile() {
        cout << "NumberTile destructor" << endl;
    }
};

class EmptyCell : public PuzzleObject {
public:
    EmptyCell() {
        cout << "EmptyCell constructor" << endl;
    }

    void draw() const override {
        cout << "Drawing empty cell" << endl;
    }

    ~EmptyCell() {
        cout << "EmptyCell destructor" << endl;
    }
};

int main() {
    PuzzleObject* obj1 = new NumberTile(8);
    PuzzleObject* obj2 = new EmptyCell();

    obj1->draw();
    obj2->draw();

    NumberTile* tilePtr = dynamic_cast<NumberTile*>(obj1);
    if (tilePtr) {
        tilePtr->showValue();
    }

    NumberTile* wrongCast = dynamic_cast<NumberTile*>(obj2);
    if (!wrongCast) {
        cout << "obj2 is not a NumberTile" << endl;
    }

    delete obj1;
    delete obj2;

    return 0;
}
