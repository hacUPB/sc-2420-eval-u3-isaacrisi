[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/-g_ni1Wx)
# Documentación del Proyecto
## Unidad 3

Estudiante:  Isaac Pineda Múnera
Id:  000509927
---

Pagina del curso 

confusion-snapper-025.notion.site/Sistemas-Computacionales-d1806d0b626347f4aa90a17b56807004?pvs=4

# Documentacion 


Refactorizando el codigo "no" se presentaron muchos problemas pude realizar los cambios es implementar todas las clases sin errores aparantes, por un tiempo tuve un error que no sabia de donde venia y es que no estaba definiendo el constructor de las clases en el main entonces no estaba pudiendo acceder a los datos, una vez lo solucione el resto no estuvo complicado primero cree la clase entidad en esta clase tendria los valores basicos para todo lo que necesitaba, tamaño, velocidad, y posicion de esta calse necesitaba que herdaran personaje, lvl y obstacle, luego hice la clase de personaje que en esta solo debia tener la funcion para que saltara y esta funcion ya la tenia hecha solo tenia que pasarla a la clase y llamarla en el SDL_PollEvent(), y usé la misma logica para para las clases lvl y obstacle, la mayor complicacion es que a pesar de que el codigo no tiene errores sale el siguiente mensaje al intentar correrlo.

![image](https://github.com/user-attachments/assets/62b18f7f-722f-40d5-beb0-e7ad21ceaa3e)

lo que no me permite verificar si el codigo está funcionando bien, supongo que si ya que no hay errores en la compilacion por lo que esta tomando todos los valores que deberia, la unica funcion que no he podido implementar es la de verificar si el personaje esta en colision con el obstaculo, para poder hacerlo en la clase personaje tengo que crear una instancia de la clase obstaculo para poder traer su posicion, al poder traer la posicion hago una funcion que reciba la posicion y devuelva un valor booleano, que seria un entero o 0 o 1 que ya estan definidos en personaje.h como FALSE o como TRUE respectivamente, esto es lo que voy a intentar. 

ya lo implemente y en compilacion no salen errores lo que hice fue una funcion que recibiera las posiciones de personaje y de obstacle y con ellas verificar si estaban siendo iguales para que cuando lo fuesen la variable isAlive cambiase a falsa, una vez con la funcion completa en el main en la funcion update llamo a la funcion CheckIfIsAlive() para que se ejecute constantemente y tambien añadí una 
