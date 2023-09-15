#include "struct.h"

void printFruit(const Fruit myFruit){
    cout << "Type: " << myFruit.type << endl;
    cout << "Color: " << myFruit.color << endl;
    cout << "Weight: " << myFruit.weight << endl;
}

int compareFruits(Fruit * f1, Fruit * f2){
    // Compare the type
    if (f1->type < f2->type){
        return -1;
    }
    else if (f1->type > f2->type){
        return 1;
    }
    else{ // same type, check color
        if (f1->color < f2->color){
            return -1;
        }
        else if (f1->color > f2->color){
            return 1;
        }
        else{ // same type and color, check weight
            if (f1->weight < f2->weight){
                return -1;
            }
            else if (f1->weight > f2->weight){
                return 1;
            }
            else{ // same type, color, and weight
                return 0;
            }
        }
    }
}