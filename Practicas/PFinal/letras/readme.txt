Curso: 2018/2019
Asignatura: Estructura de datos
Autores: Jose Antonio Padial Molina
		 Elena Ortiz Moreno
Practica: Final "Letras"


*************************Modulo diccionario*************************
Hemos creado el TDA Diccionario. Donde en la parte privada solo tenemos un set<string> datos. Donde vamos a almacenar las palabras del diccionario.
Y en la parte publica hemos crado los funciones necesarias para manejar ese set y las necesidades para usar el TDA de Diccionario. Para poder usar
las funciones del set se han llamado en el TDA de Diccionario las funciones igual que en el set. En su interior hacemos uso del set. A parte de estas 
funciones para majer el set hemos creado las siguientes funciones adicionales:
		* Busca todas las palabras de una cierta longitud.
		* Busca las palabras que contengan una cierta cadena como pude ser un prefijo.
		* Busca las veces que aparece una determinado char en el diccionario.
		* Cuenta de cunatos char esta compuesto el diccioario.

Cuando hacemos queremos iterar sobre nuestro TDA Diccionario no se pude hacer directamente. Por eso nos hemos creado dos clases una para los
iteradores y otra para los iteradores constantes. Las cuales van a tener las mismas sobrecargas de operadores. Donde hemos sobrecargado todos los
operadore posibles.


*************************Modulo conjunto de letras*************************
El TDA de Conjunto de letras es muy parecido al TDA de Diccionario, con la diferencia de que no tenemos la funciones mencionadas para manejar
los diccionarios. Y las vasriables donde teniamos un string ahora tenemos una variable de tipo Letra.


*************************Modulo letra*************************
Este modulo lo hemos implementado en el mismo fichero que el Modulo conjunto de letras. Es simplemente un struct donde vamos a almacenar los datos necesarios
para una letra. Donde van a ser su caracter, las veces que se repiten y la puntuacion que posee esa letra.


*************************Modulo Bolsa de letras*************************
Es un TDA donde almacenan todas letras a ser utilizadas con las veces que esa letra se repiten.


*************************Test diccionario*************************
Simplemente es un main donde se carga el diccionario, lo muestra y cre un subconjunto de palabras de un determinado tamaño introducido por el usuario.
Tras esto pide una plabara y dice si esta en el diccionario o no.


*************************Cantidad de letras*************************
Es un main donde se carga el diccionario y el txt con las letras. Crea un fichero donde se va a escribir las veces que aparecen las letras del txt en el
diccionario y la frecuencia de cada una.


*************************Letras*************************
Este es el programa con el cual vamos a poder juagar con la practica que hemos desarrollado. Donde se carga el diccionario, el txt con las letras y se genera 
la bolsa con las letras. Tenemos dos formas de jugar una por puntos y otra por longitud. Si elegimos por puntos primero antes de jugar va a listar todas las
letras del txt con su respectiva puntuacion. Una vez que se inicia el juego se muestran tantas letras como se haya indicado a la hora de ejecutar.
Pide al usuario una solucion mietras no introduzca letras que no esten en la lista o ponga mas letras de lo permitido. En el caso de poner una palabra que no 
este en el diccionario le indica que esa palabra no existe. Tras esto muestra las mejores resultados. Y nos da la opcion de volver a jugar o no.


*************************Observaciones*************************
No ha nada que comentar sobre la practica. Han sido probados todos los ejecutables varias veces y han terminado con exito.