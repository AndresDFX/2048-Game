#include "tree.h"

tree::tree()
{

}

ABB tree:: createNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}

void tree::insert(ABB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = createNodo(x);
     }
     else if(x < arbol->nro)
          insert(arbol->izq, x);
     else if(x > arbol->nro)
          insert(arbol->der, x);
}

void tree::preOrder(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrder(arbol->izq);
          preOrder(arbol->der);
     }
}

void tree::lookTree(ABB arbol, int n)
{
     if(arbol==NULL)
          return;
     lookTree(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     lookTree(arbol->izq, n+1);
}



int tree::countNodes(ABB arbol){

 if (arbol==0)
 return 0;
 else return 1+countNodes(arbol->izq)+countNodes(arbol->der);

}

