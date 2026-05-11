// Archivo: Node.h
// Autor: Hecho en clase
//
// Descripción:
// Clase auxiliar que representa un nodo para estructuras enlazadas.
// Cada nodo almacena un elemento y una referencia al siguiente nodo.
//
// Funcionalidades principales:
// - Almacenar datos genéricos.
// - Conectar nodos entre sí.
//
// Esta clase es utilizada por la implementación de LinkedList

#pragma once

template <typename E>
class Node {
public:
    E element;
    Node<E>* next;

    Node(E element, Node<E>* next = nullptr) {
        this->element = element;
        this->next = next;
    }

    Node() {
        next = nullptr;
    }
};