[X][\^][0-9]+|[-,+,=,*][ ]|[0-9]+[.][0-9]+|[0-9]+|[X]|[ ]


option 1 : [X][\^][0-9]+|[-,+,=,*][ ]|[0-9]+[.][0-9]+[ ]|[0-9]+[ ]|[X][ ]|[ ]

option 2 :
^[0-9]+\.[0-9]+|^[0-9]+|^[X][\^][0-9]+|[0-9]+\.[0-9]+$|[X][\^][0-9]+$|[0-9]+$|[0-9,X\^]+[ ]?[*,+,\-][ ]?[0-9,X\^]+

option3 :
[X][\^][0-9]+|[ ]?[-,+,*][ ]?|[0-9]+[.][0-9]+|[0-9]+|[X][ ]|[0-9]+$|[0-9]+\.[0-9]+$

option 4 :
[X][\^][0-9]+|[ ]?[-,+,*][ ]?|[0-9]+[.][0-9]+|[0-9]+|[X][ ]?|[0-9]+$|[0-9]+\.[0-9]+$


regex check debu et fin :
^[0-9]+\.[0-9]+|^[0-9]+|^[X][\^][0-9]+|[0-9]+\.[0-9]+$|[X][\^][0-9]+$|[0-9]+$



regex tests :
5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0
5 * X^0 + 4 * X^1 = 4 * X^0
8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0
42 * X^0 = 42 * X^0
8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0 - 3
8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0 - X
5 + 4 * X + X^2= X^2