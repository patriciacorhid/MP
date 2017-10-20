# MP

### Metodología de la Programación - 1er curso

#### Práctica final de la asignatura:

Incluye 4 programas para probar el código realizado durante la práctica final
de la asignatura, que realicé junto a mi compañero [@dcabezas98](https://github.com/dcabezas98).

###### testarteASCII:

Lee una imagen, un archivo con caracteres ordenados formando escalas de
grises y el nombre de un archivo de salida, en el que dibuja la imagen
usando los caracteres de cada escala. Deben introducirse en la línea de
comandos.

###### testplano:

Extrae los planos de bits de una imagen y los guarda en los archivos
indicados. Requiere modificar el main para cambiar la imagen o los planos.

###### testimagen:

Crea una imagen degradada, hace un recorte de la imagen introducida y los
guarda en los archivos especificados. Requiere modificar el main.

###### testMorphing:

Lee dos imágenes (que deben tener las mismas dimensiones), un entero *n* y un
nombre de salida. Y transforma la primera imagen en la segunda en *n* pasos
y va guardando cada imagen intermedia *k* con el nombre `salidak.pgm`.
Los archivos son leídos directamente de la línea de parámetros.

##### Formato de las imágenes:
El tipo de las imágenes (texto o binario) se detecta antes de leerlas. Para la
escritura, se puede elegir entre texto o binario modificando en el main la 
llamada a la función `escribirImagen(const char nombreFichero[], bool esBinario)`
y cambiando la variable booleana `esBinario` entre **true** y **false**.

##### Objetivos de la práctica:
Esta práctica va dedicada a la familiarización con el uso de **punteros y memoria
dinámica:** constructores vacío y copia, destructor, sobrecarga de operador de asignación, etc.
También he adquirido conocimientos sobre la **gestión de imágenes:** lectura, escritura, extracción de un plano de bits,
dibujo ACII, morphing, etc. Y sobre **Estructuras de Datos dinámicas:** vector dinámica, matriz dinámica y lista de 
celdas enlazadas.
