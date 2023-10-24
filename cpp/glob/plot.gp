#!/usr/bin/gnuplot

reset

set terminal pngcairo size 800,600 enhanced font 'Verdana, 10'

# define axis
# remove border on top and right and set color to gray
set style line 11 lc rgb '#808080' lt 1
set border 3 back ls 11
set tics nomirror
# define grid
set style line 12 lc rgb '#808080' lt 0 lw 3
set grid back ls 12

# color definitions
set style line 1 dt 1 lc rgb '#e20074' lt 1 lw 3 ps 0
set style line 2 dt 1 lc rgb '#948b3d' lt 1 lw 3 ps 0
set style line 3 dt 1 lc rgb '#da7c30' lt 1 lw 3 ps 0
set style line 4 dt 1 lc rgb '#396ab1' lt 1 lw 3 ps 0

set key outside bottom right
# set datafile missing '0'
set datafile separator whitespace

set size ratio 0.3

set title 'glob vs readdir loop' font ', 10' offset 0,-1

set xlabel 'number of files as input' font ', 10'
set xrange [0:]
set yrange [0:]
set xtics font ', 10'
set ytics font ', 10'

# Lease rate
set ylabel 'time taken [ms] - lower is better' font ', 10'
set output 'a.png'
plot \
    "< awk '{ sum[$1]+=$2; count[$1]++ } END{ for(x in sum) { print x, sum[x] / count[x] } }' a.dat | sort -uV" u 1:2 t 'glob' w lp ls 1, \
    "< awk '{ sum[$1]+=$3; count[$1]++ } END{ for(x in sum) { print x, sum[x] / count[x] } }' a.dat | sort -uV" u 1:2 t 'readdir loop' w lp ls 2, \
