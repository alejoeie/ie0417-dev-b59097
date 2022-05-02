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

* Investigar los protocolos de comunicación que asegurarán la calidad de comunicación entre ``eieManager`` y ``Client``:
 
 * Comparación entre los métodos MQTT, CoAP y HTTP, los cuales son más comúnmente asociados a los protocolos con dispositivos IoT integrados.
 
 * Considerar la utilización del lenguaje para el desarrollo de ``Client``, el cual puede afinar la elección de los protocolos de comunicación.
 
* Identificar el framework de desarrollo de la API más adecuado para brindar servicio a un cliente en cualquier lenguaje de programación.
 
 * Especificar la elección del tipo de base de datos, relacional o no relacional, según el almacenamiento de datos.
 
 * Identificar el manejo de múltiples APIs como por ejemplo ThinkSpeak API, que involucra ya funciones para dispositivos interconectados.
 
 * Elegir el gestor de contenedores más apropiado para generar un contenedor con todas las dependencias de la API para que no existan conflictos en los
   llamados a funciones dentro del gestor de la API.
 
* Definir un ambiente de desarrollo que permita mapear el avance en los códigos para la API a través del control de versiones.
 
 * Identificar las comparativas entre Github y GitLab para elegir el gestor de repositorios de la empresa desarrolladora. 
   De esta manera, y bajo el estándar de código abierto y licencias open source, que el código base sea liberado a los desarrolladores de ``Client`` para    efectos de conocimiento de los parámetros del mismo.
 
* Para el desarrollo de la API desde la cual se hará efectiva la transmisión de datos:

 * Identificar el gestor de bases de datos más apropiado para el almacenamiento de datos dentro de la plataforma. 
 
 * Determinar el gestor de dominio y deployment de la base de datos en el servidor, para asegurar las conexiones desde el ``Client``.

 * Definir el modelo de cliente-servidor, estructurado mediante una comunicación RPC (Remote Procedure Call) 
   de una manera similar a la siguiente (el modelo pude ser sometido a cambios a medida que se avanza en los entregables):
  
  .. image:: img/rpc.png
   :align: center
 
Requerimientos
--------------

 * Requerimientos funcionales:
 
  * ``FUNREQ-A``: Proveer la seguridad en las conexiones dentro del sistema.
  
  * ``FUNREQ-B``: Generar una respuesta a consultas desde third-party apps (``Client``).
  
  * ``FUNREQ-C``: Proveer compatibilidad de hardware y software entre los dispositivos interconectados.
  
  * ``FUNREQ-D``: Habilitar una API dinámica con una amplia gestión de comandos que permita el ingreso
    de nuevas funcionalidades dentro de los dispositivos interconectados.
    
  * ``FUNREQ-E``: Proveer un sistema de comunicación eficiente en su ancho de banda para habilitar las conexiones
    múltiples entre los dispositivos.
    
  * ``FUNREQ-F``: Brindar un sistema de alarmas que interrumpa operaciones dentro de ``eieManager``, para 
    asegurar el rendimiento del servidor. 
 
