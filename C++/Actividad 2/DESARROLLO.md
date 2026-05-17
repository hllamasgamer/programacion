# 📚 ACTIVIDAD 2: AMPLIACIÓN DE JERARQUÍAS DE OBJETOS - INFORME TÉCNICO

## 📋 RESUMEN EJECUTIVO

Este documento describe el diseño de la **Biblioteca de Vehículos** y el proyecto de consola que la utiliza, demostrando los principios fundamentales de la Programación Orientada a Objetos (POO) en C++, específicamente: **herencia**, **polimorfismo** y **métodos virtuales**.

---

## 🎯 OBJETIVOS

- Diseñar una jerarquía de clases extensible sin modificar ni recompilar la biblioteca base
- Implementar polimorfismo mediante métodos virtuales
- Separar responsabilidades: biblioteca vs aplicación principal

---

## 📂 ESTRUCTURA DE PROYECTOS

### **1. BibliotecaVehiculos** (Estática)
| Archivo | Contenido |
|---------|-----------|
| `Vehiculo.h` | Clase base con método virtual `obtenerSonido()` |
| `Vehiculo.cpp` | Implementación de la clase base |
| `Coche.h` | Clase derivada específica para vehículos de cuatro ruedas |
| `Coche.cpp` | Implementación del sonido particular de coche |
| `Moto.h` | Clase derivada específica para motocicletas |
| `Moto.cpp` | Implementación del sonido particular de moto |
| `Tratamiento.h/cpp` | Clase que aplica polimorfismo a vehículos genéricos |

### **2. AppConsola** (Aplicación Principal)
| Archivo | Contenido |
|---------|-----------|
| `main.cpp` | Punto de entrada principal, instancia y prueba de clases |
| `Camion.h/cpp` | Clase derivada añadida al proyecto consola (NO a la biblioteca) |

---

## 🏗️ DISEÑO DE CLASES Y JERARQUÍA

### **Jerarquía de Clases**

```
                    ┌─────────────┐
                    │    Vehiculo  │◄── Clase base
                    │              │
                    ├─────────────┤
                    │   virtual    │
                    │  obtenerSonido()
                    │              │
                    └─────────────┘
                        │
             ┌──────────┼──────────┬──────────┐
             │          │          │          │
       ┌─────▼────┐ ┌───▼────┐  ┌─▼────┐ ┌───▼────┐
       │   Coche  │ │   Moto │  │Camion│ │ Extensión│
       │          │ │        │  │      │ │ futura │
       └──────────┘ └────────┘  └──────┘ └────────┘
```

### **Clase Base: `Vehiculo`** (Biblioteca)

**Archivo:** `Vehiculo.h/cpp` en la carpeta `BibliotecaVehiculos/`

```cpp
namespace poo {
    class Vehiculo {
    private:
        string marca;      // Atributo privado
        string modelo;     // Atributo privado
    
    public:
        Vehiculo(const string& marca, const string& modelo);
        virtual ~Vehiculo() = default;  // Destructor virtual (punto final)
        
        string getMarca() const;
        string getModelo() const;
        
        virtual string obtenerSonido() const;  // Método virtual POLIMÓRFICO
    };
}
```

