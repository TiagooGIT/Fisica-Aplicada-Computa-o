# gnu_project-2D_v2
#
# Física Aplicada à Computação
# Lic. Eng. Informática - Ano lectivo 2021-22
#
# nuno.pereira@ipbeja.pt
#
# CC-BY-SA 4.0

# definições iniciais
reset
set term wxt 0  enhanced
set encoding iso_8859_15
set size square
set angle degrees
set dummy t

# legendas
str_Title = "Lançamento 2D"
str_x = "t (s)"
str_y = "x, y (m)"
str_y2 = "v_{x}, v_{y} (m.s^{-1})"

set title  str_Title font "Arial, 14"
set xlabel str_x font "Arial, 11"
set ylabel str_y font "Arial, 11"
set y2label str_y2 font "Arial, 11"

# define tics
set xtic  font "Arial, 10"
set ytic nomirror font "Arial, 10"
set y2tic nomirror font "Arial, 10"

# define condições iniciais
vo = 10 # m/s
alfa = 35 # graus
yo = 15 # m
g = -9.8 # m/s2

str_vo = sprintf("v_{o} = %.1f m.s^{-1}", vo)
str_alfa = sprintf("{/Symbol a} = %.1f ^{o}", alfa)
str_yo = sprintf("y_{o} = %.1f m", yo)

set label 1 at graph 1.2, 1 str_vo font "Arial, 10"
set label 2 at graph 1.2, .9 str_alfa font "Arial, 10"
set label 3 at graph 1.2, .8 str_yo font "Arial, 10"

vox = vo * cos(alfa)
voy = vo * sin(alfa)

# cálculo do tempo de voo
a = .5*g
b = voy
c = yo

t_voo = (-b - sqrt(b*b-4*a*c)) / (2*a)
print "t_voo = ", t_voo

# Equações do movimento
x(t) = vox * t                # MRU
y(t) = yo + voy*t + .5*g*t**2 # MRUA

# Equações das velocidades
vx(t) = vox
vy(t) = voy + g*t

# define o intervalo de tempo
t_max = t_voo
set xrange [0:t_max]
plot x(t), y(t) axis x1y1 w l lw 1.5, \
     vx(t), vy(t) axis x1y2 w l lw 1.5

# gráfico da trajectória  - modo paramétrico - 2ª janela
pause (-1)
set term wxt 1 enhanced
set xlabel "x"
set ylabel "y"
unset y2label
unset y2tics
unset key
set parametric
set autoscale
set trange[0:t_voo]



xmax = x(t_voo)
set xrange [0:xmax]
set yrange [0:20]


#plot x(t), y(t)
#xo = 0 # n/s
#vo = 10 #m/s
#yo = 15 # m
#alfa = 30 #graus
#a = -9.8  #m/s é a gravidade
#ymax = y(tmax)

#tmax = -voy/a

#voy = vo * sin(alfa) #10 sin (30) = -9.9
#vox = vo * cos(alfa)
#vx(t) = vox
#vy(t) = voy + a*t
#tv = (-voy - sqrt(voy*voy-4*.5*a*yo))/a

t = 0
dt = .03

do for[n=1:82] { # em 360 graus , tendo um dt de .5 vai rodando de 0.5 ate os 360 graus
   t = n*dt

plot  x(t), y(t) axis x1y1 w l lw 1.5, 1/0, 1/0
   set object 1 circle at x(t),y(t) size .5

   set arrow 1 from x(t),y(t) rto vx(t),0 #Vetor velocidade de x com y = 0
   set arrow 2  from x(t),y(t) rto 0,vy(t) #Vetor velocidade de y com x = 0
   set arrow 3 from x(t),y(t) rto vx(t),0 + vy(t) #velocidade total

}
