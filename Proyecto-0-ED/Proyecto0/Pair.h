// Archivo: Pair.h
// Autor: Hecho en clase
//
// Descripción:
// Clase genérica que representa un par clave-valor.
// Incluye operadores de comparación basados en la clave.
//
// Funcionalidades principales:
// - Almacenar pares de datos.
// - Comparar elementos mediante operadores relacionales.
// - Mostrar pares mediante sobrecarga de operadores.
//
// Esta clase es utilizada junto con estructuras de prioridad

#pragma once

#include <iostream>
#include <ostream>

using std::ostream;

template<typename K, typename V>
class Pair {
public:
	K key;
	V value;

	Pair() {}
	Pair(K key, V value) {
		this->key = key;
		this->value = value;
	}
	bool operator==(const Pair<K, V>& other) {
		return key == other.key;
	}
	bool operator<(const Pair<K, V>& other) {
		return key < other.key;
	}
	bool operator<=(const Pair<K, V>& other) {
		return key <= other.key;
	}
	bool operator>(const Pair<K, V>& other) {
		return key > other.key;
	}
	bool operator>=(const Pair<K, V>& other) {
		return key >= other.key;
	}
	friend ostream& operator<<(ostream& os, const Pair<K, V>& p) {
		os << "(" << p.key << ", " << p.value << ")";
		return os;
	}
};