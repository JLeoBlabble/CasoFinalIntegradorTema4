# CasoFinalIntegradorTema4

https://github.com/JLeoBlabble/CasoFinalIntegradorTema4.git

## Enunciado del Proyecto
Para este proyecto, se te pide que implementes un intérprete "tiny-lisp" basado en la clase Variant y las capacidades de la Standard Template Library (STL) de C++. Deberás trabajar en CLion para este proyecto.

## Requisitos del proyecto:
Definir e implementar una clase Variant. Esta clase deberá ser capaz de representar diferentes tipos de datos, incluyendo símbolos, números, listas y procedimientos.
Implementar un método to_string() para la clase Variant que convierta una instancia de la clase a una cadena de texto.
Implementar un método to_json_string() para la clase Variant que convierta una instancia de la clase a una representación en formato JSON.
Implementar un método estático from_json_string() que tome una cadena en formato JSON y la convierta a una instancia de la clase Variant.
Implementar un método parse_json() que tome una cadena en formato JSON y la convierta a una instancia de la clase Variant.

## Rúbrica
### (30%) Implementación de la clase Variant:
Se implementó la clase Variant correctamente, y se incluyeron todos los tipos de datos requeridos.
### (20%) Método to_string():
El método to_string() está implementado correctamente y devuelve una cadena de texto que representa correctamente la instancia de la clase Variant.
### (20%) Método to_json_string():
El método to_json_string() está implementado correctamente y devuelve una representación JSON válida de la instancia de la clase Variant.
### (15%) Método estático from_json_string():
El método estático from_json_string() está implementado correctamente y puede tomar una cadena en formato JSON y convertirla en una instancia de la clase Variant.
### (15%) Método parse_json():
El método parse_json() está implementado correctamente y puede tomar una cadena en formato JSON y convertirla en una instancia de la clase Variant.

## Entrega

Todo el código debe estar bien comentado y organizado.
Se debe incluir un archivo README con instrucciones sobre cómo compilar y ejecutar tu programa.
El proyecto debe compilarse sin errores ni advertencias en CLion.

## Instrucciones para compilar y ejecutar el programa

### Requisitos previos
- Tener instalado CLion.
- Tener instalada la biblioteca `json11`.

### Pasos para compilar
1. Clona el repositorio:
   ```sh
   git clone https://github.com/JLeoBlabble/CasoFinalIntegradorTema4.git
   cd CasoFinalIntegradorTema4