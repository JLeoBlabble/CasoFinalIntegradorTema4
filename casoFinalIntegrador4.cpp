#include "casoFinalIntegrador4.h"
#include "json11.hpp"
#include <sstream>
#include <stdexcept>

using namespace std;

// Constructores de clases Variant que inicializan el tipo de variante

// + establece los punteros a nullptr. Este constructor se utiliza cuando solo se especifica el tipo de variante.
Variant::Variant(const variant_type type) : type(type), env(nullptr), proc(nullptr){}

// + el valor de la variante. Se utiliza cuando se especifica tanto el tipo como el valor de la variante.
Variant::Variant(const variant_type type, string val) : type(type), val(move(val)), proc(nullptr), env(nullptr){}

// + establece el puntero a la función proc. Se utiliza cuando se especifica una función de procedimiento.
Variant::Variant(const proc_type proc) : type(Proc), proc(proc), env(nullptr){}

// Metodo que convierte la variante a una cadena de texto para su representación.
// Este metodo utiliza un switch para determinar el tipo de variante y devolver una cadena de texto adecuada.
string Variant::to_string() const {
    switch (type) {
        case Symbol: return "Symbol: " + val; // Si el tipo es Symbol, devuelve "Symbol: " seguido del valor.
        case Number: return "Number: " + val; // Si el tipo es Number, devuelve "Number: " seguido del valor.
        case List: {
            string result = "List: ["; // Si el tipo es List, comienza la cadena con "List: [".
            for (const auto& elem : list) {
                result += elem.to_string() + ", "; // Añade cada elemento de la lista a la cadena.
            }
            // Quitar última coma y espacio
            if (!list.empty()) {
                result.pop_back();
                result.pop_back();
            }
            result += "]"; // Cierra la lista con "]".
            return result;
        }
        case Proc: return "Proc"; // Si el tipo es Proc, devuelve "Proc".
        case Lambda: return "Lambda"; // Si el tipo es Lambda, devuelve "Lambda".
        case Cadena: return "Cadena: " + val; // Si el tipo es Cadena, devuelve "Cadena: " seguido del valor.
        default: return "Unknown"; // Si el tipo es desconocido, devuelve "Unknown".
    }
}

// Metodo que convierte la variante a una cadena de texto en formato JSON.
// Este metodo utiliza un switch para determinar el tipo de variante y devolver una cadena de texto en formato JSON adecuada.
string Variant::to_json_string() const {
    switch (type) {
        case Symbol: return "\"" + val + "\""; // Si el tipo es Symbol, devuelve el valor entre comillas.
        case Number: return val; // Si el tipo es Number, devuelve el valor tal cual.
        case List: {
            string result = "["; // Si el tipo es List, comienza la cadena con "[".
            for (const auto& elem : list) {
                result += elem.to_json_string() + ", "; // Añade cada elemento de la lista a la cadena en formato JSON.
            }
            // Quitar última coma y espacio
            if (!list.empty()) {
                result.pop_back();
                result.pop_back();
            }
            result += "]"; // Cierra la lista con "]".
            return result;
        }
        case Proc: return "\"Proc\""; // Si el tipo es Proc, devuelve "Proc" entre comillas.
        case Lambda: return "\"Lambda\""; // Si el tipo es Lambda, devuelve "Lambda" entre comillas.
        case Cadena: return "\"" + val + "\""; // Si el tipo es Cadena, devuelve el valor entre comillas.
        default: return "\"Unknown\""; // Si el tipo es desconocido, devuelve "Unknown" entre comillas.
    }
}

// Metodo estático que convierte una cadena de texto en formato JSON a una instancia de Variant.
// Este metodo utiliza la biblioteca json11 para analizar la cadena JSON y luego llama a parse_json para convertir el objeto JSON en una instancia de Variant.
Variant Variant::from_json_string(const string& sjson) {
    string err; // Variable para almacenar mensajes de error.
    auto json = json11::Json::parse(sjson, err); // Analiza la cadena JSON.
    if (!err.empty()) {
        throw runtime_error("Invalid JSON: " + err); // Lanza una excepción si hay un error en el análisis.
    }
    return parse_json(json); // Convierte el objeto JSON en una instancia de Variant.
}

// Metodo estático que convierte un objeto JSON en una instancia de Variant.
// Este metodo utiliza un conjunto de condiciones para determinar el tipo de objeto JSON y crear la instancia de Variant correspondiente.
Variant Variant::parse_json(const json11::Json& job) {
    if (job.is_string()) {
        return Variant(Symbol, job.string_value()); // Si el objeto JSON es una cadena, crea una instancia de Variant de tipo Symbol.
    } else if (job.is_number()) {
        ostringstream oss;
        oss << job.number_value();
        return Variant(Number, oss.str()); // Si el objeto JSON es un número, crea una instancia de Variant de tipo Number.
    } else if (job.is_array()) {
        Variant v(List); // Si el objeto JSON es una lista, crea una instancia de Variant de tipo List.
        for (const auto& elem : job.array_items()) {
            v.list.push_back(parse_json(elem)); // Añade cada elemento de la lista JSON a la lista de Variant.
        }
        return v;
    } else if (job.is_object()) {
        return Variant(); // Si el objeto JSON es un objeto, crea una instancia de Variant vacía (puedes personalizar esto según tus necesidades).
    } else {
        return Variant(); // Si el tipo de objeto JSON es desconocido, crea una instancia de Variant vacía.
    }
}