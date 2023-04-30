# Space Invaders en C++

Este proyecto es una implementación sencilla del clásico juego Space Invaders para consola. Fue escrito en C++ y utiliza la biblioteca `ncurses` para el manejo de la entrada/salida en consola.

## Historia de Space Invaders

Space Invaders es un videojuego de arcade diseñado por Tomohiro Nishikado y lanzado al mercado en 1978. Es uno de los primeros juegos de disparos de la historia, además de ser el primero en permitir que el jugador controle un cañón y dispare a una horda de alienígenas en movimiento.

El objetivo es destruir oleadas de alienígenas con un cañón láser y obtener la mayor cantidad de puntos posible. Space Invaders fue un éxito comercial, sentando las bases para la industria de los videojuegos. Se convirtió en el videojuego más vendido de la época y un clásico de la cultura popular.

El éxito de Space Invaders llevó a la industria de los videojuegos a entrar en una nueva era, y fue el primer éxito mundial de la industria del entretenimiento electrónico. En 2007, la revista Time incluyó a Space Invaders en su lista de los 100 mejores videojuegos de todos los tiempos. En 2016, el juego fue galardonado con el Premio a la Excelencia en el Festival Fun & Serious Game de Bilbao.

## Requisitos

Para compilar y ejecutar este código, necesitarás tener instalada la biblioteca `ncurses`. En la mayoría de las distribuciones de Linux, puedes instalarla con el gestor de paquetes. Por ejemplo, en Ubuntu puedes usar el siguiente comando:

```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
```

## Compilación

Para compilar el código, puedes usar g++ o cualquier otro compilador de C++ compatible. Aquí está el comando de compilación que puedes usar:

```bash
 g++ space_invader.cpp -o space_invader -lncurses
```
## Cómo jugar

El juego se controla con las siguientes teclas:

- 'a': mueve tu nave a la izquierda.
- 'd': mueve tu nave a la derecha.
- 's': dispara para destruir a los aliens que caen desde la parte superior de la pantalla.
- 'q' Salir del juego.
Tu objetivo es destruir a todos los aliens antes de que alcancen la parte inferior de la pantalla, ya que eso significa que han invadido la Tierra y has perdido el juego.

Recuerda que tienes un límite de tiempo para destruir a los aliens y que algunos de ellos pueden moverse más rápido que otros. También ten en cuenta que los aliens se mueven hacia abajo en grupo, por lo que si logras destruir a uno de ellos, los demás se moverán más rápido.

¡Buena suerte en tu misión de salvar al mundo de la invasión alienígena!

## Autor

Miguel Medina Cantos

Estudiante de tercer año de Ingeniería Informática

Fecha de la versión: 2023/04/30

Versión: 1.0

Por favor, ten en cuenta que los comandos de instalación y compilación pueden variar dependiendo de tu sistema operativo.




