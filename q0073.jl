function count_reduced_fracs(low, high, max_denom)
    count = 0

    for denom in 2:max_denom
        for num in floor(denom * low) + 1 : ceil(denom * high) - 1
            if gcd(Int(num), denom) == 1
                count += 1
            end
        end
    end

    return count
end

println(count_reduced_fracs(1/3, 1/2, 12_000))