* Requerimientos no funcionales:
 
 * ``NFUNREQ-A``: Si existe un daño en el sistema como vulneración de información, interrupciones espontáneas de corriente
   o daño catastrófico, generar un sistema de recuperación de información que resguarde y encripte la información transmitida
   y se almacene como copia de seguridad dentro de la base de datos que se puede considerar almacenamiento de archivo. A la vez
   que se reconstruye el estado actual de la información dentro de ``eieManager`` para facilitar las transacciones desde la
   última consulta, hasta el momento de la falla, de tal forma que el administrador no se vea desprotegido ni anulado toda
   la información.
   
 * ``NFUNREQ-B``: Se debe asegurar la calidad de la protección de la información en una base de datos, cuyo proveedor del 
   servicio sea elegido con un previo análisis de equipo y comparación entre diferentes opciones disponibles.
  
 * `Atributos de seguridad de software:
  
  * Disponibilidad:
   
   * ``NFUNREQ-C``: Como se está almacenando toda la información de dispositivos en un servidor, éste
     debe asegurar la conexión y disponibilidad todo el tiempo durante el servicio.
  
  * Confiabilidad:
   
   * ``NFUNREQ-D``: Asegurar la protección de información a través de la encriptación de IPs e 
     información sensible de los dispositivos a través de métodos SHA, por ejemplo.
   
   * ``NFUNREQ-E``: Generar copias de seguridad en caso de una interrupción en la comunicación
     de un n-dispositivo.
    
  * Mantenibilidad:
  
   * ``NFUNREQ-F``: Designar personal encargado de verificar el rendimiento del sistema y generar
     un sistema de calendarios para asegurar la continuidad en la verificación.
     
   * ``NFUNREQ-G``: Atribuir responsabilidades para que exista un grupo de desarrolladores que 
     diseñen y estructuren software con actualizaciones con respecto a las librerías y dependencias
     utilizadas en el código primario.
    
   * ``NFUNREQ-H``: Optimizar el rendimiento de la API a través de parches con actualizaciones de 
     software para asegurar el up-to-date de las funciones en la gestión.
   
  * Portabilidad:
  
   * ``NFUNREQ-I``: Uso de Python para la gestión de los protocolos de entrada y salida de comandos.
   
   * ``NFUNREQ-J``: Uso de Java para la generación del código de protocolos de comunicación.
   
   * ``NFUNREQ-K``: Que todos los dispositivos manejen al menos sistemas basados en UNIX.
   
   * ``NFUNREQ-L``: Utilizar MongoDB para la base de datos y ReactJS para la UX en ``Client``.
   
   * ``NFUNREQ-M``: Utilizar algoritmos de estructuras de datos utilizando STL en C++. 
  
  * Requerimientos de Hardware:
   
   * ``NFUNREQ-N``: Utilizar un Procesador ICX Intel Xeon para el procesamiento de datos en el servidor. 
   
   * ``NFUNREQ-O``: 1 TB de almacenamiento en el servidor. 
   
   * ``NFUNREQ-P``: Memoria RAM tipo ECC para el servidor de 64GB.
   
   * ``NFUNREQ-Q``: 128GB de espacio disponible mínimo para cada dispositivo.

Patrones de Diseño
==================

El patrón de diseño proxy funcionaria perfectamente para solucionar el problema de interacción y comunicación debido a que lo que hace es que se convierte en la interfaz de algo que puede ser costoso de almacenar o algo que no se quiere que se pueda duplicar. De forma que utilizando este patrón se puede dar acceso al protocolo de comunicación que se necesita para que se realice de forma adecuada el intercambio de comunicación, así como también se podría instanciar el mensaje de forma local para que pueda ser utilizado por los distintos componentes. Este patrón se puede relacionar a los siguientes componentes:

* Device.
* Group.
* DeviceManager.
* GroupManager.
* TransportClient.

El patrón de diseño Command lo que hace es encapsular toda la información necesaria para realizar una acción cuando sea requerido.  Entonces con la implementación de este patrón se podría tener toda la información necesaria para ejecutar un comando y cuando cualquier dispositivo especifico requiera ejecutar alguno, lo podrá hacer sin problema debido a que se gracias al patrón se cuenta con todo lo necesario para que lo logre hacer de manera adecuada. También se puede encapsular toda la información posterior a la ejecución de un comando, y para completar el ciclo, se podrá esperar a que se tenga la respuesta y ya esta sea generada, utilizará la capsula generada posteriormente para finalizar.


Diagramas UML
=============

Diagrma de clases de los componentes de eieManager:

.. uml::

  	@startuml
	title Relationships - Class Diagram (eieManager)


	class EieManager 

	class APIServer{
	  +void ClientRequest()
	}
	class CommandRegistry{
	  +void CheckCommand()
	}
	class CommandInvoker{
	  +void RunCommand()
	}
	class GroupManager{
	  +void ManageGroup()
	}
	class ConfigHandler{
	  +void Configuration()
	}
	class DeviceManager{
	  +viod DeviceLifeCycle()
	}
	class TransportClient{
	  +void CommunicationProtocol()
	}
	class DatabaseHandler{
	  +void StoreData()
	}
	class Device
	class Group
	class CommandInfo{
	  +void ExtractCommandInformation()
	}




	EieManager "1" *-down- "1" ConfigHandler: Composition
	ConfigHandler  <.down-  DeviceManager: Use
	ConfigHandler  <.down-  GroupManager: Use
	APIServer "1" *-down- "1" CommandInfo: Composition
	CommandInfo "1" *-down- "1" CommandRegistry: Composition
	APIServer <|-right- TransportClient: Inheritance
	CommandRegistry "1" *-down- "1" CommandInvoker: Composition
	ConfigHandler <.down- DatabaseHandler: Use
	DeviceManager <|-down- Device: Inheritance
	GroupManager <|-down- Group: Inheritance
	TransportClient "1" *-down- "1" EieManager: Composition
	@enduml

Diagrma de clases de los componentes de eieDevice:

.. uml::

	@startuml

	title Relationships - Class Diagram (eieManager)


	class EieDevice 

	class TransportServer{
	  +void SendReply()

	}
	class CommandManager{
	  +void RunCommand()

	}
	class Command{
	  +void ImplementFunctionality()

	}

	EieDevice "1" *-down- "1" CommandManager: Composition
	EieDevice "1" *-down- "1" TransportServer: Composition
	CommandManager <|-down- Command: Inheritance
	@endumlDevic

Diagrama de secuencia (El cliente envía un comando a un dispositivo específico):

.. uml ::
	@startuml
	Client -> APIServer: Send Command

	alt successful case

	   APIServer -> TransportClient: Protocol Request
	   
	   alt successful case

	   TransportClient -> APIServer: Protocol Specification 
	   
	   else some kind of failure

	   TransportClient -> APIServer: Protocol Specification Failure
	    end
	   
	   CommandInfo -> APIServer: Command Information Request

	   alt successful case

	   APIServer -> CommandInfo: Command Information
	   
	   else some kind of failure

	   APIServer -> CommandInfo: Command Information Failure
	   end
	 
	   CommandInfo -> CommandRegistry: Command Verification Request

	   alt successful case

	   CommandRegistry -> CommandInvoker: Valid Command
	   
	   else some kind of failure

	   CommandRegistry -> CommandInfo: Invalid Command
	   end
	   
	   CommandInvoker -> DeviceManager: specifies command and device

	   DeviceManager -> Device: Run Command

	    



	else some kind of failure

	    APIServer -> Client: Please repeat

	end
	@enduml

Diagrama de secuencia (El cliente envía un comando a un grupo de broadcast):

.. uml ::
	@startuml
	Client -> APIServer: Send Command

	alt successful case

	   APIServer -> TransportClient: Protocol Request
	   
	   alt successful case

	   TransportClient -> APIServer: Protocol Specification 
	   
	   else some kind of failure

	   TransportClient -> APIServer: Protocol Specification Failure
	    end
	   
	   CommandInfo -> APIServer: Command Information Request

	   alt successful case

	   APIServer -> CommandInfo: Command Information
	   
	   else some kind of failure

	   APIServer -> CommandInfo: Command Information Failure
	   end
	 
	   CommandInfo -> CommandRegistry: Command Verification Request

	   alt successful case

	   CommandRegistry -> CommandInvoker: Valid Command
	   
	   else some kind of failure

	   CommandRegistry -> CommandInfo: Invalid Command
	   end
	   
	   CommandInvoker -> DeviceGroup: specifies command and device

	   DeviceGroup -> Group: Run Command

	    



	else some kind of failure

	    APIServer -> Client: Please repeat

	end
	@enduml


