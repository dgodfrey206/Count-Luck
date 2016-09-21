# Count-Luck
https://www.hackerrank.com/challenges/count-luck

Ron and Hermione are deep in the Forbidden Forest collecting potion ingredients, and they've managed to lose their way. The path out of the forest is blocked, so they must make their way to a portkey that will transport them back to Hogwarts.

Consider the forest as an `N x M` grid. Each cell is either empty (represented by `.`) or blocked by a tree (represented by `X`). Ron and Hermione can move (together inside a single cell) `LEFT`, `RIGHT`, `UP`, and `DOWN` through empty cells, but they cannot travel through a tree cell. Their starting cell is marked with the character `M`, and the cell with the portkey is marked with a `*`. The upper-left corner is indexed as `(0, 0)`.

    .X.X......X
    .X*.X.XXX.X
    .XX.X.XM...
    ......XXXX.
    
In example above, Ron and Hermione are located at index `(2, 7)` and the portkey is at `(1, 2)`. Each cell is indexed according to [Matrix Conventions](https://www.hackerrank.com/scoring/board-convention).

Hermione decides it's time to find the portkey and leave. Each time they are able to move in more than one direction, she waves her wand and it points to the correct direction. Ron is betting that she will have to wave her wand exactly `K` times. Can you determine if Ron's guesses are correct?

**Note**: It is guaranteed that there is only one path from the starting location to the portkey.

<h3>Input Format</h3>

The first line contains an integer, `T` , the number of test cases.

Each test case is described as follows: 
The first line contains `2` space-separated integers, `N` and `M`, respectively, denoting the forest matrix. 
The `N` subsequent lines each contain a string of length `M` describing a row of the forest matrix. 
The last line contains an integer, `K`, denoting Ron's guess as to how many times Hermione will wave her wand.

<h3>Constraints</h3>

 - `1 <= T <= 10`
 - `1 <= N,M <= 100`
 - `0 <= K <= 1000`
 - There will be exactly one `M` and one `*` in the forest.
 - Exactly one path exists between `M` and `*`.
 
<h3>Output Format</h3>
On a new line for each test case, print "Impressed" if Ron impresses Hermione by guessing correctly; otherwise, print "Oops!".
