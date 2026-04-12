# new_push_swap

## Estructura de archivos
push_swap/
├── Makefile             # Reglas obligatorias: all, clean, fclean, re (y bonus si aplica)
├── inc/                 # Directorio exclusivo para cabeceras
│   └── push_swap.h      # Estructuras de datos, prototipos y macros (sin norm errors)
├── libft/               # Tu librería estándar de 42 (fundamental para libft, printf, etc.)
├── src/                 # Código fuente dividido por responsabilidades
│   ├── main.c           # Punto de entrada (mínima lógica, solo llamadas)
│   ├── parsing/         # Módulo 1: Validación y conversión de argumentos
│   │   ├── args_check.c # Validación de caracteres, duplicados y límites de INT
│   │   └── parse.c      # Extracción de strings y conversión a enteros (ft_atoi custom)
│   ├── data_struct/     # Módulo 2: Gestión de la memoria y la estructura
│   │   ├── stack_init.c # Creación de nodos
│   │   └── stack_utils.c# Utilidades (tamaño del stack, encontrar último, liberar memoria)
│   ├── operations/      # Módulo 3: Las instrucciones permitidas (bien separadas por Norma)
│   │   ├── push.c       # pa, pb
│   │   ├── swap.c       # sa, sb, ss
│   │   ├── rotate.c     # ra, rb, rr
│   │   └── rev_rot.c    # rra, rrb, rrr
│   └── algorithm/       # Módulo 4: El cerebro de la IA
│       ├── router.c     # Selecciona la estrategia según el input (el Adaptive Multi-Strategy)
│       ├── metrics.c    # Cálculo del 'disorder' y normalización/indexación (crítico)
│       ├── simple.c     # Hardcoding para 2, 3, 4 y 5 números (O(n²))
│       └── complex.c    # Implementación de Radix / K-Sort o Chunking (O(n log n))
└── tests/               # Nuestro laboratorio de pruebas aisaldo
    ├── unit_tests/      # Programas en C para testear funciones individuales (ej. testear parsing)
    └── e2e_tests/       # Scripts en bash para probar el programa completo
        ├── err_test.sh  # Fuerza errores (letras, INT_MAX, duplicados) para verificar "Error\n"
        └── bench.sh     # Ejecuta pruebas con 100 y 500 números midiendo las operaciones