# Sierpinski-N-gon
A program written in C and run through cern root (a c interpreter + library) that generates Sierpinski N-gons, with added functionality to add points to the polygon

Inorder to run this program you will be cern root: https://root.cern/install/
To run the program simply type ".L" followed by the directory to main.cpp, and then main()

At the top of main.cpp there are two variables, sides, and between. Edit the sides variable to any integer, and set between to 0, to produce the standard Sierpinski-N-gon for that integer.

Here's an example of the program run with sides = 3, and between = 0, which gives the classic Sierpinski triangle
![image](https://user-images.githubusercontent.com/56443205/111396910-6dc86c80-8696-11eb-9f42-9dc2e641f1ba.png)

You can see green dots surrounding the fractle, these are the points I used to iterate between to generate the triangle
If you edit the between variable then extra points will be added to the polygon, evenly spaced on each side.
here's an example of the program run with sides = 5 and between = 0, followed by screenshot of the program run with sides = 5 and between = 1

![image](https://user-images.githubusercontent.com/56443205/111397084-d0ba0380-8696-11eb-908d-ff3be92bc472.png)
![image](https://user-images.githubusercontent.com/56443205/111397096-d7487b00-8696-11eb-8be7-8d277a9d2b9e.png)

An interesting effect of added more points to the polygon, is that the since the shape of the polygon is maintained, the shape of the fractle remains the same, but since more points are iterated on more copys of the fractle are created within itself.
Another interesting side note that can be seen with this program is that as more points are iterated on the fractle itself gets smaller in absolute size. This is true for adding between points or simply by increasing the number of sides on the polygon. To make it so you can still see larger polygons (even if it's a little boring since they get closer and closer to being circles) I added functionality to automatically zoom in on the fractle when the number of points is larger, although when this is the case you cannot see the green points that were used for the iteration.
