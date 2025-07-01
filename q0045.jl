# taken from https://en.wikipedia.org/wiki/Pentagonal_number#Tests_for_pentagonal_numbers
function is_pentagonal(n)
    isinteger((sqrt(24n + 1) + 1) / 6)
end

# taken from https://en.wikipedia.org/wiki/Hexagonal_number#Test_for_hexagonal_numbers
function is_hexagonal(n)
    isinteger((sqrt(8n + 1) + 1) / 4)
end

function triangle(n)
    div(n * (n+1), 2)
end

# print the next number after 40,755 which is triangular, pentagonal, and hexagonal
for i in Iterators.countfrom(40_756)
    n = triangle(i)

    if is_pentagonal(n) && is_hexagonal(n)
        println(n)
        break
    end
end

