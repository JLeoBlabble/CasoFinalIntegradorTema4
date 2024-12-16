#ifndef CASOFINALINTEGRADOR4_H
#define CASOFINALINTEGRADOR4_H

#include <vector>
#include <string>
#include <map>
#include "json11.hpp" // Asegúrate de tener esta biblioteca en tu sistema

using namespace std;

// Enumeración que define los diferentes tipos de variantes
enum variant_type { Symbol, Number, List, Proc, Lambda, Cadena };

// Declaración de la estructura Entorno
struct Entorno;

// Clase Variant que representa una variante que puede ser de diferentes tipos
class Variant {
public:
    // Definición de un tipo de puntero a función que toma un vector de Variant y devuelve un Variant
    typedef Variant(*proc_type) (const vector<Variant>&);
    // Definición de un iterador constante para un vector de Variant
    typedef vector<Variant>::const_iterator iter;
    // Definición de un mapa que asocia cadenas a Variant
    typedef map<string, Variant> map;

    // Miembros de datos de la clase Variant
    variant_type type;
    string val;
    vector<Variant> list;
    proc_type proc; // Puntero a función si el tipo es Proc
    Entorno* env; // Puntero a un entorno (nullptr)

    // Constructores de la clase Variant
    explicit Variant(variant_type type = Symbol);
    Variant(variant_type type, string val);
    explicit Variant(proc_type proc);

    // Métodos de la clase Variant
    string to_string() const; // Método que convierte la variante a una cadena de texto
    string to_json_string() const; // Método que convierte la variante a una cadena de texto en formato JSON
    static Variant from_json_string(const string& json); // Método estático que convierte una cadena JSON a una instancia de Variant
    static Variant parse_json(const json11::Json& job); // Método estático que convierte un objeto JSON a una instancia de Variant
};

#endif //CASOFINALINTEGRADOR4_H