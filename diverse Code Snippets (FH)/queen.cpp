#include <iostream>
#include <vector>

using namespace std;

class Queen {
    unsigned size;
    public:
        Queen *previous = nullptr;
        unsigned x, y;

    Queen(unsigned size) : size(size) { }

    void print() {
        cout << x << "/" << y << "  ";
        if(previous) {
            previous->print();
        } else {
            cout << endl;
        }
    }

    void increment() {
        x++;
        if(x < size) {
            return;
        }

        x = 0;
        y++;

        if(y < size) {
            return;
        }

        y = 0;
        if(previous) {
            previous->increment();
        }
    }

    bool isAllowed(Queen *other) {
        if(x == other->x || y == other->y) {
            return false;
        }

        int dx = abs((int)x - (int)other->x);
        int dy = abs((int)y - (int)other->y);

        if(dx == dy) {
            return false;
        }

        return true;
    }

    bool isLastPosition() {
        return x == size - 1 && y == size - 1;
    }
};

bool finished(vector<Queen*> queens) {
    for(auto queen : queens) {
        if(queen->isLastPosition() == false) {
            return false;
        }
    }

    return true;
}

bool checkAll(vector<Queen*> queens) {
    for(size_t i = 0; i < queens.size(); i++) {
        Queen *q1 = queens[i];

        for(size_t j = i + 1; j < queens.size(); j++) {
            Queen *q2 = queens[j];

            if(q1->isAllowed(q2) == false) {
                return false;
            }

        }
    }

    return true;
}

int main() {

    unsigned size = 5;

    vector<Queen*> queens;

    Queen *current = nullptr;
    for(unsigned i = 0; i < size; i++) {
        Queen *q = new Queen(size);
        q->previous = current;
        current = q;

        queens.push_back(q);
    }

    // current->print();


    int i = -1;
   // for(int i = 0; i < 100000; i++) {
    while(true) {
        i++;

        if(finished(queens)) {
            cout << "FINISHED without result (i=)" << i << ")" << endl;
            break;
        }

        // current->print();

        current->increment();

        if(checkAll(queens)) {
            cout << "FINISHED WITH result (i=)" << i << ")" << endl;
            current->print();
            break;
        }

    }

    //current->print();

    // for(auto q : queens) {
    //     cout << q->x << q->y << endl;
    // }
}