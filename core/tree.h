/**
  * @file tree.h
  * @version 1.0
  * @date 25/03/2020
  *
*/

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * @brief Estructura que representa un arbol binario de busqueda
 */
struct nodo{
     int nro;
     struct nodo *izq, *der;
};

/**
 * @brief Definicion de un nuevo tipo de datos dada la estructura de un nodo en un arbol binario de busqueda
 */
typedef struct nodo *ABB;

/**
 * @brief Clase que implementa todos los metodos recursivos necesarios parar insertar, consultar y contar los nodos de un arbol binario de busqueda
 */
class tree
{
    public:
        tree();

        /**
         * @brief Metodo que crea un nodo de un ABB
         * @param x Variable que almacena el valor del nodo
         * @return El nodo de un arbol binario de busqueda
         */
        ABB createNodo(int x);

        /**
         * @brief Metodo recursivo que dado un arbol, revisa la definicion de un ABB y lo inserta en la posicion adecuada
         * @param arbol Variable que almacena el valor a modificar
         * @param x Variable que almacena el valor a insertar en el ABB de manera organizada
         */
        void insert(ABB &arbol, int x);

        /**
         * @brief Metodo recursivo que dado un arbol lo recorre en preorden y lo imprime por pantalla
         * @param arbol Variable que almacena el arbol que se quiere recorrer
         */
        void preOrder(ABB arbol);

        /**
         * @brief Metodo recursivo que dado un arbol lo muestra de manera que sea facil visualizar los nodos y lo imprime por pantalla
         * @param arbol Variable que almacena el arbol que se quiere mostrar
         * @param n Variable contador que se utiliza para mostrar el arbol
         */
        void lookTree(ABB arbol, int n);

        /**
         * @brief Metodo recursivo que dado un arbol lo recorre en preorden y por cada nodo suma+1
         * @param arbol Variable que almacena el arbol que se quiere contar
         * @return Variable que devuelve la cantidad de nodos del arbol
         */
        int countNodes(ABB arbol);


};

#endif // TREE_H
