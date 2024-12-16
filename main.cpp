#include "casoFinalIntegrador4.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    try {
        // Ejemplo de uso de la clase Variant con un símbolo, número, cadena, lista y JSON

        Variant v1(Symbol, "burrinclín");
        cout << v1.to_string() << endl;

        Variant v2(Number, "42");
        cout << v2.to_string() << endl;

        Variant v3(Cadena, "chachi pistachi");
        cout << v3.to_string() << endl;

        Variant v4(List);
        v4.list.push_back(Variant(Symbol, "hola"));
        v4.list.push_back(Variant(Number, "123"));
        v4.list.push_back(Variant(Cadena, "buenos días broski"));
        cout << v4.to_string() << endl;

        // Ejemplo de uso de parse_json
        string json_str = R"({"key": "value", "number": 123, "list": ["item1", "item2"]})"; // Cadena JSON
        string err; // Variable para almacenar mensajes de error
        json11::Json json = json11::Json::parse(json_str, err); // Analizar la cadena JSON
        if (!err.empty()) {
            throw runtime_error("Error al analizar JSON: " + err); // Lanzar una excepción si hay un error
        }
        Variant v5 = Variant::parse_json(json); // Convertir el objeto JSON a una variante
        cout << v5.to_json_string() << endl;
    } catch (const exception& e) {
        cerr << "Excepción capturada: " << e.what() << endl;
        return 1;
    }

    return 0;
}