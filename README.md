#### Este algoritmo, llamado con humor Algoritmo Turco por [A. Yigit Ogun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97), está diseñado para ordenar una lista aleatoria de números enteros utilizando dos pilas y un conjunto de operaciones predefinidas. A continuación se ofrece una breve descripción general de cómo funciona:
- Inicialización: comience con dos pilas vacías, STACK_A y STACK_B.
- Empujar números a STACK_B: los números se envían de STACK_A a STACK_B en orden descendente. Esto se debe a que cuando se devuelven a STACK_A, se ordenarán automáticamente.
- Determinación de la posición en STACK_B: antes de empujar un número de STACK_A a STACK_B, el algoritmo calcula la cantidad de operaciones necesarias para colocarlo en la posición correcta en STACK_B. Si no es ni el máximo ni el mínimo, calcula dónde debe ubicarse en relación con los números existentes en STACK_B.
- Optimización con el número mágico 3: si el tamaño de la pila es tres, solo se necesita una operación para ordenar la pila, excepto en casos especiales. El algoritmo aprovecha esta eficiencia.
- Rotaciones: el algoritmo optimiza las rotaciones eligiendo el número mínimo común de rotaciones requeridas para ambas pilas antes de realizar las rotaciones.
- Regresar a STACK_A: una vez que todos los números se envían a STACK_B ordenados descendentemente, se regresan a STACK_A.
- Disposición final: finalmente, el algoritmo garantiza que el número mínimo esté en la parte superior de STACK_A, confirmando así que la pila está ordenada.

#### En general, el algoritmo utiliza estratégicamente operaciones de pila para ordenar los números de manera eficiente y al mismo tiempo minimizar la cantidad de operaciones requeridas.
