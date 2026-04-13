/* tests/test_parsing.c */

#include <stdio.h>
#include <assert.h>
#include "../include/push_swap.h" 

void run_test(char *test_name, int argc, char **argv, int expected_result)
{
    printf("Test: %-35s -> ", test_name);
    
    int result = check_args(argc, argv); 
    
    if (result == expected_result)
        printf("\033[0;32m[OK]\033[0m\n");
    else
        printf("\033[0;31m[KO] Esperaba %d, obtuve %d\033[0m\n", expected_result, result);
}

int main(void)
{
    printf("=== INICIANDO TESTS DE PARSING (V2.0) ===\n\n");

    /* 1. TESTS DE CONTEO EXACTO (N) */
    printf("--- TESTS DE CONTEO (N) ---\n");
    char *args1[] = {"./push_swap", "1", "2", "3", "-4", "5"};
    run_test("Numeros simples", 6, args1, 5); // Esperamos 5 numeros

    char *args2[] = {"./push_swap", "123", "12", "4", "58 34 22 6", "75"};
    run_test("String con multiples nums", 6, args2, 8); // Esperamos 8 numeros en total

    char *args3[] = {"./push_swap", "123", "      4727 77899 23424534   "};
    run_test("String espacios extremos", 3, args3, 4); // Esperamos 4 numeros


    /* 2. TESTS DE ARGUMENTOS VACIOS (Deben retornar 0) */
    printf("\n--- TESTS FANTASMA (Retorno 0) ---\n");
    char *args4[] = {"./push_swap"};
    run_test("Sin argumentos", 1, args4, 0);

    char *args5[] = {"./push_swap", ""};
    run_test("Argumento vacio (comillas)", 2, args5, 0);

    char *args6[] = {"./push_swap", "     ", "  "};
    run_test("Solo espacios", 3, args6, 0);


    /* 3. TESTS DE ERRORES CLASICOS (Deben retornar -1) */
    printf("\n--- TESTS ERRORES CLASICOS (Retorno -1) ---\n");
    char *args7[] = {"./push_swap", "1", "dos", "3"};
    run_test("Caracteres invalidos", 4, args7, -1);

    char *args8[] = {"./push_swap", "1", "2147483648", "3"};
    run_test("Integer Overflow (Clasico)", 4, args8, -1);

    char *args9[] = {"./push_swap", "1", "2", "3", "2"};
    run_test("Numeros duplicados", 5, args9, -1);

    char *args10[] = {"./push_swap", "1", " 2 a 3 "};
    run_test("Letra escondida", 3, args10, -1);

    char *args11[] = {"./push_swap", "++5"};
    run_test("Doble signo (++5)", 2, args11, -1);

    char *args12[] = {"./push_swap", "5-"};
    run_test("Signo al final (5-)", 2, args12, -1);


    /* 4. LA PRUEBA DE FUEGO: SUPER OVERFLOW & CEROS TRAMPOSOS */
    printf("\n--- TESTS SUPER OVERFLOW Y CEROS ---\n");
    
    char *args13[] = {"./push_swap", "9999999999999999999999999999"};
    run_test("Super Overflow (28 digitos)", 2, args13, -1);

    char *args14[] = {"./push_swap", "000000000000000000000000042"};
    run_test("Ceros inofensivos (000...42)", 2, args14, 1); // 42 es valido, retorna 1

    char *args15[] = {"./push_swap", "-00000000000000000000000000"};
    run_test("Cero negativo largo (-000...0)", 2, args15, 1); // El 0 es valido, retorna 1

    char *args16[] = {"./push_swap", "1", "00000000002147483648", "3"};
    run_test("Ceros + Overflow oculto", 4, args16, -1); // 2147483648 peta en atol

    printf("\n=== TESTS FINALIZADOS ===\n");
    return (0);
}