const SPIRAL_SIZE = 1001;

diagonal_sum = 1

n = 1
m = 2

for i in 1:SPIRAL_SIZE / 2
    for j in 1:4
        global n += m
        global diagonal_sum += n
    end

    global m += 2
end

println(diagonal_sum)

