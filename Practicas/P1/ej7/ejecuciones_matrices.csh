#!/bin/csh
@ inicio = 3
@ fin = 1000
@ incremento = 1
set ejecutable = matriz
set salida = tiempos_matrices.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000` >> $salida
  @ i += $incremento
end
