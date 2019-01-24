<h1>Open FinalFinalGWO.cpp for latest working code!!!!!</h1>
<h4>Open FinalFinalGWO.cpp for latest working code.<br> <br>Still need to add other fitness functions from benchmarks.cpp but yeah now it is almost done .. :) :)<br>I know it's not professional code or like professional coder's work, blame the algo :)</h4>
<h1 align="center"># GWO</h1>
<html>

<p><h3>Grey-Wolf-Optimization</h3>

<h4 align="center">Pseudo code for GWO :-</h4></p>

<p style="padding-right: 5px;">1. Initialize the grey wolf population Xi (i = 1, 2, ..., n)<br>
2. Initialize a, A, and C<br>
3. Calculate the fitness of each search agent<br>
4. Xα=the best search agent<br>
5. Xβ=the second best search agent<br>
6. Xδ=the third best search agent<br>
7. while (t < Max number of iterations)<br>
8. for each search agent<br>
9. Update the position of the current search agent by equation (3.7)<br>
10. end for<br>
11. Update a, A, and C<br>
12. Calculate the fitness of all search agents<br>
13. Update Xα, Xβ, and Xδ<br>
14. t=t+1<br>
15. end while<br>
16. return Xα<br>
  </p>
<p>
<h3 align="center"> Depedencies:</h3></p>
 <ul>
  <li>**Make sure your gcc version is 4.9.2 or higher** You can check it in Devcpp in compiler options
    <br>__You can download it from <a href="url">here</a>__</li>
  <li>Go to your compiler settings and add <i>"-std=c++11"</i> in the commands when calling the compiler<br>
    <t>and <i>"-static-libgcc"</i> in the commands when calling the linker</t></li>
      <li>select the <em>'TDM-GCC 4.9.2 64-bit Release'</em> I don't know why but, for 32 bit it is not <br> working maybe a <i>bug</i></li>
</ul> 

</html>
