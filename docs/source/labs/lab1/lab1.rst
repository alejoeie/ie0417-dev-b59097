*************
Laboratorio 1
*************
Planeamiento
------------
Desde una perspectiva general, se debe tener claro el objetivo
general del proyecto, el cual se encarga de visualizar la gran
imagen, es decir, el resultado esperado dentro de todos los 
lineamientos de trabajo. 
 
A modo de mención, se tiene que el objetivo del proyecto es:
"Diseñar el software de un administrador de dispositivos
interconectados en la red de una fábrica y documentarlo." 
Es claro que este enunciado debe ser descompuesto en partes
singulares que cumplan los diferentes objetivos que se generan
a partir del objetivo general. Es necesario plantear estos 
objetivos singulares para desintegrar en partes sencillas
y específicas, las necesidades dentro del desarrollo. 

Se plantean objetivos específicos respecto al desarrollo de una 
App con GUI integrada. Se debe pensar primeramente en que se debe
exponer una API que permita la transmisión de datos desde el 
administrador hacia el cliente. Desde esta perspectiva es necesario 
hacer hincapié en que un equipo remoto ajeno a nuestro grupo de desarrollo
puede programar en cualquier lenguaje el display y layout de la interfaz en la
aplicación. Entonces se debe construir una API robusta capaz de ser llamada desde 
cualquier instancia o template de cualquier tipo de código, no sin antes realizar
una investigación de los protocolos de comunicación (los cuales darán servicio a ``eieManager``) más seguros y eficientes.

Entonces, como primeros objetivos específicos se puede mencionar:

* Investigar los protocolos de comunicación que asegurarán la calidad de comunicación entre ``eieManager`` y el cliente. 

* Identificar el framework de desarrollo de la API más adecuado para brindar servicio a un cliente en cualquier lenguaje de programación.

* Definir un ambiente de desarrollo que permita mapear el avance en los códigos para la API a través del control de versiones.

* Desarrollar la API desde la cual se hará efectiva la transmisión de datos entre el software administrador y el cliente.

Se tienen en cuenta objetivos un poco más singulares y simplistas con base en el anterior argumento, sin embargo,
se debe apuntar a un mapa de trabajo que facilite el desarrollo de los entregables. 

De esta manera, se plantean los posibles entregables que pueden estructurar el cumplimiento de cada uno de los objetivos específicos 
anteriormente mencionados: 

* Para el desarrollo de la API desde la cual se hará efectiva la transmisión de datos:

 * Identificar el gestor de bases de datos más apropiado para el almacenamiento de datos dentro de la plataforma. 
 
 * Determinar el gestor de dominio y deployment de la base de datos en el servidor, para asegurar las conexiones desde el ``Client``.

 * Definir el modelo de cliente-servidor, estructurado mediante una comunicación RPC (Remote Procedure Call) de una manera similar a la siguiente
  (el modelo pude ser sometido a cambios a medida que se avanza en los entregables):
  
  .. image:: img/rpc.png
   :align: center
