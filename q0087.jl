using Primes

const limit = 5e7
const prime_limit::Int = ceil(sqrt(limit))

prime_list = primes(prime_limit)

power_triples = Set()

for p1 in prime_list
    for p2 in prime_list
        if p1*p1 + p2*p2*p2 >= limit
            break
        end

        for p3 in prime_list
            val = p1*p1 + p2*p2*p2 + p3*p3*p3*p3 # p1^2 + p3^3 + p3^4
            if val >= limit
                break
            else
                push!(power_triples, val)
            end
        end
    end
end

println(length(power_triples))

