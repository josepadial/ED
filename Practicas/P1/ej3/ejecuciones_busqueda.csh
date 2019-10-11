#!/bin/csh
@ inicio = 10
@ fin = 599990000
@ incremento1 = 10000
@ incremento2 = 10000000
@ i = $inicio
echo > tiempos_desc.dat
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./ejercicio_desc $i` >> tiempos_desc.dat
  if ($i<1000000) then
    @ i += $incremento1
  else
    @ i += $incremento2
  endif
end
