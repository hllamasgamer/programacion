Ampliación de las jerarquías de objetos

Objetivos 

En esta actividad, aprenderás a crear una jerarquía de clases que pueda ser expandida luego de haber completado su diseño y programación, es decir, un código que siga funcionando después de añadir nuevas clases a la jerarquía inicial sin que haga falta modificado ni recompilado.

Pautas de elaboración

Para realizar la actividad, es necesario crear dos proyectos en Visual Studio:

▸	Una biblioteca de clases. El tipo de proyecto debe ser «Biblioteca estática».
▸	Un proyecto de consola. En él se sitúa la función main.

Es necesario configurar los proyectos de Visual Studio:

▸	Al proyecto de consola, agrega una referencia que apunte al proyecto de la biblioteca. En el explorador de soluciones, bajo el proyecto de consola, aparecen las referencias. Selecciónalas y, haciendo clic con el botón derecho del ratón, agrega una referencia a la biblioteca de clases.


▸	Selecciona la biblioteca de clases y, haciendo clic con el botón derecho del ratón, entra en la página de propiedades. Busca «Encabezados precompilados» y establece la opción «No utilizar encabezados precompilados». Puedes eliminar los archivos creados con el proyecto, no van a utilizarse.

▸	En la biblioteca de clases, en las propiedades, «Directorios de VC++», «Directorios de inclusión públicos», establece el directorio del proyecto. De esta forma, el proyecto de consola podrá usar los encabezados (.h) de la biblioteca de clases.

En la biblioteca de clases, debes programar la jerarquía de estas. Diseña unas clases que sirvan de modelo para algún diseño que imagines y que no sea artificial (no uses clases llamadas A, A1, A2…). Debes incluir una clase base y dos o tres clases derivadas.

Agrega al menos un método virtual a la clase base de la jerarquía y define los métodos que lo sustituyen (con override) en las clases derivadas. Cada método, incluido el de la clase base, debe producir un resultado distinto.

Agrega otra clase a la biblioteca, llamada Tratamiento. Debe tener un método que toma como parámetro un puntero a la clase base y escribe en la salida estándar (la consola) el resultado de la llamada al método virtual. La intención de esta clase es demostrar que pueden utilizarse las clases derivadas, aunque aún no estén programadas. En este caso, el tratamiento consiste en unas pocas líneas de código. En un caso realista, el tratamiento consistiría en cientos de clases con miles de líneas de código.

En la función main, solo es necesario crear una instancia de una de las clases derivadas, para lo que debes usar un puntero. Hay que crear una instancia de la clase Tratamiento y realizar una llamada a su método (a no ser que el método sea estático, lo que evita tener que crear la instancia). El resultado de la ejecución dependerá de la clase derivada que se use. 
Estas son unas normas generales para la programación:

▸	Incluye las clases en el espacio de nombres poo.
▸	Pon cada clase definida en un archivo de cabecera (.h) y en un archivo fuente (.cpp). Usa el nombre de la clase para el nombre del archivo.
▸	En cada fuente, debes incluir su archivo de cabecera y los archivos de cabecera de las clases que use.
▸	No incluyas un archivo de cabecera en otro archivo de cabecera. Los errores que aparecen se solucionan con inclusiones en los archivos fuente.
▸	No olvides poner public: en las clases antes de las declaraciones. 
▸	Incluye todos los archivos de cabecera de la biblioteca en el archivo fuente de la función main.

Una vez que el proyecto se compila y se ejecuta correctamente, debes ampliar la jerarquía de clases con una clase derivada más. Sin embargo, no debes agregar esta nueva clase derivada al proyecto de la biblioteca de clases, sino que debes agregarla al proyecto de consola. La intención de la actividad es demostrar que la jerarquía de clases original y la programación que la usa, el tratamiento, no necesitan ser modificados para continuar funcionando con las clases que se agregan a la jerarquía a posteriori.

Una vez agregada dicha clase, cambia la función main para que la use y podrás comprobar que el programa sigue funcionando correctamente y que, además, la biblioteca de clases no necesita ser compilada de nuevo para funcionar con la nueva clase derivada.

Por último, describe brevemente en un documento cuál es tu diseño, cuáles son los nombres de las clases y su jerarquía, cuáles son los nombres de los archivos de cada proyecto y cómo has comprobado que la biblioteca de clases no necesita ser recompilada tras la ampliación. Explica los conceptos teóricos de la programación orientada a objetos (POO) aplicados en esta actividad.
