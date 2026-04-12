# 🧠 PUSH_SWAP — AI ANALYSIS & GENERATION PROMPT

## 📌 CONTEXTO GENERAL

Proyecto de ordenación usando:

* **2 stacks**: `a`, `b`
* **Operaciones limitadas**
* Objetivo: **minimizar número de operaciones**

### 🎯 OBJETIVO PRINCIPAL

Generar la **secuencia óptima de instrucciones** para ordenar `stack a` en orden ascendente usando:

* **Coste medido en operaciones push_swap**
* **Optimización algorítmica basada en input**

---

## ⚙️ PARÁMETROS OBLIGATORIOS (MANDATORY)

### 🧩 INPUT

* Lista de enteros (`stack a`)
* Sin duplicados
* Puede incluir negativos
* `stack b` inicia vacío

---

### 🔄 OPERACIONES PERMITIDAS (KEYWORDS)

```
sa sb ss
pa pb
ra rb rr
rra rrb rrr
```

👉 IA debe:

* Generar **solo estas instrucciones**
* Salida separada por `\n`
* Minimizar el total de operaciones

---

### 📊 MÉTRICA CRÍTICA: DISORDER

```
disorder ∈ [0,1]
```

#### Fórmula conceptual:

* Conteo de pares desordenados
* Normalización sobre total de pares

#### IMPORTANCIA:

* Determina estrategia adaptativa
* Debe calcularse **antes de operar**

---

### 🧠 ESTRATEGIAS OBLIGATORIAS

#### 1. SIMPLE — O(n²)

**Keywords:**

* insertion sort adaptation
* selection sort
* bubble sort
* min/max extraction

👉 Uso:

* Inputs pequeños o fallback

---

#### 2. MEDIUM — O(n√n)

**Keywords:**

* chunk sorting
* bucket strategy
* block partitioning
* range splitting

👉 Idea clave:

* Dividir en √n bloques

---

#### 3. COMPLEX — O(n log n)

**Keywords:**

* radix sort (LSD/MSD)
* quicksort (stack-based)
* mergesort (2 stacks)
* heap-based approach

👉 Recomendado para:

* Inputs grandes
* Alto desorden

---

#### 4. ADAPTIVE — MULTI-STRATEGY ⚡

**Dependiente de disorder:**

| Rango disorder | Complejidad | Estrategia         |
| -------------- | ----------- | ------------------ |
| < 0.2          | O(n)        | optimización local |
| 0.2–0.5        | O(n√n)      | chunk/bucket       |
| ≥ 0.5          | O(n log n)  | radix/quicksort    |

**Keywords clave:**

* adaptive selection
* hybrid algorithm
* dynamic strategy switch

---

### 📉 MODELO DE COMPLEJIDAD

⚠️ IMPORTANTE:

* Se mide en **número de operaciones push_swap**
* NO complejidad teórica clásica

---

### 🧾 OUTPUT REQUISITOS

* Secuencia mínima de operaciones
* Sin texto adicional
* Manejo de errores → `"Error\n"`

---

### 🚫 ERRORES A CONTROLAR

* No enteros
* Duplicados
* Overflow
* Input vacío

---

### 🏁 BENCHMARK (CRÍTICO)

#### Para 100 números:

* < 2000 → PASS
* < 1500 → GOOD
* < 700 → EXCELLENT

#### Para 500 números:

* < 12000 → PASS
* < 8000 → GOOD
* < 5500 → EXCELLENT

---

### 🔍 MODO BENCH (--bench)

Debe mostrar:

* disorder (%)
* estrategia usada
* complejidad
* total operaciones
* conteo por operación

---

## 🧠 DISEÑO DE IA (FOCO DEL PROMPT)

### 🔑 OBJETIVOS DE LA IA

* Analizar input
* Calcular disorder
* Seleccionar estrategia óptima
* Generar secuencia mínima

---

### 🧠 CAPACIDADES ESPERADAS

* Pattern recognition (orden parcial)
* Optimization heuristics
* Cost evaluation
* Stack simulation

---

### 🧩 ESTRUCTURA IDEAL

1. Parsing input
2. Validación
3. Cálculo disorder
4. Selección estrategia
5. Generación operaciones
6. Optimización final

---

## 🎁 BONUS — CHECKER

### 📌 OBJETIVO

Validar operaciones generadas

### INPUT:

* stack inicial
* operaciones desde stdin

### OUTPUT:

* `OK` → si ordenado correctamente
* `KO` → si falla
* `Error` → input inválido

---

## 🧠 KEYWORDS PARA PROMPT (HIGH PRIORITY)

```
push_swap
stack sorting
operation minimization
adaptive algorithm
disorder metric
two-stack system
algorithm complexity
O(n log n) optimization
chunk sorting
radix sort
instruction sequence generation
performance benchmark
operation cost model
```

---

## ⚡ META-PROMPT SUGERIDO

"Design an optimized push_swap solution that:

* Computes disorder
* Selects best algorithm dynamically
* Minimizes operation count
* Uses only allowed stack operations
* Adapts to input size and structure"

---

## 🚀 ENFOQUE DE OPTIMIZACIÓN

* Minimizar `pb/pa` innecesarios
* Agrupar rotaciones (`rr`, `rrr`)
* Reducir movimientos redundantes
* Priorizar estabilidad en chunks

---

## 🧩 NOTAS FINALES

* El éxito depende de:

  * Elección correcta de estrategia
  * Optimización de operaciones
  * Adaptabilidad al input

* Este proyecto evalúa:

  * **pensamiento algorítmico**
  * **optimización real**
  * **capacidad de análisis dinámico**

---
