# find the sum of the first n_digits decimal digits of n
# must set precision of BigFloat high enough to accurately represent all the digits
function digital_sum(n::BigFloat, n_digits::Int)
    ret::Int = 0
    for _ in 1:n_digits
        ret += floor(n) % 10
        n *= 10
    end

    ret
end

setprecision(BigFloat, 512)

digital_sum_sum = 0

for i in 2:100
    sqrt_i = sqrt(big(i))
    if !isinteger(sqrt_i)
        global digital_sum_sum += digital_sum(sqrt_i, 100)
    end
end

println(digital_sum_sum)

