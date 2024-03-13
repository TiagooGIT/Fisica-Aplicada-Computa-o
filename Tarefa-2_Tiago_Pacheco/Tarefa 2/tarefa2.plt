# teste3

reset

set term wxt
set size square
set sample 500


set title "Lançamento de projéteis 1D" font "Helvetica, 12"
set xlabel "t (s)"
set ylabel "x(t)"
set y2label "v(t)"


set key at graph 1.45,1 reverse Left samplen .7
set ytics nomirror
set y2tics
set xtics

set angle degree
set dummy t # variavel t é a independente

# CI


vo = 10 #m/s
xo = 0 # m
coe = 0.1
g = 9.8
a = g * coe

#set xrange [0:tp]

# calculoa da velocidade

#v = sqrt(vo**2 - 2 *coe*g*deltax)
#print(v)


# delta t

#deltat = (v + vo)


# Equações do moveimento

v(t) = vo - a*t # moveimento retilinio uniforme
x(t) = (xo + vo*t) - (.5*a*t*t) # moviemnto retilinio uniforme

# equações das compontes da velocidade

#vx(t) = vox
#vy(t) = voy + a*t


# cálculo do tempo de altura maxima

tmax = vo/a
#print (tmax)

# Altura maxima

#ymax = y(tmax)
#print(ymax)
xmax = x(tmax)

#calculo do tempo de voo ou paragem



# Alcance

#xa = x(tv)

# velocidade de impacto

#viy = vy(tv)
#vi = sqrt(vox*vox + viy*viy)
#gama = atan(vy(tv)/vox)

#Legendas
#str_ymax = sprintf("y_{max} = %.2f m", ymax)
#str_xmax = sprintf("x_{max} = %.2f m", xmax)
#str_tmax = sprintf("t_{max} = %.2f m", tmax)
#str_tv = sprintf("t_{v} = %.2f m", tv)
#str_xa = sprintf("x_{a} = %.2f m", xa)
#str_vi = sprintf("v_{i} = %.2f m", vi)
#str_gama = sprintf("{/Symbol g} = %.2f º", gama)
#str_vo = sprintf("v_{0} = %.2f º", vo)
#str_alfa = sprintf("{/Symbol a} = %.2f º", alfa)
#str_xo = sprintf("x_{0} = %.2f m", xo)
#str_yo = sprintf("y_{0} = %.2f m", yo)



#set label 1 str_tmax at tmax, ymax*1.3 font ",8"
#set label 2 str_xmax at tmax, ymax*1.2 font ",8"
#set label 3 str_ymax at tmax, ymax*1.1 font ",8"
#set label 4 str_tv at tv*.75, ymax*.1 font ",8"
#set label 5 str_xa at tv*.5, ymax*.1 font ",8"
#set label 6 str_vi at graph 1.3,.10
#set label 7 str_gama at graph 1.3,.32
#set label 8 str_vo at graph 1.3,.15
#set label 9 str_xo at graph 1.3,.25
#set label 10 str_alfa at graph 1.3,.35
#set label 11 str_yo at graph 1.3,.45
set autoscale

set xrange [0:10]
set yrange [0:50]
set y2range [0:10]

plot x(t), v(t) axes x1y2

    #vx(t) axes x1y2 w l lw 1.5, vy(t) axes x1y2 w l lw 1.5


#pause(-1)

#set parametric
#set trange[0:tv]
#set autoscale
#unset y2tics
#set ytics mirror
#set xlabel "x (m)"
#set ylabel "y (m)"
#set y2label ""
#set key default
#unset label


#plot x(t), y(t)
#xo = 0 # n/s
#vo = 10 #m/s
#yo = 15 # m
#alfa = 30 #graus
#a = -9.8  #m/s é a gravidade
#ymax = y(tmax)
#xmax = x(tmax)
#tmax = -voy/a

#voy = vo * sin(alfa) #10 sin (30) = -9.9
#vox = vo * cos(alfa)
#vx(t) = vox
#vy(t) = voy + a*t
#tv = (-voy - sqrt(voy*voy-4*.5*a*yo))/a
#t = tv
#dt = 1
pause (-1)
set parametric
set autoscale
unset y2tics
unset key

set xrange [0:xmax]
set x2range [0:xmax]
set yrange [0:10]

dt = 0.04
t = 0

do for[n=0 : 210] { # em 360 graus , tendo um dt de .5 vai rodando de 0.5 ate os 360 graus
   t = n*dt
   set object 1 circle at x(t),5 size 2
   set arrow 1 from x(t),5 rto v(t)
   set arrow at xo,4.6 rto xmax,0 nohead

  plot 1/0, 1/0
}
