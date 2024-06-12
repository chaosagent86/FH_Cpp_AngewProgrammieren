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

    bool isLastPosition() {
        return x == size - 1 && y == size - 1;
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
            // if(i == j) {
            //     continue;
            // }

            Queen *q2 = queens[j];

            if(q1->isAllowed(q2) == false) {
                return false;
            }

        }
    }

    return true;
}

int main() {
    // unsigned i1 = 2;
    // unsigned i2 = 4;

    // cout << abs((int)(i1 - i2)) << endl;

    unsigned size = 6;

    vector<Queen*> queens;

    Queen *current = nullptr;
    for(unsigned i = 0; i < size; i++) {
        Queen *q = new Queen(size);

        q->previous = current;
        current = q;

        queens.push_back(q);
    }


    current->print();

    int i = 0;
    while(true) {
        i++;

        if(finished(queens)) {
            cout << "FINISHED without result (i=)" << i << ")" << endl;
            break;
        }

        current->increment();

        // wann sind wir fertig?
        // 1. keine königinnen schlagen sich
        // 2. alle stehen am letzten feld


        if(checkAll(queens)) {
            cout << "FINISHED WITH result (i=)" << i << ")" << endl;
            current->print();
            break;
        }

    }

    current->print();

    for(int i = 0; i < size; i++) {
        int y = -1;

        for(Queen *q : queens) {
            if(q->x == i) {
                y = q->y;
            }
        }

        string s = string(y, '_') + 'X';

        cout << s << endl;
    }

    // }

}