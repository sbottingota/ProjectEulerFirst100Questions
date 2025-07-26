function sqrt_2_expansion(layers::Int)::Rational
    n = big(1//2)

    for _ in 1:layers - 1
        n += 2
        n = 1 // n
    end

    n + 1
end

count = 0

for i in 1:1000
    n = sqrt_2_expansion(i)

    if ndigits(numerator(n)) > ndigits(denominator(n))
        global count += 1
    end
end

println(count)

