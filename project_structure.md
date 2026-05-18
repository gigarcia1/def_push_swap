# Estructura del Proyecto Push_swap

## División por Módulos

###  Módulo 0: Compilación y Makefile
* **Makefile**: Elaboración de Makefile usando las reglas y flags necesarios para la compilación evitando relinks innecesarios. AGREGAR REGLAS PARA EL BONUS.
  
###  Módulo 1: Infraestructura y Control
* **Parsing y validación:** Gestión de los argumentos de entrada. Hay que verificar que sean números enteros válidos, que estén dentro del rango de un `int` y que no haya duplicados.
* **Gestión de Flags:** Detectar y configurar el programa si el primer argumento es un selector de estrategia: `--simple`, `--medium`, `--complex` o `--adaptive`.
* **Estructura de Datos:** Implementación de los stacks `a` y `b`. Usaremos listas doblemente enlazadas.
* **Limpieza (Memory Management):** Gestión de memoria y liberación de recursos (`free`) en cada salida o error para evitar leaks.

###  Módulo 2: Instrucciones y Benchmark
* **Movimientos:** Implementación operaciones permitidas (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).
* **Salida Estándar:** Asegurar que cada instrucción ejecutada se imprima en `stdout`.
* **Uso de `--bench`:** Si este flag está activo, las operaciones NO se imprimen en `stdout`. En su lugar, al finalizar, se debe imprimir en `stderr`: el % de desorden, la estrategia usada, la clase de complejidad, el total de movimientos y el recuento específico de cada tipo de movimiento.

###  Módulo 3: Algoritmos y Desorden
* **Cálculo de Desorden (Disorder Metric):** Implementación de la función para calcular el nivel de desorden en el input. Devuelve `0` si está ordenado, o `1` si está totalmente desordenado.
* **Algoritmo Simple:** Complejidad $O(n^{2})$. Diseñado para listas muy pequeñas (ej. insertion sort o min/max).
* **Algoritmo Medio:** Complejidad $O(n\sqrt{n})$. Diseñado para listas medianas (ej. chunks o sort por bloques).
* **Algoritmo Complejo:** Complejidad $O(n.logn)$. Implementación de alta eficiencia (ej. Radix Sort, Quick Sort o Turk Algorithm) para reducir al máximo los movimientos en listas de 500+ elementos.
* **Algoritmo Adaptativo (Default):** Evalúa el desorden inicial del stack y ejecuta automáticamente el algoritmo Simple, Medio o Complejo según los márgenes definidos.

###  Módulo 4: Optimización y Cálculos
* **Cálculo de Costes:** Funciones matemáticas auxiliares para pre-calcular la posición óptima y la cantidad de movimientos (coste) necesarios antes de ejecutar un `push` entre stacks. //OPCIONAL, PENDIENTE DE DISCUTIR
* **Chequeo de Movimientos:** Asegurar que no se realizan movimientos redundantes (ej. hacer un `ra` seguido de un `rra` inútilmente).


### Módulo 5: BONUS - Checker
* **Lectura Continua:** El programa leerá las instrucciones desde la entrada estándar (`stdin`) hasta que no haya más, esperando un `\n` tras cada una.
* **Ejecución Virtual:** Aplicará esas instrucciones sobre la lista de números recibida como argumento.
* **Validación de Resultados:** * Si al terminar, el stack `a` está ordenado y el stack `b` está vacío, imprimirá `OK\n` en `stdout`.
  * En cualquier otro caso, imprimirá `KO\n` en `stdout`.
* **Gestión de Errores Bonus:** Imprimir `Error\n` en `stderr` si hay instrucciones que no existen, mal formateadas o errores en los argumentos de entrada.
* **Compilación Bonus:** Crear una regla `bonus` en el Makefile para generar el ejecutable `checker`.

```
.
├── Makefile                # Módulo 0: Reglas all, clean, fclean, re y bonus
├── include/                # Archivos .h
│   ├── push_swap.h         # Prototipos generales y estructuras de datos
│   ├── instructions.h      # Definiciones de movimientos
│   └── algorithms.h        # Prototipos de los diferentes algoritmos
├── src/                    # Archivos .c organizados por módulos
│   ├── main.c              # Punto de entrada y lógica del Módulo 1 (Adaptive)
│   ├── setup/              # Módulo 1: Infraestructura
│   │   ├── parsing.c       # Validación de int y duplicados
│   │   ├── flags.c         # Lógica de selectores (--simple, --bench, etc.)
│   │   ├── stack_utils.c   # Inicialización de listas doblemente enlazadas
│   │   └── memory.c        # Funciones de liberación (free) y gestión de errores
│   ├── operations/         # Módulo 2: Instrucciones
│   │   ├── push.c          # pa, pb
│   │   ├── swap.c          # sa, sb, ss
│   │   ├── rotate.c        # ra, rb, rr
│   │   ├── rev_rotate.c    # rra, rrb, rrr
│   │   └── output.c        # Gestión de impresión en stdout vs silent (--bench)
│   ├── algorithms/         # Módulo 3 y 4: Lógica de ordenación
│   │   ├── metrics.c       # Cálculo de Disorder Metric
│   │   ├── algo_simple.c   # O(n²) para pocos elementos
│   │   ├── algo_medium.c   # O(n root 2) - Chunks / Bloques
│   │   ├── algo_complex.c  # O(n log n) - Radix o Turk Algorithm
│   │   └── costs.c         # Cálculo de costes y optimización de movimientos
├── bonus/                  # Módulo 5: Checker
│   ├── checker_main.c      # Main del programa bonus
│   └── checker_utils.c     # Lectura de stdin y validación final
├── libft/                  # Tu librería de funciones auxiliares (si la usas)
└── obj/                    # Archivos objeto (.o) generados (creada por Makefile)
