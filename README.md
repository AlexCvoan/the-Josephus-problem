  Console app written in C++ that solves the Josephus problem

  The statement of the problem is: there are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, the next person alive is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom.

  The program will ask for n and will create a circular simple linked list with n nodes, attributing an id to every node, from 1 to n. After the list is created, it will begin the deletion part. By using a variable named “delete”, the code will skip one node (because an executed person can’t kill the next person), deleting every other node in the list. This process will be repeated until there is only one node left in the list, the current node.
