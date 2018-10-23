# GWO
Grey-Wolf-Optimization

Pseudo code for GWO :-
<center>
Initialize the grey wolf population Xi (i = 1, 2, ..., n)<br>
Initialize a, A, and C<br>
Calculate the fitness of each search agent<br>
Xα=the best search agent<br>
Xβ=the second best search agent<br>
Xδ=the third best search agent<br>
while (t < Max number of iterations)<br>
for each search agent<br>
Update the position of the current search agent by equation (3.7)<br>
end for<br>
Update a, A, and C<br>
Calculate the fitness of all search agents<br>
Update Xα, Xβ, and Xδ<br>
t=t+1<br>
end while<br>
return Xα<br>
              </center>
