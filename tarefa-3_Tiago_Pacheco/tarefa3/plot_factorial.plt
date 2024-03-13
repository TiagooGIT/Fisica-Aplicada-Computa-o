# teste3


reset
set term wxt 0 enhanced

set size square
set angle degrees




str_Title = "Arduino factorial"

set title str_Title font "Arial, 8"


set xtic font "Arial, 8"
set ytic font "Arial, 8"
set xlabel "n" font "Arial, 5"
set ylabel "t_{exec}(us)" font "Arial, 8"
set xrange [0:180]
set yrange [0:420]


set key at graph 0.7,1 reverse Left samplen 1


plot "for_float.txt"  w l lw 1.5, \
     "for_double.txt"  w l lw 1.5, \
     "while_float.txt"    w l lw 1.5, \
     "while_double.txt"  w l lw 1.5, \
     "rec_float.txt"  w l lw 1.5, \
     "rec_double.txt"   w l lw 1.5
