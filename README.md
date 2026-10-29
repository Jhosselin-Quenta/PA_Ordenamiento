
# Evaluación de Producto - Programación Avanzada I

## Objetivo

Comparar Shell Sort y Quick Sort mediante experimentos en C++, evaluando el tiempo de ejecución y otras métricas.

## Algoritmos

- **Shell Sort:** ordenamiento por incrementos que se reducen progresivamente.
- **Quick Sort:** ordenamiento por partición alrededor de un pivote.

## Estructura del proyecto

- `src/`: códigos fuente en C++.
- `results/comparacion.csv`: mediciones de los experimentos.
- `results/promedios.csv`: tiempos promedio por algoritmo, tamaño y patrón.
- `results/estadisticas.csv`: estadísticas de las mediciones.
- `docs/articulo.tex`: artículo científico en LaTeX.
- `docs/articulo.pdf`: artículo compilado.

## Metodología

Se probaron tamaños de 1 000, 10 000 y 100 000 elementos, con entradas aleatorias, ascendentes y descendentes. Se realizaron 30 mediciones por cada combinación de tamaño y patrón.

Se registraron el tiempo de ejecución, las comparaciones, los intercambios y la profundidad de recursión de Quick Sort. Se utilizó la semilla 12345 para generar las entradas aleatorias.

## Entorno de ejecución

- Lenguaje: C++.
- Compilador: G++ 15.2.0.
- Entorno: MSYS2 UCRT64 en Windows.
- Los tiempos pueden variar según el equipo y las condiciones de ejecución.

## Compilación y ejecución

Desde la carpeta raíz del proyecto:

```bash
g++ -std=c++17 src/comparar.cpp -o comparar.exe
./comparar.exe
```

El programa genera `results/comparacion.csv`. Los promedios se encuentran en `results/promedios.csv`.

Para compilar otros programas, utiliza el archivo correspondiente de la carpeta `src/`.

## Documentación

El artículo completo está disponible en `docs/articulo.pdf`, junto con su fuente `docs/articulo.tex`.
