A = [4, -1; 1, 5;]
b = [2; -9]
L = inv(tril(A))
U = triu(A, 1)
T = -L*U
C = L*b
x = [0; 0]
prev = [0; 0]
x = T*x+C
diff =  norm(x-prev, Inf)
while(diff>.01)
prev = x
x = T*x+C
diff = norm(x-prev, Inf)
endwhile