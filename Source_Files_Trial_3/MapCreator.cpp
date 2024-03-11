#include "MapCreator.h"

using namespace std;

MapCreator::MapCreator(int width, int height){
    vector<int> * start = RandomStart(width, height);
    
}

vector<int> * MapCreator::RandomStart(int width, int height){
    // if 1 -> left side, if 2 -> top, if 3 -> right side, if 4 -> bottom
    time_t t;
    srand((unsigned) time(&t));
    int side = rand() % 4 + 1;
    vector<int> * randomStartIndex;
    int X;
    int Y;

    switch(side){
        case 1: // left side
            X = 0; // isn't random
            randomStartIndex->push_back(X);
            Y = rand() % (height - 2) + 1;
            randomStartIndex->push_back(Y);
            break;
        case 2: // top
            X = rand() % (width - 2) + 1;
            randomStartIndex->push_back(X);
            Y = 0; // isn't random
            randomStartIndex->push_back(Y);
            break;
        case 3: // right side
            X = width - 1; // isn't random
            randomStartIndex->push_back(X);
            Y = rand() % (height - 2) + 1;
            randomStartIndex->push_back(Y);
            break;
        case 4: // bottom
            X = rand() % (width - 2) + 1;
            randomStartIndex->push_back(X);
            Y = height - 1; // isn't random
            randomStartIndex->push_back(Y);
            break;
        default:
            X = 1;
            randomStartIndex->push_back(X);
            Y = 0;
            randomStartIndex->push_back(Y);
            break;
        
    }
    return randomStartIndex;
}
