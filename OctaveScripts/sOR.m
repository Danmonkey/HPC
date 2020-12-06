omega = 1.25
A = [4, -1; 1, -5]
b = [2;-9]
D = tril(A)
D(2, 1) = 0
L = tril(A, -1)
U = triu(A, 1)
L = inv(D+(omega*L))
T = L*(-((omega*U)+(omega-1)*D))
C = L*(omega*b)
prev = 0
x = [0;0]
x = T*x+C
diff = max(x)
while(diff>.01)
prev = x
x = T*x+C
diff = norm(x-prev, Inf)
endwhile