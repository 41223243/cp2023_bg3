set terminal pngcairo enhanced
set output 'trajectory_plot.png'

set title 'Two-Degree-of-Freedom Mass-Spring-Damper System'
set xlabel 'Time (s)'
set ylabel 'Position and Velocity'

plot 'trajectory_data.txt' using 1:2 with lines title 'x1', \
     'trajectory_data.txt' using 1:3 with lines title 'x2', \
     'trajectory_data.txt' using 1:4 with lines title 'v1', \
     'trajectory_data.txt' using 1:5 with lines title 'v2'
