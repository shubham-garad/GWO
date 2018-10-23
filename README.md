# GWO
Grey-Wolf-Optimization

Pseudo code for GWO :-
<center>
Initialize the grey wolf population Xi (i = 1, 2, ..., n)
Initialize a, A, and C
Calculate the fitness of each search agent
Xα=the best search agent
Xβ=the second best search agent
Xδ=the third best search agent
while (t < Max number of iterations)
for each search agent
Update the position of the current search agent by equation (3.7)
end for
Update a, A, and C
Calculate the fitness of all search agents
Update Xα, Xβ, and Xδ
t=t+1
end while
return Xα
              </center>
