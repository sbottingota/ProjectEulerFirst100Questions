const LIMIT::Int = 1e7 - 1;

function arrives_at_89(n::Int)
    while n != 1 && n != 89
        n = sum(digits(n).^ 2)
    end

    n == 89
end

println(count(i -> arrives_at_89(i), 1:LIMIT))

