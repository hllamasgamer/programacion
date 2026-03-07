# Tareas Pendientes del Taller 1

Aquí llevaremos el registro de las tareas a completar para mejorar el programa principal. 
A continuación, propongo el pseudocódigo para resolver cada punto. Si estás de acuerdo o quieres que te ayude con el código final en C++, ¡sólo pídemelo!

---

## 1. Dar mensajes más explicativos
**Objetivo:** Mostrar un mensaje claro en la consola cuando se realiza una compra, indicando qué se compró exactamente o por qué falló la compra.

**Pseudocódigo (para `main.cpp`):**
```text
SI exito ES VERDADERO:
    IMPRIMIR "¡Felicidades " + p1.nombre + "! Has comprado un " + a1.marca + " " + a1.modelo + " por " + a1.precio + " euros."
SINO:
    IMPRIMIR "Lo sentimos " + p1.nombre + ", no se pudo realizar la compra. Ya tienes el máximo de coches permitidos."
FIN SI
```

## 2. Comprar más vehículos
**Objetivo:** Crear nuevos objetos de la clase `Automovil` y simular su compra para probar que el arreglo de `comprados` funciona y ver cómo cambia el número de coches (`nComprados`).

**Pseudocódigo (para `main.cpp`):**
```text
// Crear el segundo coche
CREAR Automovil a2
a2.tipo = "Coche"
a2.marca = "Ford"
a2.modelo = "Mustang"
a2.matricula = "1234 ABC"  // IMPORTANTE para la tarea 3
// ... (asignar el resto de atributos deseados)

// Comprarlo
VARIABLE exito2 = p1.compra(a2)

SI exito2 ES VERDADERO:
    IMPRIMIR "Segunda compra exitosa."
SINO:
    IMPRIMIR "Fallo en la segunda compra."
FIN SI
```

## 3. Mostrar las matrículas de los coches comprados
**Objetivo:** Crear un método dentro de la clase `Persona` que recorra su listado de coches e imprima por pantalla la matrícula y modelo de cada uno.

**Pseudocódigo propuesto:**

**Parte A (En `Persona.h`):**
```text
Añadir a la lista de métodos públicos:
    void mostrarCoches();
```

**Parte B (En `Persona.cpp`):**
```text
FUNCIÓN mostrarCoches() DE LA CLASE Persona:
    IMPRIMIR "==========================="
    IMPRIMIR "Coches propiedad de " + nombre + ":"
    
    SI nComprados ES IGUAL A 0:
        IMPRIMIR "Esta persona aún no tiene coches."
    SINO:
        PARA i DESDE 0 HASTA nComprados - 1:
            IMPRIMIR "- Coche " + (i + 1) + ":"
            IMPRIMIR "  Marca y Modelo: " + comprados[i].marca + " " + comprados[i].modelo
            IMPRIMIR "  Matrícula: " + comprados[i].matricula
        FIN PARA
    FIN SI
    
    IMPRIMIR "==========================="
FIN FUNCIÓN
```

**Parte C (En `main.cpp`):**
```text
Al final del programa principal, llamar al nuevo método:
p1.mostrarCoches()
```
