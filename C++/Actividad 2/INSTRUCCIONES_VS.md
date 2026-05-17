# Guía de Configuración Simplificada - Actividad 2

¡Buenas noticias! He reestructurado completamente el directorio y configurado los archivos del proyecto para eliminar todas las carpetas duplicadas y anidadas innecesarias. 

Ahora tienes una estructura limpia, portable y profesional que cumple perfectamente con las pautas de entrega.

---

## 1. Estructura de Carpetas Actual

Tu solución ahora está organizada de forma impecable:
```text
Actividad 2/
├── Actividad_2.slnx                  (Archivo de solución único en la raíz)
├── BibliotecaVehiculos/              (Proyecto 1: Biblioteca Estática)
│   ├── BibliotecaVehiculos.vcxproj   (Archivo de proyecto)
│   ├── Vehiculo.h / Vehiculo.cpp
│   ├── Coche.h / Coche.cpp
│   ├── Moto.h / Moto.cpp
│   └── Tratamiento.h / Tratamiento.cpp
├── AppConsola/                       (Proyecto 2: Aplicación de Consola)
│   ├── AppConsola.vcxproj            (Archivo de proyecto)
│   ├── main.cpp                      (Punto de entrada de la aplicación)
│   └── Camion.h / Camion.cpp         (Clase de extensión)
└── documento_explicativo.md          (Memoria de la actividad)
```

---

## 2. Cómo Abrir y Ejecutar el Proyecto

No es necesario configurar nada manualmente desde cero. Todo está pre-configurado y enlazado con rutas relativas portables:

1.  Abre **Visual Studio**.
2.  Haz doble clic sobre el archivo **`Actividad_2.slnx`** que está en la carpeta raíz `Actividad 2`.
3.  ¡Listo! Visual Studio cargará automáticamente la solución con los dos proyectos (`BibliotecaVehiculos` y `AppConsola`) ya vinculados, configurados y listos.

---

## 3. Verificación de la Actividad

Para comprobar que todo funciona y que cumples con la demostración de la extensibilidad:

1.  Asegúrate de que el proyecto de consola esté configurado como proyecto de inicio:
    *   Haz clic derecho sobre **`AppConsola`** en el Explorador de soluciones.
    *   Selecciona **Establecer como proyecto de inicio** (*Set as StartUp Project*).
2.  Compila la solución completa:
    *   Clic derecho sobre la **Solución 'Actividad_2'** -> **Compilar solución** (*Build Solution*).
3.  Ejecuta pulsando **F5** o haciendo clic en **Iniciar** (depurador local). Verás en la consola la salida acústica de todos los vehículos (incluyendo el `Camion`, que se procesa a través del `Tratamiento` genérico de la biblioteca).
4.  **Demostración de No-Recompilación:**
    *   Abre `Camion.cpp` en el proyecto de consola y realiza un pequeño cambio en el texto que devuelve su sonido (ej. `"HONK HNK (Camion Modificado)"`).
    *   Haz clic derecho **únicamente** sobre el proyecto **`AppConsola`** -> **Compilar** (*Build*).
    *   Verás que compila al instante sin necesidad de volver a compilar el proyecto `BibliotecaVehiculos`. La biblioteca estática funciona con la nueva extensión sin verse alterada ni recompilada en absoluto.
