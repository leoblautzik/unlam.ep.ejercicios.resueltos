---
title:
- EJERCICIO 10.5

classoption: "aspectratio=169"
theme:
    - metropolis 
titlegraphics:  
                
 
date: junio de 2021

---

# Consigna

Se dispone de un archivo llamado Stock.dat que contiene la información de
los 10 productos que vende una fábrica. En el archivo se guarda:

* Código de artículo (entero)
* Descripción (50 caracteres máximo)
* Stock (entero)

Luego se ingresan por teclado las ventas a realizar indicando:

* Código de artículo
* Cantidad

--- 

# Consigna

La carga por teclado de las ventas finaliza con un código de artículo igual a 0.
Por cada venta se debe controlar si hay stock suficiente y si lo hay, restar
el stock de dicho producto, sino hay stock se debe vender lo que quede
disponible y grabar un registro en un archivo Faltantes.dat con la
cantidad que no pudo venderse, dicho registro debe contener:

* Código de artículo
* Cantidad

---

# Análisis

Cada registro del archivo Stock.dat contiene información del estado de un artículo. 

1. Cómo son solo 10 artículos y conozco esa cantidad, se lee el archivo y cada 
registro se pasa a una de las posiciones de un vector de sProducto. 

2. Se actualiza el vector de productos (su stock) a partir de la carga 
manual de las ventas. De acuerdo con la consigna se crea y actualiza el 
archivo faltantes.dat. 

3. Se actualiza el archivo Stock.dat con los stocks resultantes. 

4. Se muestran los resultados por pantalla. 
