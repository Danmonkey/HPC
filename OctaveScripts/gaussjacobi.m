x = [0; 0]
prev = 0
x2 = [(2+x(2,1))/4; (9+x(1,1))/5]
diff = norm(x2-x, Inf)
while(diff>.01)
x = x2
x2 = [(2+x(2,1))/4; (9+x(1,1))/5]
diff = norm(x-x2, Inf)
endwhile