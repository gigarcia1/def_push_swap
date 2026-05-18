# Push_swap

## Objetivo:
Ordenar una pila de números enteros con un conjunto limitado de instrucciones y utilizando el menor número posible de movimientos. Tenemos dos pilas: **Stack A** (con números desordenados) y **Stack B** (vacío). El objetivo es pasar todos los números al Stack A y que queden ordenados de forma ascendente.

### Reglas:
- No se permiten números duplicados.
- Solo se pueden usar las instrucciones oficiales (movimientos disponibles).
- El programa debe imprimir la lista de instrucciones final.

---

## Instrucciones Disponibles

| Movimiento | Acción |
| :--- | :--- |
| **`sa` / `sb` / `ss`** | **Swap**: Intercambia los dos primeros elementos del stack. |
| **`pa` / `pb`** | **Push**: Pasa el primer elemento de un stack al otro stack. |
| **`ra` / `rb` / `rr`** | **Rotate**: Desplaza hacia arriba (el primero pasa a ser el último). |
| **`rra` / `rrb` / `rrr`** | **Reverse Rotate**: Desplaza hacia abajo (el último pasa a ser el primero). |

<img width="2776" height="1520" alt="fundamentalPushSwapOperations" src="https://github.com/user-attachments/assets/27a9bafc-10d6-4eb2-a842-5f984dcf0643" />


## Gestión de flags

El programa soporta los siguientes parámetros para ajustar su comportamiento:

| Flag | Acción |
| :--- | :--- |
| `--simple` | Fuerza el uso del algoritmo de clase O(n²) (listas pequeñas). |
| `--medium` | Fuerza el uso del algoritmo de clase O(n√n) (listas medianas). |
| `--complex` | Fuerza el uso del algoritmo de clase O(n log n) (máxima eficiencia). |
| `--adaptive` | Fuerza el uso del algoritmo adaptativo basado en el desorden (comportamiento por defecto si no se da ningún selector). |
| `--bench` | Modo opcional. Muestra el total de movimientos realizados y métricas detalladas después de ordenar. |

**Nota sobre `--bench`**: La salida del benchmark debe enviarse a `stderr` y **solo aparecer cuando el flag está presente**. Imprime el desorden calculado en porcentaje, el nombre de la estrategia y su clase de complejidad, el número total de operaciones y el recuento de cada tipo de operación.


---

## Input y Output Esperado

El programa recibe como argumento principal el Stack A, formateado como una lista de números enteros, donde el primer valor que se introduce representa la parte superior de la pila. Adicionalmente, puede recibir los flags opcionales descritos anteriormente.

El output debe ser **estrictamente** la lista más pequeña posible de operaciones necesarias para ordenar los números del stack A de menor a mayor. Cada instrucción debe imprimirse en la salida estándar (`stdout`), separada únicamente por un salto de línea (`\n`), sin espacios ni caracteres extra.

### Ejemplo de Ejecución

**Input en la terminal:**
```bash
$> ./push_swap 2 1 3 6 5 8
```
**Output en la terminal:**
```bash
ra
pb
rra
pb
pb
ra
pb
ra
pb
pb
pa
pa
pa
pa
pa
pa
```
---
## Herramientas Externas
* **Visualizador:** [Push_swap Visualizer](https://codepen.io/ahkoh/full/bGWxmVz) para debugear la lógica de quien desarrolle los algoritmos.
* **Checker:** Validación oficial de la ordenación final, disponible en la intra. Como BONUS, se ha de desarrollar un checker propio.