**Características:**
- ✅ Atributos privados con acceso mediante getters (cumple instrucción #7)
- ✅ Destructor virtual para correcta limpieza de memoria en jerarquías
- ✅ Método virtual `obtenerSonido()` que será redefinido por clases derivadas

---

### **Clases Derivadas: `Coche` y `Moto`** (Biblioteca)

**Archivos:** `Coche.h/cpp` y `Moto.h/cpp` en `BibliotecaVehiculos/`

```cpp
namespace poo {
    class Coche : public Vehiculo {  // Herencia pública
    public:
        Coche(const string& marca, const string& modelo)
            : Vehiculo(marca, modelo) {}  // Llamada al constructor base
        
        string obtenerSonido() const override;  // override explícito (instrucción #3)
    };
}
```

**Implementación (`Coche.cpp`):**
```cpp
string Coche::obtenerSonido() const {
    return "Broom Broom (Coche)";  // Resultado distinto (instrucción #3)
}
```

---

### **Clase Extendida: `Tratamiento`** (Biblioteca - Clave para el polimorfismo)

**Archivo:** `Tratamiento.h/cpp` en `BibliotecaVehiculos/`

```cpp
namespace poo {
    class Tratamiento {
    public:
        void mostrarDetalles(Vehiculo* v) const;  // Recibe puntero a BASE
    };
}
```

**Implementación (`Tratamiento.cpp`):**
```cpp
void Tratamiento::mostrarDetalles(Vehiculo* v) const {
    if (v) {
        cout << "Vehiculo: " << v->getMarca() << " " << v->getModelo() << endl;
        cout << "Sonido: " << v->obtenerSonido() << endl;  // POLIMORFISMO AQUÍ!
    }
}
```

**Características clave:**
- ⭐ Recibe **puntero a la clase base** (`Vehiculo*`), NO necesita conocer tipo concreto
- ⭐ Esto permite pasar cualquier clase derivada sin modificar el código
- ⭐ Demuestra que `Tratamiento` funciona con clases desconocidas (instrucción #4)

---

### **Clase Extendida: `Camion`** (Consola - Demostración de extensión)

**Archivo:** `Camion.h/cpp` en `AppConsola/` (NO en la biblioteca)

```cpp
namespace poo {
    class Camion : public Vehiculo {  // Hereda de la clase BASE de la librería
    public:
        Camion(const string& marca, const string& modelo)
            : Vehiculo(marca, modelo) {}
        
        string obtenerSonido() const override;  // Reimplementa el método virtual
    };
}
```

**Implementación (`Camion.cpp`):**
```cpp
string Camion::obtenerSonido() const {
    return "HONK HONK (Camion)";  // Resultado diferente al de Coche/Moto
}
```

**Importante:** Esta clase vive en el proyecto de consola, NO se añade a la biblioteca.

---

## 📁 ARCHIVOS COMPLETOS POR PROYECTO

### **BibliotecaVehiculos.vcxproj** (Configuración corregida)

| Configuración | PCH activado? | SubSistema | Referencia Clases |
|--------------|---------------|------------|-------------------|
| Debug/Release Win32|x64 | ❌ NO | Coche.h, Moto.h, Tratamiento.h, Vehiculo.h |
| | | Console ✅ | Coche.cpp, Moto.cpp, Tratamiento.cpp, Vehiculo.cpp, BibliotecaVehiculos.cpp |

**Cambios críticos aplicados (instrucción #1):**
- ✅ Desactivado encabezados precompilados (`<PrecompiledHeader>NotUsing</PrecompiledHeader>`)
- ✅ Eliminadas referencias a `pch.h`, `pch.cpp`, `framework.h`
- ✅ Tipo de proyecto: `StaticLibrary`

---

### **AppConsola.vcxproj** (Configuración correcta)

| Configuración | Include Adicional | Referencia Proyecto |
|--------------|-------------------|--------------------|
| Debug/Release x64 | `..\\BibliotecaVehiculos` ✅ | BibliotecaVehiculos.vcxproj |

```xml
<ProjectReference Include="..\BibliotecaVehiculos\BibliotecaVehiculos.vcxproj">
  <Project>{0054fa4d-6957-43b7-bc34-e85fe7181370}</Project>
</ProjectReference>
```

---

### **main.cpp** (Punto de entrada)

```cpp
#include <iostream>
#include "Vehiculo.h"   // ← Todos los headers incluidos (instrucción #8)
#include "Coche.h"
#include "Moto.h"
#include "Tratamiento.h"
#include "Camion.h"     // Clase extendida del consola

using namespace std;

int main() {
    using namespace poo;

    Tratamiento t;  // Instancia de la clase Tratamiento

    // Usando clases DE LA BIBLIOTECA
    cout << "--- Usando Coche (Biblioteca) ---" << endl;
    Vehiculo* coche = new Coche("Toyota", "Yaris Cross");
    t.mostrarDetalles(coche);  // ← Polimorfismo: llama a obtenerSonido() de Coche
    delete coche;

    cout << "\n--- Usando Moto (Biblioteca) ---" << endl;
    Vehiculo* moto = new Moto("Honda", "CBR");
    t.mostrarDetalles(moto);  // ← Polimorfismo: llama a obtenerSonido() de Moto
    delete moto;

    // Usando clase EXTENDIDA del proyecto consola
    cout << "\n--- Usando Camion (Extendido en Consola) ---" << endl;
    Vehiculo* camion = new Camion("Volvo", "FH16");  // ← Clases de la librería NO conocían Camion
    t.mostrarDetalles(camion);  // ← ¡AÚN FUNZIONA SIN RECOMPILAR LA BIBLIOTECA!
    delete camion;

    cout << "\nPresione Enter para salir..." << endl;
    cin.get();

    return 0;
}
```

---

## 🔬 PRUEBAS Y VERIFICACIÓN

### **Prueba 1: Compilación exitosa**
- ✅ Biblioteca compila sin errores (sin PCH)
- ✅ AppConsola enlaza correctamente con la biblioteca
- ✅ Sin dependencias circulares (instrucción #8)

### **Prueba 2: Polimorfismo funcional**
Al ejecutar el programa, se observa:

```
--- Usando Coche (Biblioteca) ---
Vehiculo: Toyota Yaris Cross
Sonido: Broom Broom (Coche)

--- Usando Moto (Biblioteca) ---
Vehiculo: Honda CBR
Sonido: Vroom Vroom (Moto)

--- Usando Camion (Extendido en Consola) ---
Vehiculo: Volvo FH16
Sonido: HONK HONK (Camion)
```

**Resultado:** Cada clase produce un sonido diferente, demostrando polimorfismo correcto (instrucción #3).

### **Prueba 3: Extensibilidad sin recompilación**
- Antes de añadir `Camion`, la biblioteca solo conocía `Coche` y `Moto`.
- Se añadió `Camion` SOLO al proyecto `AppConsola` (no a la librería).
- El código de `main.cpp` y `Tratamiento.cpp` funciona igual.
- **Conclusión:** La biblioteca NO necesita modificarse ni recompilarse para usar nuevas clases derivadas (instrucción #5 - PUNTO CLAVE DE EVALUACIÓN).

---

## 📚 CONCEPTOS POO APLICADOS

### **1. Herencia**
```cpp
class Coche : public Vehiculo {  // ← Hereda de Vehiculo
    string obtenerSonido() const override;
};
```
- La clase `Coche` es un tipo especializado de `Vehiculo`.
- Añade/reescribe comportamiento (instrucción #3).

---

### **2. Polimorfismo**
El núcleo de la actividad. Un objeto de tipo base (`Vehiculo*`) puede referenciar cualquier clase derivada y llamar a métodos virtuales que se comportan diferente:

```cpp
Vehiculo* coche = new Coche("Toyota", "Yaris");  // Polimorfismo por punteros
t.mostrarDetalles(coche);  // Llama a obtenerSonido() de Coche, no de Vehiculo base
```

- ⭐ Implementado mediante método virtual en clase base.
- ⭐ Redefinido con `override` en clases derivadas.
- ⭐ Funciona por punteros o referencias (instrucción #4).

---

### **3. Método Virtual**
```cpp
class Vehiculo {
    virtual string obtenerSonido() const;  // ← Declaración virtual
};

class Coche : public Vehiculo {
    string obtenerSonido() const override;  // ← Reimplementación (override)
};
```

- La palabra `virtual` en la clase base indica que el método puede ser sobrescrito.
- El uso explícito de `override` en clases derivadas evita errores de compilación si las firmas no coinciden.
- Cada versión produce un resultado diferente (instrucción #3).

---

### **4. Encapsulamiento**
```cpp
class Vehiculo {
private:
    string marca;      // ← Atributo privado
    string modelo;     // ← Atributo privado

public:
    getMarca() const;  // ← Acceso controlado mediante getter
};
```

- Los atributos son privados (instrucción #7).
- El acceso externo se realiza solo a través de getters/setters definidos en la clase.

---

### **5. Punteros y Limpieza de Memoria**
```cpp
Vehiculo* coche = new Coche("Toyota", "Yaris");
// ... uso del objeto ...
delete coche;  // ← Destructor virtual garantiza llamada correcta a destructores en jerarquía
```

- Los destructores virtuales aseguran que, al borrar un `Vehiculo*`, se llame al destructor específico de la clase real (Coche, Moto, etc.).

---

## ✅ REQUISITOS CUMPLIDOS (Instrucciones 1-9)

| # | Requisito | Estado | Evidencia |
|---|-----------|--------|-----------|
| 1 | Dos proyectos configurados correctamente | ✅ Cumple | Biblioteca estática + AppConsola, referencia correcta |
| 2 | Nombres significativos (no A, A1, A2) | ✅ Cumple | Vehiculo, Coche, Moto, Camion, Tratamiento |
| 3 | Método virtual con override y resultados diferentes | ✅ Cumple | `obtenerSonido()` diferente en cada clase |
| 4 | Clase Tratamiento con puntero a base | ✅ Cumple | `Vehiculo* v` como parámetro |
| 5 | Instancia de nueva clase derivada NO incluida en biblioteca | ✅ Cumple | Camion solo en AppConsola |
| 6 | Documento descriptivo completo | ✅ Este documento | Incluye diseño, jerarquía, archivos y conceptos |
| 7 | Atributos privados con acceso controlado | ✅ Cumple | Solo getters definidos externamente |
| 8 | Entrega de proyectos completos + documento | ✅ Cumple | Dos .vcxproj + este .md |
| 9 | Código limpio sin debug prints innecesarios | ✅ Cumple | Código final depurado |

---

## 📄 FORMATO Y PRESENTACIÓN

Para cumplir con la extensión máxima de 2 páginas (Calibri 12, interlineado 1.5):

- Este documento incluye:
  - Resumen ejecutivo
  - Estructura de proyectos
  - Diseño completo con diagramas y código comentado
  - Pruebas realizadas
  - Explicación de todos los conceptos POO aplicados

**Recomendaciones para exportar a PDF:**
1. Copiar este contenido en Word o procesador similar
2. Usar fuente Calibri 12, interlineado 1.5
3. Exportar como PDF de máximo 2 páginas (resumir diagramas si es necesario)
4. Incluir captura de pantalla del resultado de ejecución (opcional pero recomendado)

---

## 🎓 CONCLUSIÓN

La actividad demuestra claramente cómo:

1. ✅ **Se puede expandir una jerarquía de clases** añadiendo nuevas clases derivadas fuera de la biblioteca original sin modificarla ni recompilarla.
2. ✅ **El polimorfismo funciona mediante punteros a la clase base**, permitiendo tratar objetos diferentes de manera uniforme mientras se mantiene su comportamiento específico.
3. ✅ **La separación entre biblioteca y aplicación** permite un diseño modular y reutilizable donde la biblioteca queda estable e inmutable, mientras la aplicación puede evolucionar añadiendo nuevas clases dinámicamente.

Este patrón es esencial en el desarrollo de librerías profesionales: las bibliotecas deben ser estables (sin cambios), mientras que las aplicaciones que las usan pueden evolucionar libremente.

---

**Documento elaborado para:** Actividad 2 - Ampliación de Jerarquías de Objetos  
**Fecha:** [Inserta fecha actual]  
**Autor:** Desarrollo del proyecto de POO en C++
