const limit = 99

best_digit_sum = 0

for a::BigInt in 2:limit
    for b::BigInt in 2:limit
        digit_sum = sum(digits(a^b))
        if digit_sum > best_digit_sum
            global best_digit_sum = digit_sum
        end
    end
end

println(best_digit_sum)

