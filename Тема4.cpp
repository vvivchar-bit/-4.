#include <iostream>
using namespace std;

class PuzzleElement {
protected:
    int x, y;

public:
    PuzzleElement(int x, int y) : x(x), y(y) {
        cout << "PuzzleElement constructor" << endl;
    }

    virtual void show() const {
        cout << "Base element at (" << x << ", " << y << ")" << endl;
    }

    virtual ~PuzzleElement() {
        cout << "PuzzleElement destructor" << endl;
    }
};

class NumberTile : public PuzzleElement {
private:
    int value;

public:
    NumberTile(int x, int y, int value) : PuzzleElement(x, y), value(value) {
        cout << "NumberTile constructor" << endl;
    }

    void show() const override {
        cout << "Tile " << value << " at (" << x << ", " << y << ")" << endl;
    }

    ~NumberTile() {
        cout << "NumberTile destructor" << endl;
    }
};

int main() {
    PuzzleElement* element = new NumberTile(1, 2, 5);

    element->show();

    delete element;
    return 0;
}
