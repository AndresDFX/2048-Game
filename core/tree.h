#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cstdlib>

using namespace std;

struct nodo{
     int nro;
     struct nodo *izq, *der;
};

typedef struct nodo *ABB;

class tree
{
    public:
        tree();
        ABB createNodo(int x);
        void insert(ABB &arbol, int x);
        void preOrder(ABB arbol);
        void lookTree(ABB arbol, int n);
        int countNodes(ABB arbol);

    private:


};

#endif // TREE_H
